class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_map<char,bool>mp;

        for(char ch : brokenLetters){
            mp[ch]=true;
        }

        int cnt=0;
        bool flag=true;

        for(char ch : text){
            if(ch!=' ' && mp[ch]){
                flag=false;
            }else if(ch==' '){
                if(flag)
                cnt++;
                flag=true;
            }
        }

        if(flag){
            cnt++;
        }

        return cnt;


    }
};