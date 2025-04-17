class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        
        unordered_map<int,vector<int>>mp;
        
        int n=nums.size();

        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }

        int ans=0;


        for(int i=0;i<n;i++){
            
            for(int idx : mp[nums[i]]){
                if((idx>i) && ((i*idx)%k==0)){
                    ans++;
                }
            }

        }

        return ans;
    }
};