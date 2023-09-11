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
int n,m,arr[N][N];
int dir1[N][N],dir2[N][N],dir3[N][N],dir4[N][N],ans[N][N];
int main(){
    fast
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c; cin>>c;
            arr[i][j]=(c=='.');
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            dir1[i][j]=arr[i][j]==0 ? 0 : dir1[i-1][j-1]+1;
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=m;j>=1;j--){
            dir2[i][j]=arr[i][j]==0 ? 0 : dir2[i-1][j+1]+1;
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=1;j<=m;j++){
            dir3[i][j]=arr[i][j]==0 ? 0 : dir3[i+1][j-1]+1;
        }
    }
    for (int i=n;i>=1;i--){
        for (int j=m;j>=1;j--){
            dir4[i][j]=arr[i][j]==0 ? 0 : dir4[i+1][j+1]+1;
        }
    }
    int mx=0;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            ans[i][j]=min({dir1[i][j],dir2[i][j],dir3[i][j],dir4[i][j]});
            mx=max(mx,ans[i][j]);
        }
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            if (ans[i][j]==mx&&arr[i][j]){
                cout<<i<<" "<<j<<" "<<mx-1<<'\n';
                return 0;
            }
        }
    }
    return 0;
}
