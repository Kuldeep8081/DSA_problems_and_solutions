class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int first=0;
        int second=height.size()-1;
        int area=0;
        while(first<second){
           int h1=height[first];
           int h2=height[second];

           int mini=min(h1,h2);
           area=max(area,(second-first)*mini);
           if(h1<h2){
            first++;
           }else{
            second--;
           }
        }

        return area;
    }
};