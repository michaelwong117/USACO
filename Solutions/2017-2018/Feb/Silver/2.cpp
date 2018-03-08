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
#define MOD 1000000007
#define pq priority_queue<int, vector<int>, greater<int>>
#define heap priority_queue<int>

const int maxN = 250;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef pair<ll,ll> pl;



int N, B, F[maxN], best = 9999;
pi boots[maxN];
bool pos[maxN][maxN];  // set of (location, boot) states we can reach

int solve(){
   for(int b=0; b<B; b++){
      for(int i=0; i<N; i++) {

         // Compute whether state (i, b) is reachable...
         int snow = boots[b].f, step = boots[b].s;
         
         if(F[i] > snow) { pos[i][b] = 0; continue; } // invalid state; snow too deep

         if(i==0 && b==0) pos[i][b] = 1;  // initial state

         // can we reach this state via forward step from some prior state?
         for(int i2=0; i2<i; i2++) 
            if(pos[i2][b] && i2+step>=i) pos[i][b] = 1;

         // can we reach this state via change of boot from some prior state?
         for(int b2=0; b2<b; b2++) 
            if(pos[i][b2]) pos[i][b] = 1;

         // have we reached the end?  return smallest boot # we can achieve
         if(i==N-1 && pos[i][b]) return b;
      }
   }
}
     
int main(){
   ifstream fin ("snowboots.in");
   ofstream fout ("snowboots.out");
   fin >> N >> B;
   for(int i=0; i<N; i++) fin >> F[i];
   for(int i=0; i<B; i++){
   	fin >> boots[i].f >> boots[i].s;
   }
   fout << solve() << endl; 
   return 0;
}
