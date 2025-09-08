class Solution {
public:
    bool isSafe(int n) {
        string str = to_string(n);
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '0')
                return false;
        }

        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> ans;
        for (int a = 1; a <= n; a++) {

            if (isSafe(a)) {
                int b = n - a;
                if (isSafe(b)) {
                    ans.push_back(a);
                    ans.push_back(b);
                    break;
                }
            }
        }

        return ans;
    }
};