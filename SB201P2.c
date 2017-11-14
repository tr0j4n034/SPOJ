//
//  main.c
//  practice
//
//  Created by Mahmud on 11/14/17.
//  Copyright © 2017 Mahmud. All rights reserved.
//


#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node * _next;
    struct node * _previous;
};
typedef struct node* list;

int listSize = 0;

list initialize(int value) {
    list l = (list)malloc(sizeof(list));
    l->value = value;
    l->_next = NULL;
    l->_previous = NULL;
    return l;
}
void _insert(list *l, int position, int value) {
    listSize ++;
    if (!l) {
        *l = initialize(value);
        return;
    }
    list p = initialize(value);
    if (position == 1) {
        p->_next = *l;
        *l = p;
        return;
    }
    if (position > listSize) {
        position = listSize;
    }
    list current = *l;
    while (position > 2 && current) {
        current = current->_next;
        position --;
    }
    p->_next = current->_next;
    current->_next = p;
}
void _remove(list *l, int position) {
    if (position > listSize) {
        return;
    }
    listSize --;
    if (position == 1) {
        *l = (*l)->_next;
        return;
    }
    list current = *l;
    while (position > 2) {
        current = current->_next;
        position --;
    }
    current->_next = current->_next->_next;
}
void _print(list *l) {
    if (listSize == 0) {
        puts("empty");
        return;
    }
    list current = *l;
    int printed = 0;
    while (current != NULL) {
        if (printed) {
            putchar(' ');
        }
        printf("%d", current->value);
        current = current->_next;
        printed = 1;
    }
    putchar('\n');
}

char type;
int x, y;
list l = NULL;

int main() {
    
    while(scanf(" %c", &type)) {
        if(type == 'q') {
            break;
        }
        if (type == 'f') {
            scanf("%d", &x);
            _insert(&l, 1, x);
        }
        else if(type == 'i') {
            scanf("%d%d", &x, &y);
            _insert(&l, x + 1, y);
        }
        else if(type == 'r') {
            _remove(&l, 1);
        }
        else {
            scanf("%d", &x);
            _remove(&l, x + 1);
        }
        _print(&l);
        getchar();
    }
    
    return 0;
}

