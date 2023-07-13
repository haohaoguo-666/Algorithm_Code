int removeElement(int* nums, int numsSize, int val) {
    //快慢双指针
	int src = 0;//快指针：可留下的数据
    int des = 0;//慢指针：留下数据的位置
    while(src < numsSize)
    {
        if(nums[src] != val)
        {
            nums[des++] = nums[src++];
        }
        else
        {
            src++;
        }
    }
    return des;

}