/*****
Edward Chen
703909636
For this assignment, we modify the Node, List, and Iterator classes and several functions to accompany it.
*****/

#include <iostream>
#include <list>
#include <cassert>

using namespace std;

class Node
{
public:
	Node (int x);
private:
	int value;
	Node* previous;
	Node* next;
friend class List;
friend class Iterator;
friend void sort(Node* a);
friend Node* find_smallest_in_range(Node* a, Node* b);
friend Node* maximum (Node* a, Node* b);
friend List merge(List a, List b);
};

class List
{
public:
	List();
	void push_back (int input);
	void insert (Iterator pos, int input);
	Iterator erase (Iterator pos);
	Iterator begin();
	Iterator end();
	void reverse(List x);
	void push_front();
	void swap(List& other);
	void swap_node(Node* &a, Node* &b);
	int get_size();
	Node maximum ();
	void downsize(List& names);
	void sort_sublist(Node* a);
	void sort();
	void print(List input);
	int get_node(Node a);
private:
	Node* first;
	Node* last;
	int size;
friend class Iterator;
friend void sort(Node* a);
friend List merge(List a, List b);

};

class Iterator
{
public:
	Iterator();
	int get();
	void next();
	void previous();
	bool equals(Iterator b);
	Iterator operator ++(int); //postfix
	Iterator operator ++(); // prefix
	Iterator operator --(int); //postfix
	Iterator operator --(); // prefix
	bool operator ==(Iterator b);
private:
	Node* position;
	List* container;
friend class List;
};

// Non Member functions
Node* find_smallest_in_range(Node* a, Node* b);
List merge(List a, List b);


int main()
{
	int input=1;
	List list;
	Iterator pos;
	List list2;
	int value;
	Iterator current;
	List list3;
	
	list2.push_back(2);
	list2.push_back(3);
	list2.push_back(5);
	list2.push_back(7);
	list2.push_back(11);
	

	cout << "Please input a set of nonnegative numbers for a List (Enter -1 when you are finished): " << endl;
	while (cin >> input)
		if (input == -1)
			break;
		else
		list.push_back(input);
		
	cout << "Your list is " << endl;	
	list.print(list);

	cout<< endl;
	input = 1;
	
	current = list.begin();
	while (input != -1)
	{
		current = list.begin();

		cout << "Select an index for insertion (Enter -1 when you are finished): ";
		cin >> input;
			
		if (input == -1)
			break;
		else
		{
			for(int i=0;i<input;i++)
				current.next();
			cout << "Select a value for insertion: ";
			cin >> value;
			list.insert(current,value);
		}				
	}
	
	cout << "\nYour augmented List is " << endl;
	list.print(list);

	cout << "\nThe maximum of the List is: ";
	Node max = list.maximum();
	int max_value = list.get_node(max);
	cout << max_value;

	cout << "\nThe size of the List is: ";
	int size = list.get_size();
	cout << size;
	
	cout << "\nWhen we remove every second value from this list we are left with " << endl;
	list.downsize(list);
	list.print(list);
	
	cout << "\nWhen we sort this downsized list we obtain " << endl;
	list.sort();
	list.print(list);	
	
	cout << "\nAnd this sorted list in reverse order is " << endl;
	list.reverse(list);
	list.print(list);
	
	cout << "\nIf we merge this list with the list (2,3,4,7,11) we obtain " << endl;
	list3 = merge(list,list2);
	list3.print(list3);
	
	system ("pause");
	return 0;
}

/**
Contains the value of an object in a list
@ int x is the value of the object
@ returns value
*/
Node::Node(int x)
{
	value = x;
	previous = NULL;
	next = NULL;
}

/**
Default Constructor
@ sets the first and last pointers to NULL
*/
List::List()
{
	first = NULL;
	last = NULL;
}

/**
Adds user input to the end of the list
@ parameter int input is user input
*/
void List::push_back(int input)
{
	Node* new_node = new Node(input);
   if (last == NULL) // List is empty
   {  
      first = new_node;
      last = new_node;
   }
   else
   {  
      new_node->previous = last;
      last->next = new_node;
      last = new_node;
   }
}

/**
Inserts an Iterator object at position
@ parameter pos is the position
@ int input is the user inputted value
*/
void List::insert (Iterator pos, int input)
{
	if (pos.position == NULL)
	{
		push_back(input);
		return;
	}

	Node* after = pos.position;
	Node* before = after->previous;
	Node* new_node = new Node(input);
	new_node->previous = before;
	new_node->next = after;
	after ->previous = new_node;
	if (before == NULL) // insert at beginning
		first = new_node;
	else
		before ->next = new_node;
	//size = get_size();
	size++;
}

/**
Erases an Iterator
@ parameter pos is the position
@ returns Iterator
*/
Iterator List::erase (Iterator pos)
{
	assert(pos.position !=NULL);
	Node* remove = pos.position;
	Node* before = remove->previous;
	Node* after = remove->next;
	if (remove == first)
		first = after;
	else 
		before->next = after;
	if (remove == last)
		last = before;
	else
		after->previous = before;
	delete remove;
	//Iterator pos;
	pos.position = after;
	pos.container = this;
	size--;
	cout << "the pointer is now pointing to value\n " << pos.position->value;
	cout << "the pointer position is pointing to\n" << pos.get();
	return pos;
}

/**
Creates an iterator that points to the first node
@ no parameters
*/
Iterator List::begin()
{
	Iterator iter;
	iter.position = first;
	iter.container = this;
	return iter;
}
/**
Creates an iterator that points to the last node
@ no parameters
@ returns the last node
*/
Iterator List::end()
{
	Iterator iter;
	iter.position = NULL;
	iter.container = this;
	return iter;
}

