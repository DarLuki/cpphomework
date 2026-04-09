#include <iostream>
using namespace std;

struct queue{
	int inf;
	queue *next;
};

void push (queue *&h, queue *&t, int x){
	queue *r = new queue;
	r->inf = x;
	r->next = NULL;
	if (!h && !t){
		h = t = r;
	}
	else{
		t->next = r;
		t = r;
	}
}

int pop(queue *&h, queue *&t){
	queue *r = h;
	int i = h->inf;
	h = h->next;
	if (!h)
		t = NULL;
	delete r;
	return i;
}

int main(){
	int n;
	cin >> n;
	queue *head = NULL, *tail = NULL;
	int x;
	for (int i = 0; i<n; i++){
		cin >> x;
		push(head, tail, x);
	}
	while ((head->inf)%2==1){
		int i = pop(head, tail);
		push(head, tail, i);
	}
	while(head)
		cout << pop(head, tail) << " ";
	cout << endl;
}
