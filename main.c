//
//  main.c
//  BinaryTree
//
//  Created by Khuong Tran on 8/31/17.
//  Copyright © 2017 Khuong Tran. All rights reserved.
//

#include <stdio.h>
#include "binarytree.h"
#include <stdlib.h>

tree* newNode(int data);
tree* insert(tree* root, int data);
int size(tree* node);
int maxDepth(tree* node);
int max(int x, int y);
int minValue(tree* node);
int maxValue(tree* node);
void printTree(tree* node);

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("This is example of binary tree\n");
    
    /*this code builds up a 1-2-3 binary tree by calling insert() three times*/
    tree* root = NULL;
    root = insert(root, 5);
    printf("root is %d\n", root->data);
    root = insert(root, 3);
    printf("left is %d\n", root->left->data);
    root = insert(root, 9);
    printf("right is %d\n", root->right->data);
    root = insert(root, 1);
    root = insert(root, 4);
    root = insert(root, 6);
    printf("size of tree: %d\n", size(root));
    printf("max depth is: %d\n", maxDepth(root));
    printf("min value: %d\n", minValue(root));
    printf("max value: %d\n", maxValue(root));
    printTree(root);
    printf("\n");
    /* this code creates little 1-2-3 binary tree by calling newNode() three times with one pointers*/
    /*
    tree *root = newNode(2);
    root->left = newNode(1);
    root->right = newNode(3);
    
    printf("root is: %d\n", root->data);
    printf("left node is: %d\n", root->left->data);
    printf("right node is: %d\n", root->right->data);
     */
    
    
    /* this code creates little 1-2-3 binary tree by calling newNode() three times with three pointers
    tree* node1 = newNode(1);
    tree* node2 = newNode(2);
    tree* node3 = newNode(3);
    node2->left = node1;
    node2->right = node3;
    
    printf("root is: %d\n", node2->data);
    printf("left node is: %d\n", node2->left->data);
    printf("right node is: %d\n", node2->right->data);
     */
    
    return 0;
}

tree* newNode(int data)
{
    tree* node = malloc(sizeof(tree));
    //node->data = NULL;
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    
    return node;
}

tree* insert(tree* root, int data)
{
    if(root == NULL)
    {
        return newNode(data);
    }
    else
    {
        if(data <= root->data)
        {
            root->left = insert(root->left, data);
        }
        else
        {
            root->right = insert(root->right, data);
        }
    }
    return root;
}

int size(tree* root)
{
    //int count = 0;
    tree* ptr = root;
    if(ptr == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + size(ptr->left) + size(ptr->right);
    }
}

int maxDepth(tree* node)
{
    tree* ptr = node;
    if(ptr == NULL)
    {
        return 0;
    }
    else
    {
        return 1 + max(maxDepth(ptr->left), maxDepth(ptr->right));
    }
}

int max(int x, int y)
{
    int maxNum;
    if(x <= y)
    {
        maxNum = y;
    }
    else
    {
        maxNum = x;
    }
    return maxNum;
}

int minValue(tree* node)
{
    tree* ptr = node;
    while(ptr->left != NULL)
    {
        ptr = ptr->left;
    }
    return ptr->data;
}

int maxValue(tree* node)
{
    tree* ptr = node;
    while(ptr->right != NULL)
    {
        ptr = ptr->right;
    }
    return ptr->data;
}

void printTree(tree* node)
{
    /*print tree in increasing order*/
    tree* ptr = node;
    if(ptr == NULL) return;
    printTree(ptr->left);
    printf(" %d ",ptr->data);
    printTree(ptr->right);
}
