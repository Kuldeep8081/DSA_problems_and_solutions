class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int size=nums.size();
        vector<int>ans(size,-1);
        for(int i=0;i<nums.size();i++){
            for(int val=1;val<nums[i];val++){
                if((val | (val+1))==nums[i]){
                    ans[i]=val;
                    break;
                }
            }
        }

        return ans;
    }
};