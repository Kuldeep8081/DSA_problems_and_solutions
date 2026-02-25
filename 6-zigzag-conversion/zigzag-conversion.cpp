class Solution {
public:
    string convert(string s, int numRows) {
        
        vector<string>vec(numRows);

        int num=0;
        bool isInc=true;

        int i=0;
        while(i<s.size()){
           
           int j=0;
            while(isInc && j<numRows && i<s.size()){
               vec[j].push_back(s[i]);
               i++;
               j++;
            }
            j=numRows-2;
            while(!isInc && j>0 && i<s.size() ){
               vec[j].push_back(s[i]);
               i++;
               j--;
            }

            isInc=!isInc;
        }

        string ans="";
        for( auto &str : vec){
            ans+=str;
        }

        return ans;
    }
};