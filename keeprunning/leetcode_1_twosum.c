/**
 * 暴力查找；更好的方案是用hash表提高查找速度
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int *res = (int*)malloc(2*sizeof(int));
    *returnSize = 2;
    int i,j,mid;
    for( i =0; i<numsSize; i++){
        mid = target - nums[i];
        for(j=i+1;j<numsSize;j++){
            if(nums[j]==mid){
                *res = i;
                *(res+1)=j;
                return res;
            }
        }
    }

    
}