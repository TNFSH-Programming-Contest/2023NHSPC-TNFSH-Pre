#include "testlib.h"

#include <bits/stdc++.h>



using namespace std;

bool arr[5015][5015];

int main(int argc, char* argv[]) {

    registerGen(argc, argv, 1);

    int n=atoi(argv[1]),m=atoi(argv[2]),c=atoi(argv[3]),cnt=0;

    cout<<n<<" "<<m<<"\n";

    for (int i=1;i<=n;i++){

        for (int j=1;j<=m;j++){

            int r=rnd.next(0,c);

            if (r==0) arr[i][j]=1;

            else arr[i][j]=0,cnt++;

        }

    }

    if (!cnt){

        int a=rnd.next(1,n),b=rnd.next(1,m);

        arr[a][b]=0;

    }

    for (int i=1;i<=n;i++){

        for (int j=1;j<=m;j++){

            cout<<(arr[i][j]?'#':'.');

        }

        cout<<'\n';

    }

    return 0;

}