#include<iostream>
using namespace std;
#define int long long
int mod=998244353;
const int N=1e7+100;
using ll =long long;
ll fac[N];
ll inv[N];
ll bit_pow(ll a,ll b) {
    ll ans=1;
    while(b) {
        if(b&1) ans=(ans*a)%mod;
        b>>=1;
        a=(a*a)%mod;
    }
    return ans;
}
void init() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    fac[0]=1;
    inv[1]=1;
    for(int i=1;i<N;i++) {
        fac[i]=(fac[i-1]*i)%mod;
        fac[i]%=mod;
    }
    inv[N-1]=bit_pow(fac[N-1],mod-2);
    for(int i=N-2;i>=0;i--) {
        inv[i]=(i+1)*inv[i+1]%mod;
    }
}
ll c(int a,int b) {

    if(a<b) return 0;
    return fac[a]*inv[b]%mod*inv[a-b]%mod;
}
void solve() {
    int n,k;
    cin>>n>>k;
    ll ans=0;
    for(int i=1;i<=n-k-1;i++) {
        ans=(ans+((((n-i-k)*fac[n-i])%mod*fac[i+1])%mod*c(i+k-1,i-1))%mod)%mod;
        ans+=mod;
        ans%=mod;
    }
    if(k==0) {
        ans=(ans+fac[n]*n%mod)%mod;
    }
    cout<<(ans+mod)%mod<<'\n';
}
signed main() {
    int T;
    cin>>T;
    init();
    while(T--)
        solve();
}