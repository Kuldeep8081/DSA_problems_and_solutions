class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        
        int size=spaces.size();
        int len=s.length();

        for(int i=0;i<size;i++){
            s.push_back(' ');
        }

        int newlen=s.length();


        int start=len;
        int end=newlen-1;
        
        int index=size-1;
        int val=spaces[index--];
        int cnt=len-val;
        int prevsize=cnt;
        for(int i=len-1;i>=0;i--){
            
            cnt--;
            if(end<start)
            break;
          
            swap(s[i],s[end--]);
            start--;
            if(cnt==0 ){
                if(index<0)
                return s;
               cnt=len-spaces[index--]-prevsize;
               prevsize+=cnt;
               end--;

            }

        }

        return s;
    }
};