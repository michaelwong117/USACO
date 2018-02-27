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
typedef pair<ll, ll> pll;

//set tab size to 3

vector<pll> price;
ll i = 0;
ll milk(ll quant){
	ll sum = 0;
	while(quant != 0 && i < price.size()){
		//sell as many as possible at highest price
		ll q = min(quant, price[i].sec);
		//adding the max quantitiy possible * price
		sum += q * price[i].fir;
		//quantity decreases
		price[i].sec -= q;
		quant -= q;
		//if there is no more left to sell, move to next
		if(price[i].sec == 0){
			i++;
		}
	}
	return sum;
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("rental.in");
	ofstream fout("rental.out");
	ll N, M, R;
	fin >> N >> M >> R;
	price.resize(M);
	vector<ll> cows (N);
	vector<ll> rent (R);
	vector<ll> prent (R);
	vector<ll> pmilk (N);
	for(ll i = 0; i < N; i++){
		fin >> cows[i];
	}
	for(ll i = 0; i < M; i++){
		ll q, p;
		fin >> q >> p;
		price[i] = pll(p, q);
	}
	for(ll i = 0; i < R; i++){
		fin >> rent[i];
	}
	sort(rent.begin(), rent.end(), greater<ll>());
	sort(price.begin(), price.end(), greater<pll>());
	sort(cows.begin(), cows.end(), greater<ll>());

	for(ll i = 0; i < R; i++){
		if(i == 0){
			prent[i] = rent[i];
		}
		else{
			prent[i] = prent[i-1] + rent[i];
		}
	}
	for(int i = 0; i < cows.size(); i++){
		if(i == 0){
			pmilk[i] = milk(cows[i]);
		}
		else{
			pmilk[i] = pmilk[i-1] + milk(cows[i]);
		}
	}

	ll m = -10000000;
	for(int i = 0; i < pmilk.size(); i++){
		//deal with unsigned translation problemse
		if(i+2 > cows.size()){
			m = max(m, pmilk[i]);
		}
		else{
			m = max(m, pmilk[i] + prent[min(prent.size()-1, (cows.size()-i)-2)]);
		}
	}
	fout << m << endl;
		

	
}
