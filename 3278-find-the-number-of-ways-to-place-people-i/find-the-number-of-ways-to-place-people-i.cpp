class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {

        int cnt = 0;

        for (auto& vec1 : points) {
            for (auto& vec2 : points) {
                bool flag = false;
                if (vec1[0] > vec2[0] && vec1[1] < vec2[1]) {
                    for (auto& vec3 : points) {
                        if ((vec1 != vec3 && vec2 != vec3) &&
                            vec1[0] >= vec3[0] && vec2[0] <= vec3[0] &&
                            vec1[1] <= vec3[1] && vec2[1] >= vec3[1]) {
                            flag = true;
                            break;
                        }
                    }

                    if (!flag) {
                        cnt++;
                    }
                } else if (vec1[0] == vec2[0] && vec1[1] <vec2[1]) {
                    for (auto& vec3 : points) {
                        if ((vec1 != vec3 && vec2 != vec3) &&
                            vec1[0] == vec3[0] && vec1[1] < vec3[1] &&
                            vec2[1] > vec3[1]) {
                            flag = true;
                            break;
                        }
                    }

                    if (!flag) {
                        cnt++;
                    }
                } else if (vec1[0] >vec2[0] && vec1[1] == vec2[1]) {
                    for (auto& vec3 : points) {
                        if ((vec1 != vec3 && vec2 != vec3) &&
                            vec1[0] > vec3[0] && vec2[0] < vec3[0] &&
                            vec2[1] == vec3[1]) {
                            flag = true;
                            break;
                        }
                    }

                    if (!flag) {
                        cnt++;
                    }
                }
            }
        }

        return cnt;
    }
};