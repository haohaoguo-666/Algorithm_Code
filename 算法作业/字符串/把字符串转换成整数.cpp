//https://www.nowcoder.com/practice/1277c681251b4372bdef344468e4f26e?tpId=13&&tqId=11202&rp=6&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking
class Solution {
public:
    int StrToInt(string str) {

        int x = 1;
        int i = 0;
        int sum = 0;        
        if(str[0] == '+' || str[0] == '-')
        {
            if(str[0] == '-')
                x = -1;
            i = 1;
        }
        for(;i < str.size();++i)
        {
            if(str[i] >= '0' && str[i] <= '9')
            {
                sum = sum * 10 + (str[i] - '0');
            }
            else
            {
                return 0;
            }
        }

        return sum * x;
    }
};