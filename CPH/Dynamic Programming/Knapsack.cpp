//min coins needed / min items needed for knapsack
//capcity i = va[i]
vector<int> val (n);
val[0] = 0;
for(int i = 1; i <= n; i++){
	val[i] = INF;
	for(auto c: coins){
		if(i-c >= 0){
			val[i] = min(val[i], val[i-c]+1);
		}
	}
}
//number of ways to fill knapsack / make sum using coins 
//capcity i = ways[i]
vector<int> ways (n);
ways[0] = 1;
for(int i = 0; i < ways.size(); i++){
	for(auto c: coins){
		if(i-c >= 0){
			ways[i] += ways[i-c];
			//take mod m if number of ways is too high
			ways[i] %= m;
		}
	}
}

