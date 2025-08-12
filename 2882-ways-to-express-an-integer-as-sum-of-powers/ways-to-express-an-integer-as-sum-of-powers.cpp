class Solution {
public:
    int mod = 1e9 + 7;

    vector<int> getPower(int n, int x) {
        vector<int> arr;
        for (int i = 1; ; i++) {
            long long power = 1;
            for (int j = 0; j < x; j++) power *= i; // compute i^x
            if (power > n) break;
            arr.push_back((int)power);
        }
        return arr;
    }

    int numberOfWays(int n, int x) {
        vector<int> arr = getPower(n, x);
        vector<int> dp(n + 1, 0);
        dp[0] = 1; // base case

        for (int val : arr) {
            for (int s = n; s >= val; s--) {
                dp[s] = (dp[s] + dp[s - val]) % mod;
            }
        }

        return dp[n];
    }
};
