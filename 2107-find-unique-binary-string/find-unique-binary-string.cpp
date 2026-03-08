class Solution {
public:
    string backtrack(string s,unordered_map<string,bool>&mp){
        
        if(mp.find(s)==mp.end())
        return s;
        for(int i=0;i<s.size();i++){
            if(s[i]!='1'){
                s[i]='1';
                return backtrack(s,mp);
                s[i]='0';
            }
        }
        return s;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_map<string,bool>mp;
        for(auto&str:nums){
            mp[str]=true;
        }
        string s="";
        for(int i=0;i<nums.size();i++){
            s.push_back('0');
        }
        return backtrack(s,mp);
    }
};