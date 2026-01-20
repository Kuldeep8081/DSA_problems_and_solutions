class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int maxi=*max_element(nums.begin(),nums.end());
        unordered_map<int,int>mp;
        for(int i=maxi;i>=1;i--){
            int result=i | (i+1);
            mp[result]=i;
        }

        vector<int>ans;
        for(int num : nums){
            if(!mp[num])
            ans.push_back(-1);
            else
            ans.push_back(mp[num]);
        }

        return ans;



    }
};