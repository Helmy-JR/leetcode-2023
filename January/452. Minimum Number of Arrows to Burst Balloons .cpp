// Author: Abdelrahman Helmy

#define all(vec) vec.begin(), vec.end()
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(all(points));
        int n = points[0][1];
        int ans = 1 ; 
        for(int i=1;i<points.size();i++){ 
            if(points[i][0]>n){
                ans++ ;
                n=points[i][1] ;      
            } 
            n=min(n,points[i][1]) ; 
        }
        return ans; 
    }
};
