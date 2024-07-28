#include "common_def.h"
#include <map>
class Solution {

public:
  vector<double> statisticsProbability(int num) {
    std::vector<double> res;
    std::vector<std::map<int, double>> dp;
    static constexpr double v = (double)(1) / 6;
    std::map<int, double> base = {{1, v}, {2, v}, {3, v},
                                  {4, v}, {5, v}, {6, v}};
    dp.push_back(base);
    int tgt_min = 0;
    int tgt_max = 0;
    for (int idx = 2; idx <= num; ++idx) {
      tgt_min = idx;
      tgt_max = 6 * idx;
      int index = idx - 1;
      std::map<int, double> cur_base;
      for (int j = tgt_min; j <= tgt_max; ++j) {
        auto &dp_prev = dp[index - 1];
        // prev sum 选定某个值的情况下， 如果能构成target，
        // 则当前的值是唯一确认的
        cur_base.insert(std::make_pair(j, (double)0));
        for (auto iter = dp_prev.begin(); iter != dp_prev.end(); ++iter) {
          // auto it = cur_base.find(j);
          // note: 要注意合理的取值范围
          if (j - iter->first > 0 && j - iter->first <= 6) {
            cur_base[j] += iter->second / 6;
          }
        }
      }
      dp.push_back(cur_base);
    }
    for (auto iter = dp.back().begin(); iter != dp.back().end(); ++iter) {
      res.push_back(iter->second);
    }
    return res;
  }
};

int main() {
  auto res = Solution().statisticsProbability(3);
  return 0;
}