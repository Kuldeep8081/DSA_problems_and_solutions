class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int size=prices.size();
        vector<int>ans;
        
        int dis;
        for(int i=0;i<size;i++){
            dis=0;
            for(int j=i+1;j<size;j++){
                if(prices[j]<=prices[i])
                {
                    dis=prices[j];
                    break;
                }
            }

            ans.push_back(prices[i]-dis);
        }

        return ans;
        
    }
};