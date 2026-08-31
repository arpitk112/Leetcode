class Solution {
public:
    void DFS(unordered_map<int,vector<int>> &adj, vector<bool> &visited, int u){
        visited[u] = true;

        for(auto &v : adj[u]){
            if(visited[v] == false){
                DFS(adj,visited,v);
            }
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> adj;
        int con = connections.size();
        if(con < n - 1) return -1;
        int count = 0;

        for(int i = 0; i < con; i++){
            int u = connections[i][0];
            int v = connections[i][1]; 

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool>visited(n,false);

        for(int i = 0; i<n; i++){
            if(visited[i] == false){
                DFS(adj,visited,i);
                count++;
            }
        }
        return count - 1;
    }
};