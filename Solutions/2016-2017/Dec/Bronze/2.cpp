#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){

	ofstream fout("blocks.out");
	ifstream fin("blocks.in");
	int n;
	fin >> n;
	map<char, int> blocks;
	string alpha = "abcdefghijklmnopqrstuvwxyz";
	for(char c: alpha){
		blocks[c] = 0;
	}
	for(int i = 0; i < n; i++){
		string top;

		string bottom;

		fin >> top >> bottom;
		//remove the lowest occurence of duplicates

		for(char c: top){
			if(count(top.begin(), top.end(), c) >= count(bottom.begin(), bottom.end(), c)){
				bottom.erase(remove(bottom.begin(), bottom.end(), c), bottom.end());
				blocks[c]++;

			}


		}

		for(char c: bottom){

			blocks[c]++;
		}
	}
	for(auto const x: blocks){
		fout << x.second << endl;
	}


}
