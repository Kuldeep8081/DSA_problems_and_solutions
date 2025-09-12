class Solution {
public:
    bool doesAliceWin(string s) {
        long long even = 1;  // empty prefix
        long long odd = 0;
        int parity = 0;
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};

        for (char ch : s) {
            if (vowels.count(ch)) {
                parity ^= 1;  // flip parity
            }
            if (parity == 0) {
                even++;
            } else {
                odd++;
            }
        }

        return even * odd > 0;
    }
};