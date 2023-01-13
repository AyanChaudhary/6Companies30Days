class Solution {
public:
    int findIntegers(int n) {
        int f[31]={0};
        f[0]=1;
        f[1]=2;
        for(int i=2;i<31;i++)f[i]=f[i-1]+f[i-2];
        int count=30,ans=0,lastbit=0;
        while(count>=0){
            if(n & (1<<count)){
                ans+=f[count];
                if(lastbit==1)return ans;
                lastbit=1;
            }
            else lastbit=0;

            count--;
        }
        return ans+1;
    }
};
