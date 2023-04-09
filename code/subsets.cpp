#include <bits/stdc++.h>
using namespace std;

void write(vector<int> v){
    cout<<"sub impreso: ";
    if(v.size()==0) cout<<"\n";
    for(int i=0;i<v.size();i++) cout<<v[i]<<"\n "[i+1<v.size()];
}
///genera(v,i) generara los subconjuntos que contengan a
void generar(vector<int> &v, int i,int n){
    if(i==n) write(v);
    else{
        v.push_back(i+1);
        generar(v,i+1,n);
        v.pop_back();
        generar(v,i+1,n);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    vector<int> v;
    cin>>n;
    generar(v,0,n);

    exit(0);
}

// ll N;
// vector<ll> A;
// vector<ll> subset;

// void generate_subset(int i)
// {
//     if (i == N)
//     {
//         cout << subset << '\n';
//         return;
//     }
    
//     subset.push_back(A[i]);
//     generate_subset(i+1);
//     subset.pop_back();
//     generate_subset(i+1);
// }