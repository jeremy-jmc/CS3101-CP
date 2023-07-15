
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

const int mx = int(1e4) + 10;
ll D[mx];
vector<pair<ll, ll>> P[mx];
bool visited[mx];
vector<pair<ll, ll>> adj[mx];
ll N, M;

void dijkstra(int src)
{
    for (int i = 0; i < N; i++)
    {
        D[i] = INF; 
        P[i] = vector<pair<ll,ll>>();
    }

    priority_queue<
        pair<ll, ll>, 
        vector<pair<ll, ll>>, 
        greater<pair<ll, ll>>
    > q;

    D[src] = 0;
    q.push({0, src});     // dist, node
    while (!q.empty())
    {
        // get nearest vertex to the source
        auto [d_v, curr] = q.top();
        q.pop();
        // do relaxations for all adj to the new visited vertex
        if (visited[curr])
            continue;
        visited[curr] = true;
        for (pair<ll, ll> par : adj[curr])
        {
            ll weight = par.first;
            ll neighbor = par.second;
            auto distance = D[curr] + weight;
            if (distance < D[neighbor])
            {
                D[neighbor] = distance;
                P[neighbor].clear();
                P[neighbor].push_back({weight, curr});
                q.push({D[neighbor], neighbor});
            }
            else if (distance == D[neighbor])
                P[neighbor].push_back({weight, curr});
        }
    }
}

void solve()
{
    cin >> N >> M;
    int a, b; ll W;
    for (int i = 1; i <= M; i++)
    {
        cin >> a >> b >> W;
        adj[a].pb({W, b});
        adj[b].pb({W, a});
    }
    dijkstra(0);

    // for (int i = 0; i < N; i++)
    // {
    //     cout << i << ": ";
    //     for (auto [f, s] : P[i])
    //         cout << " {" << f << ", " << s << "} ";
    //     cout << endl;
    // }
    
    for (int i = 0; i < N; i++)
        visited[i] = false;
    vector<ll> traverse{N-1};
    ll total = 0;
    while (traverse.size())
    {
        auto curr = traverse[traverse.size() - 1];
        traverse.pop_back();
        if (visited[curr])
            continue;
        visited[curr] = true;
        for (auto [f, s] : P[curr])
        {
            // cout << "curr: " << curr << " f: " << f << " s: " << s << endl;
            total += f;
            traverse.push_back(s);
        }
    }
    cout << total * 2<< endll;
}

int main()
{
    speed;
    
    ll test = 1;
    // cin >> test;
    while (test--)
        solve();

    return 0;
}
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif // ONLINE_JUDGE

/*
TEMA: SSP, Dijkstra
COMPLEJIDAD: 
    (N + M) log N + (N + M)
    
IDEA: obtener todas las aristas pertenecientes a algun camino minimo (del vertice 0 a N-1) y luego recorrerlas con un DFS/BFS para obtener el costo total que sera multiplicado por 2 para hallar el costo de sembrar flores en el road

*/