class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        
        unordered_map<int,int>vec;
        
        int diffColors=0;

        unordered_map<int,int>colors;

        vector<int>ans;

        for(int i=0;i<queries.size();i++){

            int ind=queries[i][0];
            int color=queries[i][1];
            
            if(vec[ind]==0){
                if(!colors[color]){
                    colors[color]++;
                    diffColors++;
                }else{
                    colors[color]++;
                }
            }else{
                if(!colors[color]){
                    int col=vec[ind];
                    colors[col]--;
                    colors[color]++;

                    if(!colors[col]){
                        diffColors--;
                    }
                    diffColors++;
                }else{
                    int col=vec[ind];
                    colors[col]--;
                    colors[color]++;

                    if(!colors[col]){
                        diffColors--;
                    }
                }
            }

            vec[ind]=color;
            ans.push_back(diffColors);
        }

        return ans;
    }
};