class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int n=pref.size();
        int cnt=0;
        for(auto str : words){
            if(str.size()<n){
                continue;
            }
            string str1=str.substr(0,n);
            if(str1==pref){
                cnt++;
            }

        }

        return cnt;
    }
};