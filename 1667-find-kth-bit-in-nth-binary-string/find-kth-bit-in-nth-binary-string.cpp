class Solution {
public:
    string Inv(string s){
        for(int i=0;i<s.size();i++){
            s[i]=s[i]=='1'?'0':'1';
        }
        return s;
    }
    
    char findKthBit(int n, int k) {
        unordered_map<int,string>mp;
        mp[1]="0";
        for(int i=2;i<=n;i++){
            string invert=Inv(mp[i-1]);
            reverse(invert.begin(),invert.end());
            mp[i]=mp[i-1]+"1"+invert;
        }

        return mp[n][k-1];
    }
};