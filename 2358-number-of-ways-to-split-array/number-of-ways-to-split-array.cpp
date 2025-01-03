class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        
        int ans=0;
        long long right=0;
        long long left=0;
        for(int i=0;i<nums.size();i++){
            right+=nums[i];
        }

        for(int i=0;i<nums.size()-1;i++){
            right-=nums[i];
            left+=nums[i];

            if(left>=right){
                ans++;
            }
        }

        return ans;
    }
};