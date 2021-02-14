// 寒假每日一题（入门组）0117
// WA了4次。。。。

#include <cstdio>
#include <list>
#include <vector>

class Score {
  public:
    int num;    // 编号，从0开始
    int yuwen;  // 语文成绩
    int sum;    // 总分
    Score(int i, int yw, int sx, int yy) {
        num = i;
        yuwen = yw;
        sum = yw + sx + yy;
    }
    void print() {
        printf("%d %d\n", num + 1, sum);
    }
};

int Larger(Score& s1, Score& s2) {
    if (s1.sum > s2.sum) {
        return 1;
    } else if (s1.sum < s2.sum) {
        return 0;
    } else {
        if (s1.yuwen > s2.yuwen) {
            return 1;
        } else if (s1.yuwen < s2.yuwen) {
            return 0;
        } else {
            if (s1.num < s2.num) {
                return 1;
            } else {
                return 0;
            }
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);

    std::vector<Score> Board_;

    std::list<int> Top5_;
    Top5_.push_back(0);

    for (int i = 0; i < n; i++) {
        int yw, sx, yy;
        scanf("%d %d %d", &yw, &sx, &yy);
        Score score(i, yw, sx, yy);
        Board_.push_back(score);
        if (i >= 5 && Larger(score, Board_[*Top5_.rbegin()])) {
            bool isUpdated = false;
            for (std::list<int>::reverse_iterator p = Top5_.rbegin();
                 p != Top5_.rend(); p++) {
                if (Larger(Board_[*p], score)) {
                    Top5_.insert(p.base(), score.num);
                    Top5_.pop_back();
                    isUpdated = true;
                    break;
                }
            }
            if (!isUpdated) {
                Top5_.insert(Top5_.begin(), score.num);
                Top5_.pop_back();
            }

        } else if (i >= 1 && i < 5) {
            if (!Larger(score, Board_[*Top5_.rbegin()])) {
                Top5_.push_back(score.num);
            } else {
                for (std::list<int>::iterator p = Top5_.begin();
                     p != Top5_.end(); p++) {
                    if (Larger(score, Board_[*p])) {
                        Top5_.insert(p, score.num);
                        break;
                    }
                }
            }
        }
    }

    for (std::list<int>::iterator p = Top5_.begin(); p != Top5_.end(); p++) {
        Board_[*p].print();
    }
}
