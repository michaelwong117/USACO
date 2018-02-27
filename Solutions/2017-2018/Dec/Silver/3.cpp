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

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("shuffle.in");
	ofstream fout("shuffle.out");
	int N, sum = 0;
	fin >> N;
	vector<int> cows (N+1);
	vector<int> weights (N+1);
	vector<int> leaves (N+1);
	for(int i = 1; i <= N; i++){
		fin >> cows[i];
		weights[cows[i]]++;
		leaves[i] = cows[i];
	}
	queue<int> q;
	for(int i = 1; i < weights.size(); i++){
		if(weights[i] == 0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int f = q.front();
		q.pop();
		weights[leaves[f]]--;
		if(weights[leaves[f]] == 0){
			q.push(leaves[f]);
		}
	}
	for(int i = 1; i < weights.size(); i++){
		if(weights[i] > 0){
			sum++;
		}
	}
	fout << sum << endl;
	
}
