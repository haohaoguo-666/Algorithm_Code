//https://leetcode.cn/problems/sqrtx/solutions/2220897/xde-ping-fang-gen-by-confident-ellisbal-9ic5/
class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if((long long)mid * mid > x)
            {
                right = mid -1;
            }
            else if(mid * mid < x)
            {
                left = left + 1;
            }
            else
            {
                return mid;
            }
        }

        return left - 1;
    }
};