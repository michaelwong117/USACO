
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){

	ofstream fout("cowsignal.out");
	ifstream fin("cowsignal.in");

	int M, N, K;
	fin >> M >> N >> K;
	vector<string> inputSig;
	vector<string> enlargedSig;
	for(int i = 0; i < M; i++){
		string line;
		fin >> line;
		inputSig.push_back(line);

	}
	for(auto l: inputSig){
		string row;
		for(char c: l){
			for(int i = 1; i <= K; i++){
				row += c;
			}
		}
		for(int i = 1; i <= K; i++){
			enlargedSig.push_back(row);
		}
	}
	for(auto l: enlargedSig){
		fout << l << endl;
	}

}
