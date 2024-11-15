#include "ConcurrentMap.hpp"
#include "ThreadPool.hpp"
#include <atomic>
#include <chrono>
#include <iomanip>
#include <iostream>
#include <mutex>
#include <random>
#include <sstream>

std::atomic<int> completedTasks(0);
std::mutex m_mutex;

std::string getCurrentTime() {
  auto now = std::chrono::system_clock::now();
  auto now_c = std::chrono::system_clock::to_time_t(now);
  std::stringstream ss;
  ss << std::put_time(std::localtime(&now_c), "%H:%M:%S");
  return ss.str();
}

void simulateWork(int milliseconds) {
  std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}

void processOrder(int orderId, ConcurrentMap &inventory,
                  const std::string &product) {
  std::cout << "[" << getCurrentTime() << "] Thread "
            << std::this_thread::get_id() << " processing order " << orderId
            << " for " << product << "\n";

  // Lock the inventory access to prevent concurrent modification issues
  {
    std::lock_guard<std::mutex> lock(
        m_mutex); // Using Mutex for inventory simplicity
    int currentQty = inventory.read(product);
    inventory.write(product, currentQty - 1);
  }

  std::cout << "Order " << orderId << " completed! Remaining " << product
            << " inventory: " << inventory.read(product) << "\n";

  completedTasks++;
}

int main() {
  const int TOTAL_TASKS = 7;

  ThreadPool pool(3);

  std::cout << "Created thread pool with" << TOTAL_TASKS << " workers\n\n";

  ConcurrentMap inventory;
  inventory.write("Laptop", 5);
  inventory.write("Phone", 3);
  std::cout << "Initial inventory:\n";
  std::cout << "Laptops: " << inventory.read("Laptop") << "\n";
  std::cout << "Phones: " << inventory.read("Phone") << "\n\n";
  std::cout << "Starting to process orders...\n\n";

  // Submit tasks
  pool.submit([&]() { processOrder(1, inventory, "Laptop"); });
  pool.submit([&]() { processOrder(2, inventory, "Phone"); });
  pool.submit([&]() { processOrder(3, inventory, "Laptop"); });
  pool.submit([&]() { processOrder(4, inventory, "Laptop"); });
  pool.submit([&]() { processOrder(5, inventory, "Laptop"); });
  pool.submit([&]() { processOrder(7, inventory, "Phone"); });
  pool.submit([&]() { processOrder(8, inventory, "Phone"); });

  // Wait for all tasks to complete with timeout and progress indicator
  const auto startTime = std::chrono::steady_clock::now();
  const auto timeout = std::chrono::seconds(10);

  while (completedTasks.load(std::memory_order_acquire) < TOTAL_TASKS) {
    if (std::chrono::steady_clock::now() - startTime > timeout) {
      std::cout << "Timeout waiting for tasks to complete! Completed: "
                << completedTasks.load() << "/" << TOTAL_TASKS << "\n";
      return 1;
    }
    simulateWork(100);
    std::cout << "Waiting... Completed tasks: " << completedTasks.load() << "/"
              << TOTAL_TASKS << "\r" << std::flush;
  }
  std::cout << "\nAll tasks completed!\n";
  std::cout << "\nFinal inventory:\n";
  std::cout << "completedTasks: " << completedTasks << "\n";
  std::cout << "Laptops: " << inventory.read("Laptop") << "\n";
  std::cout << "Phones: " << inventory.read("Phone") << "\n";

  // Explicit shutdown, not necessary because shutdown is called in the threadpool destructor 
  pool.shutdown();
  std::cout << "\nProgram completed successfully!\n";

  return 0;
}