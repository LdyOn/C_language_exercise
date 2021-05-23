/* 
* 实现堆数据结构。这里实现最小堆，最大堆的原理类似
*
 */
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct
{
    int max; //总容量
    int cap; //已用容量
    int *arr; //用数组存储堆
}Heap;

Heap * InitHeap(int nums);
int Insert(Heap *heap, int val);
void ShiftUp(Heap *heap, int index);
void Pop(Heap *heap, int *res);
void ShiftDown(Heap *heap, int index);
/* 
 * 初始化堆
 * @param int  元素数量
 * @return  Heap*
 */
Heap * InitHeap(int nums){
    if(nums<1){
        printf("nums must greater then 0");
        exit(-1);
    }   
    Heap *heap;
    heap = (Heap*)malloc(sizeof(Heap));
    if(heap==NULL){
        printf("Init heap fail");
        exit(-1);
    }
    heap->max = nums;
    heap->cap = 0;
    heap->arr = (int*)malloc(nums*sizeof(int));

    if(heap->arr==NULL){
        printf("Init heap fail");
        exit(-1);
    }

    return heap;
}

/** 
 * 插入元素，成功返回1，失败返回0
 * 
 */
int Insert(Heap *heap, int val){
    // 满了
    if(heap->max==heap->cap){
        return 0;
    }
    // 放入数组末尾
    heap->arr[heap->cap] = val;
    // 节点上移
    ShiftUp(heap, heap->cap);
    heap->cap++;

    return 1;
}

/** 
 * 取堆顶元素
 * 
 */
void Pop(Heap *heap, int *res){
    if(heap->cap==0){
        res = NULL;
        return;
    }

    *res = heap->arr[0];
    // 最后一个元素放到堆顶
    heap->arr[0] = heap->arr[heap->cap-1];
    heap->cap--;
    // 向下调整堆
    ShiftDown(heap, 0);
    
    return;
}

/** 
 * 向上调整元素的位置，使其符合堆的性质 
 */
void ShiftUp(Heap *heap, int index){
    int parentIndex,parent;
    parentIndex = floor(index/2);
    parent = heap->arr[parentIndex];
    while (index !=0 && parent > heap->arr[index])
    {
        // 父节点和子节点交换位置
        heap->arr[parentIndex] = heap->arr[index];
        heap->arr[index] = parent;
        index = parentIndex;
        parentIndex = floor(index/2);
        parent = heap->arr[parentIndex];
    }
    
}

/** 
 * 向下调整元素的位置，使其符合堆的性质 
 */
void ShiftDown(Heap *heap, int index){
    int childIndex,tmp;
    int *child = NULL;
    
    if(2*index+1 <= heap->cap){
        childIndex = 2*index+1;//第一个子节点的索引
        child = heap->arr+childIndex;
    }
    
    if( (2*index+2 <= heap->cap) && (*child > heap->arr[2*index+2]) ){
        childIndex = 2*index+2; // 第二个子节点的索引
        child = heap->arr+childIndex;
    }

    // 存在子节点且子节点的值小于父节点
    while(child != NULL  &&  *child < heap->arr[index]){
        // 交换
        tmp = heap->arr[childIndex];
        heap->arr[childIndex] = heap->arr[index];
        heap->arr[index] = tmp;

        child = NULL;
        index = childIndex;
        if(2*index+1 <= heap->cap){
            childIndex = 2*index+1;//第一个子节点的索引
            child = heap->arr+childIndex;
        }
        
        if( (2*index+2 <= heap->cap) && (*child > heap->arr[2*index+2]) ){
            childIndex = 2*index+2; // 第二个子节点的索引
            child = heap->arr+childIndex;
        }
    }

}

// 打印存储数组
void PrintHeap(Heap *heap){
    printf("\n**********************Heap,cap:%d**************************\n",
     heap->cap);
    for(int i=0; i<heap->cap; i++){
        printf("%d\t", heap->arr[i]);
    }
    printf("\n");
}


int main()
{
    int val;
    Heap *heap;
    // 测试数组
    int testArr[10] = {2,3,7,1,10,4,5,12,8,9};

    for(int i=0; i<10; i++){
        printf("%d\t", testArr[i]);
    }
    printf("\n");
    heap = InitHeap(15);
    for(int i=0; i<10; i++){
        Insert(heap, testArr[i]);
    }
    PrintHeap(heap);
    printf("取出最小值:\n");
    for(int i=0; i<10; i++){
        Pop(heap, &val);
        PrintHeap(heap);
    }
}

