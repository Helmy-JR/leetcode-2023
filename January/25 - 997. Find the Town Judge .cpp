// Author: Abdelrahman Helmy

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        // freq1 for the trusting people
        // freq2 for the trusted judge
        vector<int> freq1(n+1,0) , freq2(n+1,0);
        int ans = -1;

        for(int i=0;i<trust.size();i++){
            freq1[trust[i][0]]++;
            freq2[trust[i][1]]++;
        }

        for(int i=1;i<=n;i++){
            if(freq1[i] == 0 && freq2[i] == n-1) ans = i;
        }

        return ans;
    }
};
