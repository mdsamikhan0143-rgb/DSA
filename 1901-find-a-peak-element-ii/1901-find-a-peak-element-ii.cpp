class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int row = (int)mat.size();
        int cols = (int)mat[0].size();
         
        int low = 0 ;
        int high = row-1;

        while(low < high){
            int mid = (high + low ) / 2 ;
        
        int bestcol = 0 ;
        for(int col = 1; col < cols; col++){
             if(mat[mid][col]> mat[mid][bestcol]){
             bestcol = col;
          } 
        }
        if(mat[mid][bestcol]>mat[mid+1][bestcol]){
            high = mid;
        }else{
            low = mid+1; 
        }
      }
      int bestcol = 0 ;
      for(int col = 1;col<cols;col++){
        if(mat[low][col]> mat[low][bestcol]){
            bestcol = col;
        }
      }
      return {low, bestcol};

  }
};