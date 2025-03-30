class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>last_occ;

        for(int i=0;i<s.size();i++){
            last_occ[s[i]]=i;
        }

        vector<int>result;

        int start=0,end=0;

        for(int i=0;i<s.size();i++){
            end=max(end,last_occ[s[i]]);
            if(i==end){
                result.push_back(end-start+1);
                start=i+1;
            }
        }

        return result;
    }
};