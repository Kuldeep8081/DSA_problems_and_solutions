class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int size=arr.size();

        vector<int>prefixMax(begin(arr),end(arr));
        vector<int>suffixMin(begin(arr),end(arr));

        for(int i=1;i<size;i++){
            prefixMax[i]=max(prefixMax[i],prefixMax[i-1]);
        }

        for(int i=size-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i],suffixMin[i+1]);
        }

        int count=0;
        for(int i=0;i<size;i++){
            int pehleKaMax=i>0?prefixMax[i-1]:-1;
            int badKaMin=suffixMin[i];

            if(pehleKaMax<badKaMin){
                count++;
            }
        }

        return count;
    }
};