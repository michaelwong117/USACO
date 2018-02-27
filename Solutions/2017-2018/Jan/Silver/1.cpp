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

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ofstream fout ("lifeguards.out");
    ifstream fin ("lifeguards.in");
	int N;
	fin >> N;
	vector<pii> l;
	for(int i = 0; i < N; i++){
		int a, b;
		fin >> a >> b;
		l.pb({a,i});
		l.pb({b,i});
	}
	sort(all(l));
	ll totalTime = 0, lastTime = 0;
	set<int> seen;
	vector<int> alone (N);
	for(int i = 0; i < l.size(); i++){
		if(seen.size() == 0){
			seen.insert(l[i].s);
		}
		else{
			totalTime += l[i].f - lastTime;
			auto it = seen.find(l[i].s);
			if(seen.size() == 1){
				alone[*seen.begin()] += l[i].f - lastTime; 
			}
			if(it != seen.end()){

				seen.erase(it);
			}
			else{
				seen.insert(l[i].s);
			}
		}
		lastTime = l[i].f;

	}
	int ret = 99999999;
	for(auto a: alone){
		ret = min(ret, a);
	}
	fout << totalTime-ret << endl;

	
}
