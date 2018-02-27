#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <numeric>
#include <cmath>

#define ll long long
#define fir first
#define sec second
#define MOD 1e9 + 7

using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;


struct Qu {
    int w;
    int vid;
    int index;

};

struct Edge {
	int relev;
	int pp;
	int qq;
};

vector<Qu> queries;
vector<Edge> edges;
map<int, int> parent;
vector<int> order, CC;


int findSet(int x){
	if(x != parent[x]) parent[x] = findSet(parent[x]);
	return parent[x];
}
void mergeSet(int x, int y){
	int rootX = findSet(x);
	int rootY = findSet(y);
	if(order[rootX] > order[rootY]){
		CC[rootX] += CC[rootY];
		parent[rootY] = rootX;
	}
	else{
		CC[rootY] += CC[rootX];
		parent[rootX] = rootY;
	}	
	if(order[rootX] == order[rootY]) order[rootY]++;

}
//set tab size to 3
int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("mootube.in");
	ofstream fout("mootube.out");
	int N, Q;
	fin >> N >> Q;
	queries.resize(Q);
	order.resize(N+1);
	CC.resize(N+1, 1);
	parent[N] = N;
	for(int i = 0; i < N-1; i++){
		parent[i+1] = i+1;
		int p, q, r;
		fin >> p >> q >> r;
		Edge E;
		E.pp = p;
		E.qq = q;
		E.relev = r;
		edges.push_back(E);
	}
	for(int i = 0; i < Q; i++){
		int k, v;
		fin >> k >> v;
		queries[i].w = k;
		queries[i].vid = v;
		queries[i].index = i;
	}
	//sorting the queries to fill in the graph bit by bit
	sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
		return a.relev > b.relev;
	});
	sort(queries.begin(), queries.end(), [](const Qu& a, const Qu& b) {
		return a.w > b.w;
	});
	vector<int> res (Q);
	int j = 0;
	for(int i = 0; i < queries.size(); i++){
		while(j < edges.size() && edges[j].relev >= queries[i].w){
				mergeSet(edges[j].pp, edges[j].qq);
				j++;
		}
		res[queries[i].index] = CC[findSet(queries[i].vid)]-1;

	}
	for(auto a: res){
		fout << a << endl;
	}

	
}	
