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


//2 seconds runtime
//256 megabytes
//X - incorrect, T - time limit, ! - runtime or memory
//E = empty output file, M - missing output file
//make sure that you have correct finder/terminal directories

int main(){
	ifstream fin ("helpcross.in");
	ofstream fout ("helpcross.out");
	int C, N, count = 0;
	fin >> C >> N;
	vector<int> chickens;
	vector<pii> cows;
	for(int i = 0; i < C; i++){
		int a;
		fin >> a;
		chickens.push_back(a);
	}
	sort(chickens.begin(), chickens.end());
	for(int i = 0; i < N; i++){
		int x, y;
		fin >> x >> y;
		cows.push_back(pii(y, x));
		// cout << T[i] << endl;
	}
	sort(cows.begin(), cows.end());
	for(int i = 0; i < cows.size(); i++){
		auto chicken = lower_bound(chickens.begin(), chickens.end(), cows[i].sec);
		if(chicken != chickens.end() && cows[i].fir >= *chicken){
			count++;
			chickens.erase(chicken);
		}

	}
	fout << count << endl;

}






