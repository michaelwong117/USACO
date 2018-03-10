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

int editDist(string &s1, string &s2){
	int dp[s1.size()+1][s2.size()+1];
	for(int a = 0; a <= s1.size(); a++){
		for(int b = 0; b <= s2.size(); b++){
			//take first a chars of s1
			//take first b chars of s2
			//dp[a][b] = edit distance between prefix a and prefix b
			//if a is empty insert all of b
			if(a == 0){
				dp[a][b] = b;
			}
			//if b is empty remove all of a
			else if(b == 0){
				dp[a][b] = a;
			}
			//if last character is the same
			else if(s1[a-1] == s1[b-1]){
				dp[a][b] = dp[a-1][b-1];
			}
			else{
				//dp[a-1][b]+1: remove char from a
				//dp[a][b-1]+1: insert char to a
				//dp[a-1][b-1]+1: replace a char
				dp[a][b] = 1+min(dp[a-1][b], dp[a][b-1], dp[a-1][b-1]);
			}
		}
	}
	//edit distance between full strings
	return dp[s1.size()][s2.size()];
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("filename.in");
	ofstream fout("filename.out");
	string s1, s2;
	return editDist(s1, s2);
	
}
