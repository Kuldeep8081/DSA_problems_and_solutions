class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        
        long long sum1=0;
        long long sum2=0;
        int zero1=0;
        int zero2=0;

        for(int val : nums1){
            if(!val){
                zero1++;
            }

            sum1+=val;
        }
        for(int val : nums2){
            if(!val){
                zero2++;
            }

            sum2+=val;
        }

        if(sum1>sum2){
            swap(zero1,zero2);
            swap(sum1,sum2);
        }

        long long ans=-1;

        sum2+=zero2;
        long long rem=sum2-sum1;

        if((zero1 && (rem>=zero1)) || (!zero1 && !zero2 && !rem)){
            return sum2;
        }else if(zero1 && zero2 && (rem<zero1) ){
            return sum1+zero1;
        }


        return ans;


    }
};