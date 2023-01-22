// Author: Abdelrahman Helmy

class Solution {
public:
    string s;
    vector<string> v_temp;
    vector<vector<string>> ans;
    bool plain(int l, int r){
        while(l < r){
            if(s[l++] != s[r--]) return 0;
        }
        return 1;
    }

    void rec(int idx, int lst){
        if(idx == s.size()){
            if(lst == s.size())
                ans.push_back(v_temp);
            return;
        }
        rec(idx + 1, lst);
        if(plain(lst, idx)){
            v_temp.push_back(s.substr(lst, idx - lst + 1));
            rec(idx + 1, idx + 1);
            v_temp.pop_back();
        }
    }

    vector<vector<string>> partition(string s) {
        this -> s = s;
        rec(0, 0);
        return ans;
    }
};
