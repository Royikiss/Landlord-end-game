/*************************************************************************
        > File Name: tree.h
      > Author:Royi
      > Mail:royi990001@gmail.com
      > Created Time: Tue 21 May 2024 06:22:12 PM HKT
      > Describe:
 ************************************************************************/

#ifndef _TREE_H__
#define _TREE_H__

#include <vector>
#include "pai.h"

class Node {
public:
  // 默认构造
  Node();
  // 拷贝构造
  Node(PAI *, int); 
  // 表示当前节点所处位置的状态：必胜态/必败态
  int win;
  // p 存储上一把对手出的牌型
  PAI *p;
  // 存储当前节点可以出的牌型
  vector<Node *> child;
};

void getTree(Node *, int *, int *);

#endif
