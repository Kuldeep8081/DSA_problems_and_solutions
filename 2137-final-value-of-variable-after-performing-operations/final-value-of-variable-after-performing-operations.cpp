class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x=0;

        for(auto str : operations){
            if(str[0]=='-' || str[2]=='-'){
                x-=1;
            }else if(str[0]=='+' || str[2]=='+'){
                x+=1;
            }
        }

        return x;
    }
};