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
	map<string, vector<string>> matches; 
	for(int i = 0; i < n; i++){
		//a = Florida
		//b = FL
		string a, b;
		fin >> a >> b;
		a = a.substr(0, 2);
		//if the is not city is in the list of states
		if(matches.find(b) != matches.end()){
			for(auto c: matches[b]){
				if(c == a){
					if(b != c){
						count++;
					}
					
				}
			}
	
		}
		map<string, vector<string>>::iterator it = matches.find(a);
		if(it == matches.end()){
			//matches y is the state
			//x is the city
			matches[a] = {b};

				
		}
		
		else if(it != matches.end()){
			
			matches[a].push_back(b);

		}
		
	}
	fout << count << endl;
}
