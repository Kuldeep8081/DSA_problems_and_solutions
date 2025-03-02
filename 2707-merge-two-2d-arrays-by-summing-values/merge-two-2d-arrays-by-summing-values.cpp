class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        
        vector<vector<int>>ans;
         int ind1=0;
        int ind2=0;

        int n=nums1.size();
        int m=nums2.size();

        while(ind1<n && ind2<m){

            
            if(nums1[ind1][0]==nums2[ind2][0]){
                ans.push_back({nums1[ind1][0],nums1[ind1][1]+nums2[ind2][1]});
                ind1++;
                ind2++;
            }else if(nums1[ind1][0]<nums2[ind2][0]){
                ans.push_back({nums1[ind1][0],nums1[ind1][1]});
                ind1++;
            }else if(nums1[ind1][0]>nums2[ind2][0]){
                ans.push_back({nums2[ind2][0],nums2[ind2][1]});
                ind2++;
            }
        }

        while(ind1<n){
            ans.push_back({nums1[ind1][0],nums1[ind1][1]});
            ind1++;
        }

        while(ind2<m){
            ans.push_back({nums2[ind2][0],nums2[ind2][1]});
            ind2++;
        }

        return ans;
    }
};