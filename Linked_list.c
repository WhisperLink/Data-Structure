#include <stdio.h>
#include <stdlib.h>

typedef struct LL{
	struct LL* nextNode;
	int data;
}LL;

LL* head = NULL;
LL* start = NULL;

void init(LL* node, int recvdata)
{
	node -> nextNode = NULL;
	node -> data = recvdata;
}

void insert(LL* node, int recvdata)
{
	LL* newnode = (LL*)malloc(sizeof(LL));
	node -> nextNode = newnode;
	newnode -> data = recvdata;
	head = newnode; // node = newnode
}

void print_data(LL* node)
{
	while(node != NULL){
		printf("%d ", node->data);
		node = node->nextNode;
		if(node == NULL) break;
		printf("-> ");
	}
	printf("\n");
}

int delete(int recvdata)
{
	LL* temp = start;
	while(temp->nextNode != NULL)
	{
		if(temp->nextNode->data == recvdata)
		{
			temp->nextNode = temp->nextNode->nextNode;
			return 0;
		}
		temp = temp->nextNode;
	}
}

int main()
{
	head = (LL*)malloc(sizeof(LL));
	start = head;
	
	init(head, 123456); // init함수는 head 노드의 초기화를 위해 만듦. 이걸 해주지 않으면 전역변수로 선언한 head의 초기 data 변수는 0으로 초기화함
	
	insert(head, 1);
	insert(head, 2);
	insert(head, 3);
	insert(head, 4);
	insert(head, 5);
	insert(head, 6);
	
	head = NULL;
	
	delete(3);
	
	print_data(start);
}
