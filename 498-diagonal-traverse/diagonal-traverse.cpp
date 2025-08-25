class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {

        bool left = false;
        bool right = true;

        int m = mat.size();
        int n = mat[0].size();

        int i = 0;
        int j = 0;

        vector<int> ans;

        while (i <m && j <n) {

            ans.push_back(mat[i][j]);

            if (right) {

                if (i - 1 < 0 || i - 1 >= m || j + 1 <0 || j + 1 >= n) {
                    left = true;
                    right = false;
                    if(j+1>=n){
                        i++;
                    }else{
                        j++;
                    }
                } else {
                    i--;
                    j++;
                }

            } else {
                if (i + 1 < 0 || i + 1 >= m || j - 1 <0 || j - 1 >= n) {
                    right = true;
                    left = false;
                    if(i+1>=m){
                        j++;
                    }else{
                        i++;
                    }
                } else {
                    i++;
                    j--;
                }
            }

        }
        return ans;
    }
};