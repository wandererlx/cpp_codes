// Proxy.h

#ifndef _PROXY_H_
#define _PROXY_H_

class Subject {
 private:
  /* data */

 protected:
  Subject();

 public:
  virtual void Request() = 0;
  virtual ~Subject();
};

class ConcreteSubject : public Subject {
 private:
  /* data */
 public:
  ConcreteSubject(/* args */);
  ~ConcreteSubject();
  void Request();
};

class Proxy {
 private:
  Subject* _sub;

 public:
  Proxy(/* args */);
  Proxy(Subject* sub);
  ~Proxy();
  void Request();
};

#endif  //~_PROXY_H_