//
// Created by harlan on 2018/1/31.
//
#include <iostream>

using namespace std;

/**
 * 问题描述：
 * 在一个 m*n 整数矩阵中找到指定值 target。
 * 这个整数矩阵有如下性质：
 * 1. 每行从左到右数值递增
 * 2. 每列从上到下数值递增
 *
 * 解决方案：
 * 这样的矩阵有一个特点就是：每一个元素下方的元素以及右方的元素总是比它大，反之比它小。
 * 那如果从左下角开始比较，比目标元素大的话，只需要搜上方的矩阵即可，而比目标元素小的话
 * 只需要搜右方的矩阵即可。
 *
 * 具体做法：
 * temp == target return true
 * temp < target find its right sub matrix
 * temp > target find its upper sub matrix
 * return false if not found eventually.
 *
 * @param matrix
 * @param target to be found.
 * @return true if found, false otherwise.
 */
bool search(int matrix[][5], int target, int col, int row) {
    int i = col - 1;
    int j = 0;

    while (j <= col - 1 && i >= 0) {
        if (matrix[i][j] == target)return true;
        else if (matrix[i][j] > target) {
            i--;
        } else {
            j++;
        }
    }
    return false;
}

int main() {

    int matrix[5][5] = {
            {1,  4,  7,  11, 5},
            {2,  5,  8,  12, 19},
            {3,  6,  9,  16, 22},
            {10, 13, 14, 17, 24},
            {18, 21, 23, 26, 30}
    };

    bool result = search(matrix, 0, 5, 5);
    cout << result << endl;

    return 0;
}

