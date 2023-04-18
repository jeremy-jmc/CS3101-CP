
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> plli;

#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define sz(x) ((int)(x).size())
#define endll '\n'
#define yes cout << "YES" << endll
#define no cout << "NO" << endll
#define pb push_back
// #define f(i,a,b) for( ll i = a; i < b ; i++ )
// #define fr(i,a,b) for(ll i = a; i >= b; i--)

const int MX = 1e5 + 10;
const ll mod = 1e9 + 7; // 998244353
const ll INF = 1LL << 20;

template <typename T, typename V>
ostream &operator<<(ostream &os, pair<T, V> pr)
{
    os << "{" << pr.first << ", " << pr.second << "}";
    return os;
}
xor
template <template <class, class> class Container, typename T>
ostream &operator<<(ostream &os, const Container<T, allocator<T>> &container)
{
    os << "[ ";
    for (auto el : container)
        os << el << " ";
    os << "]";
    return os;
}

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

// ll binpow(ll a, int b) {
//     // return pow(a, b);
//     ll res = 1;
//     while (b > 0) {
//         if (b & 1)
//             res = res * a;
//         a = a * a;
//         b >>= 1;
//     }
//     return res;
// }

void solve()
{
}

int main()
{
#ifndef TEST
    freopen("input.in", "r", stdin);
    freopen("output.out", "w", stdout);
#endif
    // time_t start, end;
    // time(&start);
    speed;
    ll T = 1;
    // cin >> T;
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