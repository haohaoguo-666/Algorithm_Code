#include <stdio.h>
#include <stdlib.h>



typedef struct BinaryTreeNode {
    char val;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BTNode;

BTNode* rebuildTree(char* str, int* pi) {
    if (str[*pi] == '#') {
        (*pi)++;
        return NULL;
    }
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->val = str[(*pi)++];

    root->left = rebuildTree(str, pi);
    root->right = rebuildTree(str, pi);
    return root;
}

void Inorder(BTNode* root) {
    if (root == NULL) return;

    Inorder(root->left);
    printf("%c ", root->val);
    Inorder(root->right);
}



int main() {
    char str[100];
    scanf("%s", str);
    int i = 0;
    int* pi = &i;
    BTNode* root = rebuildTree(str, pi);
    Inorder(root);

}
// 64 位输出请用 printf("%lld")