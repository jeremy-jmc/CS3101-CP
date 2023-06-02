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
#define endll '\n'
#define yes cout << "YES" << endll
#define no cout << "NO" << endll
#define pb push_back

const int MX = 1e5 + 10;
const ll mod = 1e9 + 7; // 998244353
const ll INF = 1LL << 20;

void solve()
{
    ll N, M;
    cin >> N >> M;
    deque<ll> R(N); iota(all(R), 1);        // se utiliza un deque para push_front y se rellena inicialmente con los numeros del 1 al N
    map<ll, ll> fmap;   // se calcula la frecuencia de un numero en la secuencia inicial
    for (int i = 1; i <= N; i++)
        fmap[i] = 1;
    // lectura
    vector<ll> P(M + 1, -1), T(N + 1, INF);
    for (int i = 1; i <= M; i++)
        cin>>P[i];

    // se simula las reglas mencionadas
    for (ll i = 1; i <= M; i++)
    {   // O(M)
        if (fmap[P[i]]) 
        {   // si el numero existe en el arreglo (frecuencia > 0)
            // se busca la posicion del numero y se hace un intercambio entre el numero y el primer elmento de "Acciones recientes"
            ll pos = distance(R.begin(), find(all(R), P[i]));       // O(N)
            swap(R[0], R[pos]);
        }
        else 
        {   // caso contrario se agrega el nuevo numero al inicio
            R.push_front(P[i]);     // O(1)
            fmap[P[i]]++;       // se añade 1 en frecuencia para el numero entrante
            auto removed = R[R.size() - 1];
            fmap[removed]--;    // se reduce la frecuencia del numero en 1, se mantienen frecuencias por los duplicados
            if (removed <= N)
                T[removed] = min(T[removed], i);        // se actualiza el tiempo de salida de "Acciones recientes" del numero a remover
            R.pop_back();       // se elimina el ultimo elemento O(1)
        }
    }

    for (int i = 1; i <= N; i++)
    {
        if (T[i] == INF)        // los valores que nunca se minimizaron, es porque nunca se han eliminado
            cout << "-1 ";
        else cout << T[i] << " ";
    }
    cout << endll;
}

int main()
{
    time_t start, end;
    time(&start);
       
    speed;
    ll test = 1;
    cin >> test;
    while (test--)
        solve();

    return 0;
}
/*
TEMA: STL, BRUTE FORCE
IDEA: simular la idea con estructuras de STL que faciliten el tratamiento del input(std::deque)
Complejidad O(M*N)
    M = tamaño de la cola de accciones recientes que ocurriran
    N = tamaño que mantiene la cola a lo largo de todo la ejecucion del algoritmo
*/