#include <stdio.h>
#include <string.h>

int MaxCommonSubstring(int strLen1, char *str1, int strLen2, char *str2);
/* 动态规划求解最长公共子串 */
int main()
{
    char a[15] = "helloworld\n";
    char b[20] = "allowhj\n";

    MaxCommonSubstring(strlen(a), a, strlen(b), b);
}   


/** 
 * 动态规划求解两个字符串的最大公共子串
 * 给定字符串长度为n的字符串：A0A2A3...An-1和长度为m的字符串：B0B2B3.....Bm-1
 * 用二维数组，dp[n][m]表示以A[n-1]和B[m-1]结尾的最长公共子串的长度，dp[n][m]代表了一个子问题的解
 * 建立状态转移方程：
 * 当n=0 或 m=0 时，dp[n][m] = 0；
 * 当A[n-1] = B[m-1]时，dp[n][m] = dp[n-1][m-1]+1;
 * 当A[n-1] != B[m-1] dp[n][m]=0;
 * 
 */
int MaxCommonSubstring(int strLen1, char *str1, int strLen2, char *str2)
{
    int dp[100][100];
    int n,m=0;
    // 填充边界
    for ( n = 0; n <= strLen1; n++)
    {
        dp[n][0]= 0;
    }
    for ( m = 0; m <= strLen2; m++)
    {
        dp[0][m]= 0;
    }
    //建立dp table
    for ( n = 1; n <= strLen1; n++)
    {
       for (m = 1; m <= strLen2; m++)
       {
           if(str1[n-1]==str2[m-1]){
               dp[n][m] = dp[n-1][m-1]+1;
           }else{
               dp[n][m] = 0;
           }
       }
       
    }

    // 打印下dp table，长度最长的即为解
    for ( n = 0; n <= strLen1; n++)
    {
       for (m = 0; m <= strLen2; m++)
       {
          printf("[%d][%d]=%d\t", n, m, dp[n][m]);
       }
       printf("\n");
    }
    
}

