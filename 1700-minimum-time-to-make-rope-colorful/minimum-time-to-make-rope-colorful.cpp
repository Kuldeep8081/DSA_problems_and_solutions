class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int cost=0;
        int size=colors.size();
        int prev=size-1;
        for(int i=size-2;i>=0;i--){
            if(colors[prev]!=colors[i]){
                prev=i;
            }else{
                if(neededTime[prev]<=neededTime[i]){
                    cost+=neededTime[prev];
                    prev=i;
                }else{
                    cost+=neededTime[i];
                }
            }
        }

        return cost;
    }
};