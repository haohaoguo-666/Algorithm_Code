//思路一
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        //定义区间[left, right] 与target相同的最小位置
        while(left <= right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] > target)
            {
                right = mid - 1;
            }
            else if(nums[mid] == target)
            {
                return mid;
            }

        }
        return right + 1;
        
    }
};

//思路二：寻找左边界
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        //定义区间[left, right] 与target相同的最小位置
        while(left < right)
        {
            int mid = (left + right) / 2;
            if(nums[mid] < target)
            {
                left = mid + 1;
            }
            else if(nums[mid] >= target)
            {
                right = mid;
            }

        }
        return left;
        
    }
};