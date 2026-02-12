class Solution {
public:
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            unordered_map<char,int>mp;
            for(int j=i;j<s.size();j++){
                mp[s[j]]++;
                int cnt_max=INT_MIN;
                int cnt_min=INT_MAX;
                for(auto it : mp){
                    cnt_max=max(cnt_max,it.second);
                    cnt_min=min(cnt_min,it.second);
                }

                if(cnt_max==cnt_min)
                ans=max(ans,j-i+1);
            }
        }

        return ans;

    }
};