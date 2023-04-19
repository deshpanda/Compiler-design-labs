#include <bits/stdc++.h>
using namespace std;


void go(){

    map<pair<int, char>, pair<char, int>> mpp;
    mpp[{0, '('}] = { 's',3 };
    mpp[{0, 'i'}] = { 's',1 };

    mpp[{1, '('}] = { 'r',2 };
    mpp[{1, ')'}] = { 'r',2 };
    mpp[{1, '$'}] = { 'r',2 };
    mpp[{1, 'i'}] = { 'r',2 };

    mpp[{2, '$'}] = { 's',-2 };

    mpp[{3, '('}] = { 's',3 };
    mpp[{3, 'i'}] = { 's',1 };

    mpp[{4, ')'}] = { 's',5 };

    mpp[{5, '('}] = { 'r',0 };
    mpp[{5, ')'}] = { 'r',0 };
    mpp[{5, '$'}] = { 'r',0 };
    mpp[{5, 'i'}] = { 'r',0 };

    map<pair<int, char>, int> gpp;
    gpp[{0, 'S'}] = 2;
    gpp[{3, 'S'}] = 4;

    map<int, pair<int, char>> rpp;
    rpp[0] = { 6,'S' };
    rpp[2] = { 2,'S' };

    function<void(string)> check = [&](string ip){
        string st;
        st.push_back('0');
        int n = ip.size();
        int cnt = 0;
        int ptr = 0; bool temp = false;
        cout<<"stack            top        i/p op"<<endl;
        while (ptr < n){
            cout<<st<<" ";
            for (int i = 0; i < 15 - st.size(); i++) cout<<" ";
            auto t = st.back() - '0';
            if (!mpp.count({t, ip[ptr]})) break;
            if (t == 2 && ip[ptr] == '$'){
                cout<<2<<"          "<<"$"<<"             Accepted"<<endl;
                temp = true;
                break;
            }
            if (mpp[{t, ip[ptr]}].first == 's'){
                cout<<t<<"     "<<ip[ptr]<<"    "<<"shift"<<"  "<<endl;
                st.push_back(ip[ptr]);
                st.push_back(mpp[{t, ip[ptr]}].second - '0');
                ptr++;
                continue;
            }
            else{
                cout<<t<<"    "<<ip[ptr]<<"    "<<"reduce"<<"    "<<endl;
                int pops = rpp[mpp[{t, ip[ptr]}].second].first;
                char g = rpp[mpp[{t, ip[ptr]}].second].second;
                while(pops--){if(st.empty()) break; st.pop_back();}
                if (st.empty()) break;
                auto y = st.back() - '0';
                st.push_back(g);
                st.push_back(gpp[{y, g}] - '0');
            }

            cnt++;
            if (cnt > 15)break;
        }
        if (!temp) cout<<"Rejected"<<endl;
    };
    string s;
    cin>>s;
    check(s);
}


int main(){
    #ifndef ONLINE_JUDGE
        freopen("in.txt", "r", stdin);
        freopen("out.txt", "w", stdout);
    #endif
    go();
    return 0;
}