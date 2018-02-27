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

typedef pair<int,int> pii;

vector<int> unshuffle(vector<int> &v, vector<int> &shuffles){
	vector<int> temp = v;
	for(int i = 0; i < shuffles.size(); i++){
		temp[i] = v[shuffles[i]-1];
	}
	return temp;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int N;
	fin >> N;
	vector<int> shuffles (N);
	vector<int> final;
	for(int i = 0; i < N; i++){
		fin >> shuffles[i];
	}
	for(int i = 0; i < N; i++){
		int a;
		fin >> a;
		final.push_back(a);
	}
	for(int i = 0; i < 3; i++){
		final = unshuffle(final, shuffles);
	}
	for(auto a: final){
		fout << a << endl;
	}

	

}
