/*
Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 [capacity]  );

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4
*/

class LRUCache {
private:
    list<int> recents_;
    unordered_map<int, pair<int, int>> hash_;
    int cap_;
    
public:
    LRUCache(int capacity) : cap_(capacity) {}
    
    int get(int key) {
        if(hash_.empty()) return -1;
        
        unordered_map<int, pair<int, int>>::iterator it = hash_.find(key);
        if(it != hash_.end()){
            //if(recents_.front() != key) 
            recents_.push_front(key);
            it->second.second++;
            
            return it->second.first;
        }else
            return -1;
    }
    
    void put(int key, int value) {
        recents_.push_front(key);
        unordered_map<int, pair<int, int>>::iterator it = hash_.find(key);
        if(it == hash_.end()) 
            hash_[key] = pair<int, int>(value, 0);
        else {
            it->second.first = value;
            it->second.second++;
        }
        
        //cout << "size: " << hash_.size() << endl;
        while(hash_.size() > cap_){
            if(recents_.empty()) break;
            
            unordered_map<int, pair<int, int>>::iterator it = hash_.find(recents_.back());
            //cout << "back value: " << recents_.back() << endl;
            recents_.pop_back();
            
            if(it == hash_.end()){
                //cout << "in not found" << endl;
                continue;
            }

            if(it->second.second <= 0) hash_.erase(it);
            else it->second.second--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */