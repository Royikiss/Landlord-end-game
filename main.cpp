/*************************************************************************
        > File Name: main.cpp
      > Author: royi
      > Mail: royi990001@gmail.com
      > Created Time:
      > Describe:
 ************************************************************************/

#include "./include/pai.h"
#include "./include/tree.h"
#include <iostream>
#include <stack>

using namespace std;

int a[MAX_N + 5] = {0};
int b[MAX_N + 5] = {0};
void read(FILE *fin, int *arr) {
  int x;
  while (fscanf(fin, "%d", &x) != EOF) {
    if (x == 0)
      break;
    arr[x] += 1;
  }
  return;
}

void read_data() {
  FILE *fin = fopen("input", "r");
  read(fin, a);
  read(fin, b);
  fclose(fin);
  return;
}

void output_solve(Node *root, int *a, int *b) {
  int no = 0; // 需要选择的序号
  // 创建了一个栈，用于记录上一步的节点
  // 栈中存储的是节点指针
  // 栈的元素个数是偶数时，输出a数组
  // 栈的元素个数是奇数时，输出b数组
  stack<Node *> s;
  s.push(root);
  
  while (!s.empty()) {
    printf("%s : ", s.size() % 2 ? "-->" : "   ");
    PAI::output_arr(a);
    printf("%s : ", s.size() % 2 ? "   " : "-->");
    PAI::output_arr(b);

    Node *node = s.top();
    
    do {
      printf("[%3d] : back\n", -1);
      for (int i = 0; i < node->child.size(); ++i) {
        printf("[%3d] : [%s] ", i, (node->child[i]->win ? "lose" : "win"));
        node->child[i]->p->output() << endl;
      }
      cout << "==========================================" << endl;
      cout << "input :";
      cin >> no;
      if (no >= -1 && no < node->child.size()) {
        cout << "break" << endl;
        break;
      }
    } while (1);

    if (no == -1) {
      s.pop();
      node->p->back(s.size() % 2 ? a : b);
    } else {
      node->child[no]->p->take(s.size() % 2 ? a : b);
      s.push(node->child[no]);
    }
  }
  return;
}

int main() {
  cout << "Start ..." << endl;
  read_data();
  cout << "Read data success!" << endl;
  Node *root = new Node();
  cout << "Build tree..." << endl;
  getTree(root, a, b);
  cout << "Build tree success!" << endl;
  output_solve(root, a, b);
  cout << "Output success!" << endl;
  return 0;
}