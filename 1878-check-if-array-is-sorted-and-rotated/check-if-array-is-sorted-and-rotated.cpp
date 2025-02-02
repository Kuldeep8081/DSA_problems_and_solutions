class Solution {
public:
    bool check(vector<int>& nums) {
        int mini=nums[0];
        for(int i=0;i<nums.size()-1;i++){

            if(nums[i]<=nums[i+1])
            continue;
            else{
                if(nums[i+1]>mini)
                return false;
                for(int j=i+1;j<nums.size()-1;j++){
                    if(nums[j]<=nums[j+1] ){
                        if((nums[j]>mini || nums[j+1]>mini)){
                            return false;
                        }
                    }else
                    return false;
                }
            }
        }
        return true;
    }
};