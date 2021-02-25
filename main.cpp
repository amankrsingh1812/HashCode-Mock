#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int uli;
typedef long double Lf;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define fastIO  std::ios::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define N 104
#define NN 2005
#define SZ(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define loop(i,s,n) for(int i=(s);i<(n);i++)
#define loopr(i,n,s) for(int i=(n)-1;i>=(s);i--)
#define pb push_back
#define o2(a,b) cout<<(a)<<" "<<(b)<<endl
#define o3(a,b,c) cout<<(a)<<" "<<(b)<<" "<<(c)<<endl
#define o4(a,b,c,d) cout<<(a)<<" "<<(b)<<" "<<(c)<<" "<<(d)<<endl
#define cl cout<<endl
#define r0 return 0
#define e0 exit(0)
#define x first
#define y second
 
inline lli modadd(lli n,lli m,lli p=mod){
    return ((n+m)%p+p)%p;
}
 
inline lli modsub(lli n,lli m,lli p=mod){
    return ((n-m+p)%p+p)%p;
}
 
inline lli modpro(lli n,lli m,lli p=mod){
    return (((n%p)*(m%p))%p+p)%p;
}
 
uli powe(lli x,lli y){
    uli res = 1;
    while (y > 0) {
        if (y & 1)
            res = res * x;
        y = y >> 1;
        x = x * x;
    }
    return res;
}
 
lli modpow(lli x,lli y,lli p=mod){
    lli res = 1;
    while (y > 0) {
        if (y & 1)
            res = modpro(res , x, p);
        y = y >> 1;
        x = modpro(x , x, p);
    }
    return res;
}
 
inline lli modInverse(lli n, lli p=mod)
{
    if(n==1) return 1;
    return modpow(n, p-2, p);
}
 
inline lli moddiv(lli n,lli m,lli p=mod){
    return modpro(n,modInverse(m,p),p);
}
 
inline lli modadd3(lli x, lli y, lli z,lli p=mod){
    return modadd(modadd(x,y,p),z,p);
}
 
inline lli modadd4(lli x, lli y, lli z, lli w,lli p=mod){
    return modadd(modadd(x,y,p),modadd(z,w,p),p);
}
 
inline lli modnCr(lli fac[], int n, int r, lli p=mod)
{
    if (r==0) return 1;
    return modpro(fac[n],modInverse(modpro(fac[r],fac[n-r],p),p),p);
}
 
int main(int argc, char *argv[]){
    fastIO;
      
    return 0;
}