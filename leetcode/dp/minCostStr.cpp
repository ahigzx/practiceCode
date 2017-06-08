class MinCost {
    public:
            int findMinCost(string A, int n, string B, int m, int c0, int c1, int c2) {
                   int cost[n+1][m+1];
                   for(int i = 0; i < n + 1; i++)
                   {
                       cost[i][0] = i * c1;
                   }
                   for(int i = 1; i < m + 1; i++)
                   {
                       cost[0][i] = i * c0;
                   }
                   for(int i = 1; i < n + 1; i++)
                   {
                       for(int j = 1; j < m + 1; j++)
                       {
                           int del = cost[i-1][j] + c1;
                           int ins = cost[i][j-1] + c0;
                           int rep;
                           if(A[i-1] == B[j-1])
                           {
                               rep = cost[i-1][j-1];
                           }
                           else
                           {
                               rep = cost[i-1][j-1] + c2;
                           }
                           cost[i][j] = min(del, min(ins, rep));
                       }
                   }
                   return cost[n][m];
            }

}
