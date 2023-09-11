#include<bits/stdc++.h>
#define int long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
using namespace std;
int s[1500015],ans[1500015],n,q;
signed main(){
    fast
    cin>>n>>q;
    for (int i=1;i<=q;i++){
        int p,c; cin>>p>>c;
        s[max(p-c+1,1LL)]++;
        s[min(p+c+1,n+1)]++;
        s[p+1]-=2;
        ans[1]+=max(c-p,0LL);
    }
    for (int i=1;i<=n;i++){
        s[i]+=s[i-1];
        ans[i]+=(ans[i-1]+s[i]);
    }
    cout<<*max_element(ans+1,ans+1+n)<<'\n';
}
