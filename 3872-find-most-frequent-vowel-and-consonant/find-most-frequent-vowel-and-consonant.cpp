class Solution {
public:
    int maxFreqSum(string s) {
        
        unordered_map<int,int>freq;
        int vowel=0;
        int consonent=0;
        for(char ch : s){
           
           if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u' ){
            freq[ch]++;
            vowel=max(vowel,freq[ch]);
           }else{
            freq[ch]++;
            consonent=max(consonent,freq[ch]);
           }
        }

        return vowel+consonent;
    }
};