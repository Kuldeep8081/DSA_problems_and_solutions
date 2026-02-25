class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<pair<int,int>>vec;

        for(int val : arr){
            int cnt=__builtin_popcount(val);
            vec.push_back({cnt,val});
        }

        sort(vec.begin(),vec.end());

        vector<int>ans;

        for(auto it : vec){
            ans.push_back(it.second);
        }

        return ans;
    }
};