#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <stack> 
#include <string.h>
#include <set>

using namespace std;
string removeDoubles(const string & input){
	string output = "";
	stack<char> norepeats;
	for(int i = 0;i<input.length();i++){
		if (i == 0){
			norepeats.push(input[i]);
		}
		else {
			if(norepeats.top() != input[i]){
				norepeats.push(input[i]);
			}
			else {
				norepeats.pop();
			}
		}

	}
	while (!norepeats.empty()){
		output += norepeats.top();
		norepeats.pop();

	}
	return output;
}


int main(){
	int counter = 0;
	ofstream fout("circlecross.out");
	ifstream fin("circlecross.in");
	string N;
	fin >> N;
	N = removeDoubles(N);

	set<char> usedS;
	for(int i = 0;i<(N.length());i++) {
		const char ch = N[i];  // Current character.
		if (usedS.find(ch) != usedS.end()){
			continue;
		}


		const int j = N.find(ch, i+1);

		int second = j;
		int first = i;
		string smallN = N.substr(first+1, second-first-1);

		for (int a = 0; a<smallN.length(); a++){
			if(count(smallN.begin(), smallN.end(), smallN[a]) == 1){

				if(usedS.find(smallN[a]) == usedS.end()){

					counter += 1;
					cout << smallN[a] << endl;
					
				}

			}

		}
		usedS.insert(N[second]);

	}
	



	
	fout << counter << endl;

}
