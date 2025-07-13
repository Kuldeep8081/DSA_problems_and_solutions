class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());

        int size1=players.size();
        int size2=trainers.size();

        int i=size1-1;
        int j=size2-1;

        int maxMatching=0;

        while(i>=0 && j>=0){
            
            if(players[i]<=trainers[j]){
                maxMatching++;
                j--;
            }
            i--;
        }

        return maxMatching;
    }
};