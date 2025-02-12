class Solution {
public:
    int maximumSum(vector<int>& nums) {
        int ans=-1;

        unordered_map<int,priority_queue<int>>mp;

        for(int i=0;i<nums.size();i++){

            int num=nums[i];
            
            int sum=0;
            while(num>0){
                int digit=num%10;
                sum+=digit;
                num/=10;
            }

            if(mp[sum].size()){
                ans=max(ans,(nums[i]+mp[sum].top()));
            }

            mp[sum].push(nums[i]);
        }
        
        return ans;
        
    }
};