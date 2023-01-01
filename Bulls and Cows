string getHint(string s, string g) {
       
        int n=s.size();
        
        int a[1001]={0};
        for(int i=0;i<n;i++)a[s[i]-'0']++;
        int bulls=0,cows=0;
        for(int i=0;i<n;i++){
            if(g[i]==s[i]){
                bulls++;
                a[s[i]-'0']--;
            }
        }
        for(int i=0;i<n;i++){
            int x=g[i]-'0';
            if(s[i]!=g[i] and a[x]>0){
                cows++;
                a[x]--;
            }
        }
        string ans;
        string temp=to_string(bulls);
        ans+=temp;
        ans.push_back('A');
        temp=to_string(cows);
        ans+=temp;
        ans.push_back('B');
        return ans;
    }
