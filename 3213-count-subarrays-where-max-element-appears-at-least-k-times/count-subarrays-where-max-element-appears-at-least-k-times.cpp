class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        
        int maxi=*max_element(nums.begin(), nums.end());

        long long ans=0;
        int maxiCnt=0;

        int i=0;
        int j=0;

        

        int n=nums.size();

        while(j<n){

            if(nums[j]==maxi)
            maxiCnt++;

            while(maxiCnt>=k){
                ans+=n-j;
                if(nums[i]==maxi){
                    maxiCnt--;
                }
                i++;
            }
            

            j++;


            
        }

        return ans;
    }
};