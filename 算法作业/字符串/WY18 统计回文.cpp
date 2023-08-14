//https://www.nowcoder.com/practice/9d1559511b3849deaa71b576fa7009dc?tpId=85&&tqId=29842&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
#include <algorithm>

using namespace std;

bool ispalindrome(const string& str)
{
    string buf = str;
    reverse(buf.begin(), buf.end());
    return str == buf;
}

int main() {
    string A;
    string B;
    cin >> A >> B;
    int nums;
    for(int i = 0;i <= A.size();i++)
    {
        string C = A;
        C.insert(i, B);
        if(ispalindrome(C)) ++nums;
    }
    cout << nums;
}
// 64 位输出请用 printf("%lld")