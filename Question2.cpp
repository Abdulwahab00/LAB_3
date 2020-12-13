#include<iostream>
using namespace std;
class Queue
{
private:
	struct node
	{
		int data;
		node* nxt_add;
	};
public:
	Queue()
	{
		head = NULL;
	}
	node* head;
	int count = 0;

	bool IsEmpty();
	void Enqueue(int);
	int Dequeue();
	void Display();
	bool IsFull() const;
	

};
bool Queue::IsEmpty()
{
	if (head == NULL)
	{

		return true;
	}
	else
		return false;

}

void Queue::Enqueue(int Data)
{
	node* NewNode = new node;
	NewNode->data = Data;
	NewNode->nxt_add = NULL;
	if (head == NULL)
	{
		head = NewNode;
		count++;
	}
	else
	{
		node* temp = head;
		while (temp->nxt_add != NULL)
		{
			temp = temp->nxt_add;

		}
		temp->nxt_add = NewNode;
		count++;
	}
}
int Queue::Dequeue()
{
	if (IsEmpty())
	{
		cout << "Your Queue is Empty" << endl;
	}
	else
	{
		int z;
		node* pp = head;
		head = head->nxt_add;
		z = pp->data;
		delete pp;
		count--;
		return z;
	}
}

void Queue::Display()
{
	if (IsEmpty())
	{
		cout << "Your Queue is Empty" << endl;
	}
	else
	{
		node* ptr = head;
		cout << "The Data in Your Queue is: " << endl;
		while (ptr != NULL)
		{
			cout << ptr->data << "  ";
			ptr = ptr->nxt_add;

		}
		cout << endl;
	}
}

bool Queue::IsFull() const
{
	node* temp;
	try {
		temp = new node;
		delete temp;
		return true;
	}
	catch (bad_alloc exception)
	{
		return false;
	}
}

int main()
{
	Queue obj;
	int opt;

	cout << "----------Choose the Option to Perform Certain Operations----------" << endl;
	do
	{


		cout << "1. Enqueue" << endl
			<< "2. Dequque" << endl
			<< "3. IsEmpty" << endl
			<< "4. IsFull" << endl
			<< "5. Display" << endl
			<< "6. Clear Screen" << endl
			<< "0. Exit" << endl;
		cin >> opt;
		switch (opt)
		{
		case 1:
		{
			int y = 0;
			while (y != -222)
			{
				cout << "Enter the Element To Enqueue OR Press-222 to Exit ";
				cin >> y;
				if (y != -222)
				{

					obj.Enqueue(y);
					cout << "Your Data is Enqueued" << endl;
				}
			}
			break;

		}
		
		case 2:
		{
			cout << obj.Dequeue() << " Is Dequeue form Queue" << endl;

			break;
		}
		case 3:
		{
			if (obj.IsEmpty())
			{
				cout << "Your Queue is Empty" << endl;
			}
			else
			{
				cout << "Your Queue is not Empty" << endl;
			}
			break;
		}
		case 4:
		{
			if (obj.IsFull())
			{
				cout << "Your Queue is FULL" << endl;
			}
			else
			{
				cout << "Your Queue is not FULL" << endl;
			}
			break;
		}
		case 5:
		{
			obj.Display();
			break;
		}
		
		case 6:
		{
			system("cls");
			break;
		}
		default:
		{
			cout << "----------Enter the Correct Option----------" << endl;
		}
		}
	} while (opt != 0);
}
