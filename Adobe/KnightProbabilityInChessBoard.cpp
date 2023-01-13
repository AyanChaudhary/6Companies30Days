// Recursive Solution 
class Solution {
public:
    double solve(int row,int col,int n,int k){
        if(k==0)return 1;
        double prob=0;
        int dr[]={-2,-1,1,2,2,1,-1,-2};
        int dc[]={1,2,2,1,-1,-2,-2,-1};
        for(int i=0;i<8;i++){
            int nrow=row+dr[i];
            int ncol=col+dc[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<n)
                prob+=(double)1/8 *solve(nrow,ncol,n,k-1);
        }
        return prob;
    }
    double knightProbability(int n, int k, int row, int column) {
        return solve(row,column,n,k);

        
    }
};

// Optimised Solution Using Tabulation Method

class Solution {
public:

    double knightProbability(int n, int k, int row, int column) {
    
        vector<vector<vector<double>>>dp(n,vector<vector<double>>(n,vector<double>(k+1,0)));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)dp[i][j][0]=1;
        }
        int dr[]={-2,-1,1,2,2,1,-1,-2};
        int dc[]={1,2,2,1,-1,-2,-2,-1};
        for(int moves=1;moves<=k;moves++){
            for(int r=0;r<n;r++){
                for(int c=0;c<n;c++){
                    for(int i=0;i<8;i++){
                        int nrow=r+dr[i];
                        int ncol=c+dc[i];
                        if(nrow>=0 and nrow<n and ncol>=0 and ncol<n)
                            dp[r][c][moves]+=(double)1/8*dp[nrow][ncol][moves-1];
                    }
                }
            }
        }
        return dp[row][column][k];

    }
};
