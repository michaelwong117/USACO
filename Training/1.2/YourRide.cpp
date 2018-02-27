/*
ID: michaelwong11
PROG: ride
LANG: C++     
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    string a, b;
    int cometvalue = 1;
    int groupvalue = 1;
    fin >> a >> b;
    for (int i=0; i<a.length(); ++i) {
    	// cometvalue *= ((int) c - 64);
    	cometvalue *= a[i] - 'A' + 1;
    }
    cometvalue %= 47;
    for (int i=0; i<b.length(); ++i) {
    	groupvalue *= b[i] - 'A' + 1;
    }
    groupvalue %= 47;

    if (cometvalue == groupvalue) {
    	fout << "GO" << endl;
    	//cout << "GO" << endl;
    }
    else {
    	fout << "STAY" << endl;
    	//cout << "STAY" << endl;
    }
    return 0;
}
