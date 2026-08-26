class Solution {
public:
    bool courseFin(unordered_map<int,vector<int>> &adj,vector<int> &indegree, int n){
        queue<int> que;
        int count = 0;
        
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                count++;
                que.push(i);
            }
        }

        while(!que.empty()){
            int u = que.front();
            que.pop();

            for(auto &v : adj[u]){
                indegree[v]--;

                if(indegree[v] == 0){
                    count++;
                    que.push(v);
                }
            }
        }
        return (count == n);
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>adj;
        vector<int> indegree(numCourses,0);

        for(auto &vec : prerequisites){
            int v = vec[0];
            int u = vec[1];

            adj[u].push_back(v);

            indegree[v]++;   
        }

        return courseFin(adj,indegree,numCourses);
    }
};