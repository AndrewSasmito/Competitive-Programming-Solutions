class Solution {
public:

    int dfs(int x, int y, vector<vector<int>>& grid){
        if (x == grid.size()){
            return y;
        }else if (grid[x][y] == 1){

            if (y == grid[0].size() - 1){
                return -1;
            }else if (grid[x][y + 1] == -1){
                return -1;
            }else{
                return dfs(x + 1, y + 1, grid);
            }
        }else{

            if (y == 0){
                return -1;
            }else if (grid[x][y - 1] == 1){
                return -1;
            }else{
                return dfs(x + 1, y - 1, grid);
            }
        }
    }

    vector<int> findBall(vector<vector<int>>& vs) {
        vector <int> ans;

        for (int i = 0; i<vs[0].size(); ++i){
            ans.push_back(dfs(0, i, vs));
        }
        return ans;
    }
};
