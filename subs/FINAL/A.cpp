

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
    os << "{" << pr.first << ", " << pr.second << "}";
    // os << pr.first << " " << pr.second;
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

ll D[25][65];
pair<int, int> P[25][65];
vector<string> grid;
ll H, W;

void initialize()
{
    for (int i = 0; i < 25; i++)
        for (int j = 0; j < 65; j++)
            D[i][j] = INF;
}

bool is_valid(int i, int j)
{
    return i >= 0 && i < H && j >= 0 && j < W;
}

void solve()
{
    
}

int main()
{
    speed;
    
    // ll test = 1;
    // cin >> test;
    // while (test--)
    //     solve();
    while (true)
    {
        cin >> H >> W;
        if (H == 0 && W == 0)
            break;
        grid = vector<string>(H);
        for (int i = 0; i < H; i++)
            cin >> grid[i];
        
        ll min_global_cost = INF;
        vector<pair<int, int>> min_path;
        for (int nodo = 0; nodo < W; nodo++)
        {
            
            for (int i = 0; i < H; i++)
                for (int j = 0; j < W; j++)
                    D[i][j] = INF;

            priority_queue<
                pair<ll, pair<int, int>>,
                vector<pair<ll, pair<int, int>>>,
                greater<pair<ll, pair<int, int>>>
            > pq;

            for (int j = 0; j < W; j++)
                P[0][j] = {-1, -1};

            D[0][nodo] = (grid[0][nodo] - '0');
            pq.push({D[0][nodo], {0, nodo}});
            while (!pq.empty())
            {
                auto [cost, pos] = pq.top();
                auto [i, j] = pos;
                pq.pop();

                if (D[i][j] != cost)
                    continue;
                
                vector<pair<int, int>> adyacentes = {
                    {i, j-1}, {i+1, j-1}, {i+1, j}, {i+1, j+1}, {i, j+1},
                    {i-1, j-1}, {i-1, j}, {i-1, j+1},
                };
                
                for (auto [x, y] : adyacentes)
                {
                    if (is_valid(x, y))
                    {
                        auto weight = (grid[x][y] - '0');
                        if (D[x][y] > D[i][j] + weight)
                        {
                            D[x][y] = D[i][j] + weight;
                            P[x][y] = {i, j};
                            pq.push({D[x][y], {x, y}});
                        }
                    }
                }
            }
                
            ll min_cost = INF, min_cost_index = 0;
            for (int i = 0; i < W; i++)
            {
                if (D[H-1][i] < min_cost)
                {
                    min_cost = D[H-1][i];
                    min_cost_index = i;
                }
            }
            
            vector<pair<int, int>> path;
            path.push_back({H-1, min_cost_index});
            auto [i, j] = path.back();
            while (i != -1)
            {
                path.push_back({i, j});
                auto [x, y] = P[i][j];
                i = x;
                j = y;
            }
            reverse(path.begin(), path.end());
            if (min_cost < min_global_cost)
            {
                min_global_cost = min_cost;
                min_path = path;
            }
        }
        vector<string> aux_grid = grid;
        for (auto [x, y] : min_path)
            aux_grid[x][y] = ' ';
        for (string row : aux_grid)
            cout << row << endll;
        cout << endll;
    }
    return 0;
}


/*
TEMA: Grafos, SSSP
COMPLEJIDAD: 
    V = W*H
    E = 8*W*H (acotado)
    
    complejidad final ->  W * (V + E) log(V)

IDEA: Ejecutar Dijkstra para cada uno de los elementos de la primera fila y ver cual de los elementos de la ultima fila genera el corte (de galleta) minimo

*/