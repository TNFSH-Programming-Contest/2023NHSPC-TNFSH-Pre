#include "testlib.h"
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);
    int n=atoi(argv[1]),q=atoi(argv[2]),c=atoi(argv[3]);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cout<<n<<" "<<q<<"\n";
    for (int i=1;i<=q;i++){
        int a=rnd.next(1,n),b=rnd.next(1,c);
        cout<<a<<" "<<b<<'\n';
    }
    return 0;

}