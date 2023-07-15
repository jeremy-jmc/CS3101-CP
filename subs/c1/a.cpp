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

const int sz = 2*1e5+10;
const ll INF = 1LL<<20;

void solve()
{
    ll N; 
    cin>>N;
    vector<ll> bs(N);
    for(ll& b: bs) cin>>b;
    sort(all(bs));
    // cout<<bs<<endll;
    int i = 0, ci;
    for (; i < bs.size(); i++)
    {
        int j = i+1;
        while (j < bs.size())
        {
            if (bs[j] - bs[j-1] > 1)
                break;
            j++;
        }
        j--;

        if (j - i > 1)
        {
            cout<<bs[i]<<"-"<<bs[j]<<" ";
            i = j;
        }
        else
            cout<<bs[i]<<" ";   
    }   cout<<endll;
    
}

int main() 
{
    speed;

    ll T = 1;
    // cin>>T;
    while (T--)
        solve();

    return 0;
}