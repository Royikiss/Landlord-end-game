/*************************************************************************
        > File Name: pai.h
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Tue 21 May 2024 11:37:10 AM HKT
      > Describe:
 ************************************************************************/

#ifndef _PAI_H__
#define _PAI_H__

#include <iostream>
#include <ostream>
#include <vector>
#define MAX_N 18
using namespace std;

enum class PAI_TYPE {
  DAN_TYPE,                         // 单张
  DUIZI_TYPE,                       // 对子
  SHUNZI_TYPE,                      // 顺子
  LIANDUI_TYPE,                     // 连对
  SANDAI_TYPE,                      // 三带一
  SIDAI_TYPE,                       // 四带二 (new)
  ZHADAN_TYPE,                      // 炸弹
  WANGZHA_TYPE,                     // 王炸
  PASS_TYPE,                        // pass
};

// 牌的基类
class PAI {
public:
  PAI(PAI_TYPE type);
  static vector<PAI *> getPai(int *);
  static vector<PAI *> getLegalPai(int *, PAI *);
  static void output_arr(int *);
  virtual ostream &output() = 0;
  virtual bool operator>(PAI *pre) = 0;
  virtual void take(int *) = 0;
  virtual void back(int *) = 0;
  PAI_TYPE type; 
  virtual ~PAI() = default;
};

class PASS : public PAI {
public:
  PASS();
  ostream &output() override; 
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr); 
};

class DAN : public PAI {
public:
  DAN(int x);
  ostream &output() override;
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr);
private:
  int x;
};

class DUIZI : public PAI {
public:
  DUIZI(int x);
  ostream &output() override; 
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr);

private:
  int x;
};

class SHUNZI : public PAI {
public:
  SHUNZI(int x, int len);
  ostream &output() override;
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr);

private:
  int x, len;
};

class LIANDUI : public PAI {
public:
  LIANDUI(int x, int len);
  ostream &output() override;
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr);

private:
  int x, len;
};

class SANDAI : public PAI {
public:
  SANDAI(int x, PAI *dai);
  ostream &output() override;
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr);
private:
  int x;
  PAI *dai;
};

class SIDAI : public PAI {
public:
    SIDAI(int x, PAI *dai1, PAI *dai2);
    ostream &output() override;
    bool operator>(PAI *pre) override;
    void take(int *) override;
    void back(int *) override;
    static vector<PAI *> get(int *arr);
private:
    int x;
    PAI *dai1, *dai2;           // 可以是两张单张或两对子
};

class ZHADAN : public PAI {
public:
  ZHADAN(int x);
  ostream &output() override;
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr);

private:
  int x;
};

class WANGZHA : public PAI {
public:
  WANGZHA();
  ostream &output() override;
  bool operator>(PAI *pre) override;
  void take(int *) override;
  void back(int *) override;
  static vector<PAI *> get(int *arr);
};

#endif
