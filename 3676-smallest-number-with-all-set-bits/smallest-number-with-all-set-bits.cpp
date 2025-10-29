class Solution {
public:
    int smallestNumber(int n) {
        
        while(true){
            int val =n;
            if((val&(val+1))==0)
            return n;
            n++;
        }

        return n;
    }
};