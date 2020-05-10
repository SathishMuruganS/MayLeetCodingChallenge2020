/**
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false

Constraints:

1. 2 <= coordinates.length <= 1000
2. coordinates[i].length == 2
3. -10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
4. coordinates contains no duplicate point.

**/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = coordinates.size();
        if (n < 2){
            return false;
        }
        
        if (n == 2){
            return true;
        }
            
        int a = coordinates[1][0] - coordinates[0][0];
        int b = coordinates[1][1] - coordinates[0][1];
 
        
        for (int i = 1; i< n; i++){
            int c = coordinates[i][0] - coordinates[0][0]; 
            int d = coordinates[i][1] - coordinates[0][1];
            
            if ((a*d) != (c*b)){
                return false;
            }
        }   
        return true;
    }
};

