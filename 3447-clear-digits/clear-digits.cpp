class Solution {
public:
    string clearDigits(string s) {
        
        string st="";
        for(int i=0;i<s.length();i++){
            
            int val=s[i]-'0';

            if(val>=0 && val<=9 && st.size()){
                st.pop_back();
            }
            else
            st.push_back(s[i]);
        }

        return st;
    }
};