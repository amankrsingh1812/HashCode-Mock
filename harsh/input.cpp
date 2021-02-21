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

int main(){

	fstream fin, fout;
	fin.open("a_example", ios::in);

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

	// cout<<m<<" "<<t2<<" "<<t3<<" "<<t4<<endl;
	// REP(i,0,m){
	// 	REP(j,0,arr[i].size()){
	// 		cout<<arr[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }

	fin.close();

}