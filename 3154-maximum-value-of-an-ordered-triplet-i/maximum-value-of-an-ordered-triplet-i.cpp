class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        
        long long maxTriplet=0;
        int maxElement=0;
        long long maxDiff=0;

        for(int i=0;i<nums.size();i++){

            maxElement=max(maxElement,nums[i]);
             maxTriplet=max(maxTriplet,maxDiff*nums[i]);
            maxDiff=max(maxDiff,(long long)maxElement-nums[i]);
        }



        return maxTriplet;
    }
};