#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int ans[1500015],n,q;
signed main(){
    fast
    cin>>n>>q;
    for (int i=1;i<=q;i++){
        int p,c; cin>>p>>c;
        for (int j=1;j<=n;j++)
            ans[j]=ans[j]+max(c-abs(p-j),0LL);
    }
    cout<<*max_element(ans+1,ans+1+n)<<'\n';
}
