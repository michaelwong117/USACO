void search(int y) {
    if (y == n) {
count++;
return; }
    for (int x = 0; x < n; x++) {
       if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
       column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
       search(y+1);
       column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
} }
//Queens on a chessboard
The search begins by calling search(0). 
The size of the board is n × n, and the code calculates the number of solutions to count.
The code assumes that the rows and columns of the board are numbered from 0 to n − 1. 
When the function search is called with parameter y, it places a queen on row y and then calls itself with parameter y + 1. 
Then, if y = n, a solution has been found and the variable count is increased by one.
