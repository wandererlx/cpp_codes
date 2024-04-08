//
// Created by shawnunili on 2020-03-31.
//

#ifndef UBFRECALLSERVER_MAXHEAP_H
#define UBFRECALLSERVER_MAXHEAP_H

#include <stdint.h>
#include <vector>
#include <queue>
#include <string>

struct MergeSortData{
    int64_t cid;
    float score;
    size_t index;
};

auto maxHeapCmp = [](const MergeSortData lhs, const MergeSortData rhs) {
    return lhs.score < rhs.score;
};
// https://www.cnblogs.com/navy-coding/p/15374628.html
class MaxHeap {
    typedef std::priority_queue<MergeSortData, std::vector<MergeSortData>, decltype(maxHeapCmp)> MaxHeapType;
public:
    MaxHeap(size_t heapSize);

    bool pop(MergeSortData& minData);

    bool insert(const MergeSortData& data);

    bool empty();

private:
    size_t m_heapSize;
    MaxHeapType m_queue_;
};


#endif //UBFRECALLSERVER_MAXHEAP_H
