/**
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

 

Example 1:

Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
Example 2:

Input: matrix = 
[
  [1,0,1],
  [1,1,0],
  [1,1,0]
]
Output: 7
Explanation: 
There are 6 squares of side 1.  
There is 1 square of side 2. 
Total number of squares = 6 + 1 = 7.
 

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1
**/


#include <iostream>
#include <vector>

using namespace std;

template<typename T>
void vector_print_2DArray(vector<T> a){
	cout<<"["<<endl;
	for(auto ii: a){
		cout<<"[";
		for(auto jj: ii){
			cout<<jj<<" ";
		}
		cout<<"]"<<endl;
	}
	cout<<"]"<<endl;
}

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r = matrix.size();
		
        if (r == 0){
            return 0;
        }

        int c = matrix[0].size();
        vector<vector<int>> dp(r+1, vector<int>(c+1));
        int count = 0;
        for(int i = 1; i<=r; i++){
            for(int j = 1; j<=c; j++){
                if(matrix[i-1][j-1]){
                    dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + matrix[i-1][j-1];
                    count+= dp[i][j];
                }
            }
        }
        vector_print_2DArray(dp);		
        return count;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> matrix{
                                {0,1,1,1},
                                {1,1,1,1},
                                {0,1,1,1}
                                };

    vector<vector<int>> matrix1{
                                {1,0,1},
                                {1,1,0},
                                {1,1,0}
                                };

    vector<vector<int>> matrix2{						   
                                {0,0,0},
                                {0,1,0},
                                {0,1,0},
                                {1,1,1},
                                {1,1,0}
                                };

    cout<<s.countSquares(matrix)<<endl;
    cout<<s.countSquares(matrix1)<<endl;
    cout<<s.countSquares(matrix2)<<endl;
    return 0;							   
}
