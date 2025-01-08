class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int cnt=0;
        for(int i=0;i<words.size()-1;i++){
            
            string str1=words[i];
            int size=str1.size();
            for(int j=i+1;j<words.size();j++){
                if(words[j].size()<str1.size()){
                    continue;
                }

                string str2=words[j];
                
                string pre=str2.substr(0,size);
                string suf=str2.substr(str2.size()-size,size);

                if(str1==pre && suf==str1){
                    cnt++;
                }
            }
        }

        return cnt;
    }
};