// Author: Abdelrahman Helmy

class Solution {
public:
    int minDeletionSize(vector<string>& v) {
        int n=v.size();  // rows
        int m = v[0].size(); // columns
        int cnt=0; // deleted columns
        for(int i=0;i<m;i++){ // looping over columns
            bool ans=0;
            for(int j=1;j<n;j++){ // looping over rows
                if(v[j][i] < v[j-1][i]) ans=1; // ceck if sorted or not and caluclate the column one time by the bool.
            }
            cnt +=ans; //updating the deleted columns
        }
        return cnt; // answer
    }
};
