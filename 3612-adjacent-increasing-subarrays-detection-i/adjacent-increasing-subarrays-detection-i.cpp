class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        bool flag=true;
        for(int i=0;i<nums.size()-2*k+1;i++){
            flag=true;
            for(int j=i+1;j<i+k;j++){
               if(nums[j-1]>=nums[j]){
                flag=false;
                break;
               }
            }


            for(int j=i+k+1;j<i+2*k;j++){
                if(nums[j-1]>=nums[j]){
                    flag=false;
                    break;
                }
            }

            if(flag)
            return true;
          
        }

        if(flag)
        return true;

        return false;
    }
};