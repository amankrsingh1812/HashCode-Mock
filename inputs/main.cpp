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

const int N1=1e+5+10;
string intersectionName[N1];
map<string,int> nameToId;
int D,I,S,V,F,L[N1],B[N1],E[N1],cntStreet[N1];
vector<int>adjInp[N1],adjOut[N1];
pair<long long,int> distSum[N1];
vector<int> path[N1];

void initialise(int n)
{
	for(int i=0;i<n;i++)
	{
		adjInp[i].clear();
		adjOut[i].clear();
		cntStreet[i]=B[i]=E[i]=L[i]=0;
		distSum[i]={0,0};
		path[i].clear();
	}
	nameToId.clear();
	//path.clear();
}

bool comp(int s1,int s2)
{
	return cntStreet[s1]>cntStreet[s2];
}

int main(int argc, char *argv[]){
    //fastIO;
    for(char file='f';file<='f';file++){
        string inFileName;
		//cout<<file;
		inFileName.push_back(file);
		inFileName+=".txt";
		string outFileName;
		outFileName.push_back(file);
		outFileName+= "out.txt";
		//cout<<outFileName;

		ifstream fin(inFileName);
		initialise(N1);
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
			int P;
			fin>>P;
			//long long distSum=0;
			//vector<int> path;
			distSum[i].y=i;
			while(P--)
			{
				string s;
				fin>>s;
				int sId=nameToId[s];
				distSum[i].first+=L[sId];
				path[i].push_back(sId);
				if(P>1)
					cntStreet[sId]++;
				else if(P==1)
					cntStreet[sId]+=6;

			}
			//if(distSum>D)
			//{
				//continue;
			//}
			//path.pop_back();
			//for(auto sId:path)
			//{
				//cntStreet[sId]++;
			//}
			
		}
		//for(int i=0;i<S;i++)
			//cout<<cntStreet[i]<<"\n";
		//for(int i=0;i<S;i++)
			//if(L[i]>D/8)
				//cntStreet[i]=0;
		//sort(distSum+1,distSum+V+1);
		//for(int i=1;i<=V;i++)
		//{
			//path[i].pop_back();
			//for(auto st:path[i])
			//{
				//cntStreet[st]++;
				//if(i<=V/2)
					//cntStreet[st]++;
			//}
		//}
		int A=0;
		for(int i=0;i<=I;i++)
		{
			int sz=0;
			for(auto i1:adjInp[i])
			{
				if(cntStreet[i1]>0)
				{
					sz++;
				}
			}
			if(sz>0)
				A++;
		}

		ofstream fout(outFileName);
		fout<<A<<"\n";

		map<int,int> jugad;
		for(int i=0;i<I;i++)
		{
			//cout<<i<<": ";
			if(adjInp[i].size()==0)
				continue;
			long long int sz=0;
			//cout<<adjInp[i].size()<<"\n";
			sort(adjInp[i].begin(),adjInp[i].end(),comp);
			//int g=cntStreet[adjInp[i][0]];
			long long g=0;
			for(auto i1:adjInp[i])
			{
				//cout<<cntStreet[i1]<<" ";
				if(cntStreet[i1]>0)
				{
					//g=__gcd(cntStreet[i1],g)
					g+=cntStreet[i1];
					sz++;
				}
			}
			//cout<<" *"<<sz<<"\n";
			jugad[sz]++;
			if(sz==0)
				continue;
			fout<<i<<"\n";
			fout<<sz<<"\n";
			//sz=sz*2;

			int cnt = adjInp[i].size();
            int jj = 1;
			for(auto i1:adjInp[i])
			{
				if(cntStreet[i1]>0){
                    jj++;
					fout<<intersectionName[i1]<<" ";
                    if(jj < sz/3){
                        fout<<3<<"\n";
                    }
                    else if(jj < (2*sz)/3){
                        fout<<2<<"\n";
                    }
                    else{
                        fout<<1<<"\n";
                    }
                }
			}		//for(auto i1:adjInp[i])
			//{
				//if(cntStreet[i1]>0)
				//{
					//long long int d1=((cntStreet[i1]+g-1)*2LL)/g;
					////d1=2;
					//d1=min((long long)D,d1);
					//fout<<intersectionName[i1]<<" "<<d1<<"\n";
				//}
			//}
		}
		for(auto u:jugad)
			cout<<u.x<<" "<<u.y<<"\n";

		fout.close();
		fin.close();
    }
    return 0;
}
