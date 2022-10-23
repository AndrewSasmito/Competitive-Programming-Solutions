class Solution {
public:
    #define ll long long
    
    long long calc(vector <int> &v, vector<int> & c, ll num){
        ll ret = 0;
        for (int i = 0; i<v.size(); ++i){
            ret += (abs(num - v[i]) * c[i]);
        }
        return ret;
    }
    
    long long minCost(vector<int>& v, vector<int>& c) {
        ll lo = 0, hi = 1000000;
        
        while (lo < hi){
            ll mid = (lo + hi) / 2;
            
		    ll plus = calc(v, c, mid+1);
		    ll neutral = calc(v, c, mid);

	    	if (neutral>plus)
			    lo = mid + 1;
	    	else
	    		hi = mid;
        }
        cout << calc(v, c, lo) << ' ' << calc(v, c, hi) << '\n';
        return calc(v, c, lo);
    }
};
