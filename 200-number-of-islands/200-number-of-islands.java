class Solution {
    int x[] = new int[]{-1,1,0,0};
    int y[] = new int[]{0,0,-1,1};
    public int numIslands(char[][] A) {
        int N = A.length;
        int M = A[0].length;
        int c=0;
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                if(A[i][j] == '1'){
                    c++;
                    dfs(A,i,j,N,M);
                }
            }
        }
        return c;
    }

    void dfs(char[][] A,int i,int j, int N,int M){
        if(i<0||j<0||i>=N||j>=M||A[i][j]=='0') return;
        A[i][j] = '0';
        for(int k=0;k<4;k++){
            dfs(A,i+x[k],j+y[k],N,M);
        }
    }
}
