//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> visited(V, 0);
        vector<pair<int, int>> mst;
        
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int sum = 0;
        
        pq.push({0, {0,-1}});
       
        
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            if(visited[node] == 1) continue;
            visited[node] = 1;
            sum += wt;
            
            for(auto it : adj[node]){
               int adjNode = it[0];
               int edgeW = it[1];
               
               if(visited[adjNode] != 1){
                   pq.push({edgeW, {adjNode, node}});
            
               }
            }
            
        }
        return sum;
        
    }
};

//{ Driver Code Starts.


