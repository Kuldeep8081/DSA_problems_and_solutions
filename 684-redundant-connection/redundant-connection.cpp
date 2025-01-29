class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        

        unordered_map<int,vector<int>>adj;

        vector<int>index;
        unordered_map<int,bool>visited;

        for(int i=0;i<edges.size();i++){
            auto vec=edges[i];
            int val1=vec[0];
            int val2=vec[1];

            if(visited[vec[0]] && visited[vec[1]]){
                index.push_back(i);
            }

            visited[vec[0]]=true;
            visited[vec[1]]=true;

            adj[val1].push_back(val2);
            adj[val2].push_back(val1);
        }
        
        vector<int>ans;
        for(int i=index.size()-1;i>=0;i--){
            auto vec=edges[index[i]];
            int val1=vec[0];
            int val2=vec[1];
            unordered_map<int,bool>nodeVisited;

            auto vec1=adj[val1];
            
            nodeVisited[val1]=true;

            stack<int>st;
            
            for(int i=0;i<vec1.size();i++){
                if(vec1[i]!=val2)
                st.push(vec1[i]);
            }

            while(!st.empty()){
                int val=st.top();
                st.pop();
                nodeVisited[val]=true;
                auto vec2=adj[val];
                
                if(val2==val){
                    ans={val1,val2};
                    return ans;
                }
                for(int i=0;i<vec2.size();i++){
                    if(!nodeVisited[vec2[i]]){
                        st.push(vec2[i]);
                    }
                }
            }

            
        }

        return ans;
    }
};