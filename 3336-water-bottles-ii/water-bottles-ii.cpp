class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int empty=0;
        int bottlesDrunk=0;

        while(numBottles || empty>=numExchange ){
            if(empty<numExchange){
                bottlesDrunk+=numBottles;
                empty+=numBottles;
                numBottles=0;
            }else{
                empty-=numExchange;
                numExchange++;
                numBottles++;
            }
        }


        return bottlesDrunk+numBottles;
    }
};