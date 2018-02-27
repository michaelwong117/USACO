#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

vector<vector<pii>> v;
vector<bool> Seen (100001);

int N, Q;
int bfs(int vid, int w){
	int count = 0;
	queue<pii> q;
	q.push(pii(vid, -1));
	Seen[vid] = 1;
	while(!q.empty()){
		pii f = q.front();
		q.pop();
		for(int i = 0; i < v[f.fir].size(); i++){
			if(Seen[v[f.fir][i].fir] == 0){
				Seen[v[f.fir][i].fir] = 1;
				if(f.sec == -1){
					if(v[f.fir][i].sec >= w){
						count++;
					}
					q.push(pii(v[f.fir][i].fir, v[f.fir][i].sec));
				}
				else if(min(f.sec, v[f.fir][i].sec) >= w){
					count++;
				}
				q.push(pii(v[f.fir][i].fir, min(f.sec, v[f.fir][i].sec)));

			}
		}
	}
	return count;
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");
	fin >> N >> Q;
	v.resize(N+1);
	for(int i = 0; i < N-1; i++){
		int p, q, r;
		fin >> p >> q >> r;
		v[p].push_back(pii(q, r));
		v[q].push_back(pii(p, r));
	}
	for(int i = 0; i < Q; i++){
		int k, vid, count = 0;
		fin >> k >> vid;
		fout << bfs(vid, k) << endl;
		Seen.clear();
		Seen.resize(100001);
	}
}
