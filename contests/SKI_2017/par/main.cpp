#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> v1(n), v(n);
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v1[x-1] = i;
    }
    for(int i=0; i<n; i++) {
        int x;
        cin >> x;
        v[i] = v1[x-1];
    }
    v1.clear();

    set<int> st;
    for(int i=n-1; i>=0; i--) {
        int num_lower = distance(st.begin(), st.lower_bound(v[i]));
        if(num_lower > k) {
            cout << "NIE\n";
            return 0;
        }
        st.insert(v[i]);
    }

    cout << "TAK\n";
}
