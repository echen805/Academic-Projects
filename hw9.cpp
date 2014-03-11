/*****
Edward Chen
703909636
For this assignment, we modified the BinarySearchTree, TreeNode and TreeIterator class 
and several functions that accompany it.
*****/

#include <iostream>
#include <cassert>
#include <string>

using namespace std;

class TreeNode
{
public:
   void insert_node(TreeNode* new_node);
   void print_nodes();
   bool find(int value);
   int subsize(int size);
private:
   int data;
   TreeNode* left;
   TreeNode* right;
   TreeNode* parent;
friend class BinarySearchTree;
friend class TreeIterator;
friend int size();
};

class BinarySearchTree
{
public:
   BinarySearchTree();
   TreeIterator begin();
   void insert(int data);
   void erase(int data);
   int count(int data);
   void print();
   int smallest();
   int largest();
   string BinaryCode (int k);
   int size();
private:
   TreeNode* root;
friend class TreeIterator;
friend class TreeNode;
friend int subsize();
};

class TreeIterator
{
public:
	TreeIterator();
	int get();
	void left_child();
	void right_child();
	void up();
	bool equals(TreeIterator b);
	TreeIterator operator ++(int); //postfix
	TreeIterator operator ++(); // prefix
	TreeIterator operator --(int); //postfix
	TreeIterator operator --(); // prefix
	bool operator ==(TreeIterator b);
private:
	TreeNode* position;
	BinarySearchTree* container;
friend class BinarySearchTree;
};

int main()
{  
   int input;
   BinarySearchTree bin;
   string binarycode;
   int size = 0;


   cout << "Please input a set of distinct nonnegative numbers for a Tree (Enter -1 when you are finished):" << endl;
   while (cin >> input)
		if (input == -1)
			break;
		else
		bin.insert(input);

   int largest = bin.largest();
   cout << "\nThe maximum of the entries is: " << largest;
   int smallest = bin.smallest();
   cout << "\nThe minimum of the entries is: " << smallest;
   
   size = bin.size();
   cout << "\nThe size of the List is: " << size;
   
   cout << endl;

   input = 1;
   while (input != -1)
   {
	   cout << "Select a value for insertion (Enter -1 when finished): ";
	   cin >> input;
	   if (input != -1)
		   bin.insert(input);
	   else
		   break;
   }

   largest = bin.largest();
   cout << "\nThe maximum of the entries is: " << largest;
   smallest = bin.smallest();
   cout << "\nThe minimum of the entries is: " << smallest;
   
   size = bin.size();
   cout << "\nThe size of the List is: " << size << endl;
   

   binarycode = bin.BinaryCode(1);
   cout << "The binary code for 1 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(2);
   cout << "The binary code for 2 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(3);
   cout << "The binary code for 3 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(4);
   cout << "The binary code for 4 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(5);
   cout << "The binary code for 5 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(6);
   cout << "The binary code for 6 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(7);
   cout << "The binary code for 7 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(8);
   cout << "The binary code for 8 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(9);
   cout << "The binary code for 9 is: " << binarycode << endl;

   cout << endl;

   input = 1;
   while (input != -1)
   {
	   cout << "Select a value to erase (enter -1 when finished): ";
	   cin >> input;
	   if (input != -1)
		   bin.erase(input);
	   else
		   break;
   }

   cout << endl;
   binarycode = bin.BinaryCode(1);
   cout << "The binary code for 1 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(2);
   cout << "The binary code for 2 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(3);
   cout << "The binary code for 3 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(4);
   cout << "The binary code for 4 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(5);
   cout << "The binary code for 5 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(6);
   cout << "The binary code for 6 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(7);
   cout << "The binary code for 7 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(8);
   cout << "The binary code for 8 is: " << binarycode << endl;
   binarycode = bin.BinaryCode(9);
   cout << "The binary code for 9 is: " << binarycode << endl;
   
   system("pause");
   return 0;
}

