int removeDuplicates(int* nums, int numsSize) {
    //快慢双指针法
		int src = 0;//快指针：指向可加入的非重复数
		int des = 0;//慢指针：可加入数的位置
        while(src < numsSize)
        {
            if(nums[src] == nums[des])
            {//是重复元素
                //不用插入
                src++;
                
            }
            else
            {//不是重复元素
                //插入
                des++;
                nums[des] = nums[src++];
            }
        }
        return  des + 1;
		
}