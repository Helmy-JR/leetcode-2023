// Author: Abdelrahman Helmy

class Solution {
public:
    int minFlipsMonoIncr(string& s) {
        
        // number of zeros and ones so far
        int ones = 0, zeros = count(s.begin(), s.end(), '0');

        // store the best answer while traversing
        int min_flips = s.size();

        for(auto& c : s){
            // update number of zeros
            zeros -= (c == '0');

            // update the minimum flips
            min_flips = min(min_flips, ones + zeros);

            // update number of ones while traverse
            ones += (c == '1');
        }

        return min_flips;
    }
};
