/* 
@author Mithil Raut
@version 1.0 01/30/18
Problem:  74. Search a 2D Matrix

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
    Integers in each row are sorted from left to right.
    The first integer of each row is greater than the last integer of the previous row.

For example,
Consider the following matrix:
[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target) {
    int i = 0;
    while (i < matrixRowSize-1){
        if(matrix[i+1][0] <= target)
            i++;
        else
            break;
    }
    for (int j = 0; j< matrixColSize; j++){
        if (matrix[i][j]==target)
            return true;
    }
    return false;
}