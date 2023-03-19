#include<malloc.h>
#include<stdio.h>
#include"LinkedList.h"
Status InitList(LinkedList* L) {
	LinkedList List;
	List = (LinkedList)malloc(sizeof(LNode));
	if (List == NULL) return ERROR;
	List->next = NULL;
	*L = List;
	return SUCCESS;
}

void DestroyList(LinkedList* L) {
	LinkedList temp;
	while (*L != 0) {
		temp = *L;
		*L = (*L)->next;
		free(temp);
	}
}

Status InsertList(LNode* p, LNode* q) {
	if (p->next == NULL) {
		p->next = q;
		q->next = NULL;
	}
	else {
		q->next = p->next;
		p->next = q;
	}
	return SUCCESS;
}

Status DeleteList(LNode* p, ElemType* e) {
	if (p->next == NULL) printf("p为尾结点无法再进行删除\n");
	else if (p->next->next == NULL) {
		*e = p->next->data;
		free(p->next);
		p->next = NULL;
	}
	else{
		LNode* p_after;
		p_after = p->next;
		p->next = p_after->next;
		*e = p_after->data;
		free(p_after);
	}
	return SUCCESS;
}

void TraverseList(LinkedList L, void (*visit)(ElemType e)) {
	while (L != NULL) {
		L = L->next;
		if (L == NULL)break;
		(*visit)(L->data);
	}
	printf("\n");
}

void visit(ElemType e) {
	printf("%d ", e);
}

Status SearchList(LinkedList L, ElemType e) {
	while (L != NULL) {
		if (L->data == e) return SUCCESS;
		L = L->next;
	}
	return ERROR;
}

Status ReverseList(LinkedList* L) {
	LNode* newHead, * p1, * p2;
	p1 = (*L)->next;
	p2 = p1->next;
	p1->next = NULL;
	newHead = p1;
	while (p2 != NULL) {
		p1 = p2;
		p2 = p1->next;
		p1->next = newHead;
		newHead = p1;
	}
	(*L)->next = newHead;
	return SUCCESS;
}


Status IsLoopList(LinkedList L) {
	LinkedList fast = L, slow = L;
	while (fast->next != NULL && slow->next != NULL)
	{
		slow = slow->next;
		if ((fast = fast->next->next) == NULL)
			return ERROR;
		if (fast == slow)
			return SUCCESS;
	}
	return ERROR;
}

LNode* ReverseEvenList(LinkedList* L) {//此功能无法实现
	LinkedList p1 = *L, p2 = *L, temp, p3;
	if (p1->next == NULL)return p1;
	p2 = p1->next;
	p3 = p2;
	while (p2 != NULL) {
		temp = p2;
		p2 = p1;
		p1 = temp;
		p1 = p1->next;
		p2 = p1->next;
	}
	return p3;

}

LNode* FindMidNode(LinkedList* L) {
	LinkedList p1 = *L, p2 = *L;
	while (p1->next != NULL) {
		p1 = p1->next;
		p2 = p2->next->next;
		if (p2 == NULL)return p1;//当链表节点数为奇数时才能实现
	}

}
