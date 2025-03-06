class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        
        unordered_map<int,int>mp;
        int n=grid.size();
        int sum=0;

        vector<int>vec;

        for(int i=0;i<n;i++){

            for(int j=0;j<n;j++){

                int val=grid[i][j];
                sum+=val;
                mp[val]++;
                if(mp[val]>1){
                    vec.push_back(val);
                    sum-=val;
                }
            }
        }

        vec.push_back((n*n)*(n*n+1)/2-sum);

        return vec;
    }
};