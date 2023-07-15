
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


// ------------------------------------------------------------------
using ftype = double;       // ll

struct point2d {
    ftype x, y;
    point2d() {}
    point2d(ftype x, ftype y): x(x), y(y) {}

    point2d& operator+=(const point2d &t) 
    {
        x += t.x;
        y += t.y;
        return *this;
    }
    point2d& operator-=(const point2d &t) 
    {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    point2d& operator*=(ftype t) 
    {
        x *= t;
        y *= t;
        return *this;
    }
    point2d& operator/=(ftype t) 
    {
        x /= t;
        y /= t;
        return *this;
    }
    point2d operator+(const point2d &t) const 
    {
        return point2d(*this) += t;
    }
    point2d operator-(const point2d &t) const 
    {
        return point2d(*this) -= t;
    }
    point2d operator*(ftype t) const 
    {
        return point2d(*this) *= t;
    }
    point2d operator/(ftype t) const 
    {
        return point2d(*this) /= t;
    }
    ftype distance(point2d other = point2d(0, 0)) const
    {
        return sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y));
    }    
};

istream& operator>>(istream& in, point2d& p)
{
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const point2d& p)
{
    out << "{" << p.x << " " << p.y << "}";
    return out;
}

point2d operator*(ftype a, point2d b) 
{
    return b * a;
}
ftype dot(point2d a, point2d b) 
{
    return a.x * b.x + a.y * b.y;
}
ftype cross(point2d a, point2d b) 
{
    return a.x * b.y - a.y * b.x;
}
ftype norm(point2d a) 
{
    return dot(a, a);
}
double abs(point2d a) 
{
    return sqrt(norm(a));
}
double proj(point2d a, point2d b) 
{
    return dot(a, b) / abs(b);
}
double angle(point2d a, point2d b) 
{
    return acos(dot(a, b) / abs(a) / abs(b));
}
point2d intersect(point2d a1, point2d d1, point2d a2, point2d d2) 
{
    return a1 + cross(a2 - a1, d2) / cross(d1, d2) * d1;
}
double distance(point2d p1, point2d p2)
{
    return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

struct point3d 
{
    ftype x, y, z;
    point3d() {}
    point3d(ftype x, ftype y, ftype z): x(x), y(y), z(z) {}
    point3d& operator+=(const point3d &t) 
    {
        x += t.x;
        y += t.y;
        z += t.z;
        return *this;
    }
    point3d& operator-=(const point3d &t) 
    {
        x -= t.x;
        y -= t.y;
        z -= t.z;
        return *this;
    }
    point3d& operator*=(ftype t) 
    {
        x *= t;
        y *= t;
        z *= t;
        return *this;
    }
    point3d& operator/=(ftype t) 
    {
        x /= t;
        y /= t;
        z /= t;
        return *this;
    }
    point3d operator+(const point3d &t) const 
    {
        return point3d(*this) += t;
    }
    point3d operator-(const point3d &t) const 
    {
        return point3d(*this) -= t;
    }
    point3d operator*(ftype t) const 
    {
        return point3d(*this) *= t;
    }
    point3d operator/(ftype t) const 
    {
        return point3d(*this) /= t;
    }
};

point3d operator*(ftype a, point3d b) 
{
    return b * a;
}
ftype dot(point3d a, point3d b) 
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}
point3d cross(point3d a, point3d b) {
    return point3d(a.y * b.z - a.z * b.y,
                   a.z * b.x - a.x * b.z,
                   a.x * b.y - a.y * b.x);
}
ftype triple(point3d a, point3d b, point3d c) 
{
    return dot(a, cross(b, c));
}
point3d intersect(point3d a1, point3d n1, point3d a2, point3d n2, point3d a3, point3d n3) 
{
    point3d x(n1.x, n2.x, n3.x);
    point3d y(n1.y, n2.y, n3.y);
    point3d z(n1.z, n2.z, n3.z); 
    point3d d(dot(a1, n1), dot(a2, n2), dot(a3, n3));
    return point3d(triple(d, y, z),
                   triple(x, d, z),
                   triple(x, y, d)) / triple(n1, n2, n3);
}
// ------------------------------------------------------------------

ftype triangle_area(point2d p1, point2d p2, point2d p3)
{
    auto [x1, y1] = p1;
    auto [x2, y2] = p2;
    auto [x3, y3] = p3;
    return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0);
}

int signed_area_parallelogram(point2d p1, point2d p2, point2d p3) {
    return cross(p2 - p1, p3 - p2);
}

// double triangle_area(point2d p1, point2d p2, point2d p3) {
//     return abs(signed_area_parallelogram(p1, p2, p3)) / 2.0;
// }

bool is_inside(point2d p1, point2d p2, point2d p3, point2d query_point)
{  
   ftype A = triangle_area(p1, p2, p3);
   ftype A1 = triangle_area(query_point, p2, p3);
   ftype A2 = triangle_area(p1, query_point, p3);
   ftype A3 = triangle_area(p1, p2, query_point);
   return (A == A1 + A2 + A3);
}

ftype polygon_area(const vector<point2d>& fig) {
    ftype res = 0;
    for (unsigned i = 0; i < fig.size(); i++) 
    {
        point2d p = i ? fig[i - 1] : fig.back();
        point2d q = fig[i];
        res += (p.x - q.x) * (p.y + q.y);
    }
    return res / 2;
}

point2d closest_point(point2d l1, point2d l2, point2d point, bool segment = false)
{
    if (segment)
    {
        if (dot(l2 - l1, point - l2) > 0)
            return l2;
        if (dot(l1 - l2, point - l1) > 0)
            return l1;
    }
    double t = dot(point - l1, l2 - l1) / norm(l2 - l1);
    return l1 + t * (l2 - l1);
}

int orientation(point2d a, point2d b, point2d c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(point2d a, point2d b, point2d c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool ccw(point2d a, point2d b, point2d c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o > 0 || (include_collinear && o == 0);
}

void convex_hull(vector<point2d>& a, bool include_collinear = false) {
    if (a.size() == 1)
        return;

    sort(a.begin(), a.end(), [](point2d a, point2d b) {
        return make_pair(a.x, a.y) < make_pair(b.x, b.y);
    });
    point2d p1 = a[0], p2 = a.back();
    vector<point2d> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2, include_collinear)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i], include_collinear))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2, include_collinear)) {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i], include_collinear))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    if (include_collinear && up.size() == a.size()) {
        reverse(a.begin(), a.end());
        return;
    }
    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
}

