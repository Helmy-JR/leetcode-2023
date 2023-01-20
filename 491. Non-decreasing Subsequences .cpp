// Author: Abdelrahman Helmy

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector < vector < int > > inc_sub;
        int n = nums.size();

        for(int mask = 0; mask < (1 << n); mask++){
            bool is_valid = true;
            vector < int > curr;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    if(curr.empty() || curr.back() <= nums[i]) curr.push_back(nums[i]);
                    else is_valid = false;
                }
            }
            if(is_valid && curr.size() > 1) inc_sub.push_back(curr);
        }
        sort(inc_sub.begin(), inc_sub.end());
        inc_sub.resize(unique(inc_sub.begin(), inc_sub.end()) - inc_sub.begin());
        
        return inc_sub;
    }
};
