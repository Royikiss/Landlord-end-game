/*************************************************************************
        > File Name: pai.cc
      > Author: royi
      > Mail: royi990001@gmail.com
      > Created Time: 08:49 PM
      > Describe: description
 ************************************************************************/

#include <vector>
#include "../include/pai.h"
using namespace std;

#define MAX_N 18

static string name[MAX_N + 5] = {"",  "",  "",    "3", "4",      "5",
                                 "6", "7", "8",   "9", "10",     "J",
                                 "Q", "K", "Ace", "2", "jocker", "JOCKER"};

PAI::PAI(PAI_TYPE type) : type(type) {}
void PAI::output_arr(int *arr) {
  for (int i = 3; i < MAX_N; ++i) {
    if (arr[i] == 0) continue;
    int num = arr[i];
    while (num--) cout << name[i] << " ";
  }
  cout << endl;
  return ;
}

PASS::PASS() : PAI(PAI_TYPE::PASS_TYPE) {}
ostream &PASS::output() { return cout << "PASS"; }
bool PASS::operator>(PAI *pre) {
  return pre->type != PAI_TYPE::PASS_TYPE;
}
void PASS::take(int *arr) { return ;}
void PASS::back(int *arr) { return ;}
vector<PAI *> PASS::get(int *arr) {
  vector<PAI *> ret;
  ret.push_back(new PASS());
  return ret;
}


DAN::DAN(int x) : x(x), PAI(PAI_TYPE::DAN_TYPE) {}
ostream &DAN::output() { return cout << "DAN : " << name[x]; }
bool DAN::operator>(PAI *pre) {
  switch (pre->type) {
    case PAI_TYPE::PASS_TYPE: return true;
    case PAI_TYPE::DAN_TYPE: {
      DAN *pre_ = dynamic_cast<DAN *>(pre);
      return this->x > pre_->x;
    } break;
    default: return false;
  }
}
void DAN::take(int *arr) {
  arr[x] -= 1;
  return ;
}
void DAN::back(int *arr) { 
  arr[x] += 1;
  return ;
}
vector<PAI *> DAN::get(int *arr) {
  vector<PAI *> temp;
  for (int i = 3; i < MAX_N; ++i) {
    if (arr[i] <= 0)
      continue;
    temp.push_back(new DAN(i));
  }
  return temp;
}

DUIZI::DUIZI(int x) : x(x), PAI(PAI_TYPE::DUIZI_TYPE) {}
ostream &DUIZI::output() { return cout << "DUIZI : " << name[x]; }
bool DUIZI::operator>(PAI *pre) {
  switch (pre->type) {
    case PAI_TYPE::PASS_TYPE: return true;
    case PAI_TYPE::DUIZI_TYPE: {
      DUIZI *pre_ = dynamic_cast<DUIZI *>(pre);
      return this->x > pre_->x;
    } break;
    default: return false;
  }
}
void DUIZI::take(int *arr) {
  arr[x] -= 2;
  return ;
}
void DUIZI::back(int *arr) { 
  arr[x] += 2;
  return ;
}
vector<PAI *> DUIZI::get(int *arr) {
  vector<PAI *> ret;
  for (int i = 0; i < MAX_N; ++i) {
    if (arr[i] <= 1)
      continue;
    ret.push_back(new DUIZI(i));
  }
  return ret;
}

SHUNZI::SHUNZI(int x, int len) : x(x), len(len), PAI(PAI_TYPE::SHUNZI_TYPE) {}
ostream &SHUNZI::output() {
  cout << "SHUNZI : ";
  for (int i = x; i < x + len; ++i) {
    cout << name[i] << " ";
  }
  return cout;
}
bool SHUNZI::operator>(PAI *pre) {
  switch (pre->type) {
    case PAI_TYPE::PASS_TYPE: return true;
    case PAI_TYPE::SHUNZI_TYPE: {
      SHUNZI *pre_ = dynamic_cast<SHUNZI *>(pre);
      if (this->len != pre_->len) return false;
      return this->x > pre_->x;
    } break;
    default: return false;
  }
}
void SHUNZI::take(int *arr) {
  for (int i = x; i < x + len; ++i) {
    arr[i] -= 1;
  }
  return ;
}
void SHUNZI::back(int *arr) { 
  for (int i = x; i < x + len; ++i) {
    arr[i] += 1;
  }
  return ;
}
vector<PAI *> SHUNZI::get(int *arr) {
  vector<PAI *> ret;
  // length
  for (int l = 5; l < 12; ++l) {
    for (int i = 3, I = 14 - l + 1; i < I; ++i) {
      int flag = 1;
      for (int j = i; j < i + l; ++j) {
        if (arr[j])
          continue;
        flag = 0;
        break;
      }
      if (flag == 1)
        ret.push_back(new SHUNZI(i, l));
    }
  }
  return ret;
}

LIANDUI::LIANDUI(int x, int len) : x(x), len(len), PAI(PAI_TYPE::LIANDUI_TYPE) {}
ostream &LIANDUI::output() {
  cout << "LIANDUI : ";
  for (int i = x; i < x + len; ++i) {
    cout << name[i] << " ";
  }
  return cout;
}
bool LIANDUI::operator>(PAI *pre) {
  switch (pre->type) {
    case PAI_TYPE::PASS_TYPE: return true;
    case PAI_TYPE::LIANDUI_TYPE: {
      LIANDUI *pre_ = dynamic_cast<LIANDUI *>(pre);
      if (this->len != pre_->len) return false;
      return this->x > pre_->x;
    } break;
    default: return false;
  }
}
void LIANDUI::take(int *arr) {
  for (int i = x; i < x + len; ++i) {
    arr[i] -= 2;
  }
  return ;
}
void LIANDUI::back(int *arr) { 
  for (int i = x; i < x + len; ++i) {
    arr[i] += 2;
  }
  return ;
}
vector<PAI *> LIANDUI::get(int *arr) {
  vector<PAI *> ret;
  // length
  for (int l = 3; l < 12; ++l) {
    for (int i = 3, I = 14 - l + 1; i < I; ++i) {
      int flag = 1;
      for (int j = i; j < i + l; ++j) {
        if (arr[j] >= 2)
          continue;
        flag = 0;
        break;
      }
      if (flag == 1)
        ret.push_back(new LIANDUI(i, l));
    }
  }
  return ret;
}

