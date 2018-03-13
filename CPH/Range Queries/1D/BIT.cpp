template<class T, int SZ> struct BIT {
    T bit[SZ+1];
    BIT() { memset(bit,0,sizeof bit); }
    void upd(int k, T val) { // add val to index k
        while(k <= SZ){
            bit[k] += val; k += k&-k;
        }
    }
    T query(int k) {
        T sum = 0;
        while(k >= 1){
            sum += bit[k];
            k -= k&-k;
        }
        return sum;
    }
    T query(int l, int r) { return query(r)-query(l-1); } // range query [l,r]
};
