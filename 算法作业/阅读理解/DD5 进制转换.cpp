//https://www.nowcoder.com/practice/ac61207721a34b74b06597fe6eb67c52?tpId=85&&tqId=29862&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
#include <stack>
using namespace std;

int main() {
    int M, N;
    char str[17] ="0123456789ABCDEF";
    cin >> M >> N;
    stack<char> res;
    int x = 0;
    if(M < 0)
    {
        x = 1;
        M = -M;
    }
    while(M >= N)
    {
        res.push(str[M % N]);
        M /= N;
    }
    res.push(str[M]);
    if(x == 1)
    {
        cout << '-';
    }
    while(!res.empty())
    {
        cout << res.top();
        res.pop();
    }
}
