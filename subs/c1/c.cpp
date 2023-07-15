// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse4")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;

#define speed ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
#define endll '\n'
#define yes cout<<"Yes"<<endll
#define no cout<<"No"<<endll
#define pb push_back
#define f(i,a,b) for( ll i = a; i < b ; i++ ) 
#define fr(i,a,b) for(ll i = a; i >= b; i--)

const int MX = 2*1e5 + 10;
const ll mod = 998244353;      // 1e9+7

template<typename T, typename V>
ostream& operator << (ostream& os, pair<T, V> pr)
{ os << "{" << pr.first << ", " << pr.second << "}";  return os; }

template<template<class, class> class Container, typename T>
ostream& operator<<(ostream& os, const Container<T, allocator<T>>& container)
{ os<<"[ "; for(auto el : container) os << el << " "; os<<"]"; return os; }

template<
    template<class, class> class C1,
    template<class, class> class C2,
    typename T
>
bool container_equal(
    const C1<T, allocator<T>>& c1,
    const C2<T, allocator<T>>& c2
)
{
    if (c1.size() != c2.size())
        return false;
    auto itc1 = c1.begin();
    auto itc2 = c2.begin();

    for (; itc1 != c1.end(); ++itc1, ++itc2)
        if (*itc1 != *itc2)
            return false;
    return true;
}

const int sz = 2*1e5+10;
const ll INF = 1LL<<20;

void solve()
{
    string f, s;
    cin >> f >> s;
    vector<int> vf, vs;
    string line;

    stringstream input;
    input = stringstream(f);
    while (getline(input, line, ':'))
        vf.pb(stoi(line));

    input = stringstream(s);
    while (getline(input, line, ':'))
        vs.pb(stoi(line));
    
    
    if (container_equal(vf, vs))
    {
        cout << "24:00:00" << endll;
        return;
    }

    if (vf[2] > vs[2])
    {
        vs[2] += 60;
        vs[1]--;
    }
    if (vf[1] > vs[1])
    {
        vs[1] += 60;
        vs[0]--;
    }
    if (vf[0] > vs[0])
        vs[0] += 24;

    for (int i = 0; i <= 2; i++)
    {
        cout << setw(2) << right << setfill('0') << vs[i] - vf[i];
        if (i < 2)
            cout<<":";
    }
    cout << endll;
}

int main() 
{
    speed;

    ll T = 1;
    // cin>>T;
    while (T--)
        solve();

//     time(&end);
//     double time_taken = double(end - start);
//     cout << "\nTime: " << fixed << time_taken << setprecision(5) << " sec " << endl;
// #ifdef LOCAL_TIME
//     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
// #endif
    return 0;
}