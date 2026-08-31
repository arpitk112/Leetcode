#define ll long long

class Solution {
public:
    vector<ll> parent;
    vector<ll> size;

    ll find(ll x) {
        if (x == parent[x]) {
            return x;
        }
        return parent[x] = find(parent[x]);
    }
    void Union(ll x, ll y) {
        ll px = find(x);
        ll py = find(y);

        if (px == py)
            return;

        if (size[px] < size[py]) {
            parent[px] = py;
            size[py] += size[px];
        } else {
            parent[py] = px;
            size[px] += size[py];
        }
    }

    ll countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        size.resize(n,1);

        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        for(auto &it : edges){
            Union(it[0],it[1]);
        }

        ll ans = 0;
        ll remaining = n;
        ll sum = 0;

        vector<ll> par;

        for(int i = 0; i<n; i++){
            if(parent[i] == i){
                par.push_back(size[i]);
                ans += size[i] * sum;
                sum += size[i];
            }
        }

        for(int i = 0; i< par.size(); i++){
            cout << par[i] << " ";
        }
        return ans;
    }
};