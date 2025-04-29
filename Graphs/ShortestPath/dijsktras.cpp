// User Function Template
class Solution {
    public:
      // Function to find the shortest distance of all the vertices
      // from the source vertex src.
      vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
          int v = adj.size();
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  
          vector<int> dist(v, INT_MAX);
          dist[src] = 0;
          
          pq.push({0, src});
          
          while(!pq.empty()){
              int distance = pq.top().first;
              int node = pq.top().second;
              pq.pop();
              
              for(auto it : adj[node]){
                int edgeWeight = it.second;
                int adjNode = it.first;
                
                // important
                if(dist[adjNode] > distance + edgeWeight){
                dist[adjNode] = distance + edgeWeight;
                pq.push({dist[adjNode], adjNode});
                }
                   
              }
          }
          return dist;
      }
  };