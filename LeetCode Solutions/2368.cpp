class Solution {
public:

    int reachableNodes(int n, vector<vector<int>>& s, vector<int>& v) {
        unordered_map <int, bool> m;
        vector <int> adj[100001];
        queue <int> q;
        int cnt = 0;
        for (int i= 0 ; i< s.size(); ++i){
            adj[s[i][0]].push_back(s[i][1]);
            adj[s[i][1]].push_back(s[i][0]);
        }
        for (int i = 0; i< v.size(); ++i){
            m[v[i]] = 1;
        }
        q.push(0);
        m[0] = 1;
        
        while (q.size()){
            int cur = q.front();
            q.pop();
            
            for (int x : adj[cur]){
                if (m[x] == 1){
                    continue;
                }
                
                m[x] = 1;
                ++cnt;
                q.push(x);
            }
        }
        
        return cnt + 1;
    }
};
