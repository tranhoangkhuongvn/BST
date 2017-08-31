//
//  binarytree.h
//  BinaryTree
//
//  Created by Khuong Tran on 8/31/17.
//  Copyright © 2017 Khuong Tran. All rights reserved.
//

#ifndef binarytree_h
#define binarytree_h

typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;

#endif /* binarytree_h */
