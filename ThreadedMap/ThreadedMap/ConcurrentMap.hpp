#include <shared_mutex>
#include <string>
#include <unordered_map>

class ConcurrentMap {
public:
  int read(const std::string &key);

  void write(const std::string &key, const int &value);

  size_t size() const;

  void erase(const std::string &key);

  bool contains(const std::string &key) const;
  void clear();

  std::unordered_map<std::string, int>
  bulk_read(const std::vector<std::string> &keys);

  void bulk_write(const std::unordered_map<std::string, int> &entries);

private:
  std::unordered_map<std::string, int> map;
  mutable std::shared_mutex m_mutex;
};
