#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
using namespace chrono;
typedef long long int ll;
#ifndef ONLINE_JUDGE
#define debug(x) cerr<<#x<<" ";_print_(x);cerr<<endl;
#else
#define debug(x)
#endif
void _print_(ll t) { cerr << t; }
void _print_(int t) { cerr << t; }
void _print_(string t) { cerr << t; }
void _print_(char t) { cerr << t; }
void _print_(long double t) { cerr << t; }
void _print_(double t) { cerr << t; }
template <class T, class V> void _print_(pair <T, V> p);
template <class T, class V> void _print_(pair <T, V> p) { cerr << "{"; _print_(p.first); cerr << ","; _print_(p.second); cerr << "}"; }
template <class T> void _print_(set <T> v);
template <class T> void _print_(set <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T, class V> void _print_(map <T, V> v);
template <class T, class V> void _print_(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T> void _print_(multiset <T> v);
template <class T> void _print_(multiset <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
template <class T> void _print_(vector <T> v);
template <class T> void _print_(vector <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
#define endl "\n";
#define ceil(x, y) x / y + (x % y != 0)
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define MOD 1000000007
#define MOD1 998244353
#define PI 3.141592653589793238462
// template<class T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// template<class T> using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
vector<ll> sieve(int n) { int* arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) { vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1; } return vect; }
ll gcd(ll a, ll b) { return b == 0 ? a : gcd(b, a % b); }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
vector<ll> factors(ll n){ vector<ll> a; while(n % 2 == 0){ a.push_back(2); n /= 2; } for (int i = 3; i * i <= n; i+=2){ while (n % i == 0){ a.push_back(i); n /= i; } } if (n > 2){ a.push_back(n); } return a; }
ll nCr(ll n, ll r) { r = max(r, n - r);ll ans = 1;for (ll i = n; i > r; i--) { ans *= i;ans /= (n - i + 1); }return ans; }
ll modpow(ll x, ll n, ll m) { if (n == 0) return 1 % m;ll u = modpow(x, n / 2, m);u = (u * u) % m;if (n % 2 == 1) u = (u * x) % m;return u; }//x^n mod m
ll expo(ll a, ll b, ll mod) { ll res = 1; while (b > 0) { if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1; } return res; }
ll mminvprime(ll a, ll b) { return expo(a, b - 2, b); }
ll mod_add(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a + b) % m) + m) % m; }
ll mod_mul(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a * b) % m) + m) % m; }
ll mod_sub(ll a, ll b, ll m) { a = a % m; b = b % m; return (((a - b) % m) + m) % m; }
ll mod_div(ll a, ll b, ll m) { a = a % m; b = b % m; return (mod_mul(a, mminvprime(b, m), m) + m) % m; }  //only for prime m
vector<string> a(1e5);
map<char, int> fir_vis, fol_vis;
map<char, vector<string>> mpp;
map<char, set<char>> fir, fol;
char eps = '#';
void cal_first(char c){
    fir_vis[c] = 1;
    for (auto &it: mpp[c]){

        if (!mpp.count(it[0])){
            fir[c].insert(it[0]);
            continue;
        }

        if (!fir_vis[it[0]]) cal_first(it[0]);

        for (auto& j: fir[it[0]]){
            if (j == eps){
                int i;
                for (i = 1; i < it.size(); i++){
                    if (!mpp.count(it[i])){
                        fir[c].insert(it[i]);
                        break;
                    }
                    if (!fir_vis[it[i]]) cal_first(it[i]);
                    for (auto& k: fir[it[i]]){
                        if (k != eps){
                            fir[c].insert(k);
                        }
                    }
                    if (fir[it[i]].find(eps) == fir[it[i]].end()) break;
                }
                if (i == it.size()) fir[c].insert(j);
                continue;
            }
            fir[c].insert(j);
        }
    }
}
void cal_fol(char c){
    fol_vis[c] = 1;
    for (int i = 0; i < a.size(); i++){
        string s = a[i];
        for (int j = 3; j < s.size(); j++){
            if (s[j] == c){
                int ind = j + 1;
                if (ind == s.size()){
                    if (!fol_vis[s[0]]) cal_fol(s[0]);
                    if (s[0] == c) fol[s[0]].insert('$');
                    for (auto& k: fol[s[0]]) fol[c].insert(k);
                }
                else{
                    if (!mpp.count(s[ind])){
                        fol[c].insert(s[ind]);
                        continue;
                    }
                    for (auto& k: fir[s[ind]]){
                        if (k == eps){
                            int jj = j + 1;
                            for (int jj = j + 1; jj < s.size(); jj++){
                                if (!mpp.count(s[jj])){
                                    fol[c].insert(s[jj]);
                                    break;
                                }
                                for (auto& ch: fir[s[jj]]){
                                    if (ch != eps) fol[c].insert(ch);
                                }
                                if (fir[s[jj]].find(eps) == fir[s[jj]].end()) break;
                            }
                            if (jj == s.size()){
                                if (s[0] == c) fol[s[0]].insert('$');
                                if (!fol_vis[s[0]]) cal_fol(s[0]);
                                for (auto& k: fol[s[0]]) fol[c].insert(k);
                            }
                            continue;
                        }
                        fol[c].insert(k);
                    }
                }
            }
        }
    }
}
void go(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
        string s = a[i].substr(3, a[i].size());
        mpp[a[i][0]].push_back(s);
    }

    for (auto& it: a){
        if (!fir_vis[it[0]]) cal_first(it[0] );
    }

    for (auto& it: fir){
        cout<<it.first<<" -- ";
        for (auto& i: it.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

    fol[a[0][0]].insert('$');
    for (auto& it: a){
        if (!fol_vis[it[0]]) cal_fol(it[0]);
    }

    for (auto& it: fol){
        cout<<it.first<<" -- ";
        for (auto& i: it.second){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif
    auto start1 = high_resolution_clock::now();
    go();
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1 - start1);
    cerr << "Time: " << duration.count() / 1000 << endl;
    return 0;
}
