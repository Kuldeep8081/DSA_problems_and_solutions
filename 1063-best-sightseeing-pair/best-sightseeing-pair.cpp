class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int ans=INT_MIN;
        int val1=INT_MIN;
        val1=max(val1,values[0]);
        for(int i=1;i<values.size();i++){
            ans=max(ans,val1+values[i]-i);
            val1=max(val1,values[i]+i);
        }

        return ans;

    }
};