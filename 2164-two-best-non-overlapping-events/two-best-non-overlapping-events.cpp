class Solution {
public:
    int n;
    int t[1000001][3];
    int binarySearch(vector<vector<int>>&events, int endTime){
        int l=0;
        int r=n-1;
        int result=n;

        while(l<=r){
            int mid=l+(r-l)/2;

            if(events[mid][0]>endTime){
                result=mid;
                r=mid-1;
            }else{
                l=mid+1;
            }
        }

        return result;
    }

    int solve(vector<vector<int>>&events,int i,int cnt){

        if(cnt==2 || i>=n)
        return 0;

        if(t[i][cnt]!=-1){
            return t[i][cnt];
        }

        int nextValidEventIndex=binarySearch(events,events[i][1]);
        int take=events[i][2]+solve(events,nextValidEventIndex,cnt+1);

        int not_take=solve(events,i+1,cnt);
        return t[i][cnt]= max(take,not_take);
    }
    int maxTwoEvents(vector<vector<int>>& events) {
        n=events.size();
        sort(begin(events),end(events));
        memset(t,-1,sizeof(t));

        int cnt=0;
        return solve(events, 0, cnt);
    }
};