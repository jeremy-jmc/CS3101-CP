template<
    template<class, class> class C1,
    template<class, class> class C2,
    typename T
>
bool container_equal(
    const C1<T, allocator<T>>& c1,
    const C2<T, allocator<T>>& c2
)
{
    if (c1.size() != c2.size())
        return false;
    auto itc1 = c1.begin();
    auto itc2 = c2.begin();

    for (; itc1 != c1.end(); ++itc1, ++itc2)
        if (*itc1 != *itc2)
            return false;
    return true;
}

bool isPrime(int n) {
    if(n <= 1)
        return false;
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}

bool mod_(ll num) {
    if (num > mod)
        return num - mod;
    return num;
}

ll binpow(ll a, ll b, ll md=1) {
    a %= md;
    ll res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % md;
        a = a * a % md;
        b >>= 1;
    }
    return res;
}
