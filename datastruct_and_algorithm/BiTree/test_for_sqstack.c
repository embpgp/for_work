

#include "SqStack.h"

int main(void)
{
	SqStack s;
	BTNode* p;
	StackInit(&s);
	BiTree root = Create(1, NULL, NULL);
	BTNode* l = Create(2, NULL, NULL);
	BTNode* r = Create(3, NULL, NULL);
	push(&s, root);
	push(&s, l);
	push(&s, r);
	p = pop(&s);
	printf("%d\n", p->data);
	p = pop(&s);
	printf("%d\n", p->data);
	p = pop(&s);
	printf("%d\n", p->data);
	p = pop(&s);
	if(p)
		printf("%d\n", p->data);
	else
		puts("error");
	return 0;
}
