// Author: Abdelrahman Helmy

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int ans=0;
        map<int,int> mp;
        for(auto& tasks:tasks) mp[tasks]++;
        for(auto& [l, r] : mp){
            if(r==1) return -1;

            ans += ceil(r/3.0);
        }
        return ans;
    }
};
