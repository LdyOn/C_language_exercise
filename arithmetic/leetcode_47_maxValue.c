
/*
在一个 m*n 的棋盘的每一格都放有一个礼物，
每个礼物都有一定的价值（价值大于 0）。
你可以从棋盘的左上角开始拿格子里的礼物，
并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个棋盘及其上面的礼物的价值，
请计算你最多能拿到多少价值的礼物？
输入: 
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 12
解释: 路径 1→3→5→2→1 可以拿到最多价值的礼物

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/li-wu-de-zui-da-jie-zhi-lcof
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
来源：力扣（LeetCode）
*/
#include <stdio.h>
#include <stdlib.h>

int maxValue(int** grid, int gridSize, int* gridColSize);
void PrintArray(int **a, int row, int col);

int main(){
	int matrix[3][3] = {{1,3,1},{1,5,1},{4,2,1}};
	int **p,col,res;
	p = (int **)malloc(sizeof(int *) *3);
    for(int i = 0; i < 3; i ++)
    {
        p[i] = matrix[i];//将二维数组行地址赋值到对应的一维指针上。
    }
	// PrintArray(p,3,3);
	col = 3;
	res = maxValue(p,3,&col);
	printf("%d\n",res);
}


/*用动态规划来解
* dp[m][n]表示取m+1行、n+1列时的一个解
* 状态方程：
* dp[m][n] = max{dp[m-1][n],dp[m][n-1]} + grid[m][n];
*/
int maxValue(int** grid, int gridSize, int* gridColSize){
    int dp[201][201];
    int m,n,count=0;
    // 处理边界
    for(m=0;m<gridSize;m++){
    	count += grid[m][0];
    	dp[m][0] = count;
    }
    count = 0;
    for(m=0;m<*gridColSize;m++){
    	count += grid[0][m];
    	dp[0][m] = count;
    }

    for(m=1; m<gridSize; m++){
    	for(n=1; n<*gridColSize; n++){
    		dp[m][n] = (dp[m-1][n]>dp[m][n-1]?dp[m-1][n]:dp[m][n-1])+grid[m][n];
    	}
    }

    return dp[gridSize-1][(*gridColSize)-1];
}

void PrintArray(int** a, int row, int col){
	for(int i=0; i < row; i++){
		for(int j=0; j < col; j++){
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}


