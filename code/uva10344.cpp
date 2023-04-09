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

const int MX = 1e5 + 10;
const ll mod = 1e9+7;      // 998244353
const ll INF = 1LL<<20;

template<typename T, typename V>
ostream& operator << (ostream& os, pair<T, V> pr)
{ os << "{" << pr.first << ", " << pr.second << "}";  return os; }

template<template<class, class> class Container, typename T>
ostream& operator<<(ostream& os, const Container<T, allocator<T>>& container)
{ os<<"[ "; for(auto el : container) os << el << " "; os<<"]"; return os; }

vector<ll> A(5);
bool flag;

int main() 
{
// #ifndef TEST
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
    speed;
    ll T = 1;
    // cin>>T;
    while (true)
    {
        flag = false;
        for (ll& ai: A) 
            cin>>ai;
        if (A[0] == 0 && A[1] == 0 && A[2] == 0 && A[3] == 0 && A[4] == 0)
            break;
        
        sort(all(A));       // ! si no se inicia ordenado no se llegan a explorar todas las permutaciones
        do {
            vector<ll> prev {A[0]};
            for (int i = 1; i < 5; i++)
            {
                vector<ll> aux;    
                for (ll& el : prev)
                {
                    if (i == 4)
                    {
                        if (el * A[i] == 23 || el + A[i] == 23 || el - A[i] == 23)
                        {
                            flag = true;
                            break;
                        }
                    }
                    else {
                        aux.pb(el * A[i]);
                        aux.pb(el - A[i]);
                        aux.pb(el + A[i]);
                    }
                }
                prev = aux;
            }
            if (flag)
                break;
        } while (next_permutation(all(A)));
        
        if (flag)
            cout << "Possible\n";
        else
            cout << "Impossible\n";
    }
    return 0;
}
