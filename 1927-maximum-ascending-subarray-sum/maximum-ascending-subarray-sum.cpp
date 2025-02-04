class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        
        int ans=0;

        int sum=nums[0];

        ans=max(ans,sum);

        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                sum+=nums[i];
            }
            else{
                ans=max(ans,sum);
                sum=nums[i];
            }
        }
        ans=max(ans,sum);

        return ans;
    }
};