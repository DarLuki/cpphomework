#include <iostream>
#include <algorithm>
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
	int x, minel, left = 0, right = 0;
	for (int i = 0; i<n; i++){
		cin >> x;
		if (i == 0) minel = x;
		minel = min(minel, x);
		push(head, tail, x);
	}
	int f = 0;
	for (int i = 0; i<n; i++){
		int x = pop(head, tail);
		if (x == minel) right = i;
		if (x == minel && f == 0) f = 1;
		else push(head, tail, x);
	}
	f = 0;
	for (int i = 0; i < n-1; i++){
		int x = pop(head, tail);
		if (i != right - 1 || x != minel) push(head, tail, x);
	}
	while(head)
		cout << pop(head, tail) << " ";
	cout << endl;
}
