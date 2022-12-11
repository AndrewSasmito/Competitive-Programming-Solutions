class Solution {
public:
    vector <int> adj[100001];
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        int ans = -1000001, cur, hm;
        for (int i = 0; i<edges.size(); ++i){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        
        for (int i = 0; i<vals.size(); ++i){
            cur = 0;
            vector <int> tmp;
            for (int x : adj[i]){
                tmp.push_back(vals[x]);
            }
            sort(tmp.begin(), tmp.end(), greater<int>());
            hm = tmp.size();
            for (int i = 0; i<min(k, hm); ++i){
                if (tmp[i] <= 0)
                    break;
                
                cur += tmp[i];
            }
            ans = max(ans, cur + vals[i]);
        }
        return ans;
    }
};
