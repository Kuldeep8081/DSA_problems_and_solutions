class Solution {
public:
   unordered_map<int,int>place;
   int binary_search(vector<int>&potions,int s,int e,int val,long long target ){
       int ans=0;

       while(s<=e){
         int mid=s+(e-s)/2;
         int midval=potions[mid];
         long long mul=(long long)midval*val;
         if(mul==target){
            return ans=potions.size()-place[midval];
         }
         else if(mul>target){
            e=mid-1;
            ans=potions.size()-mid;
         }else{
            s=mid+1;
         }
       }

       return ans;


   }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());

        for(int i=potions.size()-1;i>=0;i--){
            place[potions[i]]=i;
        }
        vector<int>ans;
        for(int val : spells){
            
            ans.push_back(binary_search(potions,0,potions.size()-1,val,success));
        }

        return ans;
    }
};