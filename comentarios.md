

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



