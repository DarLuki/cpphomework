#include <iostream>
#include <cmath>

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

bool check(int x){
	if (x < 2) return false;
	for (int i = 2; i <= sqrt(x); i++){
		if (x%i == 0) return false;
	}
	return true;
}

stack *result(stack *&h, int x){
	stack *res=NULL;
	stack *hlp = NULL;
	while (h){
		if (check(h->inf)){
			push(hlp, x);
		}
		push(hlp, pop(h));
	}
	reverse(hlp);
	return hlp;
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
