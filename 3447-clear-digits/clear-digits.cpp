class Solution {
public:
    string clearDigits(string s) {
        
        for(int i=0;i<s.length();i++){
            
            int digit=s[i]-'0';
            if(digit>=0 && digit<=9){
                if(i>0)
                {
                    s.erase(s.begin()+i-1,s.begin()+i+1);
                    i-=2;
                }else{
                    s.erase(s.begin()+i);
                    i--;
                }

                
            }
        }

        return s;
    }
};