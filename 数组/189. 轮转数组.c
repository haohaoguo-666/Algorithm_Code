// 思路一
// void rotate(int* nums, int numsSize, int k) {

//     int ptr[numsSize];
//     int* start = ptr;
//     int number = numsSize - k % numsSize;
//     int n = 0;
//     //后k个拷贝到前面
//     for (int i = number; i < numsSize; i++) {
//         ptr[n] = nums[i];
//         n++;
//     }
//     //前n-k个拷贝到后面
//     for (int i = 0; i < number; i++) {
//         ptr[n] = nums[i];
//         n++;
//     }
//     for (int i = 0; i < numsSize; i++) {
//         nums[i] = ptr[i];
//     }

// }

//思路二
//版本一
// void rotate(int* nums, int numsSize, int k) {
    
//     int ptr[numsSize];
//     int* start = ptr;
//     int number = numsSize - k % numsSize;
//     int n = 0;
//     //后k个拷贝到前面
//     for (int i = number; i < numsSize; i++) {
//         ptr[n] = nums[i];
//         n++;
//     }
//     //前n-k个拷贝到后面
//     for (int i = 0; i < number; i++) {
//         ptr[n] = nums[i];
//         n++;
//     }
//     for (int i = 0; i < numsSize; i++) {
//         nums[i] = ptr[i];
//     }
    
// }
//版本二
// void rotate(int* nums, int numsSize, int k) {
//     int* ptr = (int*)malloc(sizeof(int) * numsSize);
//     int* start = ptr;
//     int number = numsSize - k % numsSize;
//     //后面k个拷贝到前面
//     for (int i = number; i < numsSize; i++) {
//         *ptr++ = nums[i];
//     }
//     //前n-k个拷贝到后面
//     for (int i = 0; i < number; i++) {
//         *ptr++ = nums[i];
//     }
//     for (int i = 0; i < numsSize; i++) {
//         nums[i] = start[i];
//     }
// }

//思路3
//三段逆置法

//将begin到end进行逆置
void reverse(int* num, int begin, int end) {
    while (begin < end) {
        int temp = num[begin];
        num[begin] = num[end];
        num[end] = temp;
        begin++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    //将0到n-k-1逆置
    reverse(nums,0, numsSize - k%numsSize - 1);
    //将n-k到numsSize-1逆置
    reverse(nums,numsSize - k%numsSize, numsSize-1);
    //将0到numsSize-1逆置
    reverse(nums, 0, numsSize - 1);
}