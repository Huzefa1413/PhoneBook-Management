#include <iostream>
#include <conio.h>

using namespace std;

struct Node
{
	string number;
	string name;
	Node* prev, * next;
};

struct Node* Head = NULL;

string InfinityStructureName[10];
string InfinityStructureNumber[10];
int InfinityStructureSize = 10;
int front = -1;
int rear = -1;

void Insert(string element1, string element2)
{
	if ((rear + 1) % InfinityStructureSize == front)
		// check if structure is full suppose rear points at 9(last element) and front points 
		// at 0(first element) then 9 + 1 % 10 = 0 which is equal to front which means structure is full
	{
		if (front == rear) //if structure has only one element then delete it and point it at start
		{
			front = -1;
			rear = -1;
		}
		else //if structure have more than one element then suppose if front is pointing at 9 then after  
			 //calculation it will become 9 + 1 % 10 which is equal to 0 now front will point at start again
		{
			front = (front + 1) % InfinityStructureSize;
		}
	}
	if (front == -1 && rear == -1) //if structure is empty update front and rear
	{
		front = 0;
		rear = 0;
	}
	else //if structure is not empty then suppose if rear is 9 then after calculation
		 //9 + 1 % 10 = 0 so now element will be inserted at start again
	{
		rear = (rear + 1) % InfinityStructureSize;
	}
	InfinityStructureNumber[rear] = element1;
	InfinityStructureName[rear] = element2;
}
void recentlydeleteddisplay()
{
	// Function to display status of Circular Queue
	int i;
	int sno = 1;
	if (front == -1) //if front is -1 which means queue is empty and no contacts are deleted yet
	{
		cout << "  _________________________________________________________________________ " << endl;
		cout << " |                                                                         |" << endl;
		cout << " |                       NO CONTACTS ARE DELETED                           |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
	}
	else
	{
		cout << "  __________________________________________________________________________" << endl;
		cout << " |          |                               |                               |" << endl;
		cout << " |   S/no   |            Name               |            Number             |" << endl;
		cout << " |__________|_______________________________|_______________________________| " << endl;
		cout << " |          |                               |                               |" << endl;
		for (i = front; i != rear; i = (i + 1) % InfinityStructureSize) // condition to update front as discussed earlier
		{
			if (InfinityStructureNumber[i].length() > 6)
			{
				cout << " |   " << sno << ".     |\t\t " << InfinityStructureNumber[i] << "\t    |\t      " << InfinityStructureName[i] << "\t    |" << endl;
			}
			else
			{
				cout << " |   " << sno << ".     |\t\t " << InfinityStructureNumber[i] << "\t\t    |\t      " << InfinityStructureName[i] << "\t    |" << endl;
			}
			sno++;
		}
		if (InfinityStructureNumber[i].length() > 6)
		{
			cout << " |   " << sno << ".     |\t\t " << InfinityStructureNumber[i] << "\t    |\t      " << InfinityStructureName[i] << "\t    | <- Latest Deleted Contact" << endl;
		}
		else
		{
			cout << " |   " << sno << ".     |\t\t " << InfinityStructureNumber[i] << "\t\t    |\t      " << InfinityStructureName[i] << "\t    | <- Latest Deleted Contact" << endl;
		}
		cout << " |          |                               |                               |" << endl;
		cout << " |__________|_______________________________|_______________________________|" << endl;
	}
}
void InsertContacts()
{
	string option;
	do
	{
		struct Node* newNode = new Node();
		newNode->next = Head; //Intitializing newnode -> next part to head because we are inserting it at head to reduce time complexity
		newNode->prev = NULL; //We know that Head node prev part is always NULL
		cout << "\n ENTER NAME  : ";
		cin >> newNode->name;
		cout << " ENTER NUMBER: ";
		cin >> newNode->number;

		while (newNode->number.length() != 11)//comparing if the entered number is equal to 11 or not
		{
			cout << " ENTER VALID NUMBER: ";
			cin >> newNode->number;
		}
		if (Head == NULL) //if the node inserted is first node then initialize Head = newnode
		{
			Head = newNode;
		}
		else //If the node inserted is not the first node then update prev pointer of head node to newnode 
		{
			Head->prev = newNode;
			Head = newNode; //Set newnode as head
		}

		cout << "\n TO CONTINUE INSERTING CONTACTS PRESS Y/y: ";
		cin >> option;
	} while (option == "y" || option == "Y");

}
void SortingContact()
{
	Node* i, * j;
	for (i = Head; i->next != NULL; i = i->next)//start from head till second last node 
	{
		for (j = i->next; j != NULL; j = j->next) //start from current node pointed by i till last node
		{
			if (i->name > j->name) //comparing names to sort in ascending order
			{
				swap(i->name, j->name);
				swap(i->number, j->number);
			}
		}
	}
}

