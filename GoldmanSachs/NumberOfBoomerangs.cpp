class Solution {
public:
    double dist(pair<int,int>&a,pair<int,int>&b){
        double x=pow(b.first-a.first,2);
        double y=pow(b.second-a.second,2);
        return sqrt(x+y);        
    }
    int numberOfBoomerangs(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int ans=0;
       
        for(int i=0;i<n;i++){
            pair<int,int>x={a[i][0],a[i][1]};
            unordered_map<double,int>mp;
            for(int j=0;j<n;j++){
                if(j==i)continue;
                pair<int,int>y={a[j][0],a[j][1]};
                double dis=dist(x,y);
                mp[dis]++;                
            }
            for(auto it:mp){
                auto val=it.second;
                if(val>1)ans+=val*(val-1);
            }
        }
        return ans;
    }
};
