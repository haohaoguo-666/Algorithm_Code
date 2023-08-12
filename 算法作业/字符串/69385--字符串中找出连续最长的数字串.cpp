//https://www.nowcoder.com/practice/bd891093881d4ddf9e56e7cc8416562d?tpId=85&&tqId=29864&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
using namespace std;

int main() {
    string str, res, cur;
    cin >> str;
    for(int i = 0;i <= str.length();i++)//要注意必须<=,避免遗漏数字字符串
    {
        if(str[i] >= '0' && str[i] <='9')
        {
            cur += str[i];
        }
        else
        {
            if(res.size() < cur.size())
            {
                res = cur;
            }
            cur.clear();
        }
    }

    cout << res;
 
}
