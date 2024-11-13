#include "ConcurrentMap.hpp"

int ConcurrentMap::read(const std::string &key) {
  std::shared_lock<std::shared_mutex> lock(m_mutex);
  auto it = map.find(key);
  if (it != map.end()) {
    return it->second;
  }
  return {};
}

void ConcurrentMap::write(const std::string &key, const int&value) {
  std::unique_lock<std::shared_mutex> lock(m_mutex);
  map[key] = value;
}

size_t ConcurrentMap::size() const {
  std::shared_lock<std::shared_mutex> lock(m_mutex);
  return map.size();
}

void ConcurrentMap::erase(const std::string &key) {
  std::unique_lock<std::shared_mutex> lock(m_mutex);
  map.erase(key);
}

bool ConcurrentMap::contains(const std::string &key) const {
  std::shared_lock<std::shared_mutex> lock(m_mutex);
  return map.find(key) != map.end();
}

void ConcurrentMap::clear() {
  std::unique_lock<std::shared_mutex> lock(m_mutex);
  map.clear();
}

std::unordered_map<std::string, int>
ConcurrentMap::bulk_read(const std::vector<std::string> &keys) {
  std::shared_lock<std::shared_mutex> lock(m_mutex);
  std::unordered_map<std::string, int> results;
  for (const auto &key : keys) {
    auto it = map.find(key);
    if (it != map.end()) {
      results[key] = it->second;
    }
  }
  return results;
}

void ConcurrentMap::bulk_write(
    const std::unordered_map<std::string, int> &entries) {
  std::unique_lock<std::shared_mutex> lock(m_mutex);
  for (const auto &[key, value] : entries) {
    map[key] = value;
  }
}
