class Solution {
public:
    int minimumOperations(vector<int>& nums) {

        unordered_map<int,int>mp;

        for(auto val : nums){
            mp[val]++;
        }

        int cnt=0;
        int ans=0;

        for(int j=0;j<nums.size();j++)
            {
                cnt++;
                for(int i=j;i<nums.size()&& i<j+3;i++){
                   if(mp[nums[i]]>1) {
                       ans+=cnt;
                       cnt=0;
                       break;
                   }
                }

                for(int i=j;i<nums.size()&& i<j+3;i++){
                        mp[nums[i]]--;
                }

                j=j+2;
                
                
            }

        return ans;

    }
};