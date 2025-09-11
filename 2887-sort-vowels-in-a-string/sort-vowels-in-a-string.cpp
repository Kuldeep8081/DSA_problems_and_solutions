class Solution {
public:
    string sortVowels(string s) {
        
        vector<char>vowels;

        for(char ch : s){
            if(ch=='a' || ch=='A' ||ch=='e' || ch=='E' ||ch=='i' || ch=='I' ||ch=='o' || ch=='O' ||ch=='u' || ch=='U' ){
                vowels.push_back(ch);
            }
        }

        sort(vowels.begin(),vowels.end());
        
        int j=0;
        for(int i=0;i<s.size();i++){
           char ch=s[i];
           if(ch=='a' || ch=='A' ||ch=='e' || ch=='E' ||ch=='i' || ch=='I' ||ch=='o' || ch=='O' ||ch=='u' || ch=='U' ){
                s[i]=vowels[j++];
            }
        }

        return s;
    }
};