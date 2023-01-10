class Solution {
public:
    int minimumCardPickup(vector<int>& c) {
        unordered_map<int,int>mp;
        int ans=1e6;
        for(int i=0;i<c.size();i++){
            if(mp.find(c[i])!=mp.end()){
                ans=min(ans,i-mp[c[i]]+1);
            }
            mp[c[i]]=i;
        }
        if(ans==1e6)return -1;
        return ans;
    }
};
