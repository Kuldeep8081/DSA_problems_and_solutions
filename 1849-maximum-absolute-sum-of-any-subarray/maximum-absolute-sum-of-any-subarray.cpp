class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int res=abs(nums[0]);
        int maxEnding=nums[0];
        
        int minEnding=nums[0];
        for(int i=1;i<nums.size();i++){

            maxEnding=max(maxEnding+nums[i],nums[i]);
            minEnding=min(minEnding+nums[i],nums[i]);

            res=max(res,max(maxEnding,abs(minEnding)));
        }

        return res;

    }
};