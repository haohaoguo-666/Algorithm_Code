//https://www.nowcoder.com/practice/52d382c2a7164767bca2064c1c9d5361?tpId=37&&tqId=21310&rp=1&ru=/activity/oj&qru=/ta/huawei/question-ranking
#include <iostream>
using namespace std;

int score_count(string& str) {
    int length = 0;//密码长度
    int nums_xzm = 0;//小写字母个数
    int nums_dzm = 0;//大写字母个数
    int nums_sz = 0;//数字个数
    int nums_fh = 0;//符号个数
    int nums_jl = 0;//奖励档次
    int res = 0;

    length = str.size();
    for (auto i : str) {
        if (i >= 'a' && i <= 'z')
            ++nums_xzm;
        else if (i >= 'A' && i <= 'Z')
            ++nums_dzm;
        else if (i >= '0' && i <= '9')
            ++nums_sz;
        else
            ++nums_fh;
    }

    if (length <= 4)
        res += 5;
    else if (length <= 7)
        res += 10;
    else
        res += 25;

    if (nums_xzm > 0 && nums_dzm == 0)
        res += 10;
    else if (nums_xzm == 0 && nums_dzm > 0)
        res += 10;
    else if (nums_xzm > 0 && nums_dzm > 0)
        res += 20;

    if (nums_sz == 1)
        res += 10;
    else if (nums_sz > 1)
        res += 20;

    if (nums_fh == 1)
        res += 10;
    else if (nums_fh > 1)
        res += 25;

    if (nums_dzm > 0 && nums_xzm > 0 && nums_sz > 0 && nums_fh > 0)
        res += 5;
    else if ((nums_dzm > 0 || nums_xzm > 0) && nums_sz > 0 && nums_fh > 0)
        res += 3;
    else if ((nums_dzm > 0 || nums_xzm > 0) && nums_sz > 0)
        res += 2;

    return res;
}

int main() {
    string str;
    while (cin >> str) {
        int score = score_count(str);
        if (score >= 90) {
            cout << "VERY_SECURE" << endl;
        } else if (score >= 80) {
            cout << "SECURE" << endl;
        } else if (score >= 70) {
            cout << "VERY_STRONG" << endl;
        } else if (score >= 60) {
            cout << "STRONG" << endl;
        } else if (score >= 50) {
            cout << "AVERAGE" << endl;
        } else if (score >= 25) {
            cout << "WEAK" << endl;
        } else {
            cout << "VERY_WEAK" << endl;
        }
    } 
    return 0;
}
// 64 位输出请用 printf("%lld")