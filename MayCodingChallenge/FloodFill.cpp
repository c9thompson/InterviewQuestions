/*
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
*/

class Solution {
public:
    void nextPixel(vector<vector<int>>& image, list<pair<int, int>>& nextPixels, int& oldColor, int& newColor){
        int row = nextPixels.front().first;
        int col = nextPixels.front().second;
        nextPixels.pop_front();
        
        if(image[row][col] == newColor) return;
        image[row][col] = newColor;
        
        //left
        if(col > 0){
            if(image[row][col - 1] == oldColor){
                nextPixels.push_back(pair<int, int>(row, col-1));
            }
        }
        //right
        if(col < image[0].size() - 1){
            if(image[row][col + 1] == oldColor){
                nextPixels.push_back(pair<int, int>(row, col+1));
            }
        } 
        //up
        if(row > 0){
            if(image[row-1][col] == oldColor){
                nextPixels.push_back(pair<int, int>(row-1, col));
            }
        }
        //down
        if(row < image.size() - 1){
            if(image[row+1][col] == oldColor){
                nextPixels.push_back(pair<int, int>(row+1, col));
            }
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        list<pair<int, int>> nextPixels(1, pair<int, int>(sr, sc));
        int oldColor = image[sr][sc];
        
        while(nextPixels.size() > 0)
            nextPixel(image, nextPixels, oldColor, newColor);
        
        return image;
    }
};