class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    int lcm(int a, int b) {
        return (a / gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        for (int num : nums) {
            res.push_back(num);
            // merge while last two are not coprime
            while (res.size() > 1) {
                int n = res.size();
                int g = gcd(res[n-1], res[n-2]);
                if (g == 1) break; // they are coprime
                long long newVal = 1LL * res[n-1] / g * res[n-2];
                res.pop_back();
                res.pop_back();
                res.push_back((int)newVal);
            }
        }
        return res;
    }
};
