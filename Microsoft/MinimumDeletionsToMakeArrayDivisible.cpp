class Solution {
public:
    int gcd(int a,int b){
        if(a==0)return b;
        return gcd(b%a,a);
    }
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int hcf=numsDivide[0];        
        int n=numsDivide.size();
        for(int i=1;i<n;i++){
            hcf=gcd(numsDivide[i],hcf);
        }
        for(int i=0;i<nums.size();i++){
            if(hcf%nums[i]==0)return i;
        }
        return -1;
    }
};
