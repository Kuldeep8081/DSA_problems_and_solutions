class Solution {
public:
    bool hasAlternatingBits(int n) {
        int num=1;
        int prevBit=n&1;
        n>>=1;

        while(n){
            int nextBit=n&1;
            n>>=1;
            if(nextBit==prevBit)
            return false;

            prevBit=nextBit;
        }



        return true;
    }
};