class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        
        if(s1.length()!=s2.length())
        return false;


        vector<int>vec;

        for(int i=0;i<s1.length();i++){
            
            if(s1[i]!=s2[i]){
            vec.push_back(i);
            }
            if(vec.size()>2)
            return false;
        }


        if((vec.size()==1) || (vec.size()==2 && ((s1[vec[0]]!=s2[vec[1]]) || (s1[vec[1]]!=s2[vec[0]]))))
        return false;

        return true;

        
    }
};