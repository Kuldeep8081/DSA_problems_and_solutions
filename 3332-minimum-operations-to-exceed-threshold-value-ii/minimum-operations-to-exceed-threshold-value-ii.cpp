class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        priority_queue<long,vector<long>,greater<long>>pq;

        for(auto val : nums){
            pq.push(val);
        }

        int ans=0;

        while(pq.size()>=2 && pq.top()<k){
            
            long val1=pq.top();
            pq.pop();
            long val2=pq.top();
            pq.pop();

            ans++;

            long op=(long)val1*2+val2;

            pq.push(op);
        }

        return ans;
    }
};