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

bool lessThan(ll a, ll b, ll c, ll d){
    if(b == d){
        return a < c;
    }
    else{
        
        return a*d < c*b;

    }
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("homework.in");
	ofstream fout("homework.out");
	int N;
	fin >> N;
	vector<ll> v (N);
	vector<ll> averages;
	ll min = 9999999;
	for(int i = 0; i < N; i++){
		fin >> v[i];
	}
	for(int i = v.size()-1; i >= 0; i--){
		if(i == v.size()-1){
			min = v[i];
			averages.push_back(0);
		}
		else{
			ll next = v[i] + averages[v.size()-i-2];
			if(v[i] < min){
				next += min;
				min = v[i];
				next -= min;
				averages.push_back(next);
			}
			else{
				averages.push_back(next);
			}
		}
	}
	pll max = pll(0, 1);
	vector<int> maxes;
	for(int i = 1; i < averages.size(); i++){
		if(lessThan(max.fir, max.sec, averages[i], i)){
			maxes.clear();
			max = pll(averages[i], i);
			maxes.push_back(i);
		}
		else{
			if(max.fir * i ==  max.sec * averages[i]){
				maxes.push_back(i);
			}

		}
	}
	sort(maxes.begin(), maxes.end(), greater<int>());
	for(auto a: maxes){
		if(v.size() - 1 - a != 0){
			fout << v.size() - 1 - a << endl;
		}
	}




	
}
