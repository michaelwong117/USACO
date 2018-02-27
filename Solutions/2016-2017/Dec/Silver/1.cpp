#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>

using namespace std;

// first element >= x
// int l = lower_bound(haybales, 0, haybales.size()-1, a);
// search index for everything greater than or equal to b  
// v = lower_bound(haybales, 0, haybales.size()-1, b+1);
// find index for everything less than or equal b
int lower_bound(vector<int> &v, int low, int high, int key){
	while(low < high){
		int mid = (high+low)/2;
		if(v[mid] == key){

			return mid;
		}

		if(v[mid] < key){
			low = mid+1;
		}
		else{
			high = mid;
		}
	}
	if(v[low] < key){
		return low+1;
	}

	return low;
}

int main(){
	ifstream fin("haybales.in");
	ofstream fout("haybales.out");
	int N, Q;
	fin >> N >> Q;
	vector<int> haybales;
	for(int i = 0; i < N; i++){
		int coord;
		fin >> coord;
		haybales.push_back(coord);
	}
	sort(haybales.begin(), haybales.end());
	for(int i = 0; i < Q; i++){
		int a, b;
		fin >> a >> b;
		int l = lower_bound(haybales, 0, haybales.size()-1, a);
		int v = lower_bound(haybales, 0, haybales.size()-1, b+1);
		fout << v - l << endl;
	}


}
