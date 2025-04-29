//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    bool dfs(int node,vector<vector<int>> &adj, vector<int> &visited, vector<int> &pathvisited){
        visited[node] = 1;
        pathvisited[node] = 1;
        
        for(auto it : adj[node]){
            // when the node is not visited
            if(visited[it] == 0){
                if(dfs(it, adj, visited, pathvisited) == true) return true;
            }
            if(visited[it] == 1 && pathvisited[it] == 1){
                return true;
            }
            
        }
        pathvisited[node] = 0;
        return false;
        
    }
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<vector<int>> adj) {
        
        vector<int> visited(V, 0);
        vector<int> pathvisited(V, 0);
        
        for(int i = 0; i < V; i++){
            if(visited[i] == 0){
                if(dfs(i, adj, visited, pathvisited) == true){
                    return true;
                }
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends