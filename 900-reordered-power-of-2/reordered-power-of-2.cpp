class Solution {
public:
    bool reorderedPowerOf2(int n) {
        // Convert n to its digit frequency
        string s = to_string(n);
        sort(s.begin(), s.end());

        // Precompute sorted digit patterns for all powers of 2 up to 10^9
        static unordered_set<string> powerPatterns;
        if (powerPatterns.empty()) {
            for (int i = 1; i <= 1e9; i <<= 1) {
                string p = to_string(i);
                sort(p.begin(), p.end());
                powerPatterns.insert(p);
            }
        }

        // Just check if n's pattern exists
        return powerPatterns.count(s);
    }
};
