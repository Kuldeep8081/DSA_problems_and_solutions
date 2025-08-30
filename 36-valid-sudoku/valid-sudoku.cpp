class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        // validate row
        for (int i = 0; i < 9; i++) {
            unordered_map<char, bool> mp;
            unordered_map<char, bool> mp2;
            for (int j = 0; j < 9; j++) {
                if (board[i][j] >= '1' && board[i][j] <= '9') {
                    if (mp[board[i][j]])
                        return false;
                    mp[board[i][j]] = true;
                }
                if (board[j][i] >= '1' && board[j][i] <= '9') {
                    if (mp2[board[j][i]])
                        return false;
                    mp2[board[j][i]] = true;
                }
            }
        }

        for (int i = 0; i < 9; i = i + 3) {
            for (int j = 0; j < 9; j = j + 3) {

                unordered_map<char, bool> mp;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {

                        if (board[k][l] >= '1' && board[k][l] <= '9') {
                            if (mp[board[k][l]])
                                return false;
                            mp[board[k][l]] = true;
                        }
                    }
                }
            }
        }

        return true;
    }
};