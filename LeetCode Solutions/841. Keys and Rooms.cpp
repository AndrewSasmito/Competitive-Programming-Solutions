class Solution {
public:
    unordered_map <int, bool> m;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        m[0] = 1;
        for (int k = 0; k<rooms.size(); ++k)
            for (int i = 0; i<rooms.size(); ++i){
                if (m[i] == 0)
                    continue;
                
                for (int j = 0; j<rooms[i].size(); ++j)
                    m[rooms[i][j]] = 1;
            }
        
        for (int i = 0; i<rooms.size(); ++i){
            if (m[i] == 0)
                return 0;
        }

        return 1;
    }
};
