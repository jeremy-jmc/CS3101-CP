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

const int mx = int(1e4) + 10;
ll D[mx], P[mx];
vector<pair<ll, ll>> adj[mx];
ll N, M;

void dijkstra(int src, int dest)
{
    for (int i = 0; i < mx; i++)
    {
        D[i] = INF; 
        P[i] = -1;
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
        ll v = q.top().second;
        ll d_v = q.top().first;
        q.pop();
        // do relaxations for all adj to the new visited vertex
        
        for (pair<ll, ll> par : adj[v])
        {
            ll weight = par.first;
            ll to = par.second;

            if (D[v] + weight < D[to])
            {
                D[to] = D[v] + weight;
                P[to] = v;
                q.push({D[to], to});
            }
        }
    }
}

void solve()
{
    ll N, total_sheeps = 0; cin >> N;
    string str; cin >> str;

    for (int i = 0; i < N; i++)
        if (str[i] == '*')
            total_sheeps++;
    
    ll ls = 0, res = 0;
    for (int i = 0; i < N; i++)
    {
        if (str[i] == '.')
            res += min(ls, total_sheeps - ls);
        else
            ls++;
    }
    cout << res << endll;
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
