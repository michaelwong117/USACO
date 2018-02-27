
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main(){

	ofstream fout("square.out");
	ifstream fin("square.in");
	int x1, x2, x3, x4;
	int y1, y2, y3, y4;
	fin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
	int maxheight = max(max(y1, y2), max(y3, y4));

	int minheight = min(min(y1, y2), min(y3, y4));

	int squareh = maxheight - minheight;

	int maxlength = max(max(x1, x2), max(x3, x4));

	int minlength = min(min(x1, x2), min(x3, x4));

	int squarel = maxlength - minlength;

	int squareD = max(squareh, squarel);
	fout << squareD * squareD << endl;

}
