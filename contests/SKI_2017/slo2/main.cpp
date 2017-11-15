#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long LL;

int main() {
    ios_base::sync_with_stdio(0);
    string str;
    cin >> str;
    int m, n;
    cin >> m >> n;
    vector<pair<int, int>> dp(m);
    REP(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        dp[i] = {a, b};
    }

    stack<int> st;
    int l = n;
    for(int i=m-1; i>=0; i--) {
        int ld = max(0, min(dp[i].second - dp[i].first + 1, l - 1 - dp[i].second));
        st.push(ld);
        l -= ld;
    }

    crope cr(str.substr(0, l));
    for(int i=0; i<m; i++) {
        int b = dp[i].second;
        int ld = st.top();
        st.pop();
        crope dop = cr.substr(b - ld + 1, ld);
        reverse(dop.begin(), dop.end());
        cr.insert(b + 1, dop);
    }

    cout << cr;
}
