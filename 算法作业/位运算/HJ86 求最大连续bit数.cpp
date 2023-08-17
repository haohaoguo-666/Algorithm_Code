//https://www.nowcoder.com/practice/4b1658fd8ffb4217bc3b7e85a38cfaf2?tpId=37&&tqId=21309&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
#include <iostream>
using namespace std;

int main() {
    int a;
    int max = 0;
    int length = 0;
    cin >> a;
    while(a)
    {
        if(a & 1)
        {
            ++length;
            if(length > max)
            max = length;
        }   
        else 
        {
            length = 0;
        }
        a = a >> 1;
    }

    cout << max << endl;
}