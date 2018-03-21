#include <vector>
#include <map>
#include <unordered_map>
#include <random>
using namespace std;

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mapping.find(val) != mapping.end())
        {
            return false;
        }
        mapping[val] = mem.size();
        mem.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (mapping.find(val) == mapping.end())
        {
            return false;
        }
        int last = mem.size() - 1;
        int pos = mapping[val];
        if (pos != last)
        {
            mem[pos] = mem[last];
            mapping[mem[last]] = pos;
        }
        mapping.erase(val);
        mem.erase(mem.cend() - 1);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        uniform_int_distribution<int> distribution(0, mem.size() - 1);
        int pos = distribution(generator);
        return mem[pos];
    }
    private:
        vector<int> mem;
        unordered_map<int, int> mapping;
        default_random_engine generator;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */