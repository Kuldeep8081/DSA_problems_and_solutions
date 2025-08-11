class Solution {
public:
    
    queue<int> getBinary(int n){
        queue<int>q;

        while(n>0){
           int rem=n%2;
           n/=2;
           q.push(rem);
        }

        return q;
    }
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        
        int size=queries.size();
        int mod=1e9+7;
        queue<int>q=getBinary(n);

        vector<int>powers;

        int pow=1;

        while(!q.empty()){
            int val=(q.front())*pow;
            if(val)
            powers.push_back(val);

            pow*=2;
            q.pop();
        }

        vector<int>ans;

        for(int i=0;i<size;i++){

            long long prod=1;
            int first=queries[i][0];
            int second=queries[i][1];

            for(int j=first;j<=second;j++){
                prod*=powers[j]%mod;
                prod%=mod;
            }

            ans.push_back((int)prod);
        }

        return ans;
    }
};