class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int inc=1;
        int dec=1;
        int ans=INT_MIN;

        for(int i=1;i<nums.size();i++){

            if(nums[i]<nums[i-1]){
                ans=max(ans,max(inc,dec));
                dec++;
                inc=1;
            }else if(nums[i]>nums[i-1]){
                ans=max(ans,max(inc,dec));
                inc++;
                dec=1;
            }else
            {
                ans=max(ans,max(inc,dec));
                inc=1;
                dec=1;
            }
        }

        ans=max(ans,max(inc,dec));

        return ans;
    }
};