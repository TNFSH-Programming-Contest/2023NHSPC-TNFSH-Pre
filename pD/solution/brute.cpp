//#pragma GCC optimize("Ofast,unroll-loops,O3")
//#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include<bits/stdc++.h>
//#include<bits/extc++.h>
//#pragma pack(1)
#define int long long
#define pii pair<int,int>
#define x first
#define y second
#define N 200015
using namespace std;
//using namespace __gnu_pbds;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//typedef tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update> order_multiset;
//typedef tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> order_set;
int n,q,arr[N];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>q;
    for (int i=0;i<n;i++)
        cin>>arr[i];
    while (q--){
        int op,a,b,ans=0; cin>>op;
        if (op==1){
            cin>>a;
            for (int i=0;i<n;i+=a)
                ans+=arr[i];
            cout<<ans<<'\n';
        }
        else {
            cin>>a>>b;
            arr[a]=b;
       	}
    }
}
