//https://www.nowcoder.com/practice/02d8d42b197646a5bbd0a98785bb3a34?tpId=85&&tqId=29857&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking
#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if((a + c) % 2 == 0 && (d - b) % 2 == 0 && (b + d) % 2 == 0 && (c-a) == (d + b))
    {
        A = (a + c) / 2;
        C = (d - b) / 2;
        B = (b + d) / 2;
        cout << A << ' ' << B << ' ' << C << endl;
    }
    else 
    {
        cout << "No" << endl;

    }
    return 0;
}
