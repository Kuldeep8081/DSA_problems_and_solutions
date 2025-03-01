class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        for(int i=0;i<nums.size()-1;i++){

            if(nums[i]==nums[i+1]){

                nums[i]*=2;
                nums[i+1]=0;
            }
        }

        int i=0;

        while(i<nums.size()-1){

            if(nums[i]==0){
                int j=i+1;
                while( j<nums.size() && nums[j]==0 ){
                    j++;
                }
                
                if(j<nums.size())
                swap(nums[i],nums[j]);
            }

            i++;
        }

        return nums;
    }
};