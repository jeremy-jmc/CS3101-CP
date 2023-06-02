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

ll dp[int(1e5) + 10];
ll H[int(1e5) + 10];
void solve()
{
    ll N, K; cin >> N >> K;
    for (int i = 1; i <= N; i++)
        cin >> H[i];        // leer alturas de piedras

    dp[1] = 0;  // como se inicia en la piedra 1, su costo incurrido es 0
    for (int i = 2; i <= N; i++)
    {   
        dp[i] = abs(H[i] - H[i-1]) + dp[i-1];       // se inicializa el primer valor de dp[i] haciendo un salto desde el anterior
        ll cont = 2;    // a partir de ello se recorrer hasta el i-K si es que se puede (>= 1)
        while (cont <= K && i - cont >= 1)
        {   // se calcula por cada uno de los K anteriores (alcanzables)
            dp[i] = min(dp[i], abs(H[i] - H[i-cont]) + dp[i-cont]);
            cont++;
        }
    }
    cout << dp[N] << endll; // minimo costo incurrido en llegar a la piedra N
}

int main()
{
    speed;
    ll test = 1;
    while (test--)
        solve();
    return 0;
}

/*
TEMA: DP
IDEA:
dp(i) = {
    costo minimo incurrido en llegar a la piedra i
    min(
        dp[i-1] + abs(H[i] - H[i-1]),
        dp[i-2] + abs(H[i] - H[i-2]),
        ...
        dp[i-K] + abs(H[i] - H[i-K])
            para todo i-K tal que i-K >= 1
    )
}

COMPLEJIDAD: O(N*K)
*/