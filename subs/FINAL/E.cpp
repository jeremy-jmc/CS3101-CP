
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
    ll A, B;
    cin >> A >> B;
    cout << A + B << endll;
}

int main()
{
    speed;
    
    ll test = 1;
    cin >> test;
    while (test--)
        solve();

    return 0;
}

/*
TEMA: GREEDY
COMPLEJIDAD: 
    O(1)
IDEA: 
    La idea se encuentra en que cualquier movimiento que haga el primero A o B, el segundo jugador haga B o A respectivamente
    para que el primero se quede sin movimientos posibles en la tercera jugada.
*/
