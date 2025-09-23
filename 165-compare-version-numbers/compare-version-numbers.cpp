class Solution {
public:
    int compareVersion(string version1, string version2) {

        unordered_map<int, int> mp1;
        unordered_map<int, int> mp2;

        string str1 = "";
        int cnt1 = 1;

        for (char ch : version1) {
            if (ch == '.') {
                int val = stoi(str1);
                mp1[cnt1++] = val;
                str1 = "";
                continue;
            }
            str1.push_back(ch);
        }
        mp1[cnt1] = stoi(str1);

        string str2 = "";
        int cnt2 = 1;

        for (char ch : version2) {
            if (ch == '.') {
                int val = stoi(str2);
                mp2[cnt2++] = val;
                str2 = "";
                continue;
            }
            str2.push_back(ch);
        }
        mp2[cnt2] = stoi(str2);

        char ch = '.';

        int maxi=max(cnt1,cnt2);

        for (int i = 1; i <= maxi; i++) {
            if (mp1[i] > mp2[i])
                return 1;
            else if (mp1[i] < mp2[i])
                return -1;
        }

        return 0;
    }
};