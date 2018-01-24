/* 
@author Mithil Raut
@version 1.0 01/24/18
Problem:  54. Spiral Matrix
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
For example,
Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5]. 
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
    int* result = (int*)malloc(sizeof(int) * (matrixRowSize*matrixColSize));
    
    int colmin = 0, colmax = matrixColSize - 1, rowmax = matrixRowSize - 1, rowmin = 0, result_index = 0;
    while(1){
    for(int i = colmin; i <= colmax; i++)
        result[result_index++] = matrix[rowmin][i];
    if (++rowmin > rowmax) break;
    
    for(int j = rowmin; j <= rowmax; j++)
        result[result_index++] = matrix[j][colmax];
    if (--colmax < colmin) break;
    
    for(int i = colmax; i >= colmin; i--)
        result[result_index++] = matrix[rowmax][i];
    if (--rowmax < rowmin) break;
    
    for(int j = rowmax; j >= rowmin; j--)
        result[result_index++] = matrix[j][colmin];
    if (++colmin > colmax) break;
    }
    return result;
}