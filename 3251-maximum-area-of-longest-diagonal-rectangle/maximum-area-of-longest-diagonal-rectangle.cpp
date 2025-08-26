class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        
        int maxArea=0;
        double maxDiag=0.0;

        for(auto &vec : dimensions){

            double dia=sqrt(pow(vec[0],2)+pow(vec[1],2));

            if(dia==maxDiag){
                maxArea=max(maxArea,vec[0]*vec[1]);
            }else if(dia>maxDiag){
                maxDiag=dia;
                maxArea=vec[0]*vec[1];
            }
        }

        return maxArea;

    }
};