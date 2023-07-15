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

// template<typename T, typename V>
// ostream& operator << (ostream& os, pair<T, V> pr)
// { os << "{" << pr.first << ", " << pr.second << "}";  return os; }

// template<template<class, class> class Container, typename T>
// ostream& operator<<(ostream& os, const Container<T, allocator<T>>& container)
// { os<<"[ "; for(auto el : container) os << el << " "; os<<"]"; return os; }

// template<
//     template<class, class> class C1,
//     template<class, class> class C2,
//     typename T
// >
// bool container_equal(
//     const C1<T, allocator<T>>& c1,
//     const C2<T, allocator<T>>& c2
// )
// {
//     if (c1.size() != c2.size())
//         return false;
//     auto itc1 = c1.begin();
//     auto itc2 = c2.begin();

//     for (; itc1 != c1.end(); ++itc1, ++itc2)
//         if (*itc1 != *itc2)
//             return false;
//     return true;
// }

// bool isPrime(int n) {
//     if(n <= 1)
//         return false;
//     for(int i = 2; i <= sqrt(n); i++) {
//         if(n % i == 0)
//             return false;
//     }
//     return true;
// }

// bool mod_(ll num) { 
//     if (num > mod)
//         return num - mod;
//     return num;
// }


vector<ll> A;
vector<bool> vis;

bool bit_traverse(ll obj, ll current, ll level=0)
{
    // cout << "\t" << obj << "  " << current << endll;
    
    if (current == obj)
        return true;
    if (current > obj)
        return false;
    if (level == 9)
        return false;
    else
    {
        for (int i = 0; i < A.size(); i++)
        {   // O(20)
            if (!vis[i] && 
                (A[i] & ll(1LL<<level))         // check if element has on the level-th bit
            )
            {
                vis[i] = true;
                // for (size_t j = 0; j < level; j++)
                //     cout << "\t";
                // for (ll j = 0; j < A.size(); j++)
                // {
                //     if (!vis[j]) cout << A[j] << " ";
                //     else cout << "x ";
                // }   cout << " -> " << obj << " - " << A[i] << " = " << obj - A[i] << endll;
                
                bool flag = false;
                if (obj - A[i] >= 0)
                    flag = bit_traverse(obj-A[i], current, level+1);
                if (flag)
                    return true;    

                flag = bit_traverse(obj, current, level+1);
                if (flag)
                    return true;
                
                vis[i] = false;
            }
        }
        return false;
        // O(20*2*2^11)
    }
    return false;
}

void solve()
{
    ll N, P;
    cin >> N >> P;

    A = vector<ll>(P);
    vis = vector<bool>(P, false);

    for (ll i = 0; i < P; i++)
        cin >> A[i];

    if (bit_traverse(N, 0LL))
        cout << "YES" << endll;
    else
        cout << "NO" << endll;
}   // 0 <= N <= 1000 |  1 <= P <= 20

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
    cin>>T;
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

/*
*/