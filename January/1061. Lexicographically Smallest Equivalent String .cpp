// Author: Abdelrahman Helmy

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<char>vec(26);
        iota(vec.begin(),vec.end(),'a');
        int n = s1.size();
        for(int i=0; i<n; i++){
           char maxi = max(vec[s1[i]-'a'],vec[s2[i]-'a']);
           char mini = min(vec[s1[i]-'a'],vec[s2[i]-'a']);
           for(int i=0; i<26; i++){
               if(vec[i]==maxi){
                   vec[i] = mini;
               }
           }
        }
        for(auto&i:baseStr){
            i = vec[i-'a'];
        }
        
        return baseStr;
    }
};
