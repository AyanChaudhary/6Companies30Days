class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        int idx=0;
        vector<int>h(n,0);
        h[0]=1;
        for(int i=0;i<n;i++)h[i]=i;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 and dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    h[i]=j;    
                }
            }
            if(dp[i]>dp[idx])idx=i;
        }
        vector<int>ans;
        while(h[idx]!=idx){
            ans.push_back(nums[idx]);
            idx=h[idx];
        }
        ans.push_back(nums[idx]);
        
        return ans;
    }
};
