#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int value)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Duyệt theo thứ tự trước (NLR)
void preorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// Duyệt theo thứ tự giữa (LNR)
void inorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Duyệt theo thứ tự sau (LRN)
void postorderTraversal(Node *root)
{
    if (root == NULL)
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

Node *BST_search(Node *root, int value)
{
    Node *Q = NULL;
    Node *P = root;
    while (P != NULL)
    {
        if (value == P->data)
        {
            printf("%d da co trong cay!!!\n", value);
            return P;
        }
        Q = P;
        if (value < P->data)
            P = P->left;
        else
            P = P->right;
    }
    P = createNode(value);
    if (root == NULL)   
        root = P;
    else
    {
        if (value < Q->data)
            Q->left = P;
        else
            Q->right = P;
    }
    printf("Khong tim thay, da bo sung vao cay!!!\n");
    return P;
}

int BTS_delete(Node *root, int value){
    Node *Q = NULL;
    Node *P = root;
    while (P != NULL)
    {
        if (value == P->data)
            break;
        Q = P;
        if (value < P->data)
            P = P->left;
        else
            P = P->right;
    }
    if(P == NULL) {
        printf("%d khong co tren cay!!!\n", value);
        return 0;
    }
    if (P->left != NULL && P->right != NULL){
        Node* tmp = P;
        Q = P;
        P = P->left;
        while (P->right != NULL){
            Q = P;
            P = P->right;
        }
        tmp->data = P->data;
    }
    Node* Child;
    if (P->left != NULL) Child = P->left;
    else Child = P->right;
    if(P == root) root = Child;
    else{
        if(Q->left == P) Q->left = Child;
        else Q->right = Child;
    }
    free(P);
    return 1;
}

int main()
{
    Node *root = NULL;
    int a;
    printf("Nhap gia tri node root cua cay: ");
    scanf("%d", &a);
    root = BST_search(root, a);
    int tmp;
    while(tmp != 0){
        printf("Nhap gia tri node, nhap 0 neu da nhap het node cua cay: ");
        scanf("%d", &tmp);
        if(tmp != 0){
            BST_search(root, tmp);
        }
    }
    printf("Duyet theo thu tu truoc: \n");
    preorderTraversal(root);
    printf("\n");
    printf("Duyet theo thu tu giua: \n");
    inorderTraversal(root);
    printf("\n");
    printf("Duyet theo thu tu sau: \n");
    postorderTraversal(root);
    printf("\n");

    int value;
    printf("Nhap gia tri trong cay ban muon xoa: ");
    scanf("%d", &value);
    if(BTS_delete(root, value)){
        printf("Ket qua sau khi xoa: \n");
        printf("Duyet theo thu tu truoc: \n");
        preorderTraversal(root);
        printf("\n");
        printf("Duyet theo thu tu giua: \n");
        inorderTraversal(root);
        printf("\n");
        printf("Duyet theo thu tu sau: \n");
        postorderTraversal(root);
        printf("\n");
    }
    return 0;
}
