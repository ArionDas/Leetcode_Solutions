class Solution {
public:

    bool isValid(string curr, string new_string) {
        unordered_map<char, int> um;
        for(char ch:new_string) {
            if(um.find(ch)!=um.end())
                return 0;
            um[ch] += 1;
        }

        for(char ch:curr){
            if(um.find(ch)!=um.end())
                return 0;
        }

        return 1;
    }

    void backTrack(vector<string>& arr, string curr, int start, int &max_len) {
        if(max_len < curr.length())
            max_len = curr.length();

        for(int i=start; i<arr.size(); i++) {
            if(!isValid(curr, arr[i]))
                continue;
            backTrack(arr, curr+arr[i], i+1, max_len);
        }
    }

    int maxLength(vector<string>& arr) {
        int max_len = 0;
        backTrack(arr, "", 0, max_len);
        return max_len;
    }
};