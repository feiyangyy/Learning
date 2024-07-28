#include <stdio.h>

class Solution {
public:
    int findKthNumber(int k) {
        if(k <= 0) {
            return 0;
        }
        int start = 1;
        int end = start * 10 - 1;
        // 注意超过范围的问题
        uint64_t pos_count = 9;
        uint64_t start_pos = 1;
        int dig = 1;
        while(pos_count < k) {
            start *= 10;
            end = start * 10 -1;
            dig += 1;
            start_pos = pos_count + 1;
            // 实际上是end_pos
            pos_count += (uint64_t)dig * 9 * start;
        }
        // start 已有
        int dis = k - start_pos;
        // 距离start有多少数值
        int num = dis / dig;
        // 取余数，确认是num的第几位
        int num_pos = dis % dig;
        int real_num = start + num;
        printf("sp:%d, ep:%d, start:%d, end:%d, dig:%d, real num:%d\n", start_pos, pos_count, start, end, dig, real_num);
        int shift = dig - num_pos - 1;

        while(shift){
            real_num /= 10;
            --shift;
        }
        
        return real_num % 10;
    }
};

int main(){
    Solution::findKthNumber(1000);
    return 0;
}