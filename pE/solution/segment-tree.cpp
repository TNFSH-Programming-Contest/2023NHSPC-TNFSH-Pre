#pragma GCC optimize("Ofast,unroll-loops,O3")
#pragma GCC target("avx,avx2,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,fma,tune=native")
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define N 1500015
using namespace std;
long long tag_val[4*N];
int tag[4*N],n,q;
inline void push(int l,int r,int i){
    if (!tag_val[i]&&!tag[i]) return;
    int mid=(l+r)>>1;
    tag[2*i]+=tag[i]; tag[2*i+1]+=tag[i];
    tag_val[2*i]+=tag_val[i];
    tag_val[2*i+1]+=tag_val[i]+(long long)(mid-l+1)*tag[i];
    tag_val[i]=0; tag[i]=0;
}
void modify(int l,int r,int i,int ll,int rr,long long a,long long b){
    if (ll>rr) return;
    if (ll<=l&&rr>=r){
        tag[i]+=b; tag_val[i]+=a;
        return;
    }
    int mid=(l+r)>>1; push(l,r,i);
    if (rr<=mid) modify(l,mid,2*i,ll,rr,a,b);
    else if (ll>mid) modify(mid+1,r,2*i+1,ll,rr,a,b);
    else {
        modify(l,mid,2*i,ll,mid,a,b);
        modify(mid+1,r,2*i+1,mid+1,rr,a+b*(mid-ll+1),b);
    }
}
long long query(int l,int r,int i,int p){
    if (l==r) return tag_val[i];
    int mid=(l+r)>>1; push(l,r,i);
    if (p<=mid) return query(l,mid,2*i,p);
    else return query(mid+1,r,2*i+1,p);
}
signed main(){
    fast
    cin>>n>>q;
    for (int i=1;i<=q;i++){
        long long p,c; cin>>p>>c;
        modify(1,n,1,max(p-c+1,1LL),p,c-(p-max(p-c+1,1LL)),1);
        modify(1,n,1,p+1,min(p+c,(long long)n),c-1,-1);
    }
    long long ans=0;
    for (int i=1;i<=n;i++)
        ans=max(ans,query(1,n,1,i));
    cout<<ans<<'\n';
}
