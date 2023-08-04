#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;
    string s2;
    cin >> s1;
    s1.begin();
    while(cin >> s2)
    {
        s1 = s2 + " " + s1;
    }
    cout << s1 << endl;
}
//https://www.nowcoder.com/practice/ee5de2e7c45a46a090c1ced2fdc62355?tpId=85&&tqId=29867&rp=1&ru=/activity/oj&qru=/ta/2017test/question-ranking