class Solution {
public:

    void findShortestPath(vector<list<pair<int,int>>>&adj,vector<int>&dist,int src){
        dist[src]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({src,0});
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            if(dist[top.first]!=INT_MAX){
                for(auto &it : adj[top.first]){
                    if(top.second+it.second<dist[it.first]){
                        dist[it.first]=top.second+it.second;
                        pq.push({it.first,top.second+it.second});
                    }
                }
            }
        }
    }
    
    int minCost(int n, vector<vector<int>>& edges) {
        vector<list<pair<int,int>>>adj(n);

        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
            adj[edge[1]].push_back({edge[0],edge[2]*2});
        }
        vector<int>dist(n,INT_MAX);

        findShortestPath(adj,dist,0);
        if(dist[n-1]==INT_MAX)
        return -1;
        return dist[n-1];

    }
};