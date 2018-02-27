//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int, string> pis;
typedef pair<int,int> pii;

//set tab size to 3

struct cow {
	int x;
	int y;
	int power;
	int index;
};

int distance(cow a, cow b){
	//sqrt ((x2 - x2)^2 + (y2 - y1)^2)
	return floor(sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)));

}

int bfs(vector<cow> v, int i){
	set<int> seen;
	queue<cow> q;
	q.push(v[i]);
	seen.insert(i);
	int reach = 1;
	while(!q.empty()){
		cow f = q.front();
		q.pop();
		for(int j = 0; j < v.size(); j++){
			if(f.index == j) continue;
			if(f.power > distance(f, v[j])){
				if(seen.find(j) == seen.end()){
					seen.insert(j);
					q.push(v[j]);
					reach++;
				}
				
			}
		}
	}
	return reach;
}

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("moocast.in");
	ofstream fout("moocast.out");
	int N, max = 0;
	fin >> N;
	vector<cow> v (N);
	for(int i = 0; i < N; i++){
		fin >> v[i].x >> v[i].y >> v[i].power;
		v[i].index = i;
	}
	for(int i = 0; i < v.size(); i++){
		int reach = bfs(v, i);
		if(reach > max){
			max = reach;
		}
	}
	fout << max << endl;





	
}
