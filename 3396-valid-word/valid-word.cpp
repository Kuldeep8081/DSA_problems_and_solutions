class Solution {
public:
    bool isValid(string word) {
        
        int vowels=0;
        int consonents=0;

        for(char ch : word){
            if(ch=='A' || ch=='a' || ch=='E' || ch=='e' || ch=='I' || ch=='i' || ch=='O' || ch=='o' || ch=='U' || ch=='u'){
                vowels++;
            }else if((ch>='a' && ch<='z') || ch>='A' && ch<='Z'){
                consonents++;
            }else if(ch>='0' && ch<='9')
            {
                continue;
            }else
            return false;
        }

        if(vowels<1 || consonents<1 || word.size()<3)
        return false;

        return true;
    }
};