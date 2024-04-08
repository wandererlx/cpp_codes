# designPatternsByCpp

## 介绍
Factory 模式-GoF 23 种设计模式精解系列- C++实现源码

## 前言

尊重原创，本系列文本解析部分主要基于Candidate for Master’s Degree School of Computer Wuhan University的K_Eckel（frwei@whu.edu.cn）《设计模式精解-GoF 23 种设计模式解析附 C++实现源码》。为了避免重造轮子，本系列博文对源码在ubuntu16.04下做了验证并上传到了[gitee](https://gitee.com/PattenKuo/designpatternsbycpipei)，再次感谢。

如有问题，可邮件联系我([guopengzhen@guopengzhen.com](mailto:guopengzhen@guopengzhen.com))并共同探讨解决方案。

## 设计模式简介
什么是设计模式？官方一点的说法是:
>设计模式（Design pattern）代表了最佳的实践，通常被有经验的面向对象的软件开发人员所采用。设计模式是软件开发人员在软件开发过程中面临的一般问题的解决方案。这些解决方案是众多软件开发人员经过相当长的一段时间的试验和错误总结出来的。
通俗点，就是：*软件开发实践中常见问题的通用解决方案*（我称之为GS, General Solutions）。

在 1994 年，由 Erich Gamma、Richard Helm、Ralph Johnson 和 John Vlissides 四人合著出版了一本名为 《**Design Patterns - Elements of Reusable Object-Oriented Software**》（**中文译名：设计模式 - 可复用的面向对象软件元素**） 的书，该书首次提到了软件开发中*设计模式*的概念。
四位作者合称 **GOF**（四人帮，全拼 Gang of Four）。
在这本书里，提出了23种通用设计模式，分为三类:
* -**创建型模式**(Creating Pattern):提供了一种在创建对象的同时隐藏创建逻辑的方式，而不是使用 `new` 运算符直接实例化对象。这使得程序在判断针对某个给定实例需要创建哪些对象时更加灵活。提供了一种在创建对象的同时隐藏创建逻辑的方式，而不是使用 `new` 运算符直接实例化对象。这使得程序在判断针对某个给定实例需要创建哪些对象时更加灵活。
* -**结构型模式**（Structrual Pattern）:关注类和对象的组合。继承的概念被用来组合接口和定义组合对象获得新功能的方式。
* -**行为型模式**（Behavioral  Pattern）:特别关注对象之间的通信。

## 目录

### 创建型模式(Creating Pattern)

[Factory 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/15645/) | [AbstactFactory 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/34277/) | [Singleton 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/48635/) | [Builder 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/42048/) | [Prototype 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/16065/)

### 结构型模式（Structrual Pattern）

[Bridge 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/14587/) | [Adapter 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/65216/) | [Decorator 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/61255/) | [Composite 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/30230/) | [Flyweight 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/53984/) | [Facade 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/51937/) | [Proxy 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/26330/)

### 行为型模式（Behavioral  Pattern）

[Template 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/52399/) | [Strategy 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/63289/) | [State 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/63548/) | [Observer 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/25006/) | [Memento 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/46123/) | [Mediator 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/44726/) | [Command 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/1841/) | [Visitor 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/65039/) | [Iterator 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/5352/) | [Interpreter 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/32738/) | [Chain of Responsibility 模式](https://guopengzhen.com/%E8%AE%BE%E8%AE%A1%E6%A8%A1%E5%BC%8F/61386/)
