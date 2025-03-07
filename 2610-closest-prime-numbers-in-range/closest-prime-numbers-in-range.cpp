class Solution {
public:
    vector<bool>prime;
    void SieveOfEratosthenes(int left, int right)
{
    prime.assign(right+1,true);
  for (int p = 2; p * p <= right; p++) {


        if (prime[p] == true) {
            
            for (int i = p * p; i <= right; i += p)
                prime[i] = false;
        }
    }
}
    vector<int> closestPrimes(int left, int right) {
        SieveOfEratosthenes(left,right);
        vector<int>vec={-1,-1};
        int num1=0;
        int num2=0;
        
        int diff=INT_MAX;
        for(int i=right;i>=left;i--){
            
            if( i!=1 && prime[i]){
                num1=i;
                if(num2!=0){
                    
                    int d=(num2-num1);
                    if(diff>=d){
                        vec={num1,num2};
                        diff=d;
                    }

                }
                num2=num1;
            }

        }

        return vec;
    }
};