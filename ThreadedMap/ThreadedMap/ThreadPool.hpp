#include "TaskQueue.hpp"
#include <functional>
#include <thread>
#include <vector>

class ThreadPool {
public:
  ThreadPool(size_t numThreads)
      : m_shutdown(false) {
    StartWorkerThread(numThreads);
  }

  void submit(std::function<void()> task) {
    if (!m_shutdown) {
      m_taskQueue.addTask(std::move(task));
    }
  }

  void shutdown() {
    m_shutdown = true;
    m_taskQueue.notifyAll();

    for (auto &worker : m_workers) {
      if (worker.joinable()) {
        worker.join();
      }
    }
  }

  ~ThreadPool() { shutdown(); }

private:
  TaskQueue<std::function<void()>> m_taskQueue;
  std::vector<std::thread> m_workers;
  std::atomic<bool> m_shutdown;

  void StartWorkerThread(size_t numThreads) {
    for (int i = 0; i < numThreads; i++) {
      m_workers.emplace_back([this] {
        while (true) {
          std::function<void()> task;
          if (!m_taskQueue.getTask(task) || m_shutdown) {
            break;
          }
          task();
        }
      });
    }
  }
};