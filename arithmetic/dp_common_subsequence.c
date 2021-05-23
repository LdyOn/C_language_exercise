#include <stdio.h>

int MaxCommonSubSeqLength(int strLen1, char *str1, int strLen2, char *str2);

/* 动态规划解最长公共子序列 */
int main(){
    char str1[10] = "25125\0";
    char str2[10] = "052152\0";
    MaxCommonSubSeqLength(5,str1,6,str2);
}


/** 
 * 给定字符串数组A[n]和B[m]，求最大公共子序列的长度
 * 用dp[n][m]表示取A的前n个字符、B的前m个字符时的解
 * 状态转移方程：
 * dp[n][m] = dp[n-1][m-1] +1 , A[n-1] = B[m-1]时;
 * dp[n][m] = max{d[n-1][m], dp[n][m-1]} , A[n-1] != B[m-1];
 * 边界条件：
 * dp[0][*] = 0 ; dp[*][0] = 0;
 */
int MaxCommonSubSeqLength(int strLen1, char *str1, int strLen2, char *str2){
    // 定义一个table
    int dp[500][500];
    int i,j = 0;
    // 初始化
    for ( i = 0; i <= strLen1; i++)
    {
        dp[i][0] = 0;
    }

    for ( j = 0; j <= strLen2; j++)
    {
        dp[0][j] = 0;
    }
    
    for ( i = 1; i <= strLen1; i++)
    {
        for ( j = 1; j <= strLen2; j++)
        {
            if(str1[i-1]==str2[j-1]){
                dp[i][j] = dp[i-1][j-1] +1 ;
            }else{
                dp[i][j] = dp[i-1][j] > dp[i][j-1] ? dp[i-1][j] : dp[i][j-1];
            }           
        }
    }
    return dp[strLen1][strLen2];
    
}


