class Solution {
public:

    int LeftBorder(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        //定义区间[left, right]
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] >= target)
            {
                right = mid;//左边界
            }
        }
        return right;

    }

    int RightBorder(vector<int>& nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        //定义区间[left, right]
        while(left < right)
        {
            int mid = (left + right + 1) / 2;//确定右边界要+1，不然会进入死循环
            if(nums[mid] <= target)
            {
                left = mid;//右边界
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.empty()) return{-1, -1};
        int left = LeftBorder(nums, target);
        if(nums[left] != target)
            return {-1, -1};
        int right = RightBorder(nums, target);

        return {left, right};
    }
};