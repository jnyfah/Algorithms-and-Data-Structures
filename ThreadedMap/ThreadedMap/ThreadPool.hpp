#include "TaskQueue.hpp"
#include <atomic>
#include <functional>
#include <iostream>
#include <thread>
#include <vector>


class ThreadPool {
public:
  ThreadPool(size_t numThreads) : m_shutdown(false) {
    startWorkerThreads(numThreads);
  }

  ThreadPool(const ThreadPool &) = delete;
  ThreadPool &operator=(const ThreadPool &) = delete;

  void submit(std::function<void()> task) {
    if (!m_shutdown) {
      m_taskQueue.addTask(std::move(task));
    }
  }

  void shutdown() {
    std::cout << "ThreadPool shutdown initiated\n";
    m_shutdown = true;
    m_taskQueue.notifyAll(); // Wake up all threads

    for (auto &worker : m_workers) {
      std::cout << "Joining worker thread\n";
      if (worker.joinable()) {
        worker.join();
      }
    }
    std::cout << "ThreadPool shutdown complete\n";
  }

  ~ThreadPool() {
    if (!m_shutdown) {
      shutdown();
    }
  }

private:
  TaskQueue<std::function<void()>> m_taskQueue;
  std::vector<std::thread> m_workers;
  std::atomic<bool> m_shutdown;

  void startWorkerThreads(size_t numThreads) {
    m_workers.reserve(numThreads);
    for (size_t i = 0; i < numThreads; ++i) {
      m_workers.emplace_back([this, i] {
        std::cout << "\nWorker " << i << " started\n";
        while (!m_shutdown) {
          std::function<void()> task;

          if (!m_taskQueue.getTask(task, m_shutdown)) {
            continue; // Either queue is empty or shutdown was signaled
          }

          task();
        }
        std::cout << "Worker " << i << " exiting\n";
      });
    }
  }
};