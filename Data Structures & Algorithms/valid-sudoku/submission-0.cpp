class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            map<char,int>rowmap;
            for(int j=0;j<m;j++){
                if(board[i][j]=='.') continue;
                rowmap[board[i][j]]++;
                if( rowmap[board[i][j]]>1) return false;
            }
        }

        for(int i=0;i<n;i++){
            map<char,int>colmap;
            for(int j=0;j<m;j++){
                if(board[j][i]=='.') continue;
                colmap[board[j][i]]++;
                if(colmap[board[j][i]]>1) return false;
            }
        }

        for(int i=0;i<n;i+=3){
            for(int j=0;j<m;j+=3){
                int k=i,l=j;
                map<char,int>squaremap;
                for(int k=i;k<i+3;k++){
                    for(int l=j;l<j+3;l++){
                        if(board[k][l]=='.') continue;
                        squaremap[board[k][l]]++;
                        if(squaremap[board[k][l]]>1) return false;
                    }
                }

            }
        }
        return true;
    }
};
