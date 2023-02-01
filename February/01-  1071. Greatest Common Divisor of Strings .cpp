// Author: Abdelrahman Helmy

class Solution {
public:
    bool check(string& s, string& k){
        if(s.size() % k.size()) return 0; // if the length of string isn't divisible the substring return 
        for(int i=0;i<s.size();i += k.size()){
            if(s.substr(i,k.size()) != k) return 0; // check if the string == current substring 
        }
        return 1;
    }
    string gcdOfStrings(string str1, string str2) {
        string test="", ans="";
        for(int i=0;i<str2.size();i++){
            test += str2[i]; // adding the next char
            if(check(str1,test) && check(str2,test)) ans = test; // checking the string with the new character
        }

        return ans;
    }
};
