#include <iostream>
using namespace std;

class Search {
private:
	class Node {
	public:
		int data;
		Node* next;

		Node(int data)
		{
			this->data = data;
			next = nullptr;
		}
	};

public:
	Node* head = nullptr;
	Node* tempo = nullptr;

	// Function to add new nodes at the end of the list
	void addNode(int data)
	{
		Node* new1 = new Node(data);

		// If linked list is empty
		if (head == nullptr) {
			head = new1;
		}
		else {
			tempo->next = new1;
		}

		tempo = new1;

		// last node points to the first node
		tempo->next = head;
	}

	void find(int key)
	{
		// temp will traverse the circular linked list for
		// searching the element
		Node* temp = head;

		// flag used to check if the element is found or not
		int f = 0;
		if (head == nullptr) {
			cout << "List is empty" << endl;
		}
		else {
			do {
				if (temp->data == key) {
					cout << key << " Found" << endl;
					f = 1;
					break;
				}
				temp = temp->next;
			} while (temp != head);

			if (f == 0) {
				cout << key << " Not Found" << endl;
			}
		}
	}
};

// Driver code
int main()
{
	Search s;

	// Adds data to the list
	s.addNode(5);
	s.addNode(4);
	s.addNode(3);
	s.addNode(2);

	// Search for node 2 in the list
	int key = 2;
	s.find(key);

	// Search for node 6 in the list
	key = 6;
	s.find(key);

	return 0;
}
