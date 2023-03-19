#include<malloc.h>
#include<stdio.h>
#include"��ͷ.h"
Status InitList_DuL(DuLinkedList* L)
{
	DuLinkedList List;
	List = (DuLinkedList)malloc(sizeof(DuLNode));
	if (List == NULL) return ERROR;
	List->next = NULL;
	*L = List;
	return SUCCESS;
}

void DestroyList_DuL(DuLinkedList* L) {
	DuLinkedList temp;
	while (*L != 0) {
		temp = *L;
		*L = (*L)->next;
		free(temp);
	}
}


Status InsertBeforeList_DuL(DuLNode* p, DuLNode* q) {
	if (p->next == NULL) {
		p->next = q;
		q->prior= p;//��ʱq��Ϊ��һ���ڵ�
	}
	else {
		DuLinkedList temp;
		temp = p->next;
		p->next = q;
		q->next = temp;
		temp->prior = q;
		q->prior = p;
		
	}
	return SUCCESS;

}


Status InsertAfterList_DuL(DuLNode* p, DuLNode* q) {
	if (p->next == NULL)
	{
		p->next = q;
		q->prior = p;
		return SUCCESS;
	}
	else
	{
		DuLinkedList temp;
		temp = p->next;
		p->next = q;
		q->next = temp;
		temp->prior = q;
		q->prior = p;
		return SUCCESS;
	}
}


Status DeleteList_DuL(DuLNode* p, ElemType* e) {//�޷�ʵ��e�ĸ�ֵ����
	if (p->next == NULL)
	{
		printf("����Ϊ�գ��޷�ɾ��\n");
		return ERROR;
	}
	else if (p->next->next == NULL) {
		*e = p->next->data;
		free(p->next);
		p->next = NULL;
	}
	else{
		DuLinkedList p_after = p->next;
		p->next = p_after->next;
		p->next->prior = p;
		*e = p_after->data;
		free(p_after);
		return SUCCESS;
	}
}


void TraverseList_DuL(DuLinkedList L, void (*visit)(ElemType e)) {
	while (L != NULL) {
		L = L->next;
		if (L == NULL) break;
		(*visit)(L->data);
	}
}

void visit(ElemType e) {
	printf("%d ", e);
}


