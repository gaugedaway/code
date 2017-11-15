typedef long long ll;
inline ll gcc(ll a, ll b) {
    while(b) {
        a %= b;
        a ^= b;
        b ^= a;
        a ^= b;
    }
    return a;
}

int main(int argc, char** argv) {
    return gcc(argv[1][0] - '0', argv[1][1] - '0');
}
