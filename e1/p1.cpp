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

const int MX = 1e5 + 10;
const ll mod = 1e9 + 7; // 998244353
const ll INF = 1LL << 20;

void solve()
{
    map<ll, ll> fmap;
    ll N; cin >> N;
    vector<ll> arr(N);
    for (int i = 0; i < N; i++)
        cin>>arr[i], fmap[arr[i]]++;        // se calculan las frecuencias de los numeros
    
    if (fmap.size() == 1)       // caso base: todos los numeros iguales, nada que hacer
        cout << "0\n";
    else if (fmap[1] > 0 && fmap.size() > 1)    // caso imposible existe algun 1 y algun numero distinto de 1
        cout << "-1\n";
    else {
        // simulacion
        vector<pair<ll, ll>> arr_pos(N);        // se tiene un array conformado por los valores (posiblemente transformados) asociados a su posicion original. par (value, index)
        vector<pair<ll, ll>> idx_res;       // se guardan los pasos de la simulacion en un vector de pares
        for (int i = 0; i < N; i++) // inicializacion
            arr_pos[i] = {arr[i], i};
        
        while (fmap.size() > 1)     // mientras el array no contenga un unico numero
        {
            sort(all(arr_pos));     // sortear el array  O(N lgN)
            arr_pos[N-1].first = ceil((double)arr_pos[N-1].first/(double)arr_pos[0].first);     // se minimiza el maximo
            idx_res.pb({arr_pos[N-1].second + 1, arr_pos[0].second + 1});       // se agrega un nuevo paso correspondiente a la anterior operacion
            
            // se recalcula el mapa de frecuencias dado que un numero nuevo ha aparecido
            fmap = map<ll, ll>();       // O(N)
            for (auto [f, s] : arr_pos)
                fmap[f]++;
        }
        // output de pasos de la simulacion
        cout << idx_res.size() << endll;
        for (auto [i, j] : idx_res)
            cout << i << " " << j << endll;
    }
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
TEMA: GREEDY, BRUTE FORCE, WEAK CONSTRAINTS

IDEA en 3 pasos
    demostrar cuando el resultado q = -1 o pensar en si q nunca va a ser -1 para lanzar simulacion para todos los posibles casos
        se encuentra el caso de que si existe algun 1 en el array y algun otro elemento distinto de 1 estos nunca pondran ser iguales ya que la la division entre 1 no provoca ningun cambio
    fijar casos bases
        elementos iguales -> 0
    los demas casos: 
        simulars
            la eleccion greedy es reducir al mayor dividiendolo entre el menor
            si segun el problema se demuestra que existen a lo mucho 30n el brute force a lo mucho hara 30 * 100 iteraciones dado que n <= 100 por la cantidad test cases (t<= 1000) entra en menos de 1s
COMPLEJIDAD:
    El costo de una iteracion por simulacion es NlgN
    En peor caso se hacen lg(1e9) pasos para reducir un numero, dado que se quieren reducir N numeros -> N lg(1e9)

    Finalmente O(N^2 lgN lg(1e9))
*/
