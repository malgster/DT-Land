# Binary search trees

## Introduction 

A binary tree is a  type of **graph** : a hierarchical data structure with a set of connected nodes, with each node bifurcating *two children nodes **at most**,* referred to as *left child* and *right child*

A binary tree is hierarchical, it always *has one root*, where the bifurcation begins. 

PS : the tree structure has multiples variants (BST, Red-black Tree, Treap...), but I chose to implement the binary tree as it is the most common of them all. ~~that's why i said i didn't implements all data structures.~~

## In memory

every binary tree here is composed of at least one node, with two pointers to a left and right child sub-tree/node, that points to **NULL** when thre isn't any. It also has a pointer to his parent, if this node/binary tree is the root, this pointer will be **NULL**, it not, point to his designated parent in the higher hierarchy. 

We used the root of a binary tree to access it all.

## Operations

the structure of binary trees make them ideal for recursion, so it's use will be ~~recurring~~ present in all the operations presented. 

### Basics 

#### Unite 

It's the process of linking two BT/nodes to one higher in the hierarchy. by making his left and right pointers points to them both, and making it their parent.

#### Height 

Consist of fiding the largest number of edges *from the root to the most distant node*.

### binary tree traversal

It's the process of visiting each node in the tree exactly once. if the search result in a visit to *all the vertices of the binary tree* : it's called **a traversal**.

There are three traversal techniques for a binary tree :

#### Preorder traversal

* Visit the current node of the BT (at first : the *root*).
* traverse the current node's left sub-tree/node recursively.
* traverse the current node's right sub-tree/node Recursively.

#### Inorder traversal

* traverse the current node's left sub-tree/node recursively.
* visit the current node (parent).
* traverse the current node's right sub-tree/node Recursively.

#### Postorder traversal

* traverse the current node's left sub-tree/node recursively.
* traverse the current node's right sub-tree/node Recursively.
* visit the current node.


