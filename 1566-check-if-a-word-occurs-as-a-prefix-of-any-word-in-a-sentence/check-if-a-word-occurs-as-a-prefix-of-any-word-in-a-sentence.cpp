class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        
        char st=searchWord[0];
        int len=searchWord.length();
        int wordcnt=1;
        for(int i=0;i<sentence.length();i++){
           
           if(sentence[i]==' ')
           wordcnt++;
           if(( i==0 || sentence[i-1]==' ') && sentence[i]==st){
              int j=i+1;
              int ind=1;
               while(ind<len && j<sentence.length()){
                   if(sentence[j]==searchWord[ind]){
                    j++;
                    ind++;
                   }else
                   break;
               }
               if(ind==len)
               return wordcnt;
           }

           
        }

        return -1;
    }
};