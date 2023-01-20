//author : Abdelrahman Helmy

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int sumgas=0,sumcost=0,now=0,ans=0,n=cost.size(); 
        for(int i=0;i<n;i++){
            sumcost+=cost[i];
            sumgas+=gas[i];
            now+=(gas[i]-cost[i]);
            if(now<0){
                now=0;
                ans=i+1;
            }
        }
        if(sumcost>sumgas) return -1;
        return ans;   
    }
};
