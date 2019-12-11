#include <map>
#include <set>
#include <list>
#include <ctime>
#include <cmath>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define  lowbit(x)  x & (-x)
#define  mes(a, b)  memset(a, b, sizeof a)
#define  fi         first
#define  se         second
#define  INOPEM     freopen("in.txt", "r", stdin)
#define  OUTOPEN    freopen("out.txt", "w", stdout)

typedef unsigned long long int ull;
typedef long long int ll;
const int    maxn = 1e5 + 10;
const int    maxm = 1e5 + 10;
const int    mod  = 1e9 + 7;
const ll     INF  = 1e18 + 100;
const int    inf  = 0x3f3f3f3f;
const double pi   = 4.0 * atan(1.0);
const double eps  = 1e-8;
using namespace std;

int n, m;
int cas, tol, T;

int key = 99991;
int seed = 131;
struct Node{
    char s1[11];
    char s2[11];
    int next;
} node[maxn];
int head[maxn];

void init() {
    tol = 0;
    mes(head, -1);
    mes(node, 0);
}

void addnode(int k, char *s, char *t) {
    strcpy(node[tol].s1, s);
    strcpy(node[tol].s2, t);
    node[tol].next = head[k];
    head[k] = tol++;
}

void insert(char *s1, char *s2) {
    int tmp = 0;
    int len = strlen(s1);
    for(int i=0; i<len; i++) {
        tmp = tmp * seed + s1[i] - 'a';
        tmp %= key;
    }
    addnode(tmp, s1, s2);
}

void find(char *s1) {
    int k = 0;
    int len = strlen(s1);
    for(int i=0; i<len; i++) {
        k = k * seed + s1[i] - 'a';
        k %= key;
    }
    for(int i=head[k]; ~i; i=node[i].next) {
        if(strcmp(node[i].s1, s1) == 0) {
            printf("%s\n", node[i].s2);
            return ;
        }
    }
    printf("eh\n");
}

int main() {
    init();
    char s[22];
    char s1[11], s2[11];
    while(1) {
        gets(s);
        if(s[0] == '\0')
            break;
        sscanf(s, "%s%s", s1, s2);
//        printf("%s %s\n", s1, s2);
        insert(s2, s1);
    }
    // for(int i=0; i<tol; i++) {
    //     printf("%s %s\n", node[i].s1, node[i].s2);
    // }
    while(~scanf("%s", s1)) {
        find(s1);
    }
    return 0;
}