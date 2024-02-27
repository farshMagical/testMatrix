#include "factoryWorker.hpp"

#include <gtest/gtest.h>

TEST(MatrixTranspose, ValidTest_BoundaryCases) {
    Matrix orig {
        .data = {
            1
        },
        .width = 1,
        .height = 1
    };
    Matrix fin {
        .data = {
            1
        },
        .width = 1,
        .height = 1
    };
    EXPECT_EQ(orig.ParallelTranspose(), fin);
    EXPECT_EQ(orig.Transpose(), fin);

    Matrix orig1 {
        .data = {
            1,
            2,
            3,
        },
        .width = 1,
        .height = 3
    };   
    Matrix fin1 {
        .data = {
            1,2,3
        },
        .width = 3,
        .height = 1
    };

    EXPECT_EQ(orig1.ParallelTranspose(), fin1);
    EXPECT_EQ(orig1.Transpose(), fin1);

    EXPECT_EQ(fin1.ParallelTranspose(), orig1);
    EXPECT_EQ(fin1.Transpose(), orig1);
}

TEST(MatrixTranspose, ValidTest) {
    Matrix orig = Matrix {
        .data = {
            10,11,12,13,14,15,16,17,18,19,
            20,21,22,23,24,25,26,27,28,29,
            30,31,32,33,34,35,36,37,38,39
        },
        .width = 10,
        .height = 3
    };
    Matrix fin {
        .data = {
            10,20,30,
            11,21,31,
            12,22,32,
            13,23,33,
            14,24,34,
            15,25,35,
            16,26,36,
            17,27,37,
            18,28,38,
            19,29,39,
        },
        .width = 3,
        .height = 10 
    };
    EXPECT_EQ(orig.ParallelTranspose(), fin);
    EXPECT_EQ(orig.Transpose(), fin);

    EXPECT_EQ(fin.ParallelTranspose(), orig);
    EXPECT_EQ(fin.Transpose(), orig);
}