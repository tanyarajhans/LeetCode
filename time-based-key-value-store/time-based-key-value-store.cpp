class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> m;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        m[key].insert({timestamp,value});
    }
    
    string get(string key, int timestamp) {
        auto it=m[key].upper_bound(timestamp);
        return (it==m[key].begin())?"":prev(it)->second;
    }
};
​
/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
