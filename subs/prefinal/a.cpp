
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

void solve()
{
    ll N; cin >> N;
    ll cont2 = 1, cont11 = 0;

    for (int i = 2; i <= N; i++)
    {
        auto num_digits = floor(
            cont2 * log(2)/log(10) + (cont11 + 1) * log(11)/log(10)
        ) + 1;
        if (num_digits == i)
            cont11++;
        else
            cont2++;
    }
    while (cont2--) cout << "2 ";
    while (cont11--) cout << "11 ";
    cout << endll;
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
