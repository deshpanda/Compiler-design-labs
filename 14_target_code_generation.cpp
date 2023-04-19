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
void go(){
	string s;
	cin >> s;
	char fir = s[0];
	s = s.substr(2, s.size());
	map<char, ll> mpp;
	if (s.back() > 'z' || s.back() < 'a') {
		cout << "Invalid" << nl;
		return;
	}
	rep(i, s.size()) {
		if (s[i] >= 'a' && s[i] <= 'z') mpp[s[i]]++;
	}
	for (auto it : mpp) {
		if (it.ss >= 2) {
			cout << "Invalid" << nl;
			return;
		}
	}
	for (ll i = 1; i < s.size(); i++) {
		if (s[i] <= 'z' && s[i] >= 'a') {
			if (s[i - 1] <= 'z' && s[i - 1] >= 'a') {
				cout << "Invalid" << nl;
				return;
			}
		}
		if (s[i] > 'z' || s[i] < 'a') {
			if (s[i - 1] > 'z' || s[i - 1] < 'a') {
				cout << "Invalid" << nl;
				return;
			}
		}
	}
	int op = 4;
	int cc = 0;
	while (s.size() > 1) {
		if (op == 4) {
			string temp;
			rep(i, s.size()) {
				if (s[i] == '/') {
					int a = -1, b = -1;
					a = s[i - 1] - '0';
					if (s[i - 1] < '0' || s[i - 1] > '4') {
						cout << "MOV R" << cc << ", " << s[i - 1] << nl;
						a = cc;
						cc++;
					}
					if (s[i + 1] < '0' || s[i + 1] > '4') {
						b = cc;
						cout << "MOV R" << cc << ", " << s[i + 1] << nl;
						cc++;
					}
					else b = s[i + 1] - '0';
					temp = s.substr(0, i - 1);
					temp.pb(a + '0');
					temp += s.substr(i + 2, s.size());
					cout << "DIV R" << a << ", R" << b << nl;
					s = temp;
					break;
				}
			}
			if (temp.size() == 0)
				op = 3;
		}
		else if (op == 3) {
			string temp;
			rep(i, s.size()) {
				if (s[i] == '*') {
					int a = -1, b = -1;
					a = s[i - 1] - '0';
					if (s[i - 1] < '0' || s[i - 1] > '4') {
						cout << "MOV R" << cc << ", " << s[i - 1] << nl;
						a = cc;
						cc++;
					}
					if (s[i + 1] < '0' || s[i + 1] > '4') {
						b = cc;
						cout << "MOV R" << cc << ", " << s[i + 1] << nl;
						cc++;
					}
					else b = s[i + 1] - '0';
					temp = s.substr(0, i - 1);
					temp.pb(a + '0');
					temp += s.substr(i + 2, s.size());
					cout << "MUL R" << a << ", R" << b << nl;
					s = temp;
					break;
				}
			}
			if (temp.size() == 0)
				op = 2;
		}
		else if (op == 2) {
			string temp;

			rep(i, s.size()) {
				if (s[i] == '+') {
					int a = -1, b = -1;
					a = s[i - 1] - '0';
					if (s[i - 1] < '0' || s[i - 1] > '4') {
						cout << "MOV R" << cc << ", " << s[i - 1] << nl;
						a = cc;
						cc++;
					}
					if (s[i + 1] < '0' || s[i + 1] > '4') {
						b = cc;
						cout << "MOV R" << cc << ", " << s[i + 1] << nl;
						cc++;
					}
					else b = s[i + 1] - '0';
					temp = s.substr(0, i - 1);
					temp.pb(a + '0');
					temp += s.substr(i + 2, s.size());
					cout << "ADD R" << a << ", R" << b << nl;
					s = temp;
					break;
				}
			}
			if (temp.size() == 0)
				op = 1;
		}
		else if (op == 1) {
			string temp;
			rep(i, s.size()) {
				if (s[i] == '-') {
					int a = -1, b = -1;
					a = s[i - 1] - '0';
					if (s[i - 1] < '0' || s[i - 1] > '4') {
						cout << "MOV R" << cc << ", " << s[i - 1] << nl;
						a = cc;
						cc++;
					}
					if (s[i + 1] < '0' || s[i + 1] > '4') {
						b = cc;
						cout << "MOV R" << cc << ", " << s[i + 1] << nl;
						cc++;
					}
					else b = s[i + 1] - '0';
					temp = s.substr(0, i - 1);
					temp.pb(a + '0');
					temp += s.substr(i + 2, s.size());
					cout << "SUB R" << a << ", R" << b << nl;
					s = temp;
					break;
				}
			}
			if (temp.size() == 0)
				op = 0;
		}
		else {
			break;
		}
	}
	cout << "MOV " << fir << ", R" << s[0] << nl;
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
