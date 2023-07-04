//思路1：异或
int missingNumber(int* nums, int numsSize){
    int i = 0;
    int sum = 0;
    for(i = 0;i < numsSize;i++){
        sum = sum ^ *(nums+i);
    }
    for(i = 0;i <= numsSize;i++){
        sum = sum ^ i;
    }
    return sum;
    
}

//思路2：求和相减
int missingNumber(int* nums, int numsSize){
    int i = 0;
    int n = numsSize + 1;//加上缺失的整数一共 numsSize + 1 个整数
    int sum = n * (n - 1) / 2; 
    //0~n的整数和
    for(i = 0;i < n - 1;i++){
        sum -= *(nums+i);
        //逐个减去nums中的元素
    }
    return sum;//剩下哪个缺失的整数
    
}