void DisplayContacts()
{
	int i = 0; //for serial no
	struct Node* ptr;
	ptr = Head;    //starting point of the list to traverse it
	cout << "  __________________________________________________________________________" << endl;
	cout << " |          |                               |                               |" << endl;
	cout << " |   S/no   |            Name               |            Number             |" << endl;
	cout << " |__________|_______________________________|_______________________________| " << endl;
	cout << " |          |                               |                               |" << endl;
	while (ptr != NULL)//traverse till last
	{
		i++;
		if (ptr->name.length() > 6) // comparing length of name to display it inside box
		{
			cout << " |   " << i << ".     |\t\t " << ptr->name << "\t    |\t      " << ptr->number << "\t    |" << endl;
		}
		else
		{
			cout << " |   " << i << ".     |\t\t " << ptr->name << "\t\t    |\t      " << ptr->number << "\t    |" << endl;
		}
		ptr = ptr->next; //move to next node
	}
	cout << " |          |                               |                               |" << endl;
	cout << " |__________|_______________________________|_______________________________|" << endl;

}

void UpdateContact(string checkname)
{
	int choose;
	struct Node* updatenode;
	updatenode = Head;
	while (updatenode != NULL) //check until all nodes traversed
	{
		if (checkname == updatenode->name)//compared entered name by user with data in linked list
		{
			cout << "  _________________________________________________________________________ " << endl;
			cout << " |                                                                         |" << endl;
			cout << " |                     WHAT DO YOU WANT TO UPDATE?                         |" << endl;
			cout << " |                                                                         |" << endl;
			cout << " |     1. Name                                                             |" << endl;
			cout << " |     2. Phone Number                                                     |" << endl;
			cout << " |                                                                         |" << endl;
			cout << " |_________________________________________________________________________|" << endl;
			cout << "\n Enter Choice: ";
			cin >> choose;
			switch (choose)
			{
			case 1:
				cout << "\n ENTER NEW NAME  : ";
				cin >> updatenode->name;
				SortingContact();
				break;
			case 2:
				cout << " ENTER NEW NUMBER: ";
				cin >> updatenode->number;
				while (updatenode->number.length() != 11)//comparing length of number if it equal to 11 or not
				{
					cout << " ENTER VALID NUMBER: ";
					cin >> updatenode->number;
				}
				break;
			default:
				cout << "  _________________________________________________________________________ " << endl;
				cout << " |                                                                         |" << endl;
				cout << " |                        WRONG INPUT GIVEN....                            |" << endl;
				cout << " |_________________________________________________________________________|" << endl;
			}
			return;
		}
		updatenode = updatenode->next; //move to next node
	}
	cout << "  _________________________________________________________________________ " << endl;
	cout << " |                                                                         |" << endl;
	cout << " |              The name doesnt exist in the current data.                 |" << endl;
	cout << " |_________________________________________________________________________|" << endl;
}

void DeleteContact(string deletenamecheck)
{
	struct Node* delnode;
	delnode = Head;
	//traversing unless we get equal to user input
	while (delnode != NULL)
	{
		if (deletenamecheck == delnode->name)
		{
			break;
		}
		delnode = delnode->next;
	}
	if (delnode == NULL)
	{
		cout << "  _________________________________________________________________________ " << endl;
		cout << " |                                                                         |" << endl;
		cout << " |             Entered name is not present in the PhoneBook                |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
		return;
	}
	//Deleting First Node and there is no node afterwards // single node
	if (delnode == Head && Head->next == NULL)
	{
		Insert(delnode->name, delnode->number);//pushing data in circular queue to store recently deleted data
		free(delnode); //delete the node
		cout << "  _________________________________________________________________________ " << endl;
		cout << " |                                                                         |" << endl;
		cout << " |            Contact is Successfully Deleted from PhoneBook               |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
		Head = NULL; //point head to NULL because first and only node is deleted
	}
	//deleting first node
	else if (delnode == Head)
	{
		Head = Head->next; //point head pointer to next node 
		Insert(delnode->name, delnode->number);//pushing data in circular queue to store recently deleted data
		free(delnode);
		cout << "  _________________________________________________________________________ " << endl;
		cout << " |                                                                         |" << endl;
		cout << " |            Contact is Successfully Deleted from PhoneBook               |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
	}
	//Deleting middle node
	else if (delnode != Head && delnode->next != NULL)
	{
		//conditions to connect left and right nodes before deleting middle node
		delnode->next->prev = delnode->prev;
		delnode->prev->next = delnode->next;
		Insert(delnode->name, delnode->number);//pushing data in circular queue to store recently deleted data
		free(delnode);
		cout << "  _________________________________________________________________________ " << endl;
		cout << " |                                                                         |" << endl;
		cout << " |            Contact is Successfully Deleted from PhoneBook               |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
	}
	//Deleting Last Node
	else if (delnode->next == NULL)
	{
		delnode->prev->next = NULL;//Making second last node the last node by breaking the link
		Insert(delnode->name, delnode->number);//pushing data in circular queue to store recently deleted data
		free(delnode);
		cout << "  _________________________________________________________________________ " << endl;
		cout << " |                                                                         |" << endl;
		cout << " |            Contact is Successfully Deleted from PhoneBook               |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
	}
}

