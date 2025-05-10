#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

int main() {
	struct node *tmp = malloc(sizeof(struct node));
  	tmp->data = 0;
    tmp->left = NULL;
    tmp->right = NULL;
  
  	struct node *root = tmp;
  
    free(root);

    return 0;
}