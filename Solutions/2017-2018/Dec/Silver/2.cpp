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

struct cow {
	int day;
	int id;
	int change;
};

//set tab size to 3

int main(){
	//codeforces cin
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	int N, G;
	fin >> N >> G;
	vector<cow> v (N); 
	map<int, int> idVal;
	for(int i = 0; i < N; i++){
		fin >> v[i].day >> v[i].id >> v[i].change;
		idVal[v[i].id] = G;
	}
	sort(v.begin(), v.end(), [](cow a, cow b) {
		return a.day < b.day;
	});
	int max = G, count = 0;
	for(int i = 0; i < v.size(); i++){
		if(i == 0){
			idVal[v[i].id] += v[i].change;
			count++;
			if(v[i].change > 0){
				max += v[i].change;
			}
			continue;
		}
		else if(idVal[v[i].id] == max){
			int c = 0;
			if(v[i].change > 0){
				if(max == G){
					count++;
				}
				else{
					for(auto x: idVal){
						if(x.sec == max){
							c++;
						}
					}
					if(c > 1){
						count++;
					}	
				}
				idVal[v[i].id] += v[i].change;
				max += v[i].change;
			}
			else{
				max = 0;
				idVal[v[i].id] += v[i].change;
				for(auto x: idVal){
					if(x.sec == idVal[v[i].id]) c++;
					if(x.sec > max){
						max = x.sec;
					}
				}
				if(G > max){
					max = G;
				}
				if(max != idVal[v[i].id] || c > 1){
					count++;
				}
			}
			
		}
		else{
			idVal[v[i].id] += v[i].change;
			if(idVal[v[i].id] >= max){
				count++;
				max = idVal[v[i].id];
			}
		}

	}
	fout << count << endl;
	return 0;
}


	
