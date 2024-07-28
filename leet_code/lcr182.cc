#include "common_def.h"
#include <string>
using std::string;

class Solution {
public:
    // 如果要有额外空间限制，那么就只能原地反转
    string dynamicPassword(string password, int target) {
        string res(password.size(), '\0');
        std::copy(password.begin() + target, password.end(), res.begin());
        std::copy(password.begin(), password.begin()+target, res.begin() + password.size() - target);
        return res;
    }
};
