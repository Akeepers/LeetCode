
class UnionFind {
   private:
    std::vector<int> _parents;
    int _len;

   public:
    UnionFind(int n) {
        _len = n;
        _parents.resize(n);
        for (int i = 0; i < n; ++i) {
            _parents[i] = i;
        }
    }

    int find(int u) {
        if (_parents[u] != u) {
            _parents[u] = find(_parents[u]);
        }
        return _parents[u];
    }

    bool is_connected(int u, int v) { return find(u) == find(v); }

    // false - 代表图有环路
    bool unin(int u, int v) {
        int fau = find(u);
        int fav = find(v);
        if (fau == fav) return false;
        _parents[fav] = fau;
        return true;
    }

    int get_connected_component() {
        int cnt = -1;
        for (int i = 0; i < _len; ++i) {
            if (i == _parents[i]) cnt++;
        }
        return cnt;
    }
};