SANDAI::SANDAI(int x, PAI *dai) : x(x), dai(dai), PAI(PAI_TYPE::SANDAI_TYPE) {}
ostream &SANDAI::output() {
  cout << "SAN : " << name[x] << " DAI : ";
  dai->output();
  return cout;
}
bool SANDAI::operator>(PAI *pre) {
  switch (pre->type) {
    case PAI_TYPE::PASS_TYPE: return true;
    case PAI_TYPE::SANDAI_TYPE: {
      SANDAI *pre_ = dynamic_cast<SANDAI *>(pre);
      if (this->dai->type != pre_->dai->type) return false;
      return this->x > pre_->x;
    } break;
    default: return false;
  }
}
void SANDAI::take(int *arr) {
  arr[x] -= 3;
  dai->take(arr);
  return ;
}
void SANDAI::back(int *arr) { 
  arr[x] += 3;
  dai->back(arr);
  return ;
}
vector<PAI *> SANDAI::get(int *arr) {
  vector<PAI *> ret;
  for (int i = 3; i < MAX_N; ++i) {
    if (arr[i] < 3)
      continue;
    ret.push_back(new SANDAI(i, new PASS()));
    for (int j = 3; j < MAX_N; ++j) {
      if (arr[j] == 0 || i == j)
        continue;
      ret.push_back(new SANDAI(i, new DAN(j)));
      if (arr[j] >= 2) {
        ret.push_back(new SANDAI(i, new DUIZI(j)));
      }
    }
  }
  return ret;
}

ZHADAN::ZHADAN(int x) : x(x), PAI(PAI_TYPE::ZHADAN_TYPE) {}
ostream &ZHADAN::output() { return cout << "ZHA : " << name[x]; }
bool ZHADAN::operator>(PAI *pre) {
  switch (pre->type) {
    case PAI_TYPE::WANGZHA_TYPE: return false;
    case PAI_TYPE::ZHADAN_TYPE: {
      ZHADAN *pre_ = dynamic_cast<ZHADAN *>(pre);
      return this->x > pre_->x;
    } break;
    default: return true;
  }
}
void ZHADAN::take(int *arr) {
  arr[x] -= 4;
  return ;
}
void ZHADAN::back(int *arr) { 
  arr[x] += 4;
  return ;
}
vector<PAI *> ZHADAN::get(int *arr) {
  vector<PAI *> ret;
  for (int i = 3; i < MAX_N; ++i) {
    if (arr[i] < 4)
      continue;
    ret.push_back(new ZHADAN(i));
  }
  return ret;
}

WANGZHA::WANGZHA() : PAI(PAI_TYPE::WANGZHA_TYPE) {}
ostream &WANGZHA::output() { return cout << "WANGZHA"; }
bool WANGZHA::operator>(PAI *pre) {
  switch (pre->type) {
    case PAI_TYPE::WANGZHA_TYPE: return false;
    default: return true;
  }
}
void WANGZHA::take(int *arr) {
  arr[16] -= 1;
  arr[17] -= 1;
  return ;
}
void WANGZHA::back(int *arr) { 
  arr[16] += 1;
  arr[17] += 1;
  return ;
}
vector<PAI *> WANGZHA::get(int *arr) {
  vector<PAI *> ret;
  if (arr[16] && arr[17])
    ret.push_back(new WANGZHA());
  return ret;
}

vector<PAI *> PAI::getPai(int *arr) {
  vector<PAI *> temp;
  vector<PAI *> temp1 = DAN::get(arr);
  vector<PAI *> temp2 = DUIZI::get(arr);
  vector<PAI *> temp3 = SHUNZI::get(arr);
  vector<PAI *> temp4 = LIANDUI::get(arr);
  vector<PAI *> temp5 = SANDAI::get(arr);
  vector<PAI *> temp6 = ZHADAN::get(arr);
  vector<PAI *> temp7 = WANGZHA::get(arr);
  vector<PAI *> temp8 = PASS::get(arr);

  for (auto x : temp1)
    temp.push_back(x);
  for (auto x : temp2)
    temp.push_back(x);
  for (auto x : temp3)
    temp.push_back(x);
  for (auto x : temp4)
    temp.push_back(x);
  for (auto x : temp5)
    temp.push_back(x);
  for (auto x : temp6)
    temp.push_back(x);
  for (auto x : temp7)
    temp.push_back(x);
  for (auto x : temp8)
    temp.push_back(x);

  return temp;
}

// 根据当前手牌数量（arr）和对手上一把出的牌型（*pai）得到可以出的牌型
vector<PAI *> PAI::getLegalPai(int *arr, PAI *pai) {
  vector<PAI *> temp1 = getPai(arr);
  vector<PAI *> temp;
  for (auto x : temp1) {
    if ((*x)>(pai)) temp.push_back(x);
    else delete x;
  }
  return temp;
}