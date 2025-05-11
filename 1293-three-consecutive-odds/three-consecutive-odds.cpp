class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        
        int cnt=0;

        for(int val : arr){
            if(val%2!=0){
                cnt++;
                if(cnt==3)
                return true;
            }else{
                cnt=0;
            }


        }

        return false;
    }
};