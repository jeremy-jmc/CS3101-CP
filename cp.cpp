
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

const int MX = 1e5 + 10;
const ll mod = 1e9 + 7; // 998244353
const ll INF = 1000000000000L; //0x7fffffff;

template <typename T, typename V>
ostream &operator<<(ostream &os, pair<T, V> pr)
{
    // os << "{" << pr.first << ", " << pr.second << "}";
    os << pr.first << " " << pr.second;
    return os;
}

template <template <class, class> class Container, typename T>
ostream &operator<<(ostream &os, const Container<T, allocator<T>> &container)
{
    os << "[ ";
    for (auto el : container)
        os << el << " ";
    os << "]";
    return os;
}

template <typename Tuple, size_t... Is>
void print_tuple_helper(const Tuple& tup, index_sequence<Is...>)
{
    ((cout << (Is == 0 ? "" : ", ") << get<Is>(tup)), ...);
}

template <typename... Ts>
void print_tuple(const tuple<Ts...>& tup)
{
    cout << "(";
    print_tuple_helper(tup, index_sequence_for<Ts...>{});
    cout << ")";
}

ll binpow(ll a, ll b, ll m) {
    a %= m;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

ll gs(ll base, ll exp)
{
    ll num = (binpow(base, (exp + 1)%mod, mod) - 1 + mod)%mod;  // avoid negatives
    ll denom_inverse = binpow(base - 1, mod - 2, mod);      // fermat
    return (num * denom_inverse) % mod;
}

void prefix_function(string& s) 
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) 
    {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        
        if (s[i] == s[j])   
            j++;
        pi[i] = j;
    }

    cout << n - pi[n-1] << endl;
}

void solve()
{
    ll N; cin >> N;

    vector<ll> A(N);
    ll res = -INF;
    bool all_neg = true;
    for (ll& a : A) 
    {
        cin >> a;
        all_neg &= (a < 0);
        res = max(res, a);
    }

    if (all_neg)
    {
        cout << res << endll;
        return;
    }

    ll sum_odd = 0, sum_even = 0;
    int i = 0;
    for (; i < N; i++)
    {
        if (i&1) sum_odd += max(A[i], 0LL);
        else sum_even += max(A[i], 0LL);
    }
    res = max(sum_odd, sum_even);
    cout << res << endll;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    speed;
    
    ll test = 1;
    cin >> test;
    while (test--)
        solve();

    return 0;
}

/*
La respuesta es la suma de algun subconjunto del arreglo

Considere el conjunto de particulas indexadas pares y el conjunto de particulas indexadas impares


-3 1 4 -1 5 -9
 1 2 3  4 5  6

 -3 1 9 -9
  1 2 3 4

*/