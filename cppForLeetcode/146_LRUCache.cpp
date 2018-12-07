#include <map>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
public:
    using listiter = list<pair<int, int>>::iterator;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if(mapping.count(key) == 0)
        {
            return -1;
        }
        pair<int, listiter> &cache = mapping[key];
        caches.erase(cache.second);
        caches.emplace_front(key, cache.first);
        mapping[key] = make_pair(cache.first, caches.begin());
        return cache.first;
    }
    
    void put(int key, int value) {
        if(get(key) != -1)
        {
            mapping[key].first = value;
            return;
        }
        caches.emplace_front(key, value);
        mapping[key] = make_pair(value, caches.begin());
        if(caches.size() > cap)
        {
            mapping.erase(caches.back().first);
            caches.pop_back();
        }
    }
    
    private:
    int cap;
    list<pair<int, int>> caches;
    unordered_map<int, pair<int, listiter>> mapping;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */