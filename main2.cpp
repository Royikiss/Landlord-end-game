/*************************************************************************
        > File Name: main.cpp
      > Author: royi
      > Mail: royi990001@gmail.com
      > Created Time: 11:28 AM
      > Describe: description
 ************************************************************************/

#include "include/pai.h"
#include <iostream>

using namespace std;

void usage(int max_no) {
  if (max_no >= 1)
    printf("1 : DAN\n");
  if (max_no >= 2)
    printf("2 : DUIZI\n");
  if (max_no >= 3)
    printf("3 : SHUNZI\n");
  if (max_no >= 4)
    printf("4 : LIANDUI\n");
  if (max_no >= 5)
    printf("5 : SANDAI\n");
  if (max_no >= 6)
    printf("6 : ZHADAN\n");
  if (max_no >= 7)
    printf("7 : WANGZHA\n");
  if (max_no >= 8)
    printf("8 : PASS\n");
  printf("input : ");
  return;
}

PAI *read_pai(int max_no = 8) {
  PAI *ret;
  int no, x, len;
  while (1) {
    usage(max_no);
    cin >> no;
    if (no > max_no)
      continue;
    switch (no) {
    case 1: {
      cin >> x;
      ret = new DAN(x);
    } break;
    case 2: {
      cin >> x;
      ret = new DUIZI(x);
    } break;
    case 3: {
      cin >> x >> len;
      ret = new SHUNZI(x, len);
    } break;
    case 4: {
      cin >> x >> len;
      ret = new LIANDUI(x, len);
    } break;
    case 5: {
      cin >> x;
      PAI *dai = read_pai(2);
      ret = new SANDAI(x, dai);
    } break;
    case 6: {
      cin >> x;
      ret = new ZHADAN(x);
    } break;
    case 7: {
      ret = new WANGZHA();
    } break;
    case 8: {
      ret = new PASS();
    } break;
    }
    break;
  }
  return ret;
}

int main() {
#define MAX_N 18
  int arr[MAX_N + 5] = {0};
  int x;
  while (cin >> x) {
    if (x == 0)
      break;
    arr[x] += 1;
  }
  PAI *pai = read_pai();
  vector<PAI *> temp = PAI::getLegalPai(arr, pai);
  for (int i = 0; i < temp.size(); ++i) {
    temp[i]->output();
    cout << endl;
  }

  return 0;
}
