class Solution {
public:
    int minPairIndex(vector<int>&nums){
        int index=-1;
        int mini=INT_MAX;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]+nums[i+1]<mini){
                mini=nums[i]+nums[i+1];
                index=i;
            }
        }
        return index;
    }
    int minimumPairRemoval(vector<int>& nums) {
        
        int cnt=0;
        while(!is_sorted(nums.begin(),nums.end())){
            int idx;
            int sum;
            cnt++;
            idx=minPairIndex(nums);
            nums[idx]=nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
        }

        return cnt;
    }
};