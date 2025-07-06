class FindSumPairs {
public:
    vector<int> arr1, arr2;
    unordered_map<int, int> um;
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        arr1 = nums1;
        arr2 = nums2;
        for(auto it:arr2) {
            um[it] += 1;
        }
    }
    
    void add(int index, int val) {
        um[arr2[index]] -= 1;
        if(um[arr2[index]] == 0)
            um.erase(arr2[index]);
        arr2[index] += val;
        um[arr2[index]] += 1;
    }
    
    int count(int tot) {
        int ans = 0;
        for(auto it:arr1) {
            int req = tot - it;
            if(um.find(req) != um.end()) {
                ans += um[req];
            }
        }

        return ans;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */