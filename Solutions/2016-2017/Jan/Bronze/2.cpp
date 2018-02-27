
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>

using namespace std;

int main(){

	ofstream fout("hps.out");
	ifstream fin("hps.in");
	//remember to use fin and fout
	int n;
	fin >> n;
	vector<int> cow1;
	vector<int> cow2;
	for(int i = 0; i < n; i++){
		int a;
		int b;
		fin >> a >> b;
		cow1.push_back(a);
		cow2.push_back(b);
	}
	int count1 = 0;
	for(int i = 0; i < n; i++){
		if((cow1[i] == 1) && (cow2[i] == 2)){
			count1++;
		}
		if((cow1[i] == 2) && (cow2[i] == 3)){
			count1++;
		}
		if((cow1[i] == 3) && (cow2[i] == 1)){
			count1++;
		}
	}
	int count2 = 0;
	for(int i = 0; i < n; i++){
		if((cow1[i] == 1) && (cow2[i] == 3)){
			count2++;
		}
		if((cow1[i] == 2) && (cow2[i] == 1)){
			count2++;
		}
		if((cow1[i] == 3) && (cow2[i] == 2)){
			count2++;
		}
	}
	fout << max(count1, count2) << endl;

}
