#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back

#include<bits/stdc++.h>

using namespace std;

void splitString(string &s, vector<string> &words){
	string temp;
	for(int i=0;i<s.length();i++){
		if(s[i]!=' ')temp+=s[i];
		else {
			words.PB(temp);
			temp="";
		}
	}
	if(temp.length()){
		words.PB(temp);
	}
}

int main(int argc, char *argv[]){

	if(argc!=2){
		cout<<"Please mention input file\n";
		return 0;
	}

	fstream fin, fout;
	fin.open(argv[1], ios::in);

	ll m, t2, t3, t4;
	string temporary;
	vector<string> words;
	getline(fin,temporary,'\n');
	splitString(temporary,words);
	m=stoll(words[0]);
	t2=stoll(words[1]);
	t3=stoll(words[2]);
	t4=stoll(words[3]);

	vector<string> arr[m];

	REP(i,0,m){
		string s;
		getline(fin,s,'\n');
		splitString(s,arr[i]);
	}

	fin.close();

	map<string, ll> ingr;
	map<ll,set<ll>> ingrToPizza;

	REP(i,0,m){
		REP(j,1,arr[i].size()){
			if(ingr.find(arr[i][j])==ingr.end()){
				ingr[arr[i][j]]=ingr.size();
				ingrToPizza[ingr[arr[i][j]]].insert(i);
			} else {
				ingrToPizza[ingr[arr[i][j]]].insert(i);
			}
		}
	}

	set<ll> availablePizzas;
	REP(i,0,m){
		availablePizzas.insert(i);
	}
	set<ll> availableIngr;
	REP(i,0,ingr.size()){
		availableIngr.insert(i);
	}

	fout.open("output.txt",ios::out);

	while(t2>0){
		if(availablePizzas.size()<2)
			break;
		fout<<2<<" ";
		if(availableIngr.size()>=2){
			int coun=0;
			for(auto u:ingrToPizza){
				int x=-1;
				for(auto v:u.second){
					if(availablePizzas.find(v)!=availablePizzas.end()){
						x=v;
						break;
					}
				}
				if(x==-1){
					fout<<(*availablePizzas.begin())<<" ";
					availablePizzas.erase(*availablePizzas.begin());
				} else {
					availablePizzas.erase(x);
					fout<<x<<" ";
				}

				coun++;
				if(coun==2)break;
			}
		} else {
			for(int i=0;i<2;i++){
				fout<<(*availablePizzas.begin())<<" ";
				availablePizzas.erase(*availablePizzas.begin());
			}
		}
		fout<<'\n';

		t2--;
	}
	while(t3>0){
		if(availablePizzas.size()<3)
			break;

		fout<<3<<" ";
		if(availableIngr.size()>=3){
			int coun=0;
			for(auto u:ingrToPizza){
				int x=-1;
				for(auto v:u.second){
					if(availablePizzas.find(v)!=availablePizzas.end()){
						x=v;
						break;
					}
				}
				if(x==-1){
					fout<<(*availablePizzas.begin())<<" ";
					availablePizzas.erase(*availablePizzas.begin());
				} else {
					availablePizzas.erase(x);
					fout<<x<<" ";
				}

				coun++;
				if(coun==3)break;
			}
		} else {
			for(int i=0;i<3;i++){
				fout<<(*availablePizzas.begin())<<" ";
				availablePizzas.erase(*availablePizzas.begin());
			}
		}
		fout<<'\n';

		t3--;
	}
	while(t4>0){
		if(availablePizzas.size()<4)
			break;

		fout<<4<<" ";
		if(availableIngr.size()>=4){
			int coun=0;
			for(auto u:ingrToPizza){
				int x=-1;
				for(auto v:u.second){
					if(availablePizzas.find(v)!=availablePizzas.end()){
						x=v;
						break;
					}
				}
				if(x==-1){
					fout<<(*availablePizzas.begin())<<" ";
					availablePizzas.erase(*availablePizzas.begin());
				} else {
					availablePizzas.erase(x);
					fout<<x<<" ";
				}

				coun++;
				if(coun==4)break;
			}
		} else {
			for(int i=0;i<4;i++){
				fout<<(*availablePizzas.begin())<<" ";
				availablePizzas.erase(*availablePizzas.begin());
			}
		}
		fout<<'\n';

		t4--;
	}


	// cout<<m<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
	// REP(i,0,m){
	// 	REP(j,0,arr[i].size()){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	

}