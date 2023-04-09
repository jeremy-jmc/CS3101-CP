#include <bits/stdc++.h>

using namespace std;

void imprimir(vector<int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<"\n "[i+1<v.size()];
    }
}

void generar(vector<int> &v,int n, vector<bool> &esta){
    if(v.size()==n) imprimir(v);
    else{
        for(int i=1;i<=n;i++){
            if(esta[i]) continue;
            esta[i]=true;
            v.push_back(i);
            generar(v,n,esta);
            esta[i]=false;
            v.pop_back();

        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> v;
    int n;
    cin>>n;
    vector<bool> esta(n+1,false);
    generar(v,n,esta);

    exit(0);
}
