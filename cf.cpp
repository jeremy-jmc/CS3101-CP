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
{ 
    os << "{" << pr.first << ", " << pr.second << "}"; 
    return os;
}

template<template<class, class> class Container, typename T>
void PRINT(const Container<T, allocator<T>>& container)
{ cout<<"[ "; for(auto el : container) cout << el << " "; cout<<"]\n"; }

// template<class T>
// void PRINT(multiset<T>& ms) { cout<<"[ "; copy(all(ms), ostream_iterator<ll>(cout, " ")); cout<<"]";}

const int sz = 2*1e5+10;
const ll INF = 1LL<<20;

void solve()
{
    ll N, M;
    cin>>N>>M;
    vector<ll> H(N), T(M);
    for (ll& hi: H) cin >> hi;      // price of each ticket
    for (ll& ti: T) cin >> ti;      // max price for each customer

    sort(all(H));
    // sort(all(T));

    PRINT(H);
    PRINT(T);

    ll i = size(H) - 1, j = size(T) - 1;
    for (ll& hi : T)
    {
        cout << *lower_bound(all(T), hi) << " ";
    }
}

int main() 
{
#ifndef TEST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
//     time_t start, end;
//     time(&start);

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