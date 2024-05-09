#include <stdio.h>
#include <stdlib.h>

typedef struct dllNode {
	struct dllNode* nextNode;
	struct dllNode* prevNode;
	int data;
}dllNode;


void addNode(dllNode* node, int recvdata)
{
	dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
	
	newNode->data = recvdata;

	node -> prevNode -> nextNode = newNode;
	newNode -> prevNode = node -> prevNode;
	
	node -> prevNode = newNode;
	newNode -> nextNode = node;
}

int deleteNode(dllNode* node, int recvindex, dllNode* end)
{
	int index = 0;
	while(node != end)
	{
		if(recvindex == index)
		{
			dllNode* trash = NULL;
			trash = node;
			trash -> prevNode -> nextNode = node -> nextNode;
			trash -> nextNode -> prevNode = node -> prevNode;
			free(trash);
			return 0;
		}
		node = node -> nextNode;
		index++;
	}
}

int nodelen(dllNode* node, dllNode* end)
{
	int count_data = 0;
	while (node != end)
	{
		count_data++;
		node = node->nextNode;
	}
	return count_data;
}


void print_paticular_node(dllNode* node, int recvindex, dllNode* end)
{
	int end_Index = nodelen(node, end) - 1;
	if(recvindex > end_Index | recvindex < 0) {
		printf("인덱스 범위 초과\n");
		exit(0);
	}
	printf("맨 마지막 index = %d\n", end_Index);
	printf("인덱스 %d번 노드 데이터 출력: ", recvindex);

	int num = 0;

	if (recvindex == end_Index)
	{
		while (node->nextNode != end)
		{
			node = node->nextNode;
		}
		printf("%d <- %d\n", node->prevNode->data, node->data);
	}
	else{
		while (node != end)
		{
			if (recvindex == 0) {
				printf("%d -> %d\n", node->data, node->nextNode->data);
				break;
			}
			else if (num == recvindex) {
				printf("%d <- %d -> %d\n", node->prevNode->data, node->data, node->nextNode->data);
				break;
			}
			node = node->nextNode;
			num++;
		}
	}
}


void print_data(dllNode* node, dllNode* end)
{
	printf("모든 데이터 출력: ");
	while (node != end)
	{
		printf("%d ", node->data);
		if (node->nextNode == end) break;
		printf("-> ");
		node = node->nextNode;
	}
	printf("\n");
}


int main()
{
	dllNode* head = (dllNode*)malloc(sizeof(dllNode)); // 시작 노드
	dllNode* tail = (dllNode*)malloc(sizeof(dllNode)); // 끝 노드를 표시해주시 위해 생성
	
	head->data = 0;
	tail->data = 0;
	
	head->nextNode = tail;
	head->prevNode = head;
	tail->nextNode = tail;
	tail->prevNode = head;

	addNode(tail, 1);
	addNode(tail, 2);
	addNode(tail, 3);
	addNode(tail, 4);
	addNode(tail, 5);
	addNode(tail, 6);


	print_data(head->nextNode, tail);

	int search_index = 0;
	int delete_index = 0;
	
	printf("Input index# ");
	scanf("%d", &search_index);
	print_paticular_node(head->nextNode, search_index, tail);
	
	printf("Input delete index# ");
	scanf("%d", &delete_index);
	deleteNode(head->nextNode, delete_index, tail);

	print_data(head->nextNode, tail);

	return 0;
}
