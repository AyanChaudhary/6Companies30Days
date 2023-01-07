class Solution {
public:
    double calc(pair<int,int>&a,pair<int,int>&b){
        int x=pow(a.first-b.first,2);
        int y=pow(a.second-b.second,2);
        return sqrt(x+y);
    }
    static bool comp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first)return a.second<b.second;
        return a.first<b.first;
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {         
        vector<pair<int,int>>vec;
        vec.push_back({p1[0],p1[1]});
        vec.push_back({p2[0],p2[1]});
        vec.push_back({p3[0],p3[1]});
        vec.push_back({p4[0],p4[1]});
        sort(vec.begin(),vec.end(),comp);
        for(int i=0;i<3;i++){
            if(vec[i]==vec[i+1])return false;
        }
        if(calc(vec[0],vec[3])==calc(vec[1],vec[2]) and calc(vec[0],vec[1])==calc(vec[0],vec[2]))return true;
        return false;    
    }
};
