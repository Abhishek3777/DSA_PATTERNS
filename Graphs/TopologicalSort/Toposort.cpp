Perform a dfs for whosever we havent visited and once they no more have any new unvisited neighbours pusht them in the stack  as you return and at last pop from stack and return.

Here's the dfs code - 
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    private:
    void dfs(int node,vector<vector<int>>& adj,  vector<int> &visited,
    
    stack<int> &s){
        
        visited[node] = 1;
        
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited, s);
            }
        }
        s.push(node);
    }
  public:
    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>>& adj) {
        
        int V = adj.size();
        vector<int> visited(V, 0);
        stack<int> s;
        vector<int> ans;
        
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                dfs(i, adj, visited, s);
            }
        }
        // at last pop froms stack and print
        while(!s.empty()){
            int element = s.top();
            s.pop();
            ans.push_back(element);
        }
        return ans;
    }
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
 *   contains the elements in topological sorted form
 *   V: number of vertices
 *   *res: array containing elements in topological sorted form
 *   adj[]: graph input
 */
int check(int V, vector<int> &res, vector<vector<int>> adj) {

    if (V != res.size())
        return 0;

    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v])
                return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<vector<int>> adj(N);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> res = obj.topologicalSort(adj);

        cout << check(N, res, adj) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends