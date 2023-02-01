// Author: Abdelrahman Helmy

class Solution {
public:    
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        vector<pair<int,int>> v;
        v.assign(n, {0, 0});

        for(int i = 0; i < n; i++)
            v[i] = {ages[i], scores[i]};

        sort(v.begin(), v.end());
        int ans = 0;
        vector<int> dp(n + 5, 0);

        for(int i = 0; i < n; i++){
            dp[i] = v[i].second;
            for(int j = i - 1; j >= 0; j--){
                if(v[i].second >= v[j].second)
                    dp[i] = max(dp[i], v[i].second + dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
}; // credit >> abouelsoud
