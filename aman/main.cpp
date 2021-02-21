#include <bits/stdc++.h>
using namespace std;

// bool comp(pair<int,int> v1, pair<int,int> v2)
// {
//     return v1.second < v2.second;
// }
int main()
{
    string name = "d";
    ifstream fin("inputs/"+name+".in");
    int m;
    fin >> m;
    int t[5];
    fin >> t[2] >> t[3] >> t[4];
    vector<pair<int,int>> piz;
    for (int i = 0; i < m; i++)
    {
        int l;
        fin >> l;
        int t2=0;
        while (l--)
        {
            string s;
            fin >> s;
            t2++;
        }
        piz.push_back({t2,i});
        // sort(piz[i].begin(), piz[i].end());
    }
    sort(piz.begin(), piz.end());
    int i = piz.size();
    i--;
    vector<int> ord = {4, 2, 3};
    vector<vector<int>> ans;
    for (auto j : ord)
    {
        while (t[j]--)
        {
            if (i - j >= 0)
            {
                vector<int> tans;
                tans.push_back(j);
                for (int k = 0; k < j; k++)
                    tans.push_back(piz[i--].second);
                ans.push_back(tans);
            }
        }
    }
    ofstream fout("outputs/"+name+".out");
    fout << ans.size() << "\n";
    for (auto v : ans)
    {
        for (auto u : v)
            fout << u << " ";
        fout << "\n";
    }
}