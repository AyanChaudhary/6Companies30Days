class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& a) {
        
        vector<int> adj[N];
	    for(auto it:a){
	        adj[it[1]].push_back(it[0]);
	    }
	    vector<int>indeg(N,0);
	    for(int i=0;i<N;i++){
	        for(auto it:adj[i]){
	            indeg[it]++;
	        }
	    }
	    queue<int>q;
	    for(int i=0;i<N;i++)if(indeg[i]==0)q.push(i);
	    int cnt=0;
	    while(q.size()){
	        int node=q.front();
	        q.pop();	        
	        cnt++;
	        for(auto it:adj[node]){
	            indeg[it]--;
	            if(indeg[it]==0)q.push(it);
	        }
	    }
	    if(cnt==N)return 1;
        return 0;

    }
};
