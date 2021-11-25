#include <gtest\gtest.h>

#include "Functions.h"



TEST(DataStructures_Matrix, RotateImage)
{
    vector<vector<int>> matrix0{ {1,2,3},{4,5,6},{7,8,9} };
    RotateImage(matrix0);
    EXPECT_EQ(7, matrix0[0][0]);
    EXPECT_EQ(5, matrix0[1][1]);
    EXPECT_EQ(3, matrix0[2][2]);

    vector<vector<int>> matrix1{ {5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16} };
    RotateImage(matrix1);
    EXPECT_EQ(15, matrix1[0][0]);
    EXPECT_EQ(3, matrix1[1][1]);
    EXPECT_EQ(8, matrix1[2][2]);
    EXPECT_EQ(11, matrix1[3][3]);

    vector<vector<int>> matrix2{ {1} };
    RotateImage(matrix2);
    EXPECT_EQ(1, matrix2[0][0]);
};

TEST(DataStructures_Matrix, Search2dMatrixII)
{
    const bool result0 = Search2dMatrixII({ {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} }, 5);
    EXPECT_EQ(true, result0);

    const bool result1 = Search2dMatrixII({ {1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30} }, 20);
    EXPECT_EQ(false , result1);
};

TEST(DataStructures_Matrix, SetMatrixZeroes)
{
    vector<vector<int>> zeroMatrix0{ {1, 1, 1}, {1, 0, 1}, {1, 1, 1} };
    SetMatrixZeroes(zeroMatrix0);
    EXPECT_EQ(1, zeroMatrix0[0][0]);
    EXPECT_EQ(0, zeroMatrix0[2][1]);

    vector<vector<int>> zeroMatrix1{ {0, 1, 2, 0}, {3, 4, 5, 2}, {1, 3, 1, 5} };
    SetMatrixZeroes(zeroMatrix1);
    EXPECT_EQ(4, zeroMatrix1[1][1]);
    EXPECT_EQ(0, zeroMatrix1[2][3]);
};

TEST(DataStructures_Matrix, SpiralMatrix)
{
    vector<int> spiral0 = SpiralMatrix({ {1,2,3}, {4,5,6}, {7,8,9} });
    EXPECT_EQ(1, spiral0[0]);
    EXPECT_EQ(2, spiral0[1]);
    EXPECT_EQ(3, spiral0[2]);
    EXPECT_EQ(6, spiral0[3]);
    EXPECT_EQ(9, spiral0[4]);
    EXPECT_EQ(8, spiral0[5]);
    EXPECT_EQ(7, spiral0[6]);
    EXPECT_EQ(4, spiral0[7]);
    EXPECT_EQ(5, spiral0[8]);

    vector<int> spiral1 = SpiralMatrix({ {1,2,3,4}, {5,6,7,8}, {9,10,11,12} });
    EXPECT_EQ(1, spiral1[0]);
    EXPECT_EQ(2, spiral1[1]);
    EXPECT_EQ(3, spiral1[2]);
    EXPECT_EQ(4, spiral1[3]);
    EXPECT_EQ(8, spiral1[4]);
    EXPECT_EQ(12, spiral1[5]);
    EXPECT_EQ(11, spiral1[6]);
    EXPECT_EQ(10, spiral1[7]);
    EXPECT_EQ(9, spiral1[8]);
    EXPECT_EQ(5, spiral1[9]);
    EXPECT_EQ(6, spiral1[10]);
    EXPECT_EQ(7, spiral1[11]);
};

TEST(DataStructures_Matrix, SpiralMatrixII)
{
    vector<vector<int>> spiral0 = SpiralMatrixII(3);
    EXPECT_EQ(1, spiral0[0][0]);
    EXPECT_EQ(2, spiral0[0][1]);
    EXPECT_EQ(3, spiral0[0][2]);
    EXPECT_EQ(8, spiral0[1][0]);
    EXPECT_EQ(9, spiral0[1][1]);
    EXPECT_EQ(4, spiral0[1][2]);
    EXPECT_EQ(7, spiral0[2][0]);
    EXPECT_EQ(6, spiral0[2][1]);
    EXPECT_EQ(5, spiral0[2][2]);

    vector<vector<int>> spiral1 = SpiralMatrixII(1);
    EXPECT_EQ(1, spiral1[0][0]);
};

TEST(DataStructures_Matrix, WordSearch)
{
    bool exists0 = WordSearch({ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} }, "ABCCED");
    EXPECT_EQ(true, exists0);

    bool exists1 = WordSearch({ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} }, "SEE");
    EXPECT_EQ(true, exists1);

    bool exists2 = WordSearch({ {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'} }, "ABCB");
    EXPECT_EQ(false, exists2);

    bool exists3 = WordSearch({ {'A', 'B', 'C', 'E'}, {'S' ,'F', 'E', 'S'}, {'A', 'D', 'E', 'E'} }, "ABCESEEEFS");
    EXPECT_EQ(true, exists3);
};
