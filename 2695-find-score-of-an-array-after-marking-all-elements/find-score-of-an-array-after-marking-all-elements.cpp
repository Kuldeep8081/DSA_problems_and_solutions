class Solution {
public:
    long long findScore(vector<int>& nums) {
        
        long long score=0;
        

        unordered_map<int, queue<int>>mp;
        set<int>s;

        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push(i);
            s.insert(nums[i]);
        }



        unordered_map<int,bool>marked;

        for(auto val : s){
            int top=val;
            queue<int>q=mp[top];

            while(!q.empty()){
                int ind=q.front();
                q.pop();
                if(!marked[ind]){
                    score+=nums[ind];
                    marked[ind]=true;
                    if(ind==0 && ind!=nums.size()-1){
                        marked[ind+1]=true;
                    }else if(ind==nums.size()-1 && ind!=0){
                        marked[ind-1]=true;
                    }else if(ind>0 && ind<nums.size()){
                        marked[ind+1]=true;
                        marked[ind-1]=true;
                    }
                }
            }
        }
        
        return score;
    }
};