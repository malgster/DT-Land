# Binary search trees

## Introduction 

A binary tree is a  type of **graph** : a hierarchical data structure with a set of connected nodes, with each node bifurcating *two children nodes **at most**,* referred to as *left child* and *right child*

A binary tree is hierarchical, it always *has one root*, where the bifurcation begins. 

PS : the tree structure has multiples variants (BST, Red-black Tree, Treap...), but I chose to implement the binary tree as it is the most common of them all. ~~that's why i said i didn't implements all data structures.~~

## In memory

every binary tree here is composed of at least one node, with two pointers to a left and right child sub-tree/node, that points to **NULL** when thre isn't any. It also has a pointer to his parent, if this node/binary tree is the root, this pointer will be **NULL**, it not, point to his designated parent in the higher hierarchy. 

We used the root of a binary tree to access it all.

![](https://i.imgur.com/YrkYPh2.jpg)

## Operations

the structure of binary trees make them ideal for recursion, so it's use will be ~~recurring~~ present in all the operations presented. 

### Basics 

#### Unite :

It's the process of linking two BT/nodes to one higher in the hierarchy, by making his left and right pointers points to them both, and making it their parent.


#### Number of nodes :

Calculating all the nodes/vertices of the BT. To do that, we take the root as an input, if it's NULL we return 0 (base case for the recursion). If It isn't NULL we then make a recursive call to the left and right child and add one to the result of these (1 to count to root) and then return.  

#### Height :

Consist of fiding the largest number of edges *from the root to the most distant node*.

To do that, we take the root as an input, if it doesn't have any child nodes, we return the *0* as the heigh of the tree (base case for the recursion). Then we recurcively call the function to calculate *the height of the left and right subtree*. Finally, we compare them both, *add 1 to it* and return the maximum among them as the height *of the whole tree.* 

![](https://i.imgur.com/UQY7uxI.jpg)


### binary tree traversal

It's the process of visiting each node in the tree exactly once. if the search result in a visit to *all the vertices of the binary tree* : it's called **a traversal**.

There are three traversal techniques for a binary tree :

#### Preorder traversal :

* Visit the current node of the BT (at first : the *root*).
* traverse the current node's left sub-tree/node recursively.
* traverse the current node's right sub-tree/node Recursively.

![](https://i.imgur.com/OcsiHaP.jpg)

#### Inorder traversal :

* traverse the current node's left sub-tree/node recursively.
* visit the current node (parent).
* traverse the current node's right sub-tree/node Recursively.

![](https://i.imgur.com/kT9v2gg.jpg)

#### Postorder traversal :

* traverse the current node's left sub-tree/node recursively.
* traverse the current node's right sub-tree/node Recursively.
* visit the current node.

![](https://i.imgur.com/wYFuqyC.jpg)

## Note

I added a function in the implementation that prints the tree in a 2D form, **from left to right.**


