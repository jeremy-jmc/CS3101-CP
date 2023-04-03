#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int c=0;
    int n;
    cin>>n;
    while(n!=0){
        if(c>0) cout<<"\n";

        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        for(int i1=0;i1<n;i1++){
            for(int i2=i1+1;i2<n;i2++){
                for(int i3=i2+1;i3<n;i3++){
                    for(int i4=i3+1;i4<n;i4++){
                        for(int i5=i4+1;i5<n;i5++){
                            for(int i6=i5+1;i6<n;i6++){
                                cout<<a[i1]<<" ";
                                cout<<a[i2]<<" ";
                                cout<<a[i3]<<" ";
                                cout<<a[i4]<<" ";
                                cout<<a[i5]<<" ";
                                cout<<a[i6]<<"\n";
                            }
                        }
                    }
                }
            }
        }


        c=1;
        cin>>n;
    }

    return 0;
}
