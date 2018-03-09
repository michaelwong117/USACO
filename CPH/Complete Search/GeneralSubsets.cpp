set<vector<int>> subset;
void generateSubsets(vector<int> &v, int low, int high){
	if(low > high){
		vector<int> s;
		for(int i = 0; i < a.size(); i++){
			if(a[i]) s.push_back(i);
		}
		subset.insert(s+1);
	}
	else{
		a[low] = 1;
		generateSubsets(v, low+1, high);
		a[low] = 0;
		generateSubsets(v, low+1, high);
	}
}
vector<int> subset;
int k = 0;
void subsetofint(int k) {
    if (k == n) {
       // process subset
    } else {
       search(k+1);
       subset.push_back(k);
       search(k+1);
       subset.pop_back();
    }
} 
//bits in reverse
//11001 corresponds to {0, 3, 4} (it's reversed!)
for (int b = 0; b < (1<<n); b++) {
    vector<int> subset;
    for (int i = 0; i < n; i++) {
       if (b&(1<<i)) subset.push_back(i);
    }
}

//set k == 0
//M is modulus sums of subsets
vector<ll> subset, res;
void search(vector<ll> &v, ll k, ll M) {
    if (k == v.size()) {
    	int sum = 0;
    	for(int i = 0; i < subset.size(); i++){
    		sum += v[subset[i]];
    		sum %= M;
    	}
    	res.push_back(sum);
        // process subset
    } else {
       search(v, k+1, M);
       subset.push_back(k);
       search(v, k+1, M);
       subset.pop_back();
    }
}