/*
Default Constructor
*/
BinarySearchTree::BinarySearchTree()
{  
   root = NULL;
}

/*
Points the pointer to the root node
@ returns the position of the root node
*/
TreeIterator BinarySearchTree::begin()
{
	TreeIterator iter;
	iter.position = root;
	iter.container = this;
	return iter;
}

/*
Prints the tree
*/
void BinarySearchTree::print()
{  
   if (root != NULL)
      root->print_nodes();
}

/*
Inserts a new leaf to the tree
@ parameter data the value to insert
*/
void BinarySearchTree::insert(int data)
{  
   TreeNode* new_node = new TreeNode;
   new_node->data = data;
   new_node->left = NULL;
   new_node->right = NULL;
   if (root == NULL) root = new_node;
   else root->insert_node(new_node);
}

/*
Inserts a node
@ parameter new_node the node to be inserted
*/
void TreeNode::insert_node(TreeNode* new_node)
{  
   if (parent == NULL)
	   parent = new_node->parent;
   else
   {
	   if (new_node->data < data)
	   {  
		  if (left == NULL)
		  {
			  left = new_node;
			  parent = new_node->parent;
		  }
		  else
			  left->insert_node(new_node);
	   }
	   else if (data < new_node->data)
	   {  
		  if (right == NULL)
		  {
			  right = new_node;
			  parent = new_node->parent;
		  }
		  else 
			  right->insert_node(new_node);
	   }
   }
}

/*
Checks to see if the node exists
@ parameter data, the value to check
@ returns a boolean value
*/
int BinarySearchTree::count(int data)
{
   if (root == NULL) return 0;
   else if (root->find(data)) return 1;
   else return 0;
}

/*
Erases a node
@ parameter data, the value to be erased
*/
void BinarySearchTree::erase(int data)
{
   // Find node to be removed

   TreeNode* to_be_removed = root;
   TreeNode* parent = root->parent;
   bool found = false;
   while (!found && to_be_removed != NULL)
   {
      if (to_be_removed->data < data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->right;
      }
      else if (data < to_be_removed->data)
      {
         parent = to_be_removed;
         to_be_removed = to_be_removed->left;
      }
      else found = true;
   }

   if (!found) return;

   // to_be_removed contains data

   // If one of the children is empty, use the other

   if (to_be_removed->left == NULL || to_be_removed->right == NULL)
   {
      TreeNode* new_child;
      if (to_be_removed->left == NULL) 
         new_child = to_be_removed->right;
      else 
         new_child = to_be_removed->left;
       if (parent == NULL) // Found in root
         root = new_child;
      else if (parent->left == to_be_removed)
         parent->left = new_child;
      else 
         parent->right = new_child;
      return;
   }
      
   // Neither subtree is empty

   // Find largest element of the left subtree

   TreeNode* largest_parent = to_be_removed;
   TreeNode* largest = to_be_removed->left;
   while (largest->right != NULL)
   {
      largest_parent = largest;
      largest = largest->right;
   }

   // largest contains largest child in left subtree
       
   // Move contents, unlink child
   to_be_removed->data = largest->data;
   if (largest_parent == to_be_removed)
   {
	   largest->parent = to_be_removed->parent;
       largest_parent->left = largest->left;
   }
   else
   {
	  largest->parent = to_be_removed->parent;
      largest_parent->right = largest->left;
   }
}

/*
Finds the smallest element of a tree
@ returns smallest
*/
int BinarySearchTree::smallest()
{
	TreeNode* smallest_parent = root;
	TreeNode* smallest = root->left;
	while (smallest->left != NULL)
	{
		smallest_parent = smallest;
		smallest = smallest->left;
	}
	return smallest->data;
}

/* 
Finds the largest element of a tree
@ returns largest
*/
int BinarySearchTree::largest()
{
	TreeNode* largest_parent = root;
	TreeNode* largest = root->right;
	while (largest->right != NULL)
	{
		largest_parent = largest;
		largest = largest->right;
	}
	return largest->data;
}

