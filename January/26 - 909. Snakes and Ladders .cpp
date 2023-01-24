// Author: Abdelrahman Helmy

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector < pair < int, int > > coord(n * n + 1);
        vector < int > dist(n * n + 1, 1e9);
        bool is_right = true;

        for(int r = n, idx = 1; r >= 1; r--){
            if(is_right)
                for(int c = 1; c <= n; c++)
                    coord[idx++] = {r, c};
            else
                for(int c = n; c >= 1; c--)
                    coord[idx++] = {r, c};
            is_right = !is_right;
        }

        queue < int > bfs;
        bfs.push(1);
        dist[1] = 0;

        while(!bfs.empty()){
            auto u = bfs.front();
            auto [r, c] = coord[u];        
            bfs.pop();

            for(int v = u + 1; v <= min(u + 6, n * n); v++){
                auto [new_r, new_c] = coord[v];
                int next = (board[new_r - 1][new_c - 1] == -1 ? v : board[new_r - 1][new_c - 1]);
                if(dist[next] > dist[u] + 1){
                    dist[next] = dist[u] + 1, bfs.push(next);
                }
            }
        }

        if(dist[n * n] == int(1e9))
            dist[n * n] = -1;

        return dist[n * n];
    }
};
