class Solution {
public:
    bool vis[100001];
    queue <int> q;
    int ans = 1000000;
    vector <pair<int, int>> adj[100001];
    int minScore(int n, vector<vector<int>>& tmp) {
        for (auto x : tmp){
            adj[x[0]].push_back(make_pair(x[1], x[2]));
            adj[x[1]].push_back(make_pair(x[0], x[2]));
        }
        
        q.push(1);
        
        while (q.size()){
            int cur = q.front();
            q.pop();
            if (vis[cur] == 1)
                continue;
            vis[cur] = 1;
            
            for (auto x : adj[cur]){
                if (vis[x.first] == 1)
                    continue;
                
                ans = min(ans, x.second);
                
                q.push(x.first);
            }
        }
        return ans;
    }
};
