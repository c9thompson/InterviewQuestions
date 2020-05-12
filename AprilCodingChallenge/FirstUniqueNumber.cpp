/*
Implement a class that as numbers are added to it, it maintains that first unique number to be added. If a number was unique and the same number is added to the class it is no longer considered unique.
*/

class FirstUnique {
private:
    list<int> latestUnique;
    unordered_map<int, list<int>::iterator> memory;
    unordered_map<int, list<int>::iterator>::iterator it;
    
public:
    FirstUnique(vector<int>& nums){
        for(int i = 0; i < nums.size(); ++i)
            add(nums[i]);
    }
    
    int showFirstUnique() {
        return latestUnique.empty() ? -1 : latestUnique.front();
    }
    
    void add(int value) {
        it = memory.find(value);
        if(it == memory.end()){
            latestUnique.push_back(value);
            memory[value] = --(latestUnique.end());
            // cout << "added unique: " << (*memory[value]) << endl;
        }else{
            if(it->second != latestUnique.end()){
                latestUnique.erase(it->second);
                it->second = latestUnique.end();
            }
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */