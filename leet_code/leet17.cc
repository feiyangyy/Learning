#include "common_def.h"
#include <string>
using std::string;
// dfs 入门算法
class Solution {
public:
  static std::unordered_map<char, std::string> key_hash;

  void dfs(std::string &dig, int i, std::string &tmp_res,
           std::vector<std::string> &res) {
    // 已经构造完毕了
    // 此时i == tmp_res.size()
    if (tmp_res.size() == dig.size()) {
      res.push_back(tmp_res);
      // tmp_res.pop_back();
      return;
    }
    for (int j = 0; j < key_hash[dig[i]].size(); ++j) {
      tmp_res.push_back(key_hash[dig[i]][j]);
      dfs(dig, i + 1, tmp_res, res);
      tmp_res.pop_back();
    }
  }
  vector<string> letterCombinations(string digits) {

    vector<string> res;
    std::string tmp;
    if (digits.size() == 0) {
      return res;
    }
    dfs(digits, 0, tmp, res);
    return res;
  }
};

std::unordered_map<char, std::string> Solution::key_hash = {
    {'1', ""},    {'2', "abc"},  {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
    {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};