#include<iostream>
#include<ctime>
using namespace std;


// variable
static int comparison = 0;
static int assignment = 0;
// Data structure
struct NODE {
	int data;
	NODE* p_next;
};
struct List {
	NODE* p_head;
	NODE* p_tail;
};

// Linked list function
bool InsertHead(List*& L, int data)
{
	// create a new node
	NODE* p = new NODE;
	//assignment++;
	if (p == NULL) {
		return false;
	}
	//comparison++;

	p->data = data;
	p->p_next = NULL;
	//assignment += 2;

	if (L->p_head == NULL) {
		L->p_head = L->p_tail = p;
		//comparison++;
		//assignment += 2;
	}
	else {
		// update next link and head node
		p->p_next = L->p_head;
		L->p_head = p;
		//assignment += 2;
		//comparison++;
	}
	return true;
}
void removeTail(List*& L) {

	NODE* traversal = L->p_head;
	//assignment++;
	//find the node previous tail node
	while (traversal->p_next != L->p_tail) {
		traversal = traversal->p_next;
		//assignment++;
		//comparison ++;
	}

	NODE* temp = traversal->p_next;

	traversal->p_next = NULL;
	L->p_tail = traversal;
	//assignment += 3;
	delete temp;

}
void RemoveAtPosition(List*& L, int pos) {
	NODE* p = L->p_head;
	int i = 1;
	//assignment += 2;
	if (pos == 1) {
		NODE* q = L->p_head;

		L->p_head = q->p_next;
		delete q;

		//assignment += 2;
		return;
	}
	//comparison++;
	while (i < pos - 1) {
		p = p->p_next;
		i++;

		//assignment += 2;
		//comparison++;
	}

	NODE* q = p->p_next;

	p->p_next = q->p_next;

	//assignment += 2;

	if (q == L->p_tail) {
		L->p_tail = p;
		//assignment++;
		//comparison++;
	}
	delete q;

}

// Stack Function
bool isEmpty(List& L) {
	return L.p_head == NULL;
}
void Push(List& L, NODE* p) {

	if (L.p_head == NULL) {
		L.p_head = L.p_tail = p;
		//assignment++;
	}
	else {
		// add new node into head in the linked list
		p->p_next = L.p_head;
		L.p_head = p;
		//assignment += 2;
		//comparison++;
	}

}
bool Pop(List& L) {
	if (isEmpty(L)) {
		return false;
	}
	//comparison += 2;
	NODE* p = L.p_head;

	L.p_head = p->p_next;

	//assignment += 2;
	delete p;
	return true;
}

// Queue Function
void Enqueue(List& L, NODE* p) {

	if (L.p_head == NULL) {
		L.p_head = L.p_tail = p;
		//assignment++;
		//comparison++;
	}
	else {
		// update next link and tail node
		L.p_tail->p_next = p;
		L.p_tail = p;
		//assignment += 2;
		//comparison++;
	}
}
bool Dequeue(List& L) {

	if (isEmpty(L)) {
		comparison += 2;
		return false;
	}

	comparison += 2;

	NODE* p = L.p_head;
	L.p_head = L.p_head->p_next;
	assignment += 2;
	delete p;

	return true;
}
NODE* GetFront(List& L) {
	if (isEmpty(L))
		return NULL;

	return L.p_head;
}


// Additional function
NODE* createNODE(int data) {
	NODE* p = new NODE;

	if (p == NULL)
		return NULL;

	p->data = data;
	p->p_next = NULL;

	return p;
}
void addTail(List& L, NODE*p) {

	if (L.p_head == NULL)
		L.p_head = L.p_tail = p;
	else {
		L.p_tail->p_next = p;
		L.p_tail = p;
	}

}
void Input(List& l,int num) {

	l.p_head = l.p_tail = NULL;
	
	int i = 1;

	while (i < num) {

		NODE* p = createNODE(rand() % 20);
	
		addTail(l, p);

		i++;
	}
}
void output(List l) {
	NODE* p = l.p_head;

	while (p) {
		cout << p->data << " ";
		p = p->p_next;
	}
}

// Main function
int main() {
	srand(time(NULL));
	for (int i = 0; i < 100; i++) {
		List l;
		NODE* p = createNODE(rand() % 20);
		Input(l, rand() % 250);
		Dequeue(l);
		output(l);
	}
	cout << "\n\nAfter 100 Times with number of element: " << 250;
	cout << "\n" << "Comparisons: " << comparison << "  Assignments: " << assignment;
	cout << "\n" << "Average: " << 1.0 * (comparison + assignment) / 100;
}