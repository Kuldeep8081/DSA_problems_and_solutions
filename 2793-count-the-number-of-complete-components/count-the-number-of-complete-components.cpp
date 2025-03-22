class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        
        vector<vector<int>>adj(n);

        for(auto vec : edges){
            adj[vec[0]].push_back(vec[1]);
            adj[vec[1]].push_back(vec[0]);
        }

        unordered_set<int>visited;
        int count=0;

        for(int i=0;i<n;i++){
            if(visited.find(i)==visited.end()){
                unordered_set<int>component;
                dfs(i,component,visited,adj);
                if(isCompleteComponent(component,adj)) count++;
            }
        }

        return count;



    }

    void dfs(int node,unordered_set<int>&component,unordered_set<int>&visited,vector<vector<int>>&adj){
        component.insert(node);
        visited.insert(node);

        for(int neighbor : adj[node]){
            if(visited.find(neighbor)==visited.end()){
                dfs(neighbor,component,visited,adj);
            }
        }
    }

    bool isCompleteComponent(unordered_set<int>&component,vector<vector<int>>&adj){
        for(int node : component){
            if(adj[node].size()!=component.size()-1){
                return false;
            }
        }

        return true;
    }

    
};