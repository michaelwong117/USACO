#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	ofstream fout("crossroad.out");
	ifstream fin("crossroad.in");
	int N;
	int counter = 0;
	fin >> N;
	map<int, int> m;
	for(int i=0;i<N;++i){
		int cow;
		int position;
		fin >> cow >> position;
		//checks if cow in map
		if (m.find(cow) != m.end()){
			if (m[cow] != position){
				counter++;
			}
		}

		m[cow] = position;

	}
	fout << counter << endl;


}
