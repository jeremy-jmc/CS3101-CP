#include <bits/stdc++.h>
using namespace std;

void solve(){
    int A,B,C,conta=0;
    cin>>A>>B>>C;
    for(int x=-100;x<=100;x++){
        for(int y=x+1;y<=100;y++){
            for(int z=y+1;z<=100;z++){
                if(x*x+y*y+z*z!=C) continue;
                if(x*y*z!=B) continue;
                if(x+y+z!=A)  continue;

                cout<<x<<" "<<y<<" "<<z<<"\n";
                return;
            }
        }
    }
    cout<<"No solution.\n";
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    while(n--){
        solve();
    }
    return 0;
}
