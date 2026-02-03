class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        bool flag=false;
        int cnt=0;
        for(int i=1;i<nums.size()-1;i++){
            
            if(flag==false && nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                 cnt++;
                 flag=true;
            }else if(flag==true && nums[i-1]>nums[i] && nums[i]<nums[i+1]){
                cnt++;
                flag=false;
            }else if(flag==true && nums[i-1]<nums[i] && nums[i]>nums[i+1] ){
                return false;
            }else if(flag==false && nums[i-1]>nums[i] && nums[i]<nums[i+1]){
                return false;
            }else if(nums[i-1]==nums[i] || nums[i]==nums[i+1])
            return false;


            
        }

        return cnt==2;
    }
};