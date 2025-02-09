class Solution {
public:
    vector<int> assignElements(vector<int>& groups, vector<int>& elements) {
        int n = groups.size();
        vector<int> ans(n, -1);

        // Step 1: Sort elements to always pick the smallest indexed valid element
        vector<pair<int, int>> sortedElements;
        for (int i = 0; i < elements.size(); i++) {
            sortedElements.emplace_back(elements[i], i);
        }
        sort(sortedElements.begin(), sortedElements.end()); // O(M log M)

        // Step 2: Precompute the smallest index for each number
        unordered_map<int, int> smallestIndex;
        for (auto &[val, idx] : sortedElements) {
            if (smallestIndex.find(val) == smallestIndex.end()) {
                smallestIndex[val] = idx; // Store first occurrence
            }
        }

        // Step 3: Process each group in O(√groups[i]) time
        for (int i = 0; i < n; i++) {
            int minIdx = INT_MAX;
            int g = groups[i];

            // Find smallest valid divisor from precomputed values
            for (int div = 1; div * div <= g; div++) {
                if (g % div == 0) {
                    // Check divisor and its pair (g / div)
                    if (smallestIndex.count(div)) {
                        minIdx = min(minIdx, smallestIndex[div]);
                    }
                    if (smallestIndex.count(g / div)) {
                        minIdx = min(minIdx, smallestIndex[g / div]);
                    }
                }
            }

            // Assign the smallest index found
            ans[i] = (minIdx == INT_MAX) ? -1 : minIdx;
        }

        return ans;
    }
};
