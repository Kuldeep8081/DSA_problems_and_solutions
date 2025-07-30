class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        vector<int>maxIndexes;

        int maxi=*max_element(nums.begin(),nums.end());

        for(int i =0;i<nums.size();i++){
            if(nums[i]==maxi){
                maxIndexes.push_back(i);
            }
        }

        int maxsub=INT_MIN;

        for(int idx : maxIndexes){
           
           if(idx && nums[idx]==nums[idx-1])
           continue;
           
           int i=idx-1;
           int bit=maxi;
           while(i>=0){
              bit&=nums[i];
              if(bit!=maxi)
              break;
              i--;
           }

           int j=idx+1;
           bit=maxi;
           while(j<nums.size()){
             bit&=nums[j];
             if(bit!=maxi)
             break;
             j++;
           }

           int ans=j-i-1;

           maxsub=max(maxsub,ans);
        }

        return maxsub;
    }
};