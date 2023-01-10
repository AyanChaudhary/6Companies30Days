class Solution {
public:
    int maxPoints(vector<vector<int>>& a) {
        int ans=0,n=a.size();
        for(int i=0;i<n;i++){
        unordered_map<double,int>mp;
            for(int j=i+1;j<n;j++){
                double slopey=(a[j][1]-a[i][1]);
                double slopex=(a[j][0]-a[i][0]);
                double slope;
                if(slopey==0)slope=0;
                else if(slopex==0)slope=1e5;
                else slope=slopey/slopex;
                mp[slope]++;
                ans=max(ans,mp[slope]);
            }
        }
        return ans+1;
    }
};