/*
Returns a binary string to indicate the position of a node
@ parameter k, the node
@ returns the string
*/
string BinarySearchTree::BinaryCode (int k)
{
	string binary;
	TreeNode* value = root;

	if (k == value->data)
		return binary;
	while (k != value->data)
	{
		if (k < value->data)
		{
			if (value->left != NULL)
			{
				value = value->left;
				binary.append("0");
			}
			else
			{
				binary.clear();
				binary.append("2");
				return binary;
			}
		}
		else if (k > value->data)
		{
			if (value->right != NULL)
			{
				value = value->right;
				binary.append("1");
			}
			else
			{
				binary.clear();
				binary.append("2");
				return binary;
			}
		}
	}
	return binary;
}

/*
Returns the size of the tree
@ parameter list the tree object
@ return size
*/
int BinarySearchTree::size()
{
	int size = 1;
	size = root->subsize(size);
	return size;
}

/*
Searches for a value in the tree
@ parameter value, the value to be searched
@ returns true/false if found
*/
bool TreeNode::find(int value)
{
   if (value < data)
   {
      if (left == NULL) return false;
      else return left->find(value);
   }
   else if (data < value)
   {
      if (right == NULL) return false;
      else return right->find(value);
   }
   else 
      return true;
}

/*
Prints the nodes that can be accessed by TreeNode class
*/
void TreeNode::print_nodes() 
{  
   if (left != NULL)
      left->print_nodes();
   cout << data << "\n";
   if (right != NULL)
      right->print_nodes();
}

/*
Prints the size of the tree that can be accessed by TreeNode class
@ parameter size, integer to record size of tree
@ returns the size
*/
int TreeNode::subsize(int size)
{
	if (left != NULL)
	{
		size++;
		size = left->subsize(size);
	}
	if (right != NULL)
	{
		size++;
		size = right->subsize(size);
	}
	return size;
}

/**
Default constructor
*/
TreeIterator::TreeIterator()
{
	position = NULL;
	container = NULL;
}

/**
Gets the value at the position
@ returns the value
*/
int TreeIterator::get()
{
	assert(position !=NULL);
	return position ->data;
}

/**
Advances the iterator to the left child.
*/
void TreeIterator::left_child()
{
	assert(position != NULL);
	position = position ->left;
}

/**
Advances the iterator to the right child.
*/
void TreeIterator::right_child()
{
	assert(position != NULL);
	position = position ->right;
}

/**
Moves the iterator to the previous node
*/
void TreeIterator::up()
{
	assert(position != container->root);
	//if (position == NULL)
		//position = container->last;
	//else
		position = position ->parent;
}

/**
Compares two iterators
@param b the iterator to compare with this iterator
@return true if this iterator and b are equal
*/
bool TreeIterator::equals(TreeIterator b)
{
	return position == b.position;
}

/***
This operator overloads ++ to move the pointer to the next link postfix
@ no parameters
moves iterator forward one
*/
TreeIterator TreeIterator::operator ++(int)
{
	assert(position != NULL);
   position = position->right;
   return *this;
}

/***
This operator overloads ++ to move the pointer to the next link prefix
@ no parameters
moves iterator forward one
*/
TreeIterator TreeIterator::operator ++()
{
	assert(position != NULL);
   position = position->left;
   return *this;
}

/***
This operator overloads -- to move the pointer to the previous link postfix
@ no parameters
moves iterator back one
*/
TreeIterator TreeIterator::operator --(int)
{
	assert(position != container->root);
   position = position ->parent;
   return *this;
}

/***
This operator overloads -- to move the pointer to the previous link prefix
@ no parameters
moves iterator back one
*/
TreeIterator TreeIterator::operator --()
{
	assert(position != container->root);
   position = position ->parent;
   return *this;
}

/**
Overloads the == operator to compare two iterators
@param b the iterator to compare with this iterator
@return true if this iterator and b are equal
*/
bool TreeIterator::operator ==(TreeIterator b)
{
	return position == b.position;
}