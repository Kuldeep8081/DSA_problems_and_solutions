class Solution {
public:
    string smallestNumber(string pattern) {
        
        int size=pattern.size();
        string num="";

        int val=1;

        stack<int>st;

        int i=0;

        while(i<=size){
            
            if(st.empty() && pattern[i]=='I'){
                num.push_back('0'+val++);
            }else if(pattern[i]=='D'){
                st.push(val++);
            }else if(!st.empty()&& (i==size || pattern[i]=='I')){
                
                num.push_back('0'+val++);

                while(!st.empty()){
                    num.push_back('0'+st.top());
                    st.pop();
                }

            }else if(st.empty() && i==size){
                num.push_back('0'+val);
            }

            i++;

        }

        return num;
    }
};