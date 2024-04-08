// Aggregate.h

#ifndef _AGGREGATE_H_
#define _AGGREGATE_H_

class Iterator;
typedef int Object;

class Aggregate {
 private:
  /* data */

 protected:
  Aggregate(/* args */);

 public:
  virtual ~Aggregate();
  virtual Iterator* CreateIterator() = 0;
  virtual Object GetItem(int idx) = 0;
  virtual int GetSize() = 0;
};

class ConcreteAggregate : public Aggregate {
 public:
  enum { SIZE = 3 };
  ConcreteAggregate(/* args */);
  ~ConcreteAggregate();
  Iterator* CreateIterator();
  Object GetItem(int idx);
  int GetSize();

 private:
  Object _objs[SIZE];
};

#endif  //~_AGGREGATE_H_