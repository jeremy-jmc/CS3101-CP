

## A - 9

Para contar cuantos numeros positivos no contienen al numero 9 se aplica principio multiplicativo.

Para un numero de n digitos la cantidad de posibilidades por digito son 10 (a excepcion del primer numero). 

Ejm: 
- Para 1 digito podemos tomar numeros del 1 al 9 (9 posibilidades)
- Para n digitos el primero tiene 9 posibilidades, mientras los demas n-1 digitos tienen 10 posibilidades (incluyendo el 0).

Por lo tanto para contar la cantidad de numeros positivos que no contienen al 9 se debe restar una posiblidad a cada digito del numero obteniendo la formula

$$
8 * \prod_{i=2}^{n} 9
$$

Dado que la cantidad de digitos va hasta 1e18 se usa exponenciacion binaria + modulo (constraint del problema).

## B - bino
Se solicita calcular $\frac{a!}{b! (a-b)!}$ modulo $p=1e9+7$ el problema es que en C++ las divisiones pueden traer problemas ademas que calcular 3 factoriales puede ser costoso computacionalmente y debido a los constraints del problema (1e6) no se pueden precomputar todos los valores de $C(n, k)$.

Se hace uso de Little Fermat's Theorem debido a que todos los numeros son menores que $p$ y por lo tanto $p$, $a$ y $b$ son coprimos.

$$
a^{p-1} \equiv 1 \mod p \\
a . a^{p-2} \equiv 1 \mod p \\
$$

Donde $a^{p-2}$ es el inverso modular. Por conveniencia matematica multiplicamos por equivalentes para eliminar los divisores.

$$
\frac{a!}{b! (a-b)!} \mod p \frac{(b!)^{p-2}}{(b!)^{p-2}} \frac{((a-b)!)^{p-2}}{((a-b)!)^{p-2}} = a! (b!)^{p-2} ((a-b)!)^{p-2} \mod p
$$

Los factoriales se pueden precomputar y para el calculo de potencias se usa exponenciacion binaria.

## C - magic mike
Para calcular el numero de posibilidades de que se pueda formar un numero multiplo de 5 se debe tomar como numeros finales a 0 y a 5.
A partir de encontrar un 0 o un 5 se calcula el numero posible de numeros que terminen en ellos $2^\text{pos-1}$

Debido que la cadena de entrada consta de $k$ repeticiones debemos extender este conteo.

Ejm: Para la cadena 13990 con k = 3 repeticiones.
Se encuentra el numero 0 en la posicion 5 asi que el numero de posibilidades es $2^{(5-1)}$ sin embargo la cadena al repetirse consta de mas numeros 0s
, 139901399013990. Obteniendo finalmente $2^(5-1) + 2^{10-1} + 2^{15-1} = 2^4 + 2^9 + 2^14 = 2^4 (1 + 2^5 + 2^10) = 2^4 * ((2^5)^0 + (2^5)^1 + (2^5)^2)$, se puede ver una serie geometrica, la cual puede reducir el numero de iteraciones que hagamos sobre el string y por lo tanto el tiempo de computacion.

## D 
## E - mucho teos

### Numero de divisores
Sea $n = {p_1}^{\alpha_1} . {p_2}^{\alpha_2} . ... . {p_k}^{\alpha_k}$ el numero de divisores se denota por:
$$\prod_{i}^{k} (\alpha_i + 1)$$

Donde $\alpha_i + 1$ representa tomar alguna de las posibles potencias y 1 mas por la potencia 0.

### Sumatoria de divisores
$$\sum \text{div(n)} = ({p_1}^0 + {p_1}^1 + ... + {p_1}^{\alpha_1}) ({p_2}^0 + {p_2}^1 + ... + {p_2}^{\alpha_2}) ... ({p_k}^0 + {p_k}^1 + ... + {p_k}^{\alpha_k})$$
Donde cada agrupacion de numeros es una serie geometrica. Por lo tanto.
$$\sum \text{div(n)} = \prod_{i=1}^{k} \frac{(p_i)^{\alpha_i + 1}-1}{p_i - 1}$$

### Productoria de divisores
Para eso se demostrara que $\prod_{d|n} d ^ 2= n^{d(n)}$

$$\prod_{d|n} d ^ 2 = \prod_{d|n} d.d = \prod_{d|n} d.\frac{n}{d} = \prod_{d|n} n = n^{d(n)}$$

Por lo tanto usando propiedades de radicacion se obtiene que el producto de los divisores de n es $n^{d(n)/2} = n^{\prod_{i}^{k} (\alpha_i + 1)/2}$

## F - mr robot 

Dado $l \leq a,b,c \leq r$ y $n.a + b - c = m$ nos lleva a ver que el valor de $b-c$ debe estar en el rango de $[l-r; r-l]$ a partir de esto se ve que $m + l - r \leq n.a \leq m + r - l$ a su vez $ (m + l - r)/a \leq n \leq (m + r - l)/a$ esto hace ver que si existe un valor $a$ tal que $l - r\leq m\%a \leq r-l$ los valores de $b$ y $c$ pueden ser restaurados facilmente.



## A - utec_alumnos
**tema**
grafos, componentes conexas, DSU

