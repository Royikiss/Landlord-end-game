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
#include <vector>
#define MAX_N 18
using namespace std;

enum class PAI_TYPE {
  DAN_TYPE,
  DUIZI_TYPE,
  SHUNZI_TYPE,
  LIANDUI_TYPE,
  SANDAI_TYPE,
  ZHADAN_TYPE,
  WANGZHA_TYPE,
  PASS_TYPE,
};

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
