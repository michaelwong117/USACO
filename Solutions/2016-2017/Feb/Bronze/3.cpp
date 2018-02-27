#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

	ofstream fout("cowqueue.out");
	ifstream fin("cowqueue.in");
	int n;
	fin >> n;
	map<int, int> times;
	for(int i = 0; i < n; i++){
		int s, p;
		fin >> s >> p;

		if(times.count(s) > 0){
			times[s] += p;
		}
		else{
			times[s] = p;
		}
	}

	int currentTime = 0;
	for(auto x: times){
		if(currentTime == 0){
			currentTime = x.first + x.second;
		}
		else{
			
			if(currentTime < x.first){
				currentTime = x.first+x.second;
			}
			else{
				currentTime += x.second;
			}

		}
	}
	fout << currentTime << endl;


}
