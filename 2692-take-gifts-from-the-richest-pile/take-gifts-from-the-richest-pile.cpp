class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        
        long long ans=0;

        priority_queue<int>pq;

        for(auto val : gifts){
            pq.push(val);
            ans+=val;
        }
        
        while(k>0){
            int val=pq.top();
            pq.pop();
            int sr=sqrt(val);
            pq.push(sr);
            int rem=val-sr;
            ans-=rem;
            k--;
        }

        return ans;

    }
};