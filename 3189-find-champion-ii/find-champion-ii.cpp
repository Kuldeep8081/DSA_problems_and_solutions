class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        
        int cnt=n;
        
        unordered_map<int,bool>head;

        unordered_map<int,bool>tail;

        for(auto vec:edges){
            
            head[vec[1]]=true;
            
            tail[vec[0]]=true;

            if(tail[vec[0]] && head[vec[0]])
                tail[vec[0]]=false;
            
            if(tail[vec[1]] && head[vec[1]])
                tail[vec[1]]=false;
        }

        int val=0;

        for(auto mp :tail){
            if(mp.second){
                val=mp.first;
            }else{
                cnt--;
            }
        }

        if(cnt>1)
        return -1;

        return val;

    }
};