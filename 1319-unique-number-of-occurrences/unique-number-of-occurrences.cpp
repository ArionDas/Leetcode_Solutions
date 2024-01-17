class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> um;
        unordered_map<int,int> occ;

        for(int i=0; i<arr.size(); i++) um[arr[i]]++;
        for(auto i=um.begin(); i!=um.end(); i++) {
            occ[i->second]++;
        }

        for(auto i=occ.begin(); i!=occ.end(); i++) {
            if(i->second > 1) return 0;
        }
        return 1;
    }
};