
class Solution {
    private:
    bool dfs(int node, int parent, vector<vector<int>>& adj,vector<bool> &visited){
        // mark node as visited
        visited[node] = true;
        // start dfs
        for(auto neighbour : adj[node]){
            if(!visited[neighbour]){
               if( dfs(neighbour, node, adj, visited)) return true;
            }
            else if(neighbour != parent){
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
      int n = adj.size();
      vector<bool> visited(n, false);
      
      for(int i = 0; i < n; i++){
          if(!visited[i]){
              if(dfs(i, -1, adj, visited)) return true;
          }
      }
      return false;
    }
};