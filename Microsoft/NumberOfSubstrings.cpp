class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int x[3]={0};
        int i=0,j=0;
        int ans=0;
        while(i<n){            
            if(x[0]>0 and x[1]>0 and x[2]>0){
                ans=ans+n-j+1;
                x[s[i]-'a']--;
                i++;    
            }
            else if(j>=n)break;
            else{
                x[s[j]-'a']++;
                j++;
            }
        }
        return ans;
    }
};
