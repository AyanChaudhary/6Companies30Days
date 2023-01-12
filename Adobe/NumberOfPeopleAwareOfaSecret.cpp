class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        int md=1e9+7;
        vector<int>dp(n+1,0);
        dp[1]=1;        
        int ans=0;
        for(int day=1;day<=n;day++){
            for(int crday=day+delay;crday<min(n+1,day+forget);crday++)
                dp[crday]=(dp[crday]+dp[day])%md;
            if(day>=n-forget+1)ans=(ans+dp[day])%md;

        }        
        return ans;
    }
};
