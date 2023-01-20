// Author: Abdelrahman Helmy

class Solution {
public:
    string labels;
    vector<vector<int>> adj;
    vector<int> ans;
    
    vector<int> dfs(int root, int par){
        vector<int> cnt(26, 0);
        cnt[labels[root] -  'a']++;
        for(auto&i: adj[root]){
            if(i == par) continue;
            vector<int> child_cnt = dfs(i, root);
            for(int i = 0; i < 26; i++)
                cnt[i] += child_cnt[i];
        }
        ans[root] = cnt[labels[root] - 'a'];
        return cnt;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        this -> labels = labels;
        adj.assign(n, vector<int> ());
        ans.assign(n, 1);
        for(auto&i: edges){ 
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, -1);
        return ans;
    }
};
