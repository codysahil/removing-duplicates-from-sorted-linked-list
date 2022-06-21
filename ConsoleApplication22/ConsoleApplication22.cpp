#include<iostream>
using namespace std;

class Node
{
public:
	int data;
	Node* next;
}*first = NULL;

void create(int arr[], int n) {
	int i;
	Node* temp, * last;
	first = new Node;
	first->data = arr[0];
	first->next = NULL;
	last = first;
	for (i = 1; i < n; i++) {
		temp = new Node;
		temp->data = arr[i];
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}
void display(Node* p) {
	while (p != NULL) {
		cout << p->data << "->";
		p = p->next;
	}
}
void duplicates(Node* p) {
	Node* k = first;
	Node* q = first->next;
	while (q != NULL) {
		if (k->data != q->data) {
			k = q;
			q = q->next;
		}
		else
		{
			k->next = q->next;
			delete q;
			q = k->next;
		}
	}
}
int main()
{
	int arr[] = { 5,10,15,15,20,25 };
	create(arr, 6);
	cout << "BEFORE";
	display(first);
	cout << endl;
	duplicates(first);
	cout << "AFTER";
	display(first);
	return 0;
}