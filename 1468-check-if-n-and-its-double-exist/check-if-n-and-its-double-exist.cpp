class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        
        unordered_map<int,bool>multiple;
        unordered_map<int,bool>single;

        for( auto val : arr){
            if(multiple[val]){
                return true;
            }
            if(single[2*val]){
                return true;
            }

            multiple[2*val]=true;
            single[val]=true;
        }
         
         return false;
    }
};