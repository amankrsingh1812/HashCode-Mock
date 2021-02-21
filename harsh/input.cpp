#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)
#define PB push_back

#include<bits/stdc++.h>

using namespace std;

void splitString(string &s, vector<string> &words, ll &n){
	string temp;
	for(int i=0;i<s.length();i++){
		if(s[i]!=' ')temp+=s[i];
		else {
			if(n==-1){
				n=stoll(temp);
				temp="";
			} else {
				words.PB(temp);
				temp="";
			}
		}
	}
	if(temp.length()){
		words.PB(temp);
	}
}

int main(){

	fstream fin, fout;
	fin.open("a_example", ios::in);

	ll m;
	string temporary;
	getline(fin,temporary,'\n');
	m=stoll(temporary);

	vector<string> arr[m];

	REP(i,0,m){
		ll len=-1;
		string s;
		getline(fin,s,'\n');
		splitString(s,arr[i],len);
	}

	// REP(i,0,m){
	// 	REP(j,0,arr[i].size()){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	fin.close();

}