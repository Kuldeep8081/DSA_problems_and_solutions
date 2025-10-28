class Solution {
public:
    void solve(vector<int>nums,int &sel,int curr,bool left,bool right)
{
        int zeroCnt=0;
        while(curr>=0 && curr<nums.size()){
            
            if(right && nums[curr]==0 ){
                curr++;
            }
            else if(left && nums[curr]==0)
            {
                curr--;
            }
            else if(right && nums[curr]>0){
                nums[curr]--;
                curr--;
                right=false;
                left=true;
            }
            else if(left && nums[curr]>0){
                nums[curr]--;
                curr++;
                right=true;
                left=false;
            }
            
        }

        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            zeroCnt++;
        }

        if(zeroCnt==nums.size())
            sel++;
    
}
    int countValidSelections(vector<int>& nums) {

        int sel=0;

        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)
            {
                mp[i]=1;
            }
        }

        for(auto index:mp){
        solve(nums,sel,index.first+1,false,true);
        solve(nums,sel,index.first-1,true,false);}

        return sel;
    }
};