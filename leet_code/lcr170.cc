#include "common_def.h"

class Solution {
public:
    int MergeSort(vector<int>& rec, vector<int>& tmp, int l, int r) {
        // the last one
        if(l>=r) {
            return 0;
        }
        int m = (l + r) / 2;
        // result
        int res = MergeSort(rec, tmp, l, m) +  MergeSort(rec, tmp, m+1, r);
        // merge
        // 处理 左边和右边
        int i = m, j = r;
        // 统计数字
        while(i >= l) {
            while(j >= m+1) {
                if(rec[i] > rec[j]) {
                    res += j - m;
                    break;
                }
                --j;
            }
            --i;
        }
        // 排序
        i = l;
        j = m+1;
        int idx = l;
        while(i <= m && j <= r){
            if(rec[i] < rec[j]) {
                tmp[idx++] = rec[i++];
            } else {
                tmp[idx++] = rec[j++];
            }
        }
        while(i<=m){
            tmp[idx++] = rec[i++];
        }
        while(j <= r) {
            tmp[idx++] = rec[j++];
        }
        for(int idx = l; idx<=r;++idx){
            rec[idx] = tmp[idx];
        }
        return res;
        // note ...
    }
    // 归并排序思想，但是不能排序
    int reversePairs(vector<int>& record) {
        std::vector<int> tmp(record.size(), 0);
        return MergeSort(record, tmp, 0, record.size() - 1);
    }
};