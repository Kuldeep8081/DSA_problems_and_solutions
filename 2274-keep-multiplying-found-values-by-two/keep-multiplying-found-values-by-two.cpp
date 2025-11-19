class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int,bool>mp;
        for(int val : nums){
            mp[val]=true;
        }

        while(mp[original]){
            original*=2;
        }

        return original;
    }
};