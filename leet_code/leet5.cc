#include "common_def.h"
#include <string>
using std::string;

class Solution {
public:
    string longestPalindrome(string s) {
      if(s==""){
        return s;
      }
      std::string res;
      int l,r;
      int len, max_len = 0;
      
      for(int idx=1;idx<s.size() -1;++idx){
        l = idx-1;
        r = idx + 1;
        len =1;
        while(l>=0 && s[l] == s[idx]){
          --l;
          ++len;
        }
        while(r<=s.size() && s[r] == s[idx]){
          ++r;
          ++len;
        }
        while(l>=0 && r < s.size() && s[r]==s[l]){
          ++r;
          --l;
          len += 2;
        }
        if(len>max_len){
          max_len = len;
          res.resize(max_len);
          std::copy(s.begin()+ l + 1, s.begin() + r, res.begin());
        }
      }
      return res;
    }


    string longestPalindrome2(string s) {
      if(s==""){
        return s;
      }
      std::string res;
      int l,r;
      int len, max_len = 0;
      std::vector< std::vector<bool>> dp(s.size(), std::vector<bool>(s.size(), false));
      for(int idx=1;idx<s.size() -1;++idx){
        dp[idx][idx] = true;
        l = idx-1;
        r = idx + 1;
        len =1;
        while(l>=0 && s[l] == s[idx]){
          dp[l][idx]= true;
          --l;
          ++len;
        }
        while(r<=s.size() && s[r] == s[idx]){
          dp[idx][r]= true;
          ++r;
          ++len;
        }
        while(l>=0 && r < s.size() && s[r]==s[l]){
          ++r;
          --l;
          len += 2;
        }
        if(len>max_len){
          max_len = len;
          res.resize(max_len);
          std::copy(s.begin()+ l + 1, s.begin() + r, res.begin());
        }
      }
      return res;
    }
};