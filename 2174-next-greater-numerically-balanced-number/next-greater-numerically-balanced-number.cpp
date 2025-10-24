class Solution {
public:
    int nextBeautifulNumber(int n) {
        
        while(true){
            vector<int>vec(10);
            int num=++n;
            while(num>0){
                int digit=num%10;
                vec[digit]++;
                num/=10;
            }

            bool flag=false;

            for(int i=0;i<10;i++){
                if(vec[i]!=0 && vec[i]!=i){
                    flag=true;
                    break;
                }
            }

            if(!flag)
            return n;

        }

        return n;
    }
};