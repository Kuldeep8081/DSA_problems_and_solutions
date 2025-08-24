class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        

        int maxi=INT_MIN;

        int left=0;
        int right=0;
        int zero=0;
        bool flag=false;

        for(int val : nums){

            if(val==0){
                zero++;
                flag=true;
            }
            
            if(zero==0 && val==1){
                left++;
            }
            else if(zero==1 && val==1){
               right++;
            }else if(zero==2 && val==1){
                left=right;
                right=1;
                zero=1;
            }
            else if(zero>2 && val==1){
                left=1;
                right=0;
                zero=0;
            }
            
            
            maxi=max(maxi,left+right);
        }

        if(!flag)
        maxi--;

        return maxi;
    }
};