class Solution {  // Author: Abdelrahman Helmy
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end()); 
        int ans=0,cnt=0;
        for(int i=0;i<costs.size();i++){
            if((ans+costs[i])<= coins) ans+=costs[i],cnt++;
        }
        return cnt;
    }
};
