#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;

template <class T>
class BIT {
public:
    BIT(int l);
    void add(int pos, T x);
    T get_prefix(int pos);

private:
    inline int jump(int x);

    vector<T> v;
    int len;
};

template <class T>
BIT<T>::BIT(int l) : len(l) {
    v.resize(l, 0);
}

template <class T>
void BIT<T>::add(int pos, T x) {
    pos++;
    for(; pos <= len; pos += jump(pos)) {
        v[pos-1] += x;
    }
}

template <class T>
T BIT<T>::get_prefix(int pos) {
    pos++;
    T ret = 0;
    for(; pos > 0; pos -= jump(pos)) {
        ret += v[pos-1];
    }
    return ret;
}

template <class T>
inline int BIT<T>::jump(int x) {
    return x&(-x);
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> vb(n), ve(n);
    REP(i, n) cin >> vb[i] >> ve[i];

    vector<int> eo(n), bo(n);
    REP(i, n) eo[i] = bo[i] = i;
    sort(eo.begin(), eo.end(), [&](int a, int b){
        if(ve[a] == ve[b]) return a < b;
        return ve[a] < ve[b];
    });
    sort(bo.begin(), bo.end(), [&](int a, int b){
        if(vb[a] == vb[b]) return a < b;
        return vb[a] < vb[b];
    });

    map<int, int> mp;
    REP(i, n) mp[vb[i]];
    int mp_len = 0;
    for(auto& p: mp) p.second = mp_len++;

    BIT<int> bit(mp_len);
    REP(i, n) bit.add(mp[vb[i]], 1);

    int best = 0, best_b, best_e;
    int bid = 0, eid = 0;
    while(eid < n) {
        int e = ve[eo[eid]];
        while(bid+1 < n && vb[bo[bid+1]] < e && bit.get_prefix(mp[vb[bo[bid]]]) < k) bid++;
        int b = vb[bo[bid]];
        int cnt = bit.get_prefix(mp[b]);
        if(cnt >= k) {
            if(e - b > best) {
                best = e - b;
                best_b = b;
                best_e = e;
            }
        }
        bit.add(mp[vb[eo[eid]]], -1);
        eid++;
    }

    cout << best << '\n';
    for(int cnt = 0, i = 0; cnt < k && i < n; i++) {
        if(vb[i] <= best_b && best_e <= ve[i]) {
            cout << i+1 << ' ';
            cnt++;
        }
    }
    cout << '\n';
}
