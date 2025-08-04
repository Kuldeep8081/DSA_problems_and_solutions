class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int>mp;
        
        int size=fruits.size();
        int i=0;
        int j=0;

        int cnt=0;
        int maxi=INT_MIN;

        while(i<=j && j<size){
           
           if(cnt<=2){
               mp[fruits[j]]++;
               if(mp[fruits[j]]==1)
               {
                cnt++;
               }
               if(cnt<=2){
               maxi=max(maxi,j-i+1);
               j++; 
               }
           }else{
            mp[fruits[i]]--;
            if(mp[fruits[i]]==0)
            cnt--;
            
            i++;
            if(cnt<=2){
                maxi=max(maxi,j-i+1);
                j++;
            }
           }

        }

        return maxi;
    }
};