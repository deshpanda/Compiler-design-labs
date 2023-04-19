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
vector<string>res;
int j=0;
vector<string>D = {"A","B","C","D","E","F","G","H","I","J","K"};
void generate(string s){
    if (s.length() == 0) return;
    if (s.length() == 1) return;
    bool flag = false;
    bool flag2 = false;
    string temp = "";
    string k = "";
    string t1 = "";string t2 = "";
    for(auto it: s){
        if (flag == false&&flag2==false)t1 += it;
        if (flag2 == true)t2 += it;
        if (it == ')'){
            flag2 = true;
            flag = false;
        }
        if(flag == true){
            temp += it;
        }
        if(it == '('){
           flag = true;
        }

    }
    if(temp != ""){
        cout<<temp<<endl;
        generate(temp);
        s = t1.substr(0, t1.size() - 1) + res[res.size() - 1][0] + t2;
    }
    temp="";
    k="";
    if(s[0]=='-'){
        string x=D[j];
        temp=x+'='+'-'+s[1];
        res.push_back(temp);
        s=x+s.substr(2,s.size()-2);
        j++;
        generate(s);
        return;
    }
    for(int i=0;i<s.length();i++){
        if(i>0&&(s[i-1]=='='||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='+'||s[i-1]=='-')&&s[i]=='-'){
            string x=D[j];
            temp=x+'='+'-'+s[i+1];
            res.push_back(temp);
            k=s.substr(0,i)+x;
            if(s.length()>i+2){
                k+=s.substr(i+2,s.size()-i-2);
            }
            s=k;
            j++;
            generate(s);
            return;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='%'){
            string x=D[j];
            temp=x+'='+s[i-1]+s[i]+s[i+1];
            res.push_back(temp);
            k=s.substr(0,i-1)+x;
            if(s.length()>i+2){
                k+=s.substr(i+2,s.size()-i-2);
            }
            s=k;
            j++;
            generate(s);
            return;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='/'){
            string x=D[j];
            temp=x+'='+s[i-1]+s[i]+s[i+1];
            res.push_back(temp);
            k=s.substr(0,i-1)+x;
            if(s.length()>i+2){
                k+=s.substr(i+2,s.size()-i-2);
            }
            s=k;
            j++;
            generate(s);
            return;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='*'){
            string x=D[j];
            temp=x+'='+s[i-1]+s[i]+s[i+1];
            res.push_back(temp);
            k=s.substr(0,i-1)+x;
            if(s.length()>i+2){
                k+=s.substr(i+2,s.size()-i-2);
            }
            s=k;
            j++;
            generate(s);
            return;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='+'){
            string x=D[j];
            temp=x+'='+s[i-1]+s[i]+s[i+1];
            res.push_back(temp);
            k=s.substr(0,i-1)+x;
            if(s.length()>i+2){
                k+=s.substr(i+2,s.size()-i-2);
            }
            s=k;
            j++;
            generate(s);
            return;
        }
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='-'){
            string x=D[j];
            temp=x+'='+s[i-1]+s[i]+s[i+1];
            res.push_back(temp);
            k=s.substr(0,i-1)+x;
            if(s.length()>i+2){
                k+=s.substr(i+2,s.size()-i-2);
            }
            s=k;
            j++;
            generate(s);
            return;
        }
    }
    if(s[1]=='=')
     res.push_back(s);
}
void show(){
    for(auto it:res){
        for(int i=0;i<it.length();i++)
            cout<<it[i]<<" ";
        cout<<endl;
    }
}
void go(){
    string s;
    cout<<"Enter an valid expression(w/o spaces):-"<<endl;
    int f=1;
    cin>>s;
    int l=0;
    vector<string>vs={"+","-","/","%","*"};
    // double operators
    for(int i=0;i<s.size();i++){
        char c=s[i];
        string h="";
        h+=c;
        auto it=find(vs.begin(),vs.end(),h);
        if(it!=vs.end()){
        l++;
        }
        else{
            l=0;
        }
        if(l==2){
            f=0;
            // cout<<f<<endl;
            break;
        }
    }
    // double terminal
    vector<string>vk={"a","b","c","d","e","f"};
    for(int i=0;i<s.size();i++){
        char c=s[i];
        string h="";
        h+=c;
        auto it=find(vk.begin(),vk.end(),h);
        if(it!=vk.end()){
            l++;
        }
        else{
            l=0;
        }
        if(l==2){
            f=0;
            break;
        }
    }
    // Bracket checker
    int op=0;
    int cl=0;
    for(int i=0;i<s.size();i++)
    {
        if(op==1){
        if(s[i]==')'){
            op--;

        }
        else if(s[i]=='('){
            f=0;
            break;
        }
        }
        else if(cl==1){
            if(s[i]=='('){
                cl--;

            }
            else if(s[i]==')'){
                f=0;
                break;
            }
        }
        else{
            if(s[i]==')'){
                cl++;
            }
            else if(s[i]=='('){
                op++;
            }
        }

    }
    vector<string>vp={"(","+","/","%","*","="};
    if(op>0 || cl>0){
        f=0;
    }
    char cp=s[s.size()-1];
        string hp="";
        hp+=cp;
    auto it=find(vp.begin(),vp.end(),hp);

    if(it!=vp.end()){
        f=0;
    }
    vector<string>vl={"(",")","+","/","%","*","="};
    char cm=s[0];
        string hm="";
        hm+=cm;
    auto ip=find(vl.begin(),vl.end(),hm);
    if(ip!=vl.end()){
        f=0;
    }
    if(f){
        generate(s);
        show();
        res.clear();
    }
    else{
        cout<<"Not a valid expression";
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

// y=-a*c
// y=-a+(a+b+c)
// y=a+b-c*d/e
// y=-a*b+c
// y=(a+b+c
// y=b++c
