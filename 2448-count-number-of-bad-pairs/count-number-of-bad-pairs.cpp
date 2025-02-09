class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        
        long long ans=0;
        int size=nums.size();

        unordered_map<int,int>mp;

        for(int i=0;i<size;i++){

            int val=nums[i]-i;
            mp[val]++;
        }

        unordered_map<int,bool>visited;

        for(int i=0;i<size-1;i++){

            int val=nums[i]-i;
            
            if(mp.count(val)){
            int v=mp[val];
            ans+=(size-i-1)-(v-1);
            mp[val]=v-1;
            }
            
        }

        return ans;


    }
};