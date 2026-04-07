#include <iostream>

using namespace std;

struct stack{
	int inf;
	stack *next;
};

void push(stack *&h, int x){
	stack *r = new stack;
	r->inf=x;
	r->next=h;
	h=r;
}

int pop(stack *&h){
	int i=h->inf;
	stack *r = h;
	h = h->next;
	delete r;
	return i;
}

void reverse(stack *&h){
	stack *head1 = NULL;
	while (h)
		push(head1, pop(h));
	h = head1;
}

stack *result(stack *&h, int x){
	stack *res=NULL;
	stack *hlp = NULL;
	reverse(h);
	while (h){
		if ((h->inf)%2==0){
			int i = pop(h);
			push(hlp, i);
		}
		else break;
	}
	push(h, x);
	while (hlp){
		int i = pop(hlp);
		push(h, i);
	}
	reverse(h);
	return h;
}

int main(){
	int n;
	cin >> n;
	stack *head = NULL;
	int x;
	for (int i = 0; i < n; i++){
		cin >> x;
		push(head, x);
	}
	reverse(head);
	int el;
	cin >> el;
	stack *res = result(head, el);
	while (res)
		cout << pop(res) << " ";
	cout << endl;
}
