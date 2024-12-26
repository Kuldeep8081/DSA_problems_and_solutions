class Solution {
public:

    void Sum(int idx,int &cnt,vector<int>&nums,const int target,const int size,int sum){
        
        if(idx==size ){
            if(sum==target){
                cnt++;
            }
            return ;
        }
        
        for(int i=0;i<2;i++){
            if(i==0){
                sum+=nums[idx];
                Sum(idx+1,cnt,nums,target,size,sum);
                sum-=nums[idx];
            }

            if(i==1){
                sum-=nums[idx];
                Sum(idx+1,cnt,nums,target,size,sum);
                sum+=nums[idx];
            }
        }

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int cnt=0;
        int size=nums.size();
        Sum(0,cnt,nums,target,size,0);
        return cnt;
    }
};