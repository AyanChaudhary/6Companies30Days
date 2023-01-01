int evalRPN(vector<string>&a) {
        stack<int>st;
        for(int i=0;i<a.size();i++){
            int val1,val2;
            if(a[i]=="+"){
                val1=st.top();st.pop();
                val2=st.top();st.pop();
                int ans=val1+val2;
                st.push(ans);
            }
            else if(a[i]=="-"){
                val1=st.top();st.pop();
                val2=st.top();st.pop();
                int ans=val2-val1;
                st.push(ans);
            }
            else if(a[i]=="*"){
                val1=st.top();st.pop();
                val2=st.top();st.pop();
                int ans=val1*val2;
                st.push(ans);
            }
            else if(a[i]=="/"){
                val1=st.top();st.pop();
                val2=st.top();st.pop();
                int ans=val2/val1;
                st.push(ans);
            }
            else{
                int val=stoi(a[i]);
                st.push(val);
            }
        }
        return st.top();
    }
