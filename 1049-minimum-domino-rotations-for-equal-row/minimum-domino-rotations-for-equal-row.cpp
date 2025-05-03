class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        
        unordered_map<int,pair<int,int>>top;
        unordered_map<int,pair<int,int>>bottom;

        int n=tops.size();

        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                top[tops[i]].second++;
            }else{
                top[tops[i]].first++;
            }
        }

        for(int i=0;i<n;i++){
            if(tops[i]==bottoms[i]){
                bottom[bottoms[i]].second++;
            }else{
                bottom[bottoms[i]].first++;
            }
        }

        int ans=-1;

        for(auto it : top){
            int rem=n-(it.second.first+it.second.second);
            if(bottom[it.first].first==rem){
                  ans=rem;
                  break;
            }
        }

        for(auto it : bottom){
            int rem=n-(it.second.first+it.second.second);
            if(top[it.first].first==rem)
            {
                ans=min(ans,rem);
                break;
            }
        }

        

        return ans;
    }
};