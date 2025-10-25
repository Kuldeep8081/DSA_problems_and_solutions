class Solution {
public:
    int totalMoney(int n) {
        
        int sum=0;
        int start=0;

        while(n>=7){
            start++;
            sum+=7*start+21;
            n-=7;
        }

        start++;
        sum+=n*start+n*(n-1)/2;

        return sum;
    }
};