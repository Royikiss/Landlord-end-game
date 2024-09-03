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
#include <sys/ioctl.h>
#include <unistd.h>
using namespace std;

struct winsize w;
size_t last_line_size;
size_t last_tittle_size;
Node *root;
int a[MAX_N + 5] = {0};
int b[MAX_N + 5] = {0};

#define _PrintLine_(fmt) { \
    for (int i = 0; i <= w.ws_row; ++i) {\
        printf("="); \
    } \
    printf(""#fmt""); \
    for (int i = 0; i <= w.ws_row; ++i) {\
        printf("="); \
    } \
    printf("\n"); \
}

#define _PrintLine_Title_(fmt) { \
    for (int i = 0; i <= w.ws_row / 2; ++i) {\
        printf("-"); \
    } \
    printf(""#fmt""); \
    for (int i = 0; i <= w.ws_row / 2; ++i) {\
        printf("-"); \
    } \
    printf("\n"); \
}

// Read data from FILE stream named fin and storge them to arr.
void read(FILE *fin, int *arr) {
    int x;
    while (fscanf(fin, "%d", &x) != EOF) {
        if (x == 0)  // It will stop read the str when the current pai was 0.
            break;
        arr[x] += 1;
    }
    return;
}

void read_data() {
    FILE *fin = fopen("input", "r");        // Default input file was named "input".
    read(fin, a);                           // Read your own and opponent's cards
    read(fin, b);
    fclose(fin);
    return;
}

void output_solve(Node *root, int *a, int *b) {
    int no = 0;
    stack<Node *> s;
    s.push(root);

    while (!s.empty()) {
        _PrintLine_Title_(当前出牌者);
        printf("%s : ", s.size() % 2 ? "→" : "w");
        PAI::output_arr(a);
        printf("%s : ", s.size() % 2 ? "w" : "→");
        PAI::output_arr(b);
        _PrintLine_Title_(----------);

        Node *node = s.top(); // Get the top element as the current node you have. 

        cout << "选择" << (s.size() % 2 ? "你" : "对手") << "要出的牌型" << endl;
        cout << endl << "↓↓↓↓↓" << endl;
        do {
            printf("[%3d] : back\n", -1);
            for (int i = 0; i < node->child.size(); ++i) {
                printf("[%3d] : [%s] ", i, (node->child[i]->win ? "n" : "✔"));
                node->child[i]->p->output() << endl;
            }
            cout << "↑↑↑↑↑" << endl;
            cout << "input the [No.] you want (chose the '✔'):";
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

void rule() {
    _PrintLine_(使用方法);
    cout << "→ 本程序采用生成博弈树的方式实现破解程序" << endl;
    cout << "→ 程序开始后,会提示当前出牌者以及其手牌'→'(未出牌的选手将会标记为'w')" << endl;
    cout << "→ 在出牌者之后会根据上一轮出牌的牌型列举出当前出牌者可以出的牌型" << endl;
    cout << "→ 在牌型之前会标记当前出牌者「必胜」的出牌方式" << endl;
    cout << "→ 你需要选择一个序号来输出当前你想要出的牌" << endl;

    cout << "「！」 注意：轮到对手时，你仍然需要选择对手出的牌型" << endl;
    _PrintLine_(========);
    return ;
}

// To get the width of the terminal.
inline void init() {
    ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    cout << "Start ..." << endl;
    read_data();
    cout << "Read data success!" << endl;
    root = new Node();
    cout << "Build tree..." << endl;
    getTree(root, a, b);
    cout << "Build tree success!" << endl;
}

int main() {
    init();
    rule();
    output_solve(root, a, b);
    return 0;
}
