class Solution {
public:
    int solve(vector<int>& days, vector<int>& costs, int ind, vector<int>& dp) {
        if (ind >= days.size())
            return 0; // No more days to cover, cost is 0.

        if (dp[ind] != -1)
            return dp[ind]; // Return the memoized result.

        // Option 1: 1-day pass
        int option1 = costs[0] + solve(days, costs, ind + 1, dp);

        // Option 2: 7-day pass
        int i = ind;
        while (i < days.size() && days[i] < days[ind] + 7)
            i++;
        int option2 = costs[1] + solve(days, costs, i, dp);

        // Option 3: 30-day pass
        i = ind;
        while (i < days.size() && days[i] < days[ind] + 30)
            i++;
        int option3 = costs[2] + solve(days, costs, i, dp);

        // Take the minimum of the three options.
        dp[ind] = min(option1, min(option2, option3));
        return dp[ind];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1); // Initialize DP array with -1.
        return solve(days, costs, 0, dp);
    }
};
