class Solution {
public:

    string generate_all_strings(int n, string s, int i, unordered_map<string,int> &um) {
        if(i==n) {
            if(um.find(s)==um.end()) {
                return s;
            }
            else
                return "no";
        }

        s = s + '0';
        string s1 = generate_all_strings(n, s, i+1, um);
        s = s.substr(0,s.length()-1) + '1';
        string s2 = generate_all_strings(n, s, i+1, um);

        if(s1=="no")
            return s2;
        else
            return s1;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,int> um;
        int n = nums.size();
        string s = "";
        for(string it:nums)
            um[it]++;

        return generate_all_strings(n, s, 0, um);
    }
};