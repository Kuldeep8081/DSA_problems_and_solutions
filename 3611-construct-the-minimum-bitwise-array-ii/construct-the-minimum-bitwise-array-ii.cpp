class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        
        vector<int>ans;
        for(int num : nums ){

            if(num%2==0){
                ans.push_back(-1);
                continue;
            }

            for(int i=0;i<32;i++){

                if((num & (1<<i))>0)
                continue;

                ans.push_back(num ^ (1<<(i-1)));
                break;
            }
        }

        return ans;
    }
};