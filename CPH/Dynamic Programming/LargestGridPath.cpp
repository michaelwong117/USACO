int sum[row][col];
int value[row][col];
for (int r = 1; r <= n; r++) {
    for (int c = 1; c <= n; c++) {
       sum[r][c] = mac(sum[r][c-1],sum[r-1][c])+value[r][c];
    }
}
