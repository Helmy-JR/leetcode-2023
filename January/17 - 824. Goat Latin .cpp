// Author: Abdelrahman Helmy

class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        string word = "", res= "";
        stringstream ss(sentence);
        int cnt = 1;
        while(ss>>word)
        { 
            if(!vowels.count(word[0]))
                word = word.substr(1, word.length()-1) + word[0];
            res += word + "ma" + addA(cnt++);
        }
        res.erase(res.end()-1);
        return res;
    }
    
    string addA(int cnt) {
        string a = "";
        for(int i=0; i<cnt; i++)
            a += "a";
        return a+" ";
    }
};
