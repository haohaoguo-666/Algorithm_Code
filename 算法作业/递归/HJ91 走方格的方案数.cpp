//https://www.nowcoder.com/practice/e2a22f0305eb4f2f9846e7d644dba09b?tpId=37&&tqId=21314&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
#include <iostream>
using namespace std;
int pathNum(int n, int m)
{
        
    if(m == 0 || n == 0)
        return 1;
    return pathNum(n - 1, m) + pathNum(n, m - 1);
}

int main() {
    int a, b;
    while (cin >> a >> b) { // 注意 while 处理多个 case
        cout << pathNum(a, b) << endl;
    }
}
// 64 位输出请用 printf("%lld")
