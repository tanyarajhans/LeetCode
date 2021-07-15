class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int, unordered_set<int>> m;
    
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
    v.push_back(val);
    m[val].insert(v.size() - 1);
    return m[val].size() == 1;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
       auto it = m.find(val);
       if (it != end(m)) {
           auto free_pos = *it->second.begin();
           it->second.erase(it->second.begin());
           v[free_pos] = v.back();
           m[v.back()].insert(free_pos);
           m[v.back()].erase(v.size() - 1);
           v.pop_back();
           if (it->second.size() == 0) 
               m.erase(it);
            return true;
          }
        return false;    
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */