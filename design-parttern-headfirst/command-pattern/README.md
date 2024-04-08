# 命令模式

本部分实现Head First中最终版的代码，关于其详细的分析过程可参考相应的书籍。

其构建基于bazel。

## 定义

将“请求”封装成对象，以便使用不同的请求、队列或者日志来参数化其他对象。命令模式也支持可撤销操作。


命令模式可以封装“方法调用”。

# note

1. command 目录中为各个实现的命令对象

2. control 为遥控器的实现

3. slot 该目录中实现的是各个插槽所联系的实际对象 譬如台灯，仓库门等

# 构建过程

bazel build //:all

# 附注

关于命令模式，在HeadFirst中还会讲解undo操作以及宏命令模式，本部分没有实现；

这是因为这两个均是本部分的附赠功能，在本部分代码少做修改便可完成。