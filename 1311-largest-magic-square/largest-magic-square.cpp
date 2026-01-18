class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> rowSum(m, vector<int>(n));
        vector<vector<int>> colSum(m, vector<int>(n));

        // row prefix sum
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += grid[i][j];
                rowSum[i][j] = sum;
            }
        }

        // col prefix sum
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int i = 0; i < m; i++) {
                sum += grid[i][j];
                colSum[i][j] = sum;
            }
        }

        // Starting from max square to min
        for (int side = min(m, n); side >= 2; side--) {

            for (int i = 0; i < m - side + 1; i++) {
                for (int j = 0; j < n - side + 1; j++) {
                    bool flag = true;

                    // target row sum
                    int targetSum = rowSum[i][j + side - 1] -
                                    (j > 0 ? rowSum[i][j - 1] : 0);
                    // checking sum of all row's
                    for (int k = 1; k < side; k++) {
                        int sum = rowSum[i + k][j + side - 1] -
                                  (j > 0 ? rowSum[i + k][j - 1] : 0);
                        if (sum != targetSum) {
                            flag = false;
                            break;
                        }
                    }

                    if (flag == false)
                        continue;
                    // check sum of all columns
                    for (int k = 0; k < side; k++) {
                        int sum = colSum[i + side - 1][j + k] -
                                  (i > 0 ? colSum[i - 1][j + k] : 0);
                        if (sum != targetSum) {
                            flag = false;
                            break;
                        }
                    }

                    if (flag == false)
                        continue;
                    int backwardD = 0;
                    int forwardD = 0;
                    for (int k = 0; k < side; k++) {
                        backwardD += grid[i + k][j + k];
                        forwardD += grid[i + k][j + side - 1 - k];
                    }

                    if (backwardD == targetSum && forwardD == targetSum)
                        return side;
                }
                            }
        }

        return 1;
    }
};