// Author: Abdelrahman Helmy

class Solution {
public:
    bool detectCapitalUse(string s) {
        bool chk=isupper(s.front());
        int cnt=0;
        for(auto& i : s){
            if(i>='A'&&i<='Z') cnt++;
        }
        if(cnt>0){
            if(cnt==s.size() || (cnt==1 && chk==true)) return true;
            else return false;
        }
        return true;
    }
};
