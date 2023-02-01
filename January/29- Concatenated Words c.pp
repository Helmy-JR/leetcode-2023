// Author: Abdelrahman Helmy

class Solution {
public:
    unordered_set<string> words_set;

    unordered_map<string, int> dp;

    int mx(string s){
        if(s.size() == 0) return 0;
        
        if(dp.count(s)) return dp[s];

        int ans = (words_set.count(s) ? 1 : -1e9);
        for(int i = 1; i < s.size(); i++){
            if(words_set.count(s.substr(0 , i)))
                ans = max(ans, 1 + mx(s.substr(i, s.size() - i)));    
        }
        return dp[s] = ans;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto&i: words)
            words_set.insert(i);
        vector<string> ans;
        for(auto&i: words)
            if(mx(i) > 1) ans.push_back(i);

        return ans;   
    }
}; // credit >> abouelsoud