void searchname(string searchnamecheck)
{
	int i = 1;
	struct Node* searchnode;
	searchnode = Head;
	while (searchnode != NULL)//traversing till last node
	{
		if (searchnamecheck == searchnode->name)
		{
			cout << "  __________________________________________________________________________" << endl;
			cout << " |          |                               |                               |" << endl;
			cout << " |   S/no   |            Name               |            Number             |" << endl;
			cout << " |__________|_______________________________|_______________________________| " << endl;
			cout << " |          |                               |                               |" << endl;
			if (searchnode->name.length() > 6) // comparing length of name to display it inside box
			{
				cout << " |   " << i << ".     |\t\t " << searchnode->name << "\t    |\t      " << searchnode->number << "\t    |" << endl;
			}
			else
			{
				cout << " |   " << i << ".     |\t\t " << searchnode->name << "\t\t    |\t      " << searchnode->number << "\t    |" << endl;
			}
			cout << " |          |                               |                               |" << endl;
			cout << " |__________|_______________________________|_______________________________|" << endl;
			return;
		}
		searchnode = searchnode->next;
	}
	cout << "  _________________________________________________________________________ " << endl;
	cout << " |                                                                         |" << endl;
	cout << " |             Entered name is not present in the PhoneBook                |" << endl;
	cout << " |_________________________________________________________________________|" << endl;
}

void searchnum(string searchnumbercheck)
{
	int i = 1;
	struct Node* searchnode;
	searchnode = Head;
	while (searchnode != NULL)//traversing till last node
	{
		if (searchnumbercheck == searchnode->number)
		{
			cout << "  __________________________________________________________________________" << endl;
			cout << " |          |                               |                               |" << endl;
			cout << " |   S/no   |            Name               |            Number             |" << endl;
			cout << " |__________|_______________________________|_______________________________| " << endl;
			cout << " |          |                               |                               |" << endl;
			if (searchnode->name.length() > 6) // comparing length of name to display it inside box
			{
				cout << " |   " << i << ".     |\t\t " << searchnode->name << "\t    |\t      " << searchnode->number << "\t    |" << endl;
			}
			else
			{
				cout << " |   " << i << ".     |\t\t " << searchnode->name << "\t\t    |\t      " << searchnode->number << "\t    |" << endl;
			}
			cout << " |          |                               |                               |" << endl;
			cout << " |__________|_______________________________|_______________________________|" << endl;
			return;
		}
		searchnode = searchnode->next;
	}
	cout << "  _________________________________________________________________________ " << endl;
	cout << " |                                                                         |" << endl;
	cout << " |            Entered number is not present in the PhoneBook               |" << endl;
	cout << " |_________________________________________________________________________|" << endl;
}

void SearchContact()
{
	int choose;
	string num;
	string name;
	string option;
	do
	{
		cout << "  _________________________________________________________________________ " << endl;
		cout << " |                                                                         |" << endl;
		cout << " |                     WHAT DO YOU WANT TO SEARCH?                         |" << endl;
		cout << " |                                                                         |" << endl;
		cout << " |     1. Name                                                             |" << endl;
		cout << " |     2. Phone Number                                                     |" << endl;
		cout << " |                                                                         |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
		cout << "\n Enter Choice: ";
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << " ENTER NAME YOU WANT TO SEARCH: ";
			cin >> name;
			searchname(name);
			break;
		case 2:
			cout << " ENTER NUMBER YOU WANT TO SEARCH: ";
			cin >> num;
			searchnum(num);
			break;
		default:
			cout << "  _________________________________________________________________________ " << endl;
			cout << " |                                                                         |" << endl;
			cout << " |                        WRONG INPUT GIVEN....                            |" << endl;
			cout << " |_________________________________________________________________________|" << endl;
			break;
		}
		cout << "\n TO CONTINUE SEARCHING PRESS Y/y: ";
		cin >> option;
	} while (option == "y" || option == "Y");
}

