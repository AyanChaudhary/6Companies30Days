class Solution {
public:
    string fractionToDecimal(long long int n, long long int d) {
        string ans;
        int f=0;
        if(n<0){
            f=!f;
            n=-n;
        }
        if(d<0){
            f=!f;
            d=-d;
        }
	    long long int q=n/d;
	    long long int r=n%d;
	    ans+=to_string(q);
        if(f==1 and n!=0)ans.insert(0,"-");
	    if(r==0)return ans;
	    ans+='.';
	    int pos=ans.size();
	    unordered_map<int,int>mp;
	    while(r!=0){
	        mp[r]=ans.size();
	        r*=10;
	        q=r/d;
	        r=r%d;
	        ans+=to_string(q);
	        if(mp.find(r)!=mp.end()){
	            ans.insert(mp[r],"(");
	            ans.push_back(')');
	            break;
	        }
	    }
        
	    return ans;
    }
};
