#include <bits/stdc++.h>
using namespace std;

const int MN = 500000, MM = 1000000;
pair<int, int> edges[MM];
bool rev[MM], vis[MM];
vector<int> gr[MN];
int lft[MN], cnt[MN];
int m;

void dfs(int s) {
    stack<pair<int, int> > st; st.push(make_pair(s, -1));
    while(!st.empty()) {
        int u = st.top().first;
        int e = st.top().second;
        if(lft[u] == 0) {
            if(e != -1 && edges[e].first == u) rev[e] = true;
            st.pop();
            continue;
        }
        int next = gr[u][--lft[u]];
        if(vis[next]) continue;
        vis[next] = true;
        if(u == edges[next].first) st.push(make_pair(edges[next].second, next));
        else st.push(make_pair(edges[next].first, next));
    }
}

void find_rev() {
    for(int i=0; i<m; i++) rev[i] = vis[i] = false;
    for(int i=0; i<MN; i++) lft[i] = gr[i].size();
    for(int i=0; i<m; i++) if(!vis[i]) dfs(edges[i].first);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i=0; i<MN; i++) cnt[i] = 0;
    cin >> m;
    for(int i=0; i<m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        edges[i] = make_pair(a, b);
        gr[a].push_back(i);
        gr[b].push_back(i);
        cnt[a]++; cnt[b]++;
    }
    for(int i=0; i<MN; i++) if(cnt[i] % 2 != 0) {
        cout << "NIE\n";
        return 0;
    }
    find_rev();
    cout << "TAK\n";
    for(int i=0; i<m; i++) {
        if(rev[i]) cout << "O\n";
        else cout << "Z\n";
    }
}
