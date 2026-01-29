class Solution {
public:
    void floyd_warshall(vector<char>& original, vector<char>& changed, vector<int>& cost,vector<vector<long long>>&dist){
        int n=original.size();

        for(int i=0;i<n;i++){
            int val=dist[original[i]-'a'][changed[i]-'a'];
            dist[original[i]-'a'][changed[i]-'a']=val>cost[i]?cost[i]:val;
        }

        for(int i=0;i<26;i++){
            dist[i][i]=0;
        }
        
        for(int via=0;via<26;via++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    dist[i][j]=min(dist[i][j], dist[i][via]+dist[via][j]);
                }
            }
        }
    }
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        
        vector<vector<long long>>dist(26,vector<long long>(26,INT_MAX));

        floyd_warshall(original,changed,cost,dist);

        long long total_cost=0;
        for(int i=0;i<source.size();i++){
            int val=dist[source[i]-'a'][target[i]-'a'];
            if(val==INT_MAX){
                return -1;
            }

            total_cost+=val;
        }

        return total_cost;


        
    }
};