
/// 8 queen chess problem
#include <bits/stdc++.h>
using namespace std;
int a,b,canti;
int row[8];

void imprimir(){
    if(canti>0) printf("\n");
    canti++;
    printf("%2d      %d", canti, row[0]+1);
    for(int i=  1;i<8; i++)printf(" %d",row[i]+1);
}

bool isvalid(int fila, int nq){
    for(int i=0;i<nq;i++){
        if(row[i]==fila || abs(row[i]-fila)==abs(i-nq)) return false;
    }
    return true;
}

void backtrack(int nq){
    if(nq==8 && row[b]==a) imprimir();
    for(int i=0;i<8;i++){
        if(isvalid(i,nq)) {
            row[nq]= i;
            backtrack(nq+1);
        }
    }
}

void solve(){
    scanf("%d%d",&a,&b);
    a--;
    b--;
    canti=0;
    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n\n");
    backtrack(0);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    scanf("%d", &t);
    while(t--){
        /// reset values of diags
        for(int i=0;i<8;i++) row[i]=0;
        /// solve

        solve();
        if(t>0) printf("\n\n");
        else printf("\n");
    }
    return 0;
}
