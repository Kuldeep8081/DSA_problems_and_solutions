class Solution {
public:
    bool hasSameDigits(string s) {

        while (s.size() >2) {
            string str="";
            for (int i = 0; i < s.size() - 1; i++) {
                int sum = ((s[i]-'0') + (s[i + 1]-'0')) % 10;
                char ch=sum+'0';
                str.push_back(ch);
            }
            s = str;
        }

        if (s[0] == s[1])
            return true;
        

        return false;
    }
};