// Author: Abdelrahman Helmy

class Solution {
public:
    vector<string> ans;
    string s;

    bool validToAdd(string& add , char c){

        string num;
        for(int i = add.size() - 1; i >= 0 and add[i] != '.'; i--)
            num = add[i] + num;
        
        num += c;

        if(num.size() > 1 and num.front() == '0')
            return false;

        return stoi(num) <= 255;
    }

    bool validIp(string& add){
        return count(add.begin() , add.end() , '.') == 3;
    }

    void Gen(int idx, string& add){
        if(idx == s.size()){
            if(validIp(add))
                ans.push_back(add);
            return;
        }

        if(add.size() and add.back() != '.'){
            add += '.';
            Gen(idx , add);
            add.pop_back();
        }

        if(validToAdd(add , s[idx])){
            add += s[idx];
            Gen(idx + 1 , add);
            add.pop_back();
        }
    }

    vector<string> restoreIpAddresses(string s){
        
        this -> s = s;
        string add;
        Gen(0 , add);
        return ans;
    }
};
