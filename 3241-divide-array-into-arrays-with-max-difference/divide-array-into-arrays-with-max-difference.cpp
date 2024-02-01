class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<vector<int>> null;
        for(int i=0; i<n; i+=1) {
            vector<int> temp;
            int maxi = INT_MIN;
            int mini = INT_MAX;
            //for(int j=1; j<=3; j++) {
                temp.push_back(nums[i]);
            i+=1;
            temp.push_back(nums[i]);
            i+=1;
            temp.push_back(nums[i]);
            //i+=1;
                maxi = max(temp[0],max(temp[1],temp[2]));
                mini = min(temp[0],min(temp[1],temp[2]));
                cout << maxi << " " << mini << endl;
                //i+=1;
            //}
            if(maxi-mini > k)
                return null;
            ans.push_back(temp);
        }
        return ans;
    }
};