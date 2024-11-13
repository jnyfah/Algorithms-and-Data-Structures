#include <condition_variable>
#include <mutex>
#include <queue>

template <typename T> class TaskQueue {

public:
  void addTask(const T &task) {
    {
      std::lock_guard<std::mutex> lock(m_mutex);
      m_queue.emplace(task);
    }
    m_cond.notify_one();
  }

  void addTask(T &&task) {
    {
      std::lock_guard<std::mutex> lock(m_mutex);
      m_queue.emplace(task);
    }
    m_cond.notify_one();
  }

  void notifyAll() {
    m_cond.notify_all();
  }

  bool getTask(T &task) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_cond.wait(lock, [this] { return !m_queue.empty(); });
    if (m_queue.empty()) {
      return false;
    }
    task = std::move(m_queue.front());
    m_queue.pop();
    return true;
  }

  bool tryGetTask(T &task) {
    std::lock_guard<std::mutex> lock(m_mutex);
    if (m_queue.empty()) {
      return false;
    }
    task = std::move(m_queue.front());
    m_queue.pop();
    return true;
  }

  constexpr size_t size() const noexcept{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_queue.size();
  }
  constexpr bool isEmpty() const noexcept{
    std::lock_guard<std::mutex> lock(m_mutex);
    return m_queue.empty();
  }

private:
  std::queue<T> m_queue;
  mutable std::mutex m_mutex;
  std::condition_variable m_cond;
};