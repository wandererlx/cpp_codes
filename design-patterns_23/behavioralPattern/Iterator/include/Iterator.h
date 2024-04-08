// Iterator.h

#ifndef _ITERATOR_H_
#define _ITERATOR_H_

class Aggregate;

typedef int Object;

class Iterator {
 private:
  /* data */

 protected:
  Iterator(/* args */);

 public:
  ~Iterator();
  virtual void First() = 0;
  virtual void Next() = 0;
  virtual bool IsDone() = 0;
  virtual Object CurrentItem() = 0;
};

class ConcreteIterator : public Iterator {
 private:
  Aggregate* _ag;
  int _idx;

 public:
  ConcreteIterator(Aggregate* ag, int idx = 0);
  ~ConcreteIterator();
  void First();
  void Next();
  bool IsDone();
  Object CurrentItem();
};

#endif //~_ITERATOR_H_