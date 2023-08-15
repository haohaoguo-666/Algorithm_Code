//https://www.nowcoder.com/practice/18ecd0ecf5ef4fe9ba3f17f8d00d2d66?tpId=85&&tqId=29846&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
using namespace std;



int main() {
    int N;
    cin >> N;
    int a = 0, b = 1, c = 0;
    while(N > c)
    {
        c = a + b;
        a = b;
        b = c;
    }
    
    cout <<  (c - N < N - a ? c - N : N - a) << endl;
}
// 64 位输出请用 printf("%lld")