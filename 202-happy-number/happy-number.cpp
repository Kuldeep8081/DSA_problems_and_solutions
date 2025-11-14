class Solution {
public:
    bool isHappy(int n) {
        if(n<0)
        return false;

        unordered_map<int,bool>mp;
        mp[n]=true;
        while(n>=1){
            if(n==1)
            return true;

            int sum=0;
            while(n>0){
                int digit=n%10;
                n/=10;
                sum+=digit*digit;
            }

            n=sum;

            if(mp[n]==true)
            return false;

            mp[n]=true;
        }


        return false;
    }
};