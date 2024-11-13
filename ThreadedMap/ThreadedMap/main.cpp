#include <iostream>
#include <iomanip>
#include <chrono>
#include <random>
#include <sstream>
#include <atomic>
#include "ThreadPool.hpp"
#include "ConcurrentMap.hpp"

std::atomic<int> completedTasks(0);  // Track completed tasks

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

void processOrder(int orderId, ConcurrentMap& inventory, const std::string& product) {
    std::cout << "[" << getCurrentTime() << "] Thread " << std::this_thread::get_id() 
              << " processing order " << orderId << " for " << product << "\n";
    
    int quantity = inventory.read(product);
    if (quantity <= 0) {
        std::cout << "Order " << orderId << ": " << product << " out of stock!\n";
        completedTasks++;
        return;
    }

    // Simulate processing time (1 second)
    simulateWork(1000);

    // Decrement inventory
    inventory.write(product, quantity - 1);
    std::cout << "Order " << orderId << " completed! Remaining " 
              << product << " inventory: " << (quantity - 1) << "\n";
    
    completedTasks++;
}

int main() {
    {  // Create a scope for the ThreadPool
        ThreadPool pool(3);
        std::cout << "Created thread pool with 3 workers\n\n";

        ConcurrentMap inventory;
        inventory.write("Laptop", 5);
        inventory.write("Phone", 3);
        
        std::cout << "Initial inventory:\n";
        std::cout << "Laptops: " << inventory.read("Laptop") << "\n";
        std::cout << "Phones: " << inventory.read("Phone") << "\n\n";

        std::cout << "Starting to process orders...\n\n";

        // Submit 6 orders
        pool.submit([&]() { processOrder(1, inventory, "Laptop"); });
        pool.submit([&]() { processOrder(2, inventory, "Phone"); });
        pool.submit([&]() { processOrder(3, inventory, "Laptop"); });
        pool.submit([&]() { processOrder(4, inventory, "Phone"); });
        pool.submit([&]() { processOrder(5, inventory, "Laptop"); });
        pool.submit([&]() { processOrder(6, inventory, "Phone"); });

        // Wait for all tasks to complete
        while (completedTasks < 6) {
            simulateWork(100);  // Check every 100ms
        }

        std::cout << "\nFinal inventory:\n";
        std::cout << "completedTasks: " << completedTasks << "\n";
        std::cout << "Laptops: " << inventory.read("Laptop") << "\n";
        std::cout << "Phones: " << inventory.read("Phone") << "\n";
    }
    
    std::cout << "\nProgram completed successfully!\n";
    return 0;
}