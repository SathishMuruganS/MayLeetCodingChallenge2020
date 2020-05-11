/**
An image is represented by a 2-D array of integers, each integer representing the pixel value of the image (from 0 to 65535).

Given a coordinate (sr, sc) representing the starting pixel (row and column) of the flood fill, and a pixel value newColor, "flood fill" the image.

To perform a "flood fill", consider the starting pixel, plus any pixels connected 4-directionally to the starting pixel of the same color as the starting pixel, plus any pixels connected 4-directionally to those pixels (also with the same color as the starting pixel), and so on. Replace the color of all of the aforementioned pixels with the newColor.

At the end, return the modified image.

Example 1:
Input: 
image = [[1,1,1],[1,1,0],[1,0,1]]
sr = 1, sc = 1, newColor = 2
Output: [[2,2,2],[2,2,0],[2,0,1]]
Explanation: 
From the center of the image (with position (sr, sc) = (1, 1)), all pixels connected 
by a path of the same color as the starting pixel are colored with the new color.
Note the bottom corner is not colored 2, because it is not 4-directionally connected
to the starting pixel.
Note:

The length of image and image[0] will be in the range [1, 50].
The given starting pixel will satisfy 0 <= sr < image.length and 0 <= sc < image[0].length.
The value of each color in image[i][j] and newColor will be an integer in [0, 65535].
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
    int dfs(vector<vector<int>>& image, int sr, int sc, int newColor, int cur_color, int r_max, int c_max){

        if (sr < 0 || sc < 0 || sr >= r_max || sc >= c_max || image[sr][sc] != cur_color || image[sr][sc] == newColor){
            return 0;
        }

        image[sr][sc] = newColor;
        dfs(image, sr-1, sc, newColor, cur_color, r_max, c_max);
        dfs(image, sr, sc-1, newColor, cur_color, r_max, c_max);
        dfs(image, sr+1, sc, newColor, cur_color, r_max, c_max);
        dfs(image, sr, sc+1, newColor, cur_color, r_max, c_max);
        return 1;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int row_max = image.size();
        if (row_max == 0){
            return image;
        }
        int col_max = image[0].size();
        int current_color = image[sr][sc];
        dfs(image, sr, sc, newColor, current_color, row_max, col_max);
        return image;
    }
};

int main()
{
    Solution s;
    vector<vector<int>> vec{
                                {1,1,1},
                                {1,1,0},
                                {1,0,1}
                            };
    vector<vector<int>> vec1{
                                {0,0,0},
                                {0,0,0},
                                {0,0,0}
                            };

    vector_print_2DArray(vec);
    s.floodFill(vec, 1,1, 2);
    vector_print_2DArray(vec);

    vector_print_2DArray(vec1);
    s.floodFill(vec1, 0,0, 2);
    vector_print_2DArray(vec1);
    return 0;
}
