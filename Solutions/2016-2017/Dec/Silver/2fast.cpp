#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

int main(){

	ifstream fin("citystate.in");
	ofstream fout("citystate.out");
	int n, count = 0;
	fin >> n;
	vector<vector<int>> v (676, vector<int>(676)); 

	for(int i = 0; i < n; i++){
		//a = Florida
		//b = FL
		string city, state;
		fin >> city >> state;
		city = city.substr(0, 2);
		int state_val = 26*(state[0] - 'A') + (state[1] - 'A');
		int city_val = 26*(city[0] - 'A') + (city[1] - 'A');

		v[city_val][state_val]++;

		
	}
	int sum = 0;
	for(int i = 0; i < 676; i++){
		for(int k = i+1; k < 676; k++){
			sum += v[i][k] * v[k][i];
		}
	}
	fout << sum << endl;

}
