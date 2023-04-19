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
bool isPunctuator(char ch) {
	string cha = " +-*/,;><=()[]{}&|";
	for (auto it : cha) {
		if (it == ch) {
			return true;
		}
	}
	return false;
}

bool valididentifer(string sub) {
	string temp = "0123456789";
	for (auto it : temp) {
		if (it == sub[0]) return false;
	}
	if (isPunctuator(sub[0])) return false;
	return true;
}

bool iskeyword(string sub) {
	vector<string> v = {"if", "else", "while", "break", "do", "continue", "int", "double", "float", "return", "char", "case", "sizeof", "long", "short", "typedef", "switch", "unsigned", "static", "goto", "struct", "void"};
	for (auto it : v) {
		if (it == sub) {
			return true;
		}
	}
	return false;
}

bool isInteger(string sub) {
	string num = "-0123456789";
	for (auto it : sub) {
		int check = 0;
		for (auto i : num) {
			if (i == it) {
				check = 1;
				break;
			}
		}
		if (check) continue;
		return false;
	}
	return true;
}

bool isReanumber(string str) {
	int i, len = str.size();
	bool flag = false;

	if (len == 0)
		return (false);
	for (i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.')
			return (false);
		if (str[i] == '.')
			flag = true;
	}
	return flag;
}

void go(){
    vector<string> v;
	string s;
	int cnt = 0;
	while (getline(cin, s)) {
		v.push_back(s);
	}
    debug(v);
    function<bool(char)> isOperator = [](char ch){
        string op = "+-*/><=";
        for (auto it : op) {
            if (it == ch) return true;
        }
        return false;
    };
	int c = 0;
	for (auto str : v) {
		if (c) {
			if (str.size() >= 2 && str[str.size() - 2] == '*' && str.back() == '/') {
				c = 0;
			}
			continue;
		}
		if (str.size() >= 2) {
			if (str[0] == '/' && str[1] == '/') {
				continue;
			}
			if (str[0] == '/' && str[1] == '*') {
				c = 1;
				continue;
			}
		}
		int left = 0, right = 0;
		int len = str.size();
		while (right <= len && left <= right) {
			if (isPunctuator(str[right]) == false) {
				right++;
			}
			if (isPunctuator(str[right]) && left == right) {
				if (isOperator(str[right])) {
					cnt++;
					cout << str[right] << " IS AN OPERATOR" << endl;
				}
				right++;
				left = right;
			}
			else if (isPunctuator(str[right]) && left != right || (right == len && left != right)) {
				string sub = str.substr(left, right - left);
				if (iskeyword(sub)) {
					cout << sub << " IS A KEYWORD" << endl;
					cnt++;
				}
				else if (isInteger(sub)) {
					cnt++;
					cout << sub << " IS AN INTEGER" << endl;
				}
				else if (isReanumber(sub)) {
					cnt++;
					cout << sub << " IS A REAL NUMBER" << endl;
				}
				else if (valididentifer(sub) && isPunctuator(str[right - 1]) == false) {
					cnt++;
					cout << sub << " IS A VALID IDENTIFIER" << endl;
				}
				else if (valididentifer(sub) == false && isPunctuator(str[right - 1]) == false) {
					cout << sub << " IS NOT A VALID IDENTIFIER" << endl;
				}
				left = right;
			}
		}
		if (str.back() == ';') {
			cnt++;
			cout << "; IS A SEPERATOR" << endl;
		}
	}
	cout << "TOTAL NUMBER OF TOKENS: " << cnt << endl;    
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