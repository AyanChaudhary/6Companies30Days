class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        int n=a.size();
        int mx=INT_MIN,mn=INT_MAX;
        if(n==1)return 0;
        for(int i=0;i<n;i++){
            if(i==0){
                if(a[i]>a[i+1]){
                    mn=min(mn,a[i]);
                    mx=max(mx,a[i]);
                }
            }
            else if(i==n-1){
                if(a[i]<a[i-1]){
                    mn=min(mn,a[i]);
                    mx=max(mx,a[i]);
                }
            }            
            else if(a[i]>a[i+1] or a[i]<a[i-1]){
                mn=min(mn,a[i]);
                mx=max(mx,a[i]);
            }
        }
        if(mn==INT_MAX or mx==INT_MIN)return 0;
        int s=0,l=n-1;
        while(s<n and a[s]<=mn)s++;
        while(l>=0 and a[l]>=mx)l--;
        return l-s+1;
    }
};
