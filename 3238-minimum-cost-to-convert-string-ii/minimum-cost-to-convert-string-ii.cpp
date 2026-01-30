class Solution {
public:
    // Fixed: Passed dist by reference (&) and fixed syntax error '>'
    void floyd_warshall(vector<string>& original, vector<string>& changed, vector<int>& cost, unordered_map<string, int>& mp, vector<vector<int>>& dist) {
        int n = dist.size(); // Use the actual size (cnt)
        
        // Initialize self-loops to 0
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        for (int i = 0; i < original.size(); i++) {
            int s = mp[original[i]];
            int d = mp[changed[i]];
            // Fixed: Take the minimum if multiple edges exist between same nodes
            dist[s][d] = min(dist[s][d], cost[i]);
        }

        // Standard Floyd-Warshall
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                if (dist[i][via] == INT_MAX) continue; // Optimization
                for (int j = 0; j < n; j++) {
                    if (dist[via][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                    }
                }
            }
        }
    }

    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost) {
        int cnt = 0;
        unordered_map<string, int> mp;
        unordered_set<int> lengths; // Optimization: Store unique lengths of substrings

        // 1. Map all unique strings to integers
        for (auto& str : original) {
            if (mp.find(str) == mp.end()) mp[str] = cnt++;
            lengths.insert(str.length());
        }
        for (auto& str : changed) {
            if (mp.find(str) == mp.end()) mp[str] = cnt++;
        }

        // 2. Compute All-Pairs Shortest Path
        vector<vector<int>> dist(cnt, vector<int>(cnt, INT_MAX));
        floyd_warshall(original, changed, cost, mp, dist);

        // 3. DP to find min cost for the full string
        int n = source.length();
        // dp[i] = min cost to convert source[0...i-1] to target[0...i-1]
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;

        for (int i = 0; i < n; i++) {
            if (dp[i] == LLONG_MAX) continue; // Unreachable state

            // Try to match substrings starting at i with equal substrings
            if (source[i] == target[i]) {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }

            // Try all possible transformation lengths found in 'original'
            for (int len : lengths) {
                if (i + len > n) continue;

                // Extract substrings
                string sub_s = source.substr(i, len);
                string sub_t = target.substr(i, len);

                // Optimization: If they are already same, cost is 0 (handled by dp[i+1] check above, 
                // but strictly needed if we skip single char loop or for longer jumps)
                if (sub_s == sub_t) {
                    dp[i + len] = min(dp[i + len], dp[i]);
                    continue;
                }

                // If both exist in map, check if there is a path
                if (mp.count(sub_s) && mp.count(sub_t)) {
                    int u = mp[sub_s];
                    int v = mp[sub_t];
                    if (dist[u][v] != INT_MAX) {
                        dp[i + len] = min(dp[i + len], dp[i] + dist[u][v]);
                    }
                }
            }
        }

        return dp[n] == LLONG_MAX ? -1 : dp[n];
    }
};