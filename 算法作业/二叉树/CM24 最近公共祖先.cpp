//https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=11017&rp=1&ru=/activity/oj&qru=/ta/cracking-the-coding-interview/question-ranking
class LCA {
public:
    int getLCA(int a, int b) {
        int parenta = a / 2;
        int parentb = b / 2;
        while(parenta != parentb)
        {
            if(parenta > parentb)
                parenta /= 2;
            else
                parentb /= 2;
        }

        return parenta;

    }
};