int maxRotateFunction(vector<int>& a) {
        int ans=INT_MIN;
        int n=a.size();int pre=0,s=0;
        for(int i=0;i<n;i++){
            pre+=a[i]*i;
            s+=a[i];
        }
        ans=max(ans,pre);
        for(int i=n-1;i>0;i--){
            pre=pre+s-(n*a[i]);
            ans=max(pre,ans);
        }
        return ans;
    }
