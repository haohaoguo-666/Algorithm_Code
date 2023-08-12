//https://www.nowcoder.com/practice/e8a1b01a2df14cb2b228b30ee6a92163?tpId=13&tqId=11181&tPage=2&rp=2&ru=/ta/coding-interviews&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param numbers int整型vector 
     * @return int整型
     */
    int MoreThanHalfNum_Solution(vector<int>& numbers) {
        // write code here
        int result = numbers[0];
        int times = 0;
        for(int i = 1;i < numbers.size();++i)
        {
            if(numbers[i] == result)
            {
                ++times;
            }
            else 
            {
                if(times == 0)
                {
                    result = numbers[i];
                }
                else 
                {
                    --times;
                }
            }
        }

        return result;
    }
};