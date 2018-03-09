int k = 0, key;
vector<int> v;
//bsearch in jumps
for(int b = n/2; b >= 1; b/2){
  while(b+k < n && v[b+k] <= key) k += b;
}
if(v[k] == key) return 1;

//nonvalid -> valid
//first value of function f that is true is z
int x = -1;
for(int b = z; b >= 1; b/2){
  while(!ok(b+x)) x += b;
}
int k = x+1;

//find how many elements x are in an array
auto a = lower_bound(array, array+n, x);
auto b = upper_bound(array, array+n, x);
cout << b-a << "\n";

//Finding the maximum value
//Binary search can also be used to find the maximum value for a function that is first increasing and then decreasing. 

int x = -1;
for (int b = z; b >= 1; b /= 2) {
    while (f(x+b) < f(x+b+1)) x += b;
}
int k = x+1;

//the idea is to use binary search for finding the largest value of x 
//for which f (x) < f (x+1)
//this implies that k = x+1 because f (x+1) > f (x+2)
