#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template<class T>
using minheap = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<class key, class value, class cmp = std::less<key>>
using ordered_map = tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;
//--------------------------------------------------------------------------------------------------------
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long int    
#define ld long double      
#define lf long float 
#define pb push_back 
#define fi first
#define se second
#define lz length() 
#define f(a,n) for(ll i=a;i<n;i++)  
#define endl "\n"   
#define iendl "\n", cout<<flush 
#define p(x) cout<<x<<endl;  
#define all(x) x.begin(),x.end()    
#define vll  vector <ll>
#define vpr vector <pair<ll,ll>>
const ll N = 1e5;
const ll M = 1e9 + 7;
//--------------------------------------------------------------------------------------------------------------------------------------------
#ifndef ONLINE_JUDGE
#define dbg(x) cerr<<#x<<" ";_print_(x);cerr<<endl;
#else
#define dbg(x)
#endif
//--------------------------------------------------------------------------------------------------------------------------------------------
// void _print_(ll t) { cerr << t; }
// void _print_(int t) { cerr << t; }
// void _print_(string t) { cerr << t; }
// void _print_(char t) { cerr << t; }
// void _print_(long double t) { cerr << t; }
// void _print_(double t) { cerr << t; }
// //--------------------------------------------------------------------------------------------------------------------------------------------
// template <class T, class V> void _print_(pair <T, V> p);
// template <class T, class V> void _print_(pair <T, V> p) { cerr << "{"; _print_(p.first); cerr << ","; _print_(p.second); cerr << "}"; }
// template <class T> void _print_(set <T> v);
// template <class T> void _print_(set <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
// template <class T, class V> void _print_(map <T, V> v);
// template <class T, class V> void _print_(map <T, V> v) { cerr << "[ "; for (auto i : v) { _print_(i); cerr << " "; } cerr << "]"; }
// template <class T> void _print_(multiset <T> v);
// template <class T> void _print_(multiset <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
// template <class T> void _print_(vector <T> v);
// template <class T> void _print_(vector <T> v) { cerr << "[ "; for (T i : v) { _print_(i); cerr << " "; } cerr << "]"; }
//-------------------------------------------------------------------------------------------------------------------------------------------------
ll binmul(ll a, ll b, ll MOD) { ll ans = 0; while (b) { if (b & 1) ans = (ans + a) % MOD; a = (a + a) % MOD; b >>= 1; } return ans; }
ll binexp(ll a, ll b, ll MOD) { ll ans = 1; while (b) { if (b & 1) ans = binmul(ans, a, MOD); a = binmul(a, a, MOD); b >>= 1; } return ans; }
//-------------------------------------------------------------------------------------------------------------
void soluchan()
{
    /* ip : xxxyy$ -> Accepted
       ip : xxxy$ -> Rejected
    */
    map <pair<int, char>, pair<char, int>> mp;
    mp[{0, 'x'}] = { 's',3 };
    mp[{0, 'y'}] = { 's',4 };

    mp[{1, '$'}] = { 's' , -2 };

    mp[{2, 'x'}] = { 's',6 };
    mp[{2, 'y'}] = { 's',7 };

    mp[{3, 'x'}] = { 's',3 };
    mp[{3, 'y'}] = { 's',4 };

    mp[{4, 'x'}] = { 'r',3 };
    mp[{4, 'y'}] = { 'r',3 };

    mp[{5, '$'}] = { 'r',1 };

    mp[{6, 'x'}] = { 'r',6 };
    mp[{6, 'y'}] = { 'r',7 };

    mp[{7, '$'}] = { 'r',3 };

    mp[{8, 'x'}] = { 'r',2 };
    mp[{8, 'y'}] = { 'r',2 };

    mp[{9, '$'}] = { 'r',2 };

    map <pair<int, char>, int> gp;
    gp[{0, 'X'}] = 1;
    gp[{0, 'Z'}] = 2;

    gp[{2, 'Z'}] = 5;

    gp[{3, 'Z'}] = 8;

    gp[{6, 'Z'}] = 9;

    map <int, pair<int, char>> rp;
    rp[1] = { 4,'X' }, rp[2] = { 4,'Z' }, rp[3] = { 2,'Z' };

    function <void(string)> check = [&](string ip){
        string st; st.push_back('0');
        int ptr = 0; bool temp = 0;
        int n = ip.length();
        ll ct = 0;
        cout << "stack          top_of_stack  I/P    Operation" << endl;
        while (ptr < n)
        {
            cout << st << " "; f(0, 15 - st.size()) cout << " ";
            auto t = st.back() - '0';
            if (!mp.count({ t,ip[ptr] })) break;
            if (t == 1 && ip[ptr] == '$')
            {
                cout << 1 << "            $        Accepted" << endl;
                // cout << "\nAccepted" << endl;
                temp = 1;
                break;
            }
            if (mp[{t, ip[ptr]}].first == 's') //Shift Operation
            {
                cout << t << "            " << ip[ptr] << "        ";
                cout << "shift" << " " << endl;
                st.push_back(ip[ptr]);
                st.pb(mp[{t, ip[ptr]}].second + '0');
                ptr++;
                // p(st)
                continue;
            }
            else                                //Reduce Operation
            {
                cout << t << "            " << ip[ptr] << "        ";
                cout << "reduce" << " " << endl;
                int pops = rp[mp[{t, ip[ptr]}].second].first;
                char g = rp[mp[{t, ip[ptr]}].second].second;
                while (pops--) { if (st.empty()) break; st.pop_back(); }
                if (st.empty()) break;
                auto y = st.back() - '0';
                st.push_back(g);
                st.push_back(gp[{ y, g}] + '0');


            }
            // p(st)
            ct++;
            if (ct > 15) break;
        }
        if (!temp) cout << "\nRejected" << endl;
    };

    string s; cin >> s;
    check(s);
    // p(s)



}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("err.txt", "w", stderr);
#endif

    int tc; cin >> tc;
    for (int e = 0; e < tc; e++)
    {
        soluchan();
    }
    return 0;
}