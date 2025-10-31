class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_map<int,bool>mp;

        vector<int>ans;

        for(int val : nums){
            if(mp[val]){
                ans.push_back(val);
            }

            mp[val]=true;
        }

        return ans;
    }
};