class RandomizedSet {
public:
    unordered_map<int,int> um;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        bool y = 0;
        if(um.find(val)==um.end()) {
            y = 1;
            um[val]++;
        }
        return y;
    }
    
    bool remove(int val) {
        bool y = 0;
        if(um.find(val)!=um.end()) {
            y = 1;
            um.erase(val);
        }
        return y;
    }
    
    int getRandom() {
        auto it = um.begin();
        std::advance(it,rand()%um.size());
        return it->first;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */