//#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC optimize("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#pragma pack(1)
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define pii pair<int,int>
#define x first
#define y second
#define N 5015
using namespace std;
//using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> order_multiset;
//typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> order_set;
int n,m,arr[N][N],s1[N][N],s2[N][N];
pii check(int d){
    for (int i=d;i<=n-d+1;i++){
        for (int j=d;j<=m-d+1;j++){
            if (s1[i+d-1][j+d-1]-s1[i-d][j-d]==0&&s2[i+d-1][j-d+1]-s2[i-d][j+d]==0)
                return {i,j};
        }
    }
    return {0,0};
}
int main(){
    fast
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c; cin>>c;
            arr[i][j]=(c=='#');
            s1[i][j]=s1[i-1][j-1]+arr[i][j];
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j--)
            s2[i][j]=s2[i-1][j+1]+arr[i][j];
    }
    int l=1,r=n+1;
    while (l<r){
        int mid=(l+r)>>1;
        if (check(mid)!=pii(0,0)) l=mid+1;
        else r=mid;
    }
    pii ans=check(l-1);
    cout<<ans.x<<" "<<ans.y<<' '<<l-2<<'\n';
    return 0;
}
