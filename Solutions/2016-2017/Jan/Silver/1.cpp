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

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

int N, Tmax;
vector<int> d;

int danceTime(int K){
	pq q;
	int maxTime = 0;
	for(int i = 0; i < N; i++){
		if(q.size() == K){
			int min = q.top()+d[i];
			maxTime = max(maxTime, min);
			q.pop();
			q.push(min);
		}
		else{
			q.push(d[i]);
			maxTime = max(maxTime, d[i]);
		}
	}
	return maxTime;
}

int bsearch(int Tmax) {
	if (Tmax < danceTime(N-1)){
		return N;
	}
	int lo = 1, hi = N;
	while(lo < hi) {
		int mid = (lo + hi) / 2, d = danceTime(mid);
		if (d <= Tmax){
			hi = mid;
		}
		else{
			lo = mid+1;
		}
	}
	return lo;
}
int main(){ 
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("cowdance.in");
	ofstream fout("cowdance.out");
	fin >> N >> Tmax;
	d.resize(N);
	for(int i = 1; i <= N; i++){
		fin >> d[i-1];
	}
	fout << bsearch(Tmax) << endl;

	
}
