class Solution {
public:
    int numSquares(int n) {
             
        vector<int> min_num_squares(n+1,0);
      
        min_num_squares[0] = 0;
        min_num_squares[1] = 1;
        
        int num_squares;
        int j;
        for(int i=2; i<=n; i++)
        {
            min_num_squares[i] = INT_MAX;
            
            j=1;
            
            while(j*j<=i)
            {
                num_squares = min_num_squares[i-j*j]+1;
                min_num_squares[i] = min(min_num_squares[i], num_squares);
                j++;
            }
            
        }
        return min_num_squares[n]; 
    }
};
