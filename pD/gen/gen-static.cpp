#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);
    int n=atoi(argv[1]),q=atoi(argv[2]),q1=atoi(argv[3]),q2=atoi(argv[4]),c=atoi(argv[5]);
    cout<<n<<" "<<q<<"\n";
    for (int i=1;i<=n;i++){
        int r=rnd.next(1,c);
        cout<<r<<" \n"[i==n];
    }
    for (int i=1;i<=q;i++){
        int op=1,a,b;
        a=rnd.next(q1,q2);
        cout<<op<<' '<<a<<'\n';

    }
    return 0;
}
