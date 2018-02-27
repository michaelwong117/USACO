#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <math.h>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int,int> pii;

bool Overlap(pii l1, pii r1, pii l2, pii r2){
   	if(l1.fir >= r2.fir || l2.fir >= r1.fir){
   		return false;
   	}
   	if(l1.sec >= r2.sec || l2.sec >= r1.sec){
   		return false;
   	}
    return true;
}

int overlap(pii l1, pii r1, pii l2, pii r2){
	if(!Overlap(l1, r1, l2, r2)){
		return 0;
	}
    int botl = max(l1.fir, l2.fir);
    int topl = max(l1.sec, l2.sec);
    int botr = min(r1.fir, r2.fir);
    int topr = min(r1.sec, r2.sec);
 	return abs((botr - botl)) * abs((topr - topl));
    
}


int main(){

	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	int x1, y1, x2, y2;
	fin >> x1 >> y1 >> x2 >> y2;
	int x3, y3, x4, y4;
	fin >> x3 >> y3 >> x4 >> y4;
	int x5, y5, x6, y6;
	fin >> x5 >> y5 >> x6 >> y6;
	int areafir = abs((x2 - x1))*abs((y2 - y1));
	int areasec = abs((x4 - x3))*abs((y4 - y3));
	int firO = overlap(pii(x1, y1), pii(x2, y2), pii(x5, y5), pii(x6, y6));
	int secO = overlap(pii(x3, y3), pii(x4, y4), pii(x5, y5), pii(x6, y6));
	fout << areafir - firO + areasec - secO << endl;
	
}	
