#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int nsz_1 = num1.size();
        int nsz_2 = num2.size();
        // std::vector<string> res;
        std::string res = "0";
        for(int idx = nsz_1 -1; idx>=0; --idx){
            int mult_n1 = num1.at(idx) - '0';
            int carry = 0;
            // std::string cur_res('0', nsz_1 - 1 - idx);
            std::string cur_res;
            for(int i = idx; i < nsz_1 -1; ++i) {
                // cur_res.push_front('0');
                cur_res = "0" + cur_res;
            }

            for(int j = nsz_2 -1; j >=0; --j) {
                int mult_n2 = num2.at(j) - '0';
                int num = mult_n1 * mult_n2 + carry;
                carry = num / 10;
                num = num %10;
                // push_back, 然后利用rbegin() 迭代，思想一致
                cur_res = (static_cast<char>(num + '0')) + cur_res;
            }
            // res.append(cur_res);
            res = AddString(res, cur_res);
        }
        return res;
    }

    string AddString(const string& n1, const string& n2) {
        std::string res;
        int i = n1.size() - 1;
        int j = n2.size() - 2;
        int carry = 0;
        while(i >= 0 && j >= 0) {
            int n = n1[i] +  n2[j] - '0' * 2 + carry;
            carry = n / 10;
            n = n % 10;
            // res.push_front(n + '0');
            res = char('0' + n) + res;
            --i;
            --j;
        }

        while (i >= 0) {
            int n = n1[i] - '0' + carry;
            carry = n /10;
            n = n % 10;
            res = char('0' + n) + res;
            --i;
        }

        while (j >= 0) {
            int n = n2[j] - '0' + carry;
            carry = n /10;
            n = n % 10;
            res = char('0' + n) + res;
            --j;
        }

        if (carry) {
            // res.push_front(carry + '0');
            res = char('0' + carry) + res;
        }
        return res;
    }
};


int main() {
    return 0;
}