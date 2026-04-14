#include <iostream>
#include <cmath>
using namespace std;

struct list{
	int inf;
	list *next;
	list *prev;
};

void push(list *&h, list *&t, int x){
	list *r = new list;
	r->inf = x;
	r->next = NULL;
	if (!h && !t){
		r->prev = NULL;
		h = r;
	}
	else{
		t->next = r;
		r->prev = t;
	}
	t = r;
}

void print(list *h, list *t){
	list *p = h;
	while (p){
		cout << p->inf << " ";
		p = p->next;
	}
}

list *find (list *h, list *t, int x){
	list *p = h;
	while (p){
		if (p->inf==x) break;
		p = p->next;
	}
	return p;
}

void insert_after(list *&h, list *&t, list *r, int y){
	list *p = new list;
	p->inf = y;
	if (r==t){
		p->next = NULL;
		p->prev = r;
		r->next = p;
		t = p;
	}
	else{
		r->next->prev = p;
		p->next = r->next;
		p->prev = r;
		r->next = p;
	}
}

void del_node (list *&h, list *&t, list *r){
	if (r == h && r == t)
		h = t = NULL;
	else if (r == h){
		h = h->next;
		h->prev = NULL;
	}
	else if (r == t){
		t = t->prev;
		h->next = NULL;
	}
	else{
		r->next->prev = r->prev;
		r->prev->next = r->next;
	}
	delete r;
}

void del_list (list *&h, list *&t){
	while (h){
		list *p = h;
		h = h->next;
		h->prev = NULL;
		delete p;
	}
}

int main(){
	int n;
	cin >> n;
	list *head = NULL;
	list *tail = NULL;
	int x;
	for (int i = 0; i < n; i++){
		cin >> x;
		push(head, tail, x);
	}
	bool f = true;
	while (f) {
		f = false;
		list *p = head;
		while (p->next){
			if (p->inf > p->next->inf){
				list *p1 = p;
				list *p2 = p->next;
				list *prev1 = p1->prev;
				list *next2 = p2->next;
				if (prev1) prev1->next = p2;
				else head = p2;
				p2->prev = prev1;
				p2->next = p1;
				p1->prev = p2;
				p1->next = next2;
				if (next2) next2->prev = p1;
				else tail = p1;
				f = true;
				p = p2;
			}
			p = p->next;
		}
	}
	print(head, tail);
}
