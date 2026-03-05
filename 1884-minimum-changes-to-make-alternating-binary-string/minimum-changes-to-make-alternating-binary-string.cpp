class Solution {
public:
    int minOperations(string s) {
        bool zero=true;
        bool one=true;
        int ope1=0;
        int ope2=0;

        for(char &ch : s){
            if((zero && ch=='0') || (!zero && ch=='1')){
                zero=!zero;
            }else if((zero && ch=='1') || (!zero && ch=='0')){
                zero=!zero;
                ope1++;
            }

            if((one && ch=='1') || (!one && ch=='0')){
                one=!one;
            }else if((one && ch=='0') || (!one && ch=='1')){
                one=!one;
                ope2++;
            }
        }

        return min(ope1,ope2);
    }
};