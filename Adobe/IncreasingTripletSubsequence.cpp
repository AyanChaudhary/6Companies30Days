class Solution {
public:
    bool increasingTriplet(vector<int>& a) {
        int n=a.size();
        int pre2=INT_MAX,pre1=INT_MAX;
        for(int i=0;i<n;i++){
            if(pre2<pre1 and pre1<a[i])return true;
            if(a[i]<pre2)pre2=a[i];
            else if(a[i]<pre1 and a[i]>pre2)pre1=a[i];
        }
        return false;
    }
};
