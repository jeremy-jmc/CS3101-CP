#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct segtree
{
    int size;
    vector<ll> values;
    // intervals are of the form [lx, rx>
    void init(int n)
    {
        size = 1;
        while (size < n)
            size *= 2;
        values.assign(2 * size, 0LL);
    }

    void build(vector<int> &a, int x, int lx, int rx)
    {
        /**
         * lx: left bound of the current segment
         * rx: right bound of the current segment
         * x: index of the current segment
         */
        if (rx - lx == 1)
        {
            if (lx < (int)a.size())
                values[x] = a[lx];
            return;
        }
        int m = (lx + rx) / 2;
        build(a, 2 * x + 1, lx, m);
        build(a, 2 * x + 2, m, rx);
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void build(vector<int> &a) { build(a, 0, 0, size); }

    void set(int i, int v, int x, int lx, int rx)
    {
        /**
         * lx: left bound of the current segment
         * rx: right bound of the current segment
         * x: index of the current segment
         * i: index of the element to be updated
         * v: value to be updated
         */
        if (rx - lx == 1)
        {
            values[x] = v;
            return;
        }
        int m = (lx + rx) / 2;
        if (i < m)
            set(i, v, 2 * x + 1, lx, m);
        else
            set(i, v, 2 * x + 2, m, rx);
        values[x] = values[2 * x + 1] + values[2 * x + 2];
    }

    void set(int i, int v) { set(i, v, 0, 0, size); }

    ll query(int l, int r, int x, int lx, int rx)
    {
        if (lx >= r || l >= rx)
            return 0;
        if (lx >= l && rx <= r)
            return values[x];
        int m = (lx + rx) / 2;
        ll s1 = query(l, r, 2 * x + 1, lx, m);
        ll s2 = query(l, r, 2 * x + 2, m, rx);
        return s1 + s2;
    }

    ll query(int l, int r) { return query(l, r, 0, 0, size); }
};

void st_test()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a)
        cin >> x;
    segtree st;
    st.init(n);
    st.build(a);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    segtree st;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    st.build(a);
    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, v;
            cin >> i >> v;
            st.set(i, v);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << st.query(l, r) << endl;
        }
    }
    return 0;
}