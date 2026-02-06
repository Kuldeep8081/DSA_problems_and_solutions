class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        
        int i=0,j=0;
        int ans=INT_MAX;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        while(j<n && i<=j){
            long long mul=(long long )k*nums[i];
           if(mul>=nums[j]){
            ans=min(ans,i+n-1-j);
            j++;
           }else{
            i++;
           }
        }

        return ans;
    }
};