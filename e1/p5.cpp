#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define speed                         \
    ios_base::sync_with_stdio(false); \
    cin.tie(0), cout.tie(0)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define endll '\n'
#define yes cout << "YES" << endll
#define no cout << "NO" << endll
#define pb push_back

ll cs[3*int(1e5) + 10];
vector<vector<ll>> adj;
vector<bool> visited;
vector<int> color;
ll A, B;
// 1 -> par , 0 -> impar
bool dfs(int u)
{
/*
retorna un booleano que representa si el grafo es bipartito
a traves del DFS se calcula el tamaño de los subcojuntos de vertices del grafo, denotados por un color 1, 0
para cada vertice ya visitado se verifica que el color no irrumpa las reglas del problema (par/impar blanco/negro)
*/
    // se cuenta el tamaño, de los subconjuntos del grafo bipartito
    if (color[u]) A++;  
    else B++;

    bool res = true;
    visited[u] = true;      // marca como visitado, aunque tambien se puede hacer seteando el color a -1 o algun valor arbitrario
    for (ll v: adj[u])
    {
        if (!visited[v])
        {
            color[v] = !color[u];       // el adyacente se pinta de un color distinto al elemento actualmente visitado
            res &= dfs(v);      // retorna que el subarbol sea bipartito
        }
        else if (color[u] == color[v])
            res &= false;       // si 2 colores adyacentes son iguales entonces el grafo no es bipartito
    }
    return res;
}

void solve()
{
    ll N, M, u, v;
    // lectura de input
    cin >> N >> M;
    adj = vector<vector<ll>>(N+1, vector<ll>());
    visited = vector<bool>(N+1, false);
    color = vector<int>(N+1, 2);    
    for (int i = 1; i <= M; i++)
    {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    
    // for (int i = 1; i <= N; i++)
    //     cout << i << " -> " << adj[i] << endll;
    ll res = 1;
    bool flag = true;
    for (int i = 1; i <= N; i++)
    {   // O(N + M)
        if (!visited[i])
        {
            A = 0, B = 0;       // se inicializan los tamaños de los subconjuntos del grafo bipartito
            color[i] = 1;       // se inicia arbitrariamente coloreando en 1
            flag &= dfs(i);     // devuelve si la componente conexa recorrida es bipartita o no
            res = (         // se asegura cualquier problema con el overflow aplicando modulo a todo
                (res % 998244353) * (cs[A]% 998244353 + cs[B]% 998244353) % 998244353
            ) % 998244353;
        }
    }
    if (flag)       // todas la componentes conexas son bipartitas
        cout << res << endll;
    else cout << "0\n"; // alguna componente conexa no es bipartita, por lo tanto no se puede hacer 2-coloreo
}

int main()
{
    speed;
    cs[0] = 1;
    for (int i = 1; i <= 3*1e5 + 10; i++)        // O(N)
        cs[i] = (cs[i-1] * 2) % 998244353;

    ll test = 1;
    cin >> test;
    while (test--)
        solve();
    return 0;
}
/*
TEMA GRAFOS, MATEMATICA

DFS sobre cada componente conexa hallando el tamaño de los subconjuntos si el grafo es bipartito.
La idea es lograr un grafo 2-coloreado
Si se define 1 como impar, 0 como par 
se puede ver que es equivalente comenzar pintando de un color u otro ya que las partes son complementarias
    1 0 1 0 1 0
    0 1 0 1 0 1
De este modo de un solo recorrido DFS se puede calcular el tamaño de los 2 subconjuntos de las componentes conexas
Como existen 2 tipos de impares y 1 de par que deben ser intercalados, el numero de formas se veria denotado por
    2*1*2*1*2*1
    1*2*1*2*1*2
Como se puede ver el numero de formas es una potencia de 2 definida por el numero de vertices de 1 color en el grafo
Sean A y B el tamaño de los subconjuntos del grafo 2-coloreo
El numero de formas se veria definido por 2^A + 2^B
Como N, M <= 3*1e5 en peor caso A y B serian 3^1e5/2 y el calculo de la potencia de 2 seria intratable
Por ese motivo se precomputa el valor de (2^n) % 998244353(valor que solicita el problema) siguiendo la formula de aritmetica modular
    (A*B)%M = (A%M*B%M)%M

Finalmente el calculo de la respuesta se define multiplicando el numero de formas entre todas las componentes conexas que son grafos bipartitos
En caso alguna componente conexa no sea grafo bipartito, no se puede generar 1 sola forma de hacer un 2-colore del grafo, en ese caso la rspta es 0

Complejidad 
    O(3*1e5 + 10) por precomputacion + O(N+M) por DFS
    O(N + M), O(V + E), vertices + aristas
*/