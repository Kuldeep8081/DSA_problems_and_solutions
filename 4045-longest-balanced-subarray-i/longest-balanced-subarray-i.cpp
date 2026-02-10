class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            unordered_map<int,bool>numVisit;
            int oddCnt=0;
            int evenCnt=0;
            for(int j=i;j<nums.size();j++){
               if(!numVisit[nums[j]]){
                numVisit[nums[j]]=true;
                if(nums[j]%2==0)
                evenCnt++;
                else
                oddCnt++;
               }

               if(evenCnt==oddCnt){
                    ans=max(ans,j-i+1);
                }
            }


        }

        return ans;
        

        
    }
};