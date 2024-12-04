class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        
        int i=0;
        int j=0;


        int len1=str1.length();
        int len2=str2.length();

        int cnt=0;

        while( i<len1 && j<len2){
            int val1=str1[i]-'a';
            int val2=str2[j]-'a';
            if((val1==val2) || (val1==25 && val2==0) || (val1+1==val2))
            {
                i++;
                j++;
                cnt++;
            }else{
                i++;
            }
        }

        if(cnt==len2)
        return true;

        return false;
    }
};