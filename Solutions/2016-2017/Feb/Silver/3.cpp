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

int N, K, R;
//burn memory to save time
vector<pii> cows;
vector<vector<bool>> seenCoord(200, vector<bool>(200));
vector<vector<bool>> lookup(200, vector<bool>(200)), roadRow(200, vector<bool>(200)), roadCol(200, vector<bool>(200));
vector<int> seen (200);

//roadRow is always in increasing order (0,0 -> 0,1) is represented as 0,0
//same with road Col (0,0 -> 1,0) is represented as 0,0


bool valid(pii start, pii finish){
	
	//if it's out of bounds

	if(finish.fir < 1 || finish.fir > N){
		return false;
	}
	if(finish.sec < 1 || finish.sec > N){
		return false;
	}

	if(seenCoord[finish.fir][finish.sec]){
		return false;
	}
	//columns are changing
	if(start.fir == finish.fir){
		//col decreasing
		if(start.sec > finish.sec){
			if(roadCol[start.fir][start.sec-1]){
				return false;
			}
		}
		//col increasing
		else{
			if(roadCol[start.fir][start.sec] == 1){
				return false;
			}
		}
		
	}
	//rows are changing
	else{
		//row decreasing
		if(start.fir > finish.fir){
			if(roadRow[start.fir-1][start.sec] == 1){
				return false;
			}
		}
		//row increasing
		else{
			if(roadRow[start.fir][start.sec] == 1){
				return false;
			}
		}
	}
	//mark as seen
	seenCoord[finish.fir][finish.sec] = 1;
	return true;
}

void bfs(pii cow, int group){
	queue<pii> q;
	q.push(cow);
	//initialize the group of cows
	seen[group] = 1;
	//mark initial as seen
	seenCoord[cow.fir][cow.sec] = 1;
	while(!q.empty()){
		pii f = q.front();
		q.pop();
		//if you aren't looking at the saem cow
		if(f != cow){
			//if you find a cow
			if(lookup[f.fir][f.sec] == 1){
				lookup[f.fir][f.sec] = 0;
				//increment the size of the group
				seen[group]++;
			}	
		}
		if(valid(f, pii(f.fir+1, f.sec))){
			q.push(pii(f.fir+1, f.sec));
		}
		if(valid(f, pii(f.fir, f.sec+1))){
			q.push(pii(f.fir, f.sec+1));
		}
		if(valid(f, pii(f.fir-1, f.sec))){
			q.push(pii(f.fir-1, f.sec));
		}
		if(valid(f, pii(f.fir, f.sec-1))){
			q.push(pii(f.fir, f.sec-1));
		}
	}
	
}


int main(){
  ifstream fin ("countcross.in");
  ofstream fout ("countcross.out");
  fin >> N >> K >> R;
  int tot = 0;
  for(int i = 0; i < R; i++){
  	int r1, c1, r2, c2;
  	fin >> r1 >> c1 >> r2 >> c2;
  	if(r1 == r2){
  		if(c1 > c2){
  			roadCol[r1][c1-1] = 1;
  		}
  		else{
  			roadCol[r1][c1] = 1;
  		}
  	}
  	else{
  		if(r1 > r2){
  			roadRow[r1-1][c1] = 1;
  		}
  		else{
  			roadRow[r1][c1] = 1;
  		}
  	}

  	//indicates road between field at r1,c1 and r2, c2

  }
  for(int i = 0; i < K; i++){
  	int r, c;
  	fin >> r >> c;
  	cows.push_back(pii(r, c));
  	lookup[r][c] = 1;
  }
  for(int i = 0; i < cows.size(); i++){
  		//if you haven't explored the group before
  		if(lookup[cows[i].fir][cows[i].sec] == 1){
  			//run a bfs on the group and all nodes that
  			//reach one another without nodes
  			//use i+1 to mark groups
  			bfs(cows[i], i+1);

  		}

  }
  
  vector<int> groups;
  for(int i = 0; i < seen.size(); i++){
  		if(seen[i] != 0){
  			groups.push_back(seen[i]);
  			//put all sizes of groups into vector groups
  		}
  		
  }
  for(int i = 0; i < groups.size()-1; i++){
  	int sum = 0;
  	for(int j = i+1; j < groups.size(); j++){
  		//to see how many can't reach one another
  		//take the sum of all groups beside the current
  		//and already seen pairings
  		//and multiply it by the current group
  		sum += groups[j];
  	}
  	tot += groups[i] * sum;
  }
  fout << tot << endl;

  //run a bfs to see if there is any way for the cow to cross
  //without crossing road
  //each cow is a node
  //if there is a path from one cow to another such that
  //you do not have to pass a road, it is not distant


}
