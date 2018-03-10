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
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	vector<int> s;
	//to find specific sum, set sum = wanted value
	int sum = 0;
	//to find all sums possible
	for(int i = 0; i < s.size(); i++) sum += s[i];
	//[first k elem used][sum]
	//any set with zero is 1
	bool pos[s.size()+1][sum+1];
	for(int i = 0; i <= s.size(); i++){
		pos[i][0] = 1;
	}
	for(int i = 1; i <= sum; i++){
		for(int j = 1; j <= s.size(); j++){
			pos[j][i] |= pos[j-1][i];
			if(i-s[j] >= 0){
				pos[j][i] |= pos[j-1][i-s[j]];
			}
		}		
	}
	//short version
	//sum equals total sum or desired
	bool pos[sum+1];
	pos[0] = 1;
	for(int j = 1; j <= s.size(); j++){
		for(int i = sum; i >= 0; i--){
			if(pos[sum]) pos[sum + s[j]] = 1;
		}
	}
	cout << pos[s.size()][sum] << endl;
	
	
	
}
