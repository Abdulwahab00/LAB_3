#include<iostream>
using namespace std;

class Queue
{
public:
	
	int* arr = nullptr;
	int rare;
	int front;
	Queue(int z)
	{
		arr= new int[z];
		 
		rare = -1;
		front = -1;

	}
	bool IsEmpty()
	{
		
		if (front == rare)
		{
			return true;
		}
		else
		{
		return false;
		}
	}

	bool IsFull()
	{
		int arrSize = sizeof(arr) / sizeof(arr[0]);
		cout << arrSize<<endl;
		if (front - 1 == arrSize)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Enqueue(int n)
	{
		if (rare == -1 && front == -1)
		{
			front++;
			rare++;
			arr[rare] = n;
		}
		else
		{
			rare++;
			arr[rare]=n;
		}

	}
	
	int Dequeue()
	{
		int i;
		if (IsEmpty())
		{
			cout << "Your Queue is Empty" << endl;
			return 0;
		}
		else
		{

			i = arr[front];
			arr[front] = 0;

			front++;
			return i;
		}
	}
	void Display()
	{
		for (int i = front; i <= rare; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	int x;
	int opt;
	cout << "Enter the Siza of Array: ";
	cin >> x;
	Queue obj(x);
	do
	{

	
		cout << "Press 1 Enqueue()" << endl
			<< "Press 2 Dequeue()" << endl
			<< "Press 3 isFull()" << endl
			<< "Press 4 isEmpty()" << endl
			<< "Press 5 Display()" << endl
			<< "Press 0 Exit()" << endl;
	cin >> opt;
	switch (opt)
	{
	case 1:
	{
		int y=0;
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
		cout << obj.Dequeue()<<" is Dequeued" << endl; 
		 
		break;
	}

	case 3:
	{
		if (obj.IsFull())
		{
			cout << "Your Queue is Full" << endl;
			
		}

		else
		{
			cout << "Your Queue is Not Full" << endl;
		}

		break;
	}
	case 4:
	{
		if (obj.IsEmpty())
		{
			cout << "Your Queue is Empty" << endl;

		}

		else
		{
			cout << "Your Queue is Not Empty" << endl;
		}

		break;
	}
	case 5:
	{
		cout << "Data in your Queue is: ";
		obj.Display();
		break;
	}
	default:
		cout << "Select the Correct Option" << endl;
		
	}

	} while (true);
	system("pause");
	return 0;
}