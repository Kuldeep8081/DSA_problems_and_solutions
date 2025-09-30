class Solution {
public:
    int solve(vector<int>&nums,int n){
        if(n==1)
        return nums[0];

        for(int i=1;i<n;i++){
            nums[i-1]=(nums[i]+nums[i-1])%10;
        }
        n--;
        return solve(nums,n);
    }
    int triangularSum(vector<int>& nums) {
        
        int n=nums.size();
        
        return solve(nums,n);
    }
};