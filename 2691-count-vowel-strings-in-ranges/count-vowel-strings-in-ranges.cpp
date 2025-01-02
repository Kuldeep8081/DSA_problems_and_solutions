class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        
        int nstr=0;

        unordered_map<char,bool>mp;
        mp['a']=true;
        mp['e']=true;
        mp['i']=true;
        mp['o']=true;
        mp['u']=true;
        
        vector<int>vec;
        for(int i=0;i<words.size();i++){
            string str=words[i];
            if(mp[str[0]] && mp[str[str.size()-1]]){
                nstr++;
            }

            vec.push_back(nstr);
        }
        vector<int>ans;
        for(auto v : queries){

            int s=v[0];
            int e=v[1];

            if(mp[words[s][0]] && mp[words[s][words[s].size()-1]]){
                ans.push_back(vec[e]-vec[s]+1);
            }else{
                ans.push_back(vec[e]-vec[s]);
            }
        }

        return ans;
    }
};