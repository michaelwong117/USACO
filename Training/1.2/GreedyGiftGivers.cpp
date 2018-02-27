/*
ID: michaelwong11
PROG: gift1
LANG: C++     
*/
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>

using namespace std;
vector<string> keys;
void print_final(map<string, int> & m) {
    ofstream fout ("gift1.out");
    for (int i=0;i<keys.size();++i){
        string p = keys[i];
        fout << p << " " << m[p] << endl;
    }
}

int main() {
    ofstream fout ("gift1.out");
    ifstream fin ("gift1.in");
    int numGroup;
    string giver;
    fin >> numGroup;
    map<string, int> m; 
    string member;
    //the actual value of each individual member is stored here.
    for (int i=0; i<numGroup; ++i) {
    	fin >> member;
        keys.push_back(member);
    	m[member] = 0;
    }

    //second loop is for the gift-giving.
    for (int i=0;i<numGroup;++i){
    	fin >> giver;
    	int amount;
    	int split;
    	fin >> amount >> split;
    	m[giver] -= amount;
        if (split == 0){
            continue;
        }
    	int leftover = amount % split;

    	int share = (int)amount / split;
    	m[giver] += leftover;
    	for (int j=0;j<split;++j){
    		fin >> member;
    		m[member] += share;
    	}

    }
    print_final(m);

}

