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
typedef pair<ll,ll> pii;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin("reststops.in");
	ofstream fout("reststops.out");
	vector<pii> rests;
	ll pathL, stops, Fspeed, Bspeed;
	fin >> pathL >> stops >> Fspeed >> Bspeed;
	for(ll i= 0; i < stops; i++){
		ll distS, tasty; 
		fin >> distS >> tasty;
		rests.pb({distS, tasty});
	}
	vector<pii> newrests;
	int maxTasty = 0;
	for(ll i = rests.size()-1; i >= 0; i--){
		if(rests[i].s > maxTasty){
			maxTasty = rests[i].s;
			newrests.pb(rests[i]);
		}
	}
	rests.clear();
	for(int i = newrests.size()-1; i >= 0; i--){
		rests.pb(newrests[i]);
	}
	pii bigPast = {-1, -1};
	for(ll i = 0; i < rests.size(); i++){
		//without stopping
		ll timethereB = rests[i].f*Bspeed;
		ll timethereF = rests[i].f*Fspeed;
		ll tasty = (timethereF-timethereB)*rests[i].s;
		//if this is first stop
		if(bigPast.f == -1){
			//bigPast.f = distance from beginning
			//bigPast.s = amount of tastiness gathered
			bigPast = {rests[i].f, tasty};
			continue;
		}
		//if you've stopped before
		ll disttonextStop = rests[i].f - bigPast.f;
		ll secondstoEat = (disttonextStop*Fspeed) - (disttonextStop*Bspeed);
		ll additionaltasty = secondstoEat*rests[i].s;
		if(bigPast.s + additionaltasty > tasty){
			bigPast = {rests[i].f, bigPast.s + additionaltasty};
		}
		else{
			bigPast = {rests[i].f, tasty};
		}	

	} 
	fout << bigPast.s << endl;

	
}
