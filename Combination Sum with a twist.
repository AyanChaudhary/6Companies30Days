void solve(int num,int k,int n,vector<int>&ds,vector<vector<int>>&ans){
        if(k==0 and n==0){
            ans.push_back(ds);
            return;
        }
        else if(k<=0 or n<=0 or num>9){
            return;
        }
        ds.push_back(num);
        solve(num+1,k-1,n-num,ds,ans);
        ds.pop_back();
        solve(num+1,k,n,ds,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(1,k,n,ds,ans);
        return ans;
    }
