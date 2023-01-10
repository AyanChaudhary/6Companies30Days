class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& P, vector<int>& C) {
        vector<int> id(P.size());
        iota(begin(id), end(id), 0);
        sort(begin(id), end(id), [&](int a, int b) { return C[a] < C[b]; });
        auto cmp = [&](int a, int b) { return P[a] < P[b]; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0, j = 0; i < k; ++i) {
            while (j < id.size() && w >= C[id[j]]) {
                pq.push(id[j]);
                ++j;
            }
            if (pq.empty()) break;
            int p = pq.top();
            pq.pop();
            w += P[p];
        }
        return w;
    }
};
