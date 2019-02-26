class RandomizedSet {
public:
    /** Initialize your data structure here. */
    unordered_set<int> hset;
    unordered_map<int, int> hmap;
    vector<int> arr;
    RandomizedSet() {
        ;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        bool contains = true;
        if(hset.find(val) == hset.end()){
            contains = false;
            hset.insert(val);
            arr.push_back(val);
            hmap[val] = arr.size()-1; // store the index
        }
        
        return !contains;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        bool contains = false;
        if(hset.find(val) != hset.end()){
            contains = true;
            hset.erase(val);
            
            int temp = arr[arr.size()-1];
            arr[arr.size()-1] = arr[hmap[val]];
            arr[hmap[val]] = temp;
            arr.pop_back();
            
            hmap[temp] = hmap[val];
            hmap.erase(val);
        }
        
        return contains;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int ind = rand() % arr.size();
        return arr[ind];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
