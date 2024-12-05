class Solution {
public:
    bool canChange(string start, string target) {
        int n = start.length();
        int i = 0, j = 0;

        // Loop through both strings using two pointers
        while (i < n || j < n) {
            // Skip empty spaces in `start` and `target`
            while (i < n && start[i] == '_') i++;
            while (j < n && target[j] == '_') j++;

            // If one pointer reaches the end, both must do so
            if (i == n || j == n) return i == j;

            // Check if the characters match
            if (start[i] != target[j]) return false;

            // Validate the movement constraints
            if (start[i] == 'L' && i < j) return false; // `L` can't move right
            if (start[i] == 'R' && i > j) return false; // `R` can't move left

            // Move both pointers
            i++;
            j++;
        }

        return true;
    }
};
