#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

inline tuple<int, int> count_letters(const string& str) {
    int lh = 0, lq = 0;
    for(char l: str) {
        if(l == 'H') lh++;
        else lq++;
    }
    return make_tuple(lh, lq);
}

inline int count_h_prefix(const string& str) {
    int c = 0;
    for(char l: str) {
        if(l == 'H') c++;
        else break;
    }
    return c;
}

inline void output_no() {
    cout << "No\n";
    exit(0);
}

bool check_pattern(const string& str, int pos, int l) {
    int n = str.size();
    if(pos+l > n) return false;
    int next = 0;
    for(int i = pos; i < pos+l; i++) {
        if(next >= n) return false;
        if(str[i] == 'H') {
            if(str[next++] != 'H') return false;
        }
        else {
            for(int j = pos; j < pos+l && next < n; j++) {
                if(next >= n) return false;
                if(str[next++] != str[j]) return false;
            }
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;

    int lh, lq;
    tie(lh, lq) = count_letters(str);

    if(lq == 0) {
        cout << "Yes\n";
        return 0;
    }

    int org_lq = sqrt(lq);
    if(org_lq * org_lq != lq) {
        output_no();
    }

    if(lh % (org_lq + 1) != 0) {
        output_no();
    }
    int org_lh = lh / (org_lq + 1);

    int org_len = org_lh + org_lq;
    int h_pref = count_h_prefix(str);
    if(h_pref % 2 != 0) {
        output_no();
    }

    if(!check_pattern(str, h_pref/2, org_len)) output_no();
    cout << "Yes\n";
}
