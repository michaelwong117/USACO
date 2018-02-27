#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>

#define ll long long
#define fir first
#define sec second


using namespace std;

typedef pair<int,int> pii;
typedef pair<int, string> pis;


int findMax(map<string, int> &m){
	int nmax = -99999999;
	for(auto x: m){
		if(x.sec > nmax){
			nmax = x.sec;
		}
	}
	return nmax;
}

string getName(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '-' || s[i] == '+'){
			return s.substr(0, i);
		}
	}
	return s;
}
int getChange(string s){
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '-' || s[i] == '+'){
			return stoi(s.substr(i, s.length()-i+1));
		}
	}
	return stoi(s);
}


int main(){
	ifstream fin("measurement.in");
	ofstream fout("measurement.out");
	int N;
	fin >> N;
	map<string, int> milk;
	vector<pis> v;
	for(int i = 0; i < N; i++){
		int a;
		string name, increase;
		fin >> a >> name >> increase;
		milk[name] = 7;
		v.push_back(pis(a, name+increase));

	}
	int count = 0, max = 7;
	sort(v.begin(), v.end());
	for(int i = 0; i < N; i++){
		int c = 0;
		if(milk[getName(v[i].sec)] == max){
			if(getChange(v[i].sec) < 0){
				milk[getName(v[i].sec)] += getChange(v[i].sec);
				for(auto x: milk)
					if(x.sec == milk[getName(v[i].sec)]) c++;
				if(findMax(milk) != milk[getName(v[i].sec)]) count++;
				else if(c > 1) count++;
			}
			else{
				for(auto x: milk)
					if(x.sec == max) c++;
				if(c > 1) count++;
				milk[getName(v[i].sec)] += getChange(v[i].sec);
			}	
		}
		else{
			milk[getName(v[i].sec)] += getChange(v[i].sec);
			if(milk[getName(v[i].sec)] >= max) count++;
		}

		max = findMax(milk);
			
	}
	
	fout << count << endl;
		

}
