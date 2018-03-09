int n;
vector<int> elems, subs(n, 1);
void LISslow(){
    //find the greatest thing less than elems[i]
    for(int i = 1; i < subs.size(); i++){
        for(int j = i-1; j >= 0; j--){
            if(elems[i] > elems[j]){
                subs[i] = max(subs[i], subs[j]+1);
            }
        }
    }
}
 
// Binary search (note boundaries in the caller)
 
int LISfast(vector<int> &v) {
    if (v.size() == 0)
        return 0;
 
    vector<int> tail(v.size(), 0);
    int length = 1; // always points empty slot in tail
 
    tail[0] = v[0];
    for (size_t i = 1; i < v.size(); i++) {
        if (v[i] < tail[0])
            // new smallest value
            tail[0] = v[i];
        else if (v[i] > tail[length-1])
            // v[i] extends largest subsequence
            tail[length++] = v[i];
        else{
            // v[i] will become end candidate of an existing subsequence or
            // Throw away larger elements in all LIS, to make room for upcoming greater elements than v[i]
            // (and also, v[i] would have already appeared in one of LIS, identify the location and replace it)
            int lb = lower_bound(tail.begin(), tail.begin()+length, v[i]) - tail.begin();
            tail[lb] = v[i];
        }
    }

    return length;
}
 
int main() {
    vector<int> v{ 2, 5, 3, 7, 11, 8, 10, 13, 6 };
    int res = LISfast(v);
    cout << "Length of Longest Increasing Subsequence is " << res << '\n';
   return 0;
}
