class Solution {
public:
    const int mod=1e9+7;
    int solve(int i,int absent,int late,vector<vector<vector<int>>>&dp){
        //base cases 

        //1.negative base case
        if(absent==2 || late==3)return 0;

        //2.positive base case
        if(i==0)return 1;


        //memoisation 
        if(dp[i][absent][late]!=-1)return dp[i][absent][late]%mod;

        int ans=0;
        //present today
        ans+=solve(i-1,absent,0,dp);
        ans%=mod;
        //absent today
        ans+=solve(i-1,absent+1,0,dp);
        ans%=mod;
        //late today
        ans+=solve(i-1,absent,late+1,dp);
        ans%=mod;
        
        return dp[i][absent][late]=ans%mod;    

    }
    int checkRecord(int n) {
        //states -> 1. index
        //          2. number of days absent 
        //          3. number of days late until now
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(3,vector<int>(4,-1)));
        return solve(n,0,0,dp);
    }
};