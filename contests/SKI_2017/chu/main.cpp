#include <bits/stdc++.h>
#define REP(i, n) for(int i=0; i<(n); i++)
using namespace std;
typedef unsigned char byte;

const int MN = 500, INF = 1000000001;
bool sciana[MN][MN][4], odw[MN][MN][4];
int d[MN][MN][4];
int n, m, start_dir, mx, my, rx, ry;

void read() {
    cin >> n >> m;
    string str;
    cin >> str;
    if(str == "GORA") start_dir = 0;
    else if(str == "PRAWO") start_dir = 1;
    else if(str == "DOL") start_dir = 2;
    else if(str == "LEWO") start_dir = 3;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            for(int k=0; k<4; k++) sciana[i][j][k] = false;
        }
    }

    for(int i=0; i<(2*n + 1); i++) {
        cin.get();
        for(int j=0; j<(2*m + 1); j++) {
            char c = cin.get();
            if(i%2 == 0 && j%2 == 0) continue;
            else if(j%2 == 0) {
                if(c == '|') {
                    if(j/2 > 0) sciana[i/2][j/2 - 1][1] = true;
                    if(j/2 < m) sciana[i/2][j/2][3] = true;
                }
            }
            else if(i%2 == 0) {
                if(c == '-') {
                    if(i/2 > 0) sciana[i/2 - 1][j/2][2] = true;
                    if(i/2 < n) sciana[i/2][j/2][0] = true;
                }
            }
            else {
                if(c == 'S') {
                    mx = i/2;
                    my = j/2;
                }
                if(c == 'R') {
                    rx = i/2;
                    ry = j/2;
                }
            }
        }
    }
}

/* void test_read() {
    cout << "Poczatkowy kierunek: " << start_dir << endl;
    cout << "Poczotkowa pozycja: " << mx << ", " << my << endl;
    cout << "Pozycja rakiety: " << rx << ", " << ry << endl;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cout << i << ", " << j << ": ";
            for(int k=0; k<4; k++) cout << (sciana[i][j][k] ? 'T' : 'N') << ' ';
            cout << endl;
        }
    }
} */

int dijkstra() {
    vector<pair<int, byte>> v1, v2;
    v1.reserve(MN*MN*4);
    v2.reserve(MN*MN*4);
    REP(i, n) REP(j, m) REP(k, 4) {
        d[i][j][k] = INF;
        odw[i][j][k] = false;
        v2.push_back({i*m + j, k});
    }
    REP(k, 4) if(k != start_dir){
        d[mx][my][k] = 1;
        v2.push_back({mx*m + my, k});
    }
    d[mx][my][start_dir] = 0;
    v1.push_back({mx*m + my, start_dir});

    while(true) {
        if(v1.empty()) {
            if(v2.empty()) break;
            auto fr = v2.back();
            while(!v2.empty() &&
                  d[v2.back().first / m][v2.back().first % m][v2.back().second] ==
                  d[fr.first / m][fr.first % m][fr.second]) {
                v1.push_back(v2.back());
                v2.pop_back();
            }
        }
        while(!v1.empty() && odw[v1.back().first / m][v1.back().first % m][v1.back().second]) v1.pop_back();
        if(v1.empty()) continue;

        auto u = v1.back();
        v1.pop_back();
        int x = u.first / m;
        int y = u.first % m;
        int dir = u.second;

        odw[x][y][dir] = true;

        if(x == rx && y == ry) return d[x][y][dir];

        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        REP(k, 4) {
            int nx = x+dx[k];
            int ny = y+dy[k];
            int dif = (k - dir + 4)%4;
            if(!sciana[x][y][k] && nx >= 0 && nx < n && ny >= 0 && ny < m && !odw[nx][ny][k]) {
                if(k == dir ||
                   (dif == 3 && sciana[x][y][dir] && !sciana[x][y][(dir+3)%4]) ||
                   (dif == 1 && sciana[x][y][dir] && sciana[x][y][(dir+3)%4] && !sciana[x][y][(dir+1)%4]) ||
                   (dif == 2 && sciana[x][y][dir] && sciana[x][y][(dir+3)%4] && sciana[x][y][(dir+1)%4] && !sciana[x][y][(dir+2)%4])) {
                    d[nx][ny][k] = d[x][y][dir];
                    v1.push_back({nx*m + ny, k});
                }

                else if(d[nx][ny][k] > d[x][y][dir] + 1) {
                    d[nx][ny][k] = d[x][y][dir] + 1;
                    v2.push_back({nx*m + ny, k});
                }
            }
        }
    }

    return -1;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    read();
    cout << dijkstra() << '\n';
}
