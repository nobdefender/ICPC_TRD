using namespace std;

// DEFINES
#define precision(x) cout << fixed << setprecision(x);
#define fast cin.tie(0); ios::sync_with_stdio(0)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
// #define nl endl
#define nl "\n"
#define sp " "
#define yes "Yes"
#define no "No"
#define int long long

// CONSTANTS
const int INF = 1e18;
// const int MOD = 1e9 + 7;
// const int MOD = 998244353;



// FSTREAMS
ifstream in("input.txt");
ofstream out("output.txt");



// RANDOM
const int RMIN = 1, RMAX = 1e9;

mt19937_64 reng(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<mt19937_64::result_type> dist(RMIN, RMAX);



// CUSTOM HASH
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
// USAGE EXAMPLES:
//
// unordered_set<long long, custom_hash> safe_set;
// unordered_map<long long, int, custom_hash> safe_map;
// gp_hash_table<long long, int, custom_hash> safe_hash_table;
//
// for pairs might be used like `3 * a + b` or `a ^ (b >> 1)`


// int128 operators
istream& operator>>(istream& in, __int128& a) {
    string s; in >> s;
    a = 0;
    if (s == "0") return in;
    for (short i = (s[0] == '-'); i < s.size(); i++)
        a = a * 10 + (s[i] - '0');
    if (s[0] == '-') a *= -1;
    return in;
}
istream& operator>>(istream& in, unsigned __int128& a) {
    string s; in >> s;
    a = 0;
    if (s == "0") return in;
    for (short i = 0; i < s.size(); i++)
        a = a * 10 + (s[i] - '0');
    return in;
}
ostream& operator<<(ostream& out, __int128 a) {
    __int128 b = a;
    if (b < 0)out << '-', b *= -1;
    string s;
    do {
        s.push_back(b % 10 + '0');
        b /= 10;
    } while (b > 0);
    for (int i = s.size() - 1; i >= 0; i--)
        out << s[i];
    return out;
}
ostream& operator<<(ostream& out, unsigned __int128 a) {
    unsigned __int128 b = a;
    string s;
    do {
        s.push_back(b % 10 + '0');
        b /= 10;
    } while (b > 0);
    for (int i = s.size() - 1; i >= 0; i--)
        out << s[i];
    return out;
}
string to_string(__int128 a){
    string s;
    bool bo = 0;
    if (a < 0) a *= -1, s.push_back('-'), bo = 1;
    do {
        s.push_back(a % 10 + '0');
        a /= 10;
    } while(a > 0);
    for(int i = 0; i < (s.size() - bo) / 2; i++)
        swap(s[i + bo], s[s.size() - i - 1]);
    return s;
}
string to_string(unsigned __int128 a){
    string s;
    do {
        s.push_back(a % 10 + '0');
        a /= 10;
    } while(a > 0);
    for(int i = 0; i < s.size() / 2; i++)
        swap(s[i], s[s.size() - i - 1]);
    return s;
}
__int128 stolll(string s){
    __int128 a = 0;
    if(s == "")return a;
    for (short i = (s[0] == '-'); i < s.size(); i++)
        a = a * 10 + (s[i] - '0');
    if (s[0] == '-') a *= -1;
    return a;
}
unsigned __int128 stoulll(string s){
    unsigned __int128 a = 0;
    if(s == "")return a;
    for (short i = 0; i < s.size(); i++)
        a = a * 10 + (s[i] - '0');
    return a;
}

// ENTRANCE
signed main() {
    precision(15);
    fast;
    prepr();
    int t = 1;
    cin >> t;
    while (t--) solve();
}