/**
Reverses the list
@ parameter x the list to reverse
@ no return
*/
void List::reverse(List x)
{
	
	Node* current = x.first;
	Node* end = x.last;
	int size = (x.get_size())/2;
	int count = 0;
	
	//for (end; end == x.first; end->previous) 
	while (count < size)
	{
		swap_node(current,end);
		end = end->previous;
		current = current->next;
		count++;
	}

	/*
	Iterator a = x.begin();
	Iterator b = x.end();
	while (b.position != a.position)
	{
		x.push_back(b.position->value);
		b.previous();	
	}
	*/
}

/**
..
*/
void List::push_front()
{
	int input;
	insert(begin(),input);
}

/**
..
*/
void List::swap(List& other)
{
	int input = 0;
	Node* temp = new Node (input);
	while (first != last)
	{
		temp = first;
		first = other.first;
		other.first = temp;
	}
}

/**
..
*/
void List::swap_node(Node* &a, Node* &b)
{
	
	
	int temp = a->value;
	a->value = b->value;
	b->value = temp;

	
	/*
	Node temp(0);
	temp.value = a.value;
	a.value = b.value;
	b.value = temp.value;
	*/
}

/**
..
*/
int List::get_size()
{
	//Node* smallest_node;
	int count = 1;
	Node* current = first;
	while (current != last)
	{
		current = current -> next;
		count++;
	}
	
	return count;
}

/**
...
*/
Node List::maximum ()
{
	Node largest_node(0);
	//largest_node->value = 0;
	largest_node.value = first->value;
	Node * current = first;
	while (current != last)
	{
		current = current -> next;
		if (current->value > largest_node.value)
			largest_node.value = current->value;
	}
	//cout << largest_node.value;
	return largest_node;
}

/**
..
*/
void List::downsize(List& names)
{
	Iterator current = names.begin();
	Iterator end = names.end();
	
	while (!(current == end))
	{
		//current = names.begin();
		//current.next();
		current.next();
		names.erase(current);
		//current.next();
	}
}

/**
..
*/
void List::sort_sublist(Node* a)
{	
	
	if (a == last)
		return;
	else
	{
		Node * smallest = find_smallest_in_range (a->next, last);
		if (smallest-> value < a->value)
		{
			swap_node(a,smallest);
			//a = smallest;
		}
		//sort_sublist(a->next);
	}
	sort_sublist(a->next);
	
}

/**
..
*/
void List::sort()
{
	sort_sublist(first);
}

/**
..
*/
Iterator::Iterator()
{
	position = NULL;
	container = NULL;
}

/**
..
*/
int Iterator::get()
{
	assert(position !=NULL);
	return position ->value;
}

/**
..
*/
void Iterator::next()
{
	assert(position != NULL);
	position = position ->next;
}

/**
..
*/
void Iterator::previous()
{
	assert(position != container->first);
	if (position == NULL)
		position = container->last;
	else
		position = position ->previous;
}

/**
..
*/
bool Iterator::equals(Iterator b)
{
	return position == b.position;
}

/***
This operator overloads ++ to move the pointer to the next link postfix
@ no parameters
moves iterator forward one
*/
Iterator Iterator::operator ++(int)
{
	assert(position != NULL);
   position = position->next;
   return *this;
}

/***
This operator overloads ++ to move the pointer to the next link postfix
@ no parameters
moves iterator forward one
*/
Iterator Iterator::operator ++()
{
	assert(position != NULL);
   position = position->next;
   return *this;
}

/***
This operator overloads -- to move the pointer to the previous link postfix
@ no parameters
moves iterator back one
*/
Iterator Iterator::operator --(int)
{
	assert(position != container->first);
   if (position == NULL)
      position = container->last;
   else 
      position = position->previous;
   return *this;
}

/***
This operator overloads -- to move the pointer to the previous link postfix
@ no parameters
moves iterator back one
*/
Iterator Iterator::operator --()
{
	assert(position != container->first);
   if (position == NULL)
      position = container->last;
   else 
      position = position->previous;
   return *this;
}

/**
...
*/
bool Iterator::operator ==(Iterator b)
{
	return position == b.position;
}

/**
..
*/
Node* find_smallest_in_range(Node* a, Node* b)
{
	Node* smallest_node = a;
	while (a != b)
	{
		a = a -> next;
		if (a->value < smallest_node->value)
			smallest_node = a;
	}
	return smallest_node;
}


/**
Merges two lists together in alternating order
@ parameter a the first list
@ parameter b the second list
@ return the final list
*/
List merge(List a, List b)
{
	List c;
	int sizeA = a.get_size();
	int sizeB = b.get_size();
	Node* posA = a.first;
	Node* posB = b.first;

	if (sizeA < sizeB)
	{
		while (posA != a.last)
		{
			c.push_back(posA->value);
			c.push_back(posB->value);
			posA = posA->next;
			posB = posB->next;
		}
		while (posB !=b.last)
		{
			c.push_back(posB->value);
			posB = posB->next;
		}
	}
	else
	{
		while (posB != b.last)
		{
			c.push_back(posA->value);
			c.push_back(posB->value);
			posA = posA->next;
			posB = posB->next;
		}
		while (posA !=a.last)
		{
			c.push_back(posA->value);
			posA = posA->next;
		}
	}
	return c;
}


/*
Prints the List
@ no parameters
@ prints the List 
*/
void List::print(List input)
{
	//Iterator pos = input.begin();

	cout << "(";
	for(Iterator pos = input.begin(); !pos.equals(input.end()); pos.next())
		if (pos.position == input.last)
			cout << pos.get() << "";
		else
			cout << pos.get() << ",";
	cout << ")";
}


int List::get_node(Node a)
{
	return a.value;
}