int main()
{
	string name, x;
	int ch;
	do
	{
		system("cls");
		cout << "  _________________________________________________________________________" << endl;
		cout << " |                                                     __________          |" << endl;
		cout << " |      __      __      __       __  __  __           (_.-:--:-._)         |" << endl;
		cout << " |     |__||__||  ||\\ ||_   __  |__||  ||  ||_/         / |__| \\           |" << endl;
		cout << " |     |   |  ||__|| \\||__      |__||__||__|| \\        |        |          |" << endl;
		cout << " |                                                     |________|          |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
		cout << " |                                                                         |" << endl;
		cout << " |                   Phone-Book Management system                          |" << endl;
		cout << " |                                                                         |" << endl;
		cout << " |   (1) INSERT NEW CONTACT                                                |" << endl;
		cout << " |   (2) DISPLAY YOUR PHONE BOOK                                           |" << endl;
		cout << " |   (3) UPDATE DETAILS ON EXISTING CONTACT                                |" << endl;
		cout << " |   (4) DELETE CONTACT                                                    |" << endl;
		cout << " |   (5) SEARCH CONTACT                                                    |" << endl;
		cout << " |   (6) VIEW RECENTLY DELETED CONTACTS                                    |" << endl;
		cout << " |   (7) EXIT                                                              |" << endl;
		cout << " |                                                                         |" << endl;
		cout << " |_________________________________________________________________________|" << endl;
		cout << "\n Enter Choice: ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			InsertContacts();
			SortingContact();
			break;
		case 2:
			if (Head == NULL)
			{
				cout << "  _________________________________________________________________________ " << endl;
				cout << " |                                                                         |" << endl;
				cout << " |                       The Phonebook is Empty                            |" << endl;
				cout << " |_________________________________________________________________________|" << endl;
			}
			else
			{
				DisplayContacts();
			}
			break;
		case 3:
			if (Head == NULL)
			{
				cout << "  _________________________________________________________________________ " << endl;
				cout << " |                                                                         |" << endl;
				cout << " |                       The Phonebook is Empty                            |" << endl;
				cout << " |_________________________________________________________________________|" << endl;
			}
			else
			{
				cout << "\n ENTER THE NAME OF WHOSE DETAILS YOU WANT TO UPDATE FROM PHONEBOOK: ";
				cin >> name;
				UpdateContact(name);
			}
			break;
		case 4:
			if (Head == NULL)
			{
				cout << "  _________________________________________________________________________ " << endl;
				cout << " |                                                                         |" << endl;
				cout << " |                       The Phonebook is Empty                            |" << endl;
				cout << " |_________________________________________________________________________|" << endl;
			}
			else
			{
				cout << "\n ENTER THE NAME YOU WANT TO DELETE FROM PHONEBOOK: ";
				cin >> name;
				DeleteContact(name);
			}
			break;
		case 5:
			if (Head == NULL)
			{
				cout << "  _________________________________________________________________________ " << endl;
				cout << " |                                                                         |" << endl;
				cout << " |                       The Phonebook is Empty                            |" << endl;
				cout << " |_________________________________________________________________________|" << endl;
			}
			else
			{
				SearchContact();
			}
			break;
		case 6:
			recentlydeleteddisplay();
			break;
		case 7:
			cout << "  _________________________________________________________________________ " << endl;
			cout << " |                                                                         |" << endl;
			cout << " |                             G O O D  B Y E !                            |" << endl;
			cout << " |_________________________________________________________________________|" << endl;
			return 0;
			break;
		default:
			cout << "  _________________________________________________________________________ " << endl;
			cout << " |                                                                         |" << endl;
			cout << " |                        WRONG INPUT GIVEN....                            |" << endl;
			cout << " |_________________________________________________________________________|" << endl;
		}
		cout << "\n TO EXIT PRESS '7' TO CONTINUE OPERATIONS PRESS ANY KEY: ";
		cin >> x;
	} while (x != "7");
	cout << "  _________________________________________________________________________ " << endl;
	cout << " |                                                                         |" << endl;
	cout << " |                             G O O D  B Y E !                            |" << endl;
	cout << " |_________________________________________________________________________|" << endl;
	return 0;
}