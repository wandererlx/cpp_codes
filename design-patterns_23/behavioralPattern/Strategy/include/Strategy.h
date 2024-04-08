// Strategy.h

#ifndef _STRATEGY_H_
#define _STRATEGY_H_

class Strategy {
 private:
  /* data */
 public:
  Strategy(/* args */);
  virtual ~Strategy();
  virtual void AlgrithmInterface() = 0;
};

class ConcreteStrategyA : public Strategy {
 private:
  /* data */
 public:
  ConcreteStrategyA(/* args */);
  virtual ~ConcreteStrategyA();
  void AlgrithmInterface();
};

class ConcreteStrategyB : public Strategy {
 private:
  /* data */
 public:
  ConcreteStrategyB(/* args */);
  virtual ~ConcreteStrategyB();
  void AlgrithmInterface();
};

#endif  //~_STRATEGY_H_
