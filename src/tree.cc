/*************************************************************************
        > File Name: tree.cc
        > Author: Royecode
      > Author: royi
      > Mail: royi990001@gmail.com
      > Created Time: 
      > Describe: 
 ************************************************************************/

#include "../include/tree.h"
#include "../include/pai.h"

// 默认必败态
Node::Node() : p(new PASS()), win(0) {}
Node::Node(PAI *p, int win = 0) : p(p), win(win) {}

// 检查手牌是否为空
static bool checkEmpty(int *arr) {
    for (int i = 3; i < MAX_N; ++i) {
        if (arr[i]) return false;
    }
    return true;
}

// a : 当前出牌用户  | b : 另一个用户
void getTree(Node *root, int *a, int *b) {
    // 如果对手手牌为空，则自己处于必败态
    if (checkEmpty(b)) {
        root->win = 0;
        return ;
    }
    
    // 得到自己所有可以出的牌型（合法牌型）
    vector<PAI *> temp = PAI::getLegalPai(a, root->p);
    // 便利自己所有可以出的牌型
    for (int i = 0; i < temp.size(); ++i) {
        Node *node = new Node(temp[i]);                     // 创建一个新的节点
        temp[i]->take(a);                                     // 在a中拿走当前的手牌
        getTree(node, b, a);                       // 递归调用向下生成博弈树
        temp[i]->back(a);                                    // 拿回当前牌型
        root->child.push_back(node);                      // 将当前得到的博弈树挂到根节点下
        if (node->win == 0) {                               // 如果当前子节点(对手)处于必败态，那么当前节点(自己)一定处于必胜态
            root->win = 1;
            break;                                          // 剪枝
        }
    }
    return ;
}
