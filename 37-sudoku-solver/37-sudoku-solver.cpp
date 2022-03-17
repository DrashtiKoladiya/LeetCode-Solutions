class Solution {
public:
    int n=9;
    int d1[9][9], d2[9][9];
    int fn(int r,int c,vector<vector<char>> & board,int x)
    {
        int i1 = r - r%3;
        int j1 = c - c%3;
        
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if((board[i+i1][j+j1]-'0')==x) return 0;
            }
        }
        
        return 1;
    }
    bool go(vector<vector<char>> &board,int r,int c)
    {
        if(r==(n-1) && c==n)
        {
            return 1;
        }
        
        if(c==n)
        {
            r++;
            c=0;
        }
        
        if(board[r][c]!='.') 
        {
            return go(board,r,c+1);
        }
        
        for(int i=1;i<=9;i++)
        {
            if(d1[r][i-1]==0 && d2[c][i-1]==0 && fn(r,c,board,i))
            {
                board[r][c]=i+'0';
                d1[r][i-1]=1;
                d2[c][i-1]=1;
                if(go(board,r,c+1))
                {
                    return 1;
                }
                d1[r][i-1]=0;
                d2[c][i-1]=0;
                board[r][c]='.';

            }
        }
        
        return 0;

    }
    void solveSudoku(vector<vector<char>>& board) {
        
        memset(d1,0,sizeof(d1));
        memset(d2,0,sizeof(d2));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='.') continue;
                
                d1[i][board[i][j]-'1']=1;
                d2[j][board[i][j]-'1']=1;
            }
        }
        
        go(board,0,0);
        
    }
};