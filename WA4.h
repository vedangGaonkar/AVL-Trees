#ifndef WA6_H
#define WA6_H
#include "node.h"

#define NODE_HEIGHT(n) (!n ? -1 : n->ht)

void insert(Node*&, int);
int height(Node *);

#endif
