class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int maxdrink=0;
        int remaining=0;
        while(numBottles>0){
            maxdrink+=numBottles;
            int sum=numBottles+remaining;
            numBottles=(sum)/numExchange;
            remaining=sum-numBottles*numExchange;
        }

        return maxdrink;
    }
};