// Author: Abdelrahman Helmy

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        stringstream ss(s);
        string word;
        while( ss >> word ) v.push_back( word );
        if (v.size() != pattern.size()) return false;
        for(int i = 0; i < pattern.size(); i++){
            for(int j = 0; j < pattern.size(); j++){
                if((pattern[i] == pattern[j]) != (v[i] == v[j]))
                    return 0;
            } 
        }
        return 1;
    }
};
