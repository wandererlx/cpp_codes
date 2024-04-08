142 环形链表

https://leetcode.cn/problems/linked-list-cycle-ii/solutions/441131/huan-xing-lian-biao-ii-by-leetcode-solution/?envType=featured-list&envId=2cktkvj?envType=featured-list&envId=2cktkvj
为何慢指针第一圈走不完一定会和快指针相遇? 可以认为快指针和慢指针是相对运动的，假设慢指针的速度是 1节点/秒，快指针的速度是 2节点/秒，当以慢指针为参考系的话（即慢指针静止），快指针的移动速度就是 1节点/秒，所以肯定会相遇。
为什么在第一圈就会相遇呢？ 设环的长度为 L，当慢指针刚进入环时，慢指针需要走 L 步(即 L 秒)才能走完一圈，此时快指针距离慢指针的最大距离为 L-1，我们再次以慢指针为参考系，如上所说，快指针在按照1节点/秒的速度在追赶慢指针，所以肯定能在 L 秒内追赶到慢指针