**descripción**
N vertices, M aristas se desea saber si el grafo esta conectado, en caso no lo este se requiere ver que aristas no estan conectadas con el nodo 1.
Se corre DSU con Kruskal y se compara cada elemento con el parent del nodo 1 para saber si pertenece a su mismo conjunto, de ese modo se sabe que elementos no estan conectados con este por algun camino.

A partir de saber que nodos no estan conectados con el 1 se puede saber si el grafo es conexo o no.

**complejidad**
Kruskal DSU con union by rank y path compression = O(M log N)


## B - maxsumarray
**tema**
Segment Tree, Data Structures, Divide & Conquer

**complejidad**
construccion: O(n), consulta: O(1), actualizacion: O(logN)

**descripción**
El problema se parece el maxsubarray sum que se hacia con divide and conquer.

La idea es o tomar la mayor parte derecha, la mayor parte izquierda o la suma conjunta de los subsegmentos intermedios conocidos como prefijos y sufijos.

el update cambia a ser la maxima suma derecha, izquierda o la parte del medio entre los arrays maxima suma derecha e izquierda conformado por los sufijos del lado izquierdo y el prefijo del lado derecho `t[n] =  max(max(t[l], t[r]), suff[l] + pref[r])`, ademas los prefijos y sufijos se actualizan con los hijos y se mantiene un array de la suma total para la reconstruccion de los prefijos y sufijos.

## C - siempre fue grafos
**complejidad**
Kruskal DSU con union by rank y path compression = O(M log N) + O(N) (eleccion de aristas que cambiar)

**tema**
grafos, componentes conexas, DSU

**descripción**
el problema te da N vertices y N-1 aristas de modo que son las aristas suficientes para generar un arbol, entonces te pide eliminar aristas y agregar nuevas para llegar a que todo el grafo este conexo.

Se hallan las componentes conexas con Kruskal, y arista que no realice un join, se agrega a un conjunto de aristas sobrantes que serviran para transformar el grafo actual a arbol.

Una vez se tienen las aristas sobrantes se toma una arista sobrante arbitraria y 2 parents de sets arbitrarios para reconstruir. Como se sabe que al final se mantendran N-1 aristas la respuesta siempre existe.

## D - mitasu
**complejidad**
construccion: O(n), consulta: O(lgN), actualizacion: O(logN)
final O(QlgN) siendo M el numero de queries

**tema**
Segment Tree, Data Structures, Divide & Conquer

**descripción**
un array de N elementos y Q consultas que pueden ser de update o consulta de suma en rango

Se utiliza un sum segment tree para calcular la suma en rango en tiempo eficiente, la dificultad del problema esta en no confundirte con el indexing.


## E - windows 97
**complejidad**
construccion: O(n), consulta: O(lgN), actualizacion: O(logN)
final O(MlgN) siendo M el numero de queries

**tema**
Segment Tree, Data Structures, Divide & Conquer

**descripción**
un array de N elementos y M consultas que pueden ser de update o consulta en rango denotas por F y C respectivamente.

Se utiliza un sum segment tree  para calcular la suma en rango dado que eso es igual a la cantidad de 1s en el rango que es lo que pide el problema.
Las actualizaciones de 1 a 0 no cambia porque la suma de 0s y 1s es el numero de 1s en cierto rango


### A
**tema**
strings, KMP

**complejidad**
O(n) por el calculo de la funcion pi[i] para toda posicion i en el stringen


**descripcion**
el problema especificamente solicita el calculo de la funcion pi[i], la cual calcula la longitud del maximo substring prefijo que a la vez es sufijo en el substring s[1...i], esto se logra con un enfoque naive en O(n^3) comparando substrs todos contra todos. Pero se puede lograr en O(n) usando informacion y propiedades de estados anteriores de la funcion (KMP)


### B

**tema**
suffix array

**complejidad**
O(N logN logN), donde N logN proviene de los ordenamientos en cada iteracion del algoritmo, y log N del tamaño del string representativo, relativo a la potencia de 2 mas cercana.
final: O(N log^2 N)

**descripcion**

construir el arreglo de sufijos e imprimirlo



### C
**tema**
string matching, KMP

**complejidad**
O(N+M) donde N es el tamaño del patrong de consulta y M el tamaño del string donde se busca

**descripcion**
contar el numero de veces que se repite un patron en un string. Se logra concatenando el patron con un caracter nulo "$" y el string total para luego ejecutar consultas sobre el arreglo pi[] tal que pi[i] tenga el tamaño del patron de consulta. A diferencia del problema C, uno cuenta posiciones, mientras que el otro imprime las posiciones donde se encuentran los patrones.


### F

**tema**
string matching, KMP

**complejidad**
O(N) para construir el arreglo pi con el algoritmo KMP

**descripcion**
Para encontrar el minimo substring S' el cual contenga a S dado multiples repeticiones (S' = S' + S' + ... + S'), se debe encontrar el maximo prefijo que tambien es sufijo, de modo que por los TC probablemente exista un overlap entre ellos.

Se usa el approach greedy (suerte + corazon) de extraer el substring del overlap con el calculo `n - pi[n-1]`, y pasa todos los TC :v



