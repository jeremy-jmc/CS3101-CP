#include <bits/stdc++.h>
using namespace std;

void imprimir(int d1,int d2){
    int x=d1,y=d2;
    vector<int> v1(5,0);
    vector<int> v2(5,0);
    for(int i=0;i<5;i++){
        v1[i]=x%10;
        v2[i]=y%10;
        x=x/10;
        y=y/10;
    }
    for(int i=4;i>=0;i--) cout<<v1[i];
    cout<<" / ";
    for(int i=4;i>=0;i--) cout<<v2[i];
    cout<<" = ";
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    int c=0;
    cin>>n;

    while(n!=0){
        if (c>0) cout<<"\n";
        if(n==1) cout<<"There are no solutions for 1.\n";
        else{
            int conta=0;
            int maxi=98765/n;
            for(int d2=1234;d2<=maxi;d2++){
                set<int> s;
                int d1=d2*n;
                int x=d1,y=d2;
                for(int j=0;j<=4;j++){
                    s.insert(x%10);
                    s.insert(y%10);
                    x=x/10;
                    y=y/10;
                }
                if(s.size()<10) continue;
                else{
                    imprimir(d1,d2);
                    cout<<n<<"\n";
                    conta++;
                }
            }
            if(conta==0) cout<<"There are no solutions for "<<n<<".\n";
        }
        cin>>n;
        c++;
    }
    return 0;
}
