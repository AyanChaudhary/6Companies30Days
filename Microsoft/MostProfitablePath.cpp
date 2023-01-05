class Solution {
 public:
  int mostProfitablePath(vector<vector<int>>& edges, int bob,
                         vector<int>& amount) {
    const int n = amount.size();
    vector<vector<int>> graph(n);
    vector<int> parent(n);
    vector<int> aliceDist(n, -1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    dfs(graph, 0, -1, 0, parent, aliceDist);    
    for (int u = bob, bobDist = 0; u != 0; u = parent[u], ++bobDist)
      if (bobDist < aliceDist[u])
        amount[u] = 0;
      else if (bobDist == aliceDist[u])
        amount[u] /= 2;

    return getMoney(graph, 0, -1, amount);
  }

 private:
 
  void dfs(const vector<vector<int>>& graph, int u, int prev, int d,
           vector<int>& parent, vector<int>& dist) {
    parent[u] = prev;
    dist[u] = d;
    for (const int v : graph[u]) {
      if (dist[v] == -1)
        dfs(graph, v, u, d + 1, parent, dist);
    }
  }

  int getMoney(const vector<vector<int>>& graph, int u, int prev,
               const vector<int>& amount) {

    if (graph[u].size() == 1 && graph[u][0] == prev)
      return amount[u];

    int maxPath = INT_MIN;
    for (const int v : graph[u])
      if (v != prev)
        maxPath = max(maxPath, getMoney(graph, v, u, amount));

    return amount[u] + maxPath;
  }
};
