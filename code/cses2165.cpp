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
#define yes cout<<"YES"<<endll
#define no cout<<"NO"<<endll
#define pb push_back
// #define f(i,a,b) for( ll i = a; i < b ; i++ ) 
// #define fr(i,a,b) for(ll i = a; i >= b; i--)

const int MX = 1e5 + 10;
const ll mod = 1e9+7;      // 998244353
const ll INF = 1LL<<20;

template<typename T, typename V>
ostream& operator << (ostream& os, pair<T, V> pr)
{ os << "{" << pr.first << ", " << pr.second << "}";  return os; }

template<template<class, class> class Container, typename T>
ostream& operator<<(ostream& os, const Container<T, allocator<T>>& container)
{ os<<"[ "; for(auto el : container) os << el << " "; os<<"]"; return os; }


vector<pair<char, char>> vpp;
void hanoi(int disks, char source, char aux, char destiny)
{
    if (disks == 0)
        return;
    hanoi(disks-1, source, destiny, aux);
    vpp.pb({source, destiny});
    // cout << source << " " << destiny << endll;
    hanoi(disks-1, aux, source, destiny);
}
void solve()
{
    ll N;
    cin>>N;
    hanoi(N, '1', '2', '3');
    cout << vpp.size() << endll;
    for (auto [f, s] : vpp)
        cout << f << " " << s << endll;
}

int main() 
{
// #ifndef TEST
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    // time_t start, end;   
    // time(&start);
    speed;
    ll T = 1;
    // cin>>T;
    while (T--)
        solve();

    // time(&end);
    // double time_taken = double(end - start);
    // cout << "\nTime: " << fixed << time_taken << setprecision(5) << " sec " << endl;
// #ifdef LOCAL_TIME
//     cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
// #endif
    return 0;
}
