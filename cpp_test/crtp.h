class DBase {
 public:
  static DBase* Instance();
  virtual ~DBase() {}
  virtual void Test(int num) = 0;

 protected:
  int i_;
};

class DDerive : public DBase {
  virtual void Test(int num) override;
};