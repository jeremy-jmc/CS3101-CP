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
COMPLEJIDAD
    En funcion a la cantidad total de bits prendidos del input

EDGE CASE:
1
1000
15
127 127 127 127 127 127 127 127 127 127 127 127 127 127 127

20
793
19
29 21 25 36 2 22 1 39 26 8 18 30 2 35 52 23 19 47 15
427
16
2 61 59 10 46 13 52 17 2 34 12 2 60 13 41 3
660
4
63 230 167 200
431
1
431
389
13
4 71 25 30 3 40 7 29 35 27 20 71 27
419
17
9 41 38 46 2 46 11 39 13 38 47 7 16 8 32 23 3
724
16
38 38 53 33 12 24 34 22 63 41 46 40 13 5 61 57
535
10
84 67 96 20 40 45 14 82 6 81
489
11
91 70 4 56 15 16 1 82 85 68 1
579
14
19 64 6 52 64 46 29 30 66 11 35 64 66 27
911
11
8 64 86 38 47 8 58 83 87 74 57
502
9
81 5 4 106 8 100 34 92 72
325
1
237
355
16
21 45 31 7 18 5 39 55 12 15 4 13 7 10 56 17
639
14
40 69 70 49 63 59 9 19 15 69 24 62 28 63
316
9
1 22 50 51 58 95 24 2 13
479
6
30 155 9 72 164 49
870
1
870
388
14
38 40 25 55 56 6 13 6 12 60 1 3 27 46
544
5
113 35 126 157 113
*/