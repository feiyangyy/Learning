#include <vector>
#include <queue>
#include <stdint.h>

class MedianFinder {
public:
    /** initialize your data structure here. */
    // less 是大顶堆，较小的数据会被往后插
    std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
    // greater 是小顶堆，较大的数据会被往后差
    std::priority_queue<int, std::vector<int>, std::greater<int>> min_heap;
    uint32_t cur_size = 0;
    MedianFinder() {

    }
    /*
        解题思路:
        1. 维持两个堆，一个是大根堆，一个是小根堆，大根堆和小根堆的数据数量要平衡, |min.size() - max.size()| <= 1;
           要判断该数字是否应该调整到大根堆中，调整的规则是,大根堆的top，比 小根堆的top 要大， 小根堆在大根堆右边，最小值应当比大根堆的最大值要大
        2. 假设当前总数字为奇数，若max.size() > min.size， 则中位数是max.first(), 反之，是min.last() （top）
        3. 如果是偶数，那么中位数就是min.last() + max.first()/2;
          
    */
    void addNum(int num) {
        
        if(min_heap.size() <= max_heap.size()) {
            min_heap.push(num);
        } else {
            max_heap.push(num);
        }
        if(min_heap.size() && max_heap.size() && min_heap.top() < max_heap.top()) {
            int tmp = max_heap.top();
            max_heap.pop();
            max_heap.push(min_heap.top());
            min_heap.pop();
            min_heap.push(tmp);
        }
        ++cur_size;
    }
    
    double findMedian() {
        // even.
        if(cur_size & 0x1) {
            // printf("min_heap top:", min_heap.top());
            return min_heap.size() > max_heap.size()? min_heap.top() : max_heap.top();
        }
        return (double)(min_heap.top() + max_heap.top()) /2;
    }
};

int main(){
    MedianFinder m;
    m.addNum(1);
    m.addNum(2);
    m.addNum(3);
    double v = m.findMedian();
    return 0;
}