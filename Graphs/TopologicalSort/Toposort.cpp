Perform a dfs for whosever we havent visited and once they no more have any new unvisited neighbours pusht them in the stack  as you return and at last pop from stack and return.
  
Topo Sort only possible in DAG

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

