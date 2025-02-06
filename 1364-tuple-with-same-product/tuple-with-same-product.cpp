class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {

        unordered_map<int,int>mp;

        int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                
                int mul=nums[i]*nums[j];
                mp[mul]++;
            }
        }


        for(auto m : mp){

            int size=m.second;
            
            if(size>1){
                ans+=size*(size-1)/2;
            }
        }

        return ans*8;
    }
};