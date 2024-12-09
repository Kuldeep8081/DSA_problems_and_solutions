class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        

        vector<bool>ans;
         
        unordered_map<int,int>mp;

        int cnt=0;

        bool previsOdd=false;
        bool previsEven=false;
        if(nums[0]%2!=0){
            previsOdd=true;
        }else{
            previsEven=true;
        }

        mp[0]=cnt;

        for(int i=1;i<nums.size();i++){
            if(nums[i]%2!=0 ){
                if(previsOdd){
                cnt++;
                mp[i]=cnt;
                }
                else{
                mp[i]=cnt;

                }
                previsOdd=true;
                previsEven=false;
            }else{
                if(previsEven){
                cnt++;
                mp[i]=cnt;
                }else{
                mp[i]=cnt;
                }
                previsEven=true;
                previsOdd=false;
            }
        }

        for(int i=0;i<queries.size();i++){

            int s=queries[i][0];
            int e=queries[i][1];

            int first=mp[s];
            int second=mp[e];
            
            int val=second-first;

            if(val>0){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }

        }

        return ans;
    }
};