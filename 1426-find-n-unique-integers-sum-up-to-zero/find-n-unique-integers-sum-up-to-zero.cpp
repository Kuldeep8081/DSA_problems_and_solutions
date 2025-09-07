class Solution {
public:
    vector<int> sumZero(int n) {
        
        int half=n/2;

        int val=n;
        vector<int>ans;

        for(int i=0;i<half;i++){
            ans.push_back(val);
            ans.push_back(-val);
            val--;
        }

        if(n%2!=0){
            ans.push_back(0);
        }

        return ans;
    }
};