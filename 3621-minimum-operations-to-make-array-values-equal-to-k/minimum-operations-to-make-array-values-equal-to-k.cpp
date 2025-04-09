class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());

        int ops=0;

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<k)
                return -1;

            if(nums[i]>k && !mp[nums[i]]){
                ops++;
                mp[nums[i]]=true;
            }
        }

        return ops;
    }
};