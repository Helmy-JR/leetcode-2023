// Author: Abdelrahman Helmy

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> mp;
        int sum = 0, ans = 0;
        mp[0] = 1;
        for(int i = 0; i < n; i++){
            sum += nums[i];
            sum = ((sum % k) + k) % k;
            ans += mp[sum];
            mp[sum]++;
        }
        return ans;
    }
};
