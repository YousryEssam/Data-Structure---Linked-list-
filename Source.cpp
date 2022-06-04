#include<bits/stdc++.h>
using namespace std;
template<typename t>
struct node
{
	t value;
	node<t>* next;
};
template<class t>
class Linkedlist
{
private:
	node<t>* st;
	node<t>* last;
	long long Size;
public:
	Linkedlist()
	{
		st = NULL;
		last = NULL;
		Size = 0; 
	}
	void insert(t item)
	{
		node<t>* new_node = new node<t>;
		new_node->value = item;
		new_node->next = NULL;
		if (Size == 0)
		{
			st = new_node;
		}
		else
		{
			node<t>* temp = st;
			while (temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next = new_node;
		}
		Size++;
	}
	void print()
	{
		node<t>* temp = st;
		if (Size == 0)
			cout << "No elements to print \n";
		else
		{
			cout << temp->value << " ";
			while (temp->next != NULL)
			{
				temp = temp->next;
				cout << temp->value << " ";
			}
			cout << '\n';
		}
	}
	bool isEmpty() { return Size == 0; }
	void clear() { st = NULL; Size = 0; }
	int size() { return Size; }
	// to find value and return it's value 
	int find(t item)
	{
		node<t>* temp = st;
		int value_place = 0;
		if (Size == 0)
			return -1;
		else
		{
			if (temp->value == item)
				return value_place;
			while (temp->next != NULL)
			{
				temp = temp->next;
				value_place++;
				if (temp->value == item)
					return value_place;
			}
		}
		return -1;
	}
	// to remove value by vlaue 
	void remove(t item)
	{
		int index = find(item);
		if (index == -1)
		{
			cout << "It is impossible\n";
			return;
		}
		node<t>* c = st->next;
		node<t>* p = st;
		if (index == 0)
		{
			st = st->next;
		}
		else
		{
			while (index>1)
			{
				p = c;
				c = c->next;
				index--;
			}
			p ->next= c->next;
		}
		Size--;
		cout << "remove done \n";
	}
	// to detet value in position  
	void remove_pos(int  n)
	{
		int index = n;
		if (index >= Size)
		{
			cout << "It is impossible\n";
			return;
		}
		node<t>* c = st->next;
		node<t>* p = st;
		if (index == 0)
		{
			st = st->next;
		}
		else
		{
			while (index > 1)
			{
				p = c;
				c = c->next;
				index--;
			}
			p->next = c->next;
		}
		cout << "remove done \n";
		Size--;
	}
	// to print value in position  
	t at(int n)
	{
		if (n >= Size || n < 0)
			cout << "Not allow\n";
		else
		{
			node<t>* temp = st;
			while (n > 1)
			{
				n--; 
				temp = temp->next;
			}
			return temp->value;
		}
	}
};
int main()
{
	Linkedlist<int> list;
	
	return 0;
}