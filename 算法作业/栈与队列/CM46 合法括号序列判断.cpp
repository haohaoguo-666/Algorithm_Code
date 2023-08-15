//https://www.nowcoder.com/practice/d8acfa0619814b2d98f12c071aef20d4?tpId=8&&tqId=11039&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
class Parenthesis {
public:
    bool chkParenthesis(string A, int n) {
        stack<char> stk;
        for(int i = 0;i < n ;++i)
        {
            if(A[i] == '(')
            {
                stk.push(A[i]);
            }
            else if(A[i] == ')')
            {
                if(!stk.empty())
                {
                    stk.pop();
                }
                else 
                {
                    return false;
                }
            }
            else  
            {
                return false;
            }
        }
        if(stk.empty())
        {
            return true;
        }

        return false;
    }
};