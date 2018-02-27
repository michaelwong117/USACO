
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

	ofstream fout("notlast.out");
	ifstream fin("notlast.in");
	//remember to use fin and fout
	int n;
	fin >> n;
	map<string, int> cowToMilk;
	for(int i = 0; i < n; i++){
		string cow;
		int milk;
		fin >> cow >> milk;
		if(cowToMilk.count(cow) == 0){
			cowToMilk[cow] = milk;
		}
		else{
			cowToMilk[cow] += milk;
		}
	}
	bool missing = false;
	vector<string> cows = {"Bessie", "Maggie", "Elsie", "Henrietta", "Gertie", "Daisy", "Annabelle"};
	for(string cow: cows){
		if(cowToMilk.count(cow) == 0){
			missing = true;
		}
	}

	if(missing){
		int minMilk = 101;
		for(auto x: cowToMilk){
			if(x.second < minMilk){
				minMilk = x.second;
			}
		}
		vector<string> secondLeastCow;
		for(auto x: cowToMilk){
			if(x.second == minMilk){
				secondLeastCow.push_back(x.first);
			}
		}
		if(secondLeastCow.size() == 1){
			fout << secondLeastCow[0] << endl;
		}
		else{
			fout << "Tie" << endl;
		}
	}
	else{

		int minMilk = 999999;
		int secondLeast = 999999;
		for(auto x: cowToMilk){
			if(x.second < minMilk){

				secondLeast = minMilk;
				minMilk = x.second;
			}
			else if((x.second < secondLeast) && (x.second > minMilk)){
				secondLeast = x.second;
			}
			// fout << x.first << " " << x.second << endl;
		}
		// cout << minMilk << " " << secondLeast << endl;
		vector<string> secondLeastCow;
		for(auto x: cowToMilk){
			if(x.second == secondLeast){
				secondLeastCow.push_back(x.first);
			}
		}
		if(secondLeastCow.size() == 1){
			fout << secondLeastCow[0] << endl;
		}
		else{
			fout << "Tie" << endl;
		}
	}

}
