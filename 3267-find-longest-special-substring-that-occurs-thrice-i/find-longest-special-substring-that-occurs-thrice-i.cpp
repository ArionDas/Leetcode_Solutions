class Solution {
public:

    bool check(string s, int k) {
        int n = s.length();
        
        for(int i=0; i<n; i++) {

            string sub = s.substr(i,k);
            unordered_map<char,int> um;
            for(auto it:sub)
                um[it]++;
            if(um.size() > 1)
                continue;
            if(sub.length() < k)
                break;
            //cout << sub << endl;
            int count = 0;

            for(int j=0; j<n; j++) {
                string temp = s.substr(j,k);
                // if(temp.length() < k)
                //     break;
                if(temp == sub) {
                    //cout << temp << " " << sub << endl;
                    count += 1;
                }
            }

            if(count>=3)
                return 1;    
        }
        return 0;
    }

    int maximumLength(string s) {
        int n = s.length();
        int ans = 0;

        for(int i=1; i<=n; i++) {
            if(check(s,i))
                ans = i;
        }

        if(ans==0)
            return -1;
        return ans;
    }
};