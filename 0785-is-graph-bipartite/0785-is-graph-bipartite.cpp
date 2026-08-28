class Solution {
public:
    bool DFS(vector<vector<int>>& graph, int curr, vector<int> &color, int currCol){
        color[curr] = currCol;

        for(int i = 0; i<graph[curr].size(); i++){
            cout << graph[curr][i] << " ";
            if(color[graph[curr][i]] == color[curr]) return false;
            if(color[graph[curr][i]] == -1){
                int colorV = 1 - currCol;
                if(!(DFS(graph,graph[curr][i],color,colorV))) return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<int>color(n,-1);

        for(int i = 0; i < graph.size(); i++){
            if(color[i] == -1){
                if(DFS(graph,i,color,0) == false) return false;
            }
        }
        return true;
    }
};