class Solution {
public:
    bool vis[200001];
    vector <int> adj[200001];
    queue <int> q;
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for (int i = 0; i<edges.size(); ++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }

        q.push(source);
        vis[source] = 1;

        while (q.size()){
            int cur = q.front();
            q.pop();

            vis[cur] = 1;

            for (auto x : adj[cur]){
                if (vis[x])
                    continue;
                q.push(x);
            }
        }
        for (int i = 0; i<n - 1; ++i){
            cout << vis[i] << ' ';
        }
        return vis[destination];
    }
};
