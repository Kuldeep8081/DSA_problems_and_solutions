class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int maxi=0;
        unordered_map<int,int>mp;
        for(int val : nums){
           mp[val]++;
           maxi=max(maxi,mp[val]);
        }

        int ans=0;

        for(auto it : mp){
            if(it.second==maxi){
                ans+=maxi;
            }
        }

        return ans;
    }
};