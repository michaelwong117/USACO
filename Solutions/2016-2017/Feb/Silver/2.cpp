//g++ filename.cpp -std=c++14 -DH
#ifdef H
#include "/Users/michaelw/stdc++.h"
#else
#include <bits/stdc++.h>
#endif

using namespace std;

#define endl '\n'
#define pb push_back
#define f first
#define s second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define pq priority_queue

typedef long long ll;
typedef pair<int, string> pis;
typedef pair<int,int> pii;

//2 seconds runtime
//256 megabytes
//X - incorrect, T - time limit, ! - runtime or memory
//E = empty output file, M - missing output file
//make sure that you have correct finder/terminal directories

int N, K, B;

int main(){
	ifstream fin ("maxcross.in");
	ofstream fout ("maxcross.out");
	fin >> N >> K >> B;
	int psum = 1;
	set<int> index;
	vector<int> signs (N);
	//formatting prefix sums
	for(int i = 0; i < B; i++){
		int a;
		fin >> a;
		index.insert(a-1);
	}
	for(auto a: index){
		signs[a] = psum;
		psum++;
	}
	int temp = 0;
	for(int i = 0; i < signs.size(); i++){
		if(signs[i] != 0){
			temp = signs[i];
		}
		signs[i] = temp;
	}

	int min = 99999999;
	//scan all possible ranges of K for the least lights you
	//need to remove
	for(int i = 0; i < N-K+1; i++){

		if(i != 0){
			if(signs[i+K-1] - signs[i-1] < min){
				min = signs[i+K-1] - signs[i-1];
			}
		}
		//if i is zero there is nothing before it to subtract
		else{
			if(signs[K-1] < min){
				min = signs[K-1];
			}
		}
		
	}

	fout << min << endl;



}
