class Solution {
public:
    bool isPowerOfTwo(int n) {
       if(n==1) 
       return true;
       if(n==0)
       return false;
       bool flag=0;
       while(n!=0)
       {
           if(n%2!=0 && n!=1)
           {
           flag=1;
           break;
           }
           n=n>>1;
       }
       if(flag)
       return false;
       else
       return true;
    }
};