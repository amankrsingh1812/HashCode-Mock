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
map<string, lli> maxScore;
void scorer(string outFileName){
    
    lli curScore = 0;



    if(maxScore[outFileName] < curScore){
        ofstream fout(outFileName);
        // WRITE TO FILE

        maxScore[outFileName] = curScore;
    }
} 

const int N=1e+5+10;
string intersectionName[N];
map<string,int> nameToId;
int D,I,S,V,F,L[N],B[N],E[N],cntStreet[N];
vector<int>adjInp[N],adjOut[N];


void initialise(int n)
{
	for(int i=0;i<n;i++)
	{
		adjInp[i].clear();
		adjOut[i].clear();
		cntStreet[i]=B[i]=E[i]=L[i]=0;
	}
	nameToId.clear();
}

bool comp(int s1,int s2)
{
	return cntStreet[s1]>cntStreet[s2];
}

int main(int argc, char *argv[]){
    fastIO;
    for(char file='a';file<='f';file++){
        string inFileName = file+".in";
        string outFileName = file+".out";

		ifstream fin(inFileName);
		initialise(N);
		fin>>D>>I>>S>>V>>F;

		for(int i=1;i<=S;i++)
		{
			fin>>B[i]>>E[i]>>intersectionName[i]>>L[i];
			nameToId[intersectionName[i]]=i;;
			adjInp[E[i]].push_back(i);
			adjOut[B[i]].push_back(i);
		}

		for(int i=1;i<=V;i++)
		{
			fin>>P;
			while(P--)
			{
				string s;
				fin>>s;
				int sId=nameToId[s];
				if(P>0)
					cntStreet[sId]++;
			}
		}
        
		int A=0;
		for(int i=0;i<=I;i++)
		{
			if(adjInp[i]>0)
				A++;
		}
		//fout<<A<<"\n";

		for(int i=0;i<=I;i++)
		{
			if(adjInp[i].size()==0)
				continue;
			//fout<<i<<"\n";
			//fout<adjInp[i].size()<<"\n";
			sort(adjInp[i].begin(),adjInp[i].end(),comp);
			int g=comp[adjInp[i][0]];
			for(auto i1:adjInp[i])
				g=__gcd(i1,g);
			
			for(auto i1:adjInp[i])
			{
				//fout<<intersectionName[i1]<<" "<<comp[i1]/g<<"\n";
			}
		}

		fin.close();
    }
    return 0;
}
