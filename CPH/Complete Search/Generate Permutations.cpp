void search() {
    if (permutation.size() == n) {
       // process permutation
    } else {
       for (int i = 0; i < n; i++) {
           if (chosen[i]) continue;
           chosen[i] = true;
           permutation.push_back(i);
           search();
           chosen[i] = false;
           permutation.pop_back();
       }
} }

//standard libraries

vector<int> permutation;
for (int i = 0; i < n; i++) {
    permutation.push_back(i);
}
do {
    // process permutation
} while (next_permutation(permutation.begin(),permutation.end()));
