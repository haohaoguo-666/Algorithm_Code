//https://www.nowcoder.com/practice/e7e0d226f1e84ba7ab8b28efc6e1aebc?tpId=8&&tqId=11065&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
class UnusualAdd {
public:
    int addAB(int A, int B) {
        if(A == 0) return B;
        if(B == 0) return A;
        int a = A ^ B;//相加后不用进位的数据
        int b = (A & B) << 1;//相加后进位的数据
        return addAB(a, b);
    }
};