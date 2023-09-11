#pragma GCC optimize("Ofast,unroll-loops,O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
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
const int dx[]={1,1,-1,-1};
const int dy[]={1,-1,1,-1};
bool check_point(int x,int y){
    if (x>=1&&x<=n&&y>=1&&y<=m)
        return arr[x][y]==0;
    return 0;
}
bool check(int x,int y,int d){
    bool ans=1;
    for (int i=0;i<4;i++)
        ans&=check_point(x+dx[i]*d,y+dy[i]*d);
    return ans;
}
int main(){
    fast
    cin>>n>>m;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            char c; cin>>c;
            arr[i][j]=(c=='#');
        }
    }
    pii ans;
    int d=-1;
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            for (int k=0;;k++){
                if (!check(i,j,k)){
                    if (d<k){
                        d=k;
                        ans={i,j};
                    }
                    break;
                }
            }
        }
    }
    cout<<ans.x<<" "<<ans.y<<" "<<d-1<<'\n';
    return 0;
}
