class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        unordered_map<int,vector<vector<int>>>mp;
        int mini=INT_MAX;

        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-1;i++){
            int diff=abs(arr[i]-arr[i+1]);
            mini=min(mini,diff);
            mp[diff].push_back({arr[i],arr[i+1]});
        }

        return mp[mini];
    }
};