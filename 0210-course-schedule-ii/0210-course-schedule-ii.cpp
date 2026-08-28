class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& prerequisites) {
        vector<int> ans;
        vector<int> indegree(V, 0);

        unordered_map<int, vector<int>> adj;

        for (auto& vec : prerequisites) {
            int u = vec[1];
            int v = vec[0];

            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> que;
        for (int u = 0; u < V; u++) {

            if(indegree[u] == 0){
                que.push(u);
            }
        }
        while (!que.empty()) {
            int top = que.front();
            que.pop();
            ans.push_back(top);


            for (auto& v : adj[top]) {
                indegree[v]--;

                if (indegree[v] == 0) {
                    que.push(v);
                }
            }
        }
        
        if(ans.size() == V) return ans;

        return {};
    }
};