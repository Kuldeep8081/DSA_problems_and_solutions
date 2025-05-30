class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        // vector<int>ans;

        for(int i=0;i<k;i++)
        {
            int min=INT_MAX;
            int index;
            for(int j=0;j<nums.size();j++)
            {
                if(nums[j]<min)
                {
                    min=nums[j];
                    index=j;
                }
            }

            nums[index]=multiplier*nums[index];
        }

        return nums;
    }
};