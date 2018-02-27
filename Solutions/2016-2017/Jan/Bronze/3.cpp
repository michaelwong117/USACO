
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

	ofstream fout("cowtip.out");
	ifstream fin("cowtip.in");
	//remember to use fin and fout
	int n;
	int count = 0;
	int iBound = -1;
	fin >> n;
	vector<string> grid;
	for(int i = 0; i < n; i++){
		string row;
		fin >> row;
		grid.push_back(row);

	}
	for(int i = n-1; i >= 0; i--){
		iBound++;
		int jBound = -1;
		for(int j = n-1; j >= 0; j--){
			jBound++;
			if(grid[i][j] == '1'){
				for(int a = 0; a < grid.size()-iBound; a++){
					for(int b = 0; b < grid[a].size()-jBound; b++){
						if(grid[a][b] == '0'){
							grid[a][b] = '1';
						}
						else{
							grid[a][b] = '0';
						}
					}
				}
				// for(auto row: grid){
				// 	cout << row << endl;
				// }
				count++;
			}
			
		}
	}
	
	fout << count << endl;
	

}
