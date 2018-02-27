//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define heap priority_queue<int>
#define vi vector<int>

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

int N;

vector<vi> fmatch(vi &moves){
	vector<vi> res(3, vi(N+1));
	for(int i = 1; i <= N; i++){
		for(int j = 0; j < 3; j++){
			res[j][i] = res[j][i-1];
		}
		res[moves[i-1]][i]++;

	}
	return res;
}



int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("hps.in");
	ofstream fout("hps.out");
	fin >> N;
	vi V (N), revV (N);
	for(int i = 0; i < N; i++){
		char a;
		fin >> a;
		if(a == 'P'){
			V[i] = 1;
			revV[N-i-1] = 1;
		}
		if(a == 'S'){
			V[i] = 2;
			revV[N-i-1] = 2;
		}
	}
	int ret = 0;
	vector<vi> prefix = fmatch(V), suffix = fmatch(revV);
	for(int i = 0; i <= N; i++){
		for(int a = 0; a < 3; a++){
			for(int b =	0; b < 3; b++){
				ret = max(ret, prefix[a][i] + suffix[b][N-i]);
			}
		}
	}
	fout << ret << endl;
}
