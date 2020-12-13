#include <iostream> 
using namespace std;
typedef struct node
{
    int Data;
    int priority;
    node* next;

}*nodeptr;

class Queue
{
private:
    nodeptr front;
    nodeptr rear;
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }
    void Enqueue(int n)
    {
        nodeptr newnode = new node();
        newnode->Data = n;
        cout << "ENTER PRIORITY: ";
        cin >> newnode->priority;
        newnode->next = NULL;
        if (front == NULL)
        {
            front = newnode;
        }
        else if (newnode->priority < front->priority)
        {
            newnode->next = front->next;
            front = newnode;
        }
        else
        {
            node* temp;
            temp = front;
            while (temp->next != NULL && temp->next->priority <= newnode->priority)
            {
                temp = temp->next;
            }
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    void Dequeue()
    {
        nodeptr temp1;
        temp1 = front;

        if (front == NULL && rear == NULL)
        {
            cout << "\Queue is Empty\n";
        }
        else
        {
            cout << front->Data << " Is Deqeued from Queue\n";
            front = front->next;
            delete(temp1);
        }
    }
    bool IsFull() const
    {
        nodeptr temp1;
        try {
            temp1 = new node;
            delete temp1;
            return false;
        }
        catch (bad_alloc exception)
        {
            return true;
        }
    }
    bool IsEmpty()
    {
        bool check = false;
        if (front == NULL && rear == NULL)
            return !check;
        return check;
    }
	void Display()
	{
		if (IsEmpty())
		{
			cout << "Your Queue is Empty" << endl;
		}
		else
		{
			node* ptr = front;
			cout << "The Data in Your Queue is: " << endl;
			while (ptr != NULL)
			{
				cout << ptr->Data << "  ";
				ptr = ptr->next;

			}
			cout << endl;
		}
	}


};


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
			obj.Dequeue();

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
			if (!obj.IsFull())
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
