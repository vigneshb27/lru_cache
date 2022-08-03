#include <stdio.h>
#include <stdlib.h>

typedef struct QNode {
	struct QNode *prev, *next;
	unsigned pageNumber; 
} QNode;

typedef struct Queue {
	unsigned count; // Number of filled frames
	unsigned numberOfFrames; // total number of frames
	QNode *front, *rear;
} Queue;


typedef struct Hash {
	int capacity; 
	QNode** array; 
} Hash;


QNode* newQNode(unsigned pageNumber)
{
	QNode* temp = (QNode*)malloc(sizeof(QNode));
	temp->pageNumber = pageNumber;

	temp->prev = temp->next = NULL;

	return temp;
}

Queue* createQueue(int numberOfFrames)
{
	Queue* queue = (Queue*)malloc(sizeof(Queue));

	
	queue->count = 0;
	queue->front = queue->rear = NULL;

	
	queue->numberOfFrames = numberOfFrames;

	return queue;
}


Hash* createHash(int capacity)
{
	
	Hash* hash = (Hash*)malloc(sizeof(Hash));
	hash->capacity = capacity;

	
	hash->array = (QNode**)malloc(hash->capacity * sizeof(QNode*));

	
	int i;
	for (i = 0; i < hash->capacity; ++i)
		hash->array[i] = NULL;

	return hash;
}

int AreAllFramesFull(Queue* queue)
{
	return queue->count == queue->numberOfFrames;
}

int isQueueEmpty(Queue* queue)
{
	return queue->rear == NULL;
}

void deQueue(Queue* queue)
{
	if (isQueueEmpty(queue))
		return;

	if (queue->front == queue->rear)
		queue->front = NULL;

	QNode* temp = queue->rear;
	queue->rear = queue->rear->prev;

	if (queue->rear)
		queue->rear->next = NULL;

	free(temp);

	queue->count--;
}


void Enqueue(Queue* queue, Hash* hash, unsigned pageNumber)
{
	if (AreAllFramesFull(queue)) {
		hash->array[queue->rear->pageNumber] = NULL;
		deQueue(queue);
	}

	QNode* temp = newQNode(pageNumber);
	temp->next = queue->front;

	if (isQueueEmpty(queue))
		queue->rear = queue->front = temp;
	else 
	{
		queue->front->prev = temp;
		queue->front = temp;
	}

	hash->array[pageNumber] = temp;

	queue->count++;
}


void ReferencePage(Queue* queue, Hash* hash, unsigned pageNumber)
{
	int num;
	QNode* reqPage = hash->array[pageNumber];

	if (reqPage == NULL)
		Enqueue(queue, hash, pageNumber);

	else if (reqPage != queue->front) {
		reqPage->prev->next = reqPage->next;
		if (reqPage->next)
			reqPage->next->prev = reqPage->prev;

		
		if (reqPage == queue->rear) {
			queue->rear = reqPage->prev;
			queue->rear->next = NULL;
		}

		reqPage->next = queue->front;
		reqPage->prev = NULL;

		reqPage->next->prev = reqPage;

		queue->front = reqPage;
	}

	Queue* ref = queue;
    QNode* node = ref -> front;
	FILE *fptr;
    fptr = fopen("readMeNow.txt","w");
	
	while(node)
    {
		printf("\n");
		num = node -> pageNumber;
        fprintf(fptr,"%d", num);
        node = node -> next;
    }
	fclose(fptr);
}

int getThePage(Queue* queue, Hash* hash, unsigned pageNumber)
{
    Queue* find = queue;
    QNode* node = find -> front;
    while(node)
    {
        if(node -> pageNumber == pageNumber)
        {
            ReferencePage(queue, hash, pageNumber);
            return pageNumber;
        }
        node = node -> next;
    }
    return -1;
}

void printAll(Queue* queue)
{
	int num;
	Queue* ref = queue;
    QNode* node = ref -> front;
	if(!node)
	{
		printf("\nCache is empty :(\n");
	}
	
	while(node)
    {
		printf("\n");
		num = node -> pageNumber;
        printf("%d\n", node -> pageNumber);
        node = node -> next;
    }
	printf("\nThe elements of the cache has been printed!!!\n");
	
}

// Driver program to test above functions
int main()
{
	
	int n;
    printf("\nEnter the size of the cache : ");
    scanf("%d", &n);
    
	Queue* q = createQueue(n);
	Hash* hash = createHash(50);

	int op = 0;
    int val, ans;
    do{
        printf("\n1. Add\n2. Get\n3. Print the cache elements\n4. Free the cache(Exit)\n\n");
        printf("Enter the operation needs to be performed : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\nEnter the page number to add : ");
            scanf("%d", &val);
            ReferencePage(q, hash, val);
			printf("Value is added to the storage!!!\n");
            break;

        case 2:
            printf("\nEnter the page number to get : ");
            scanf("%d", &val);
            ans = getThePage(q, hash, val);
            printf("\n%d\n", ans);
			if(ans == -1)
			{
				printf("Value is not found in the storage!!!\n");
			}
			else
			{
				printf("\nValue is found!!!\n");
			}

            break;

		case 3:
			printAll(q);
			break;

        case 4:
			printf("\nCache is freed!!!\n");
			printf("\nTerminating the program!!!\n\n");
            break;

        default:
            printf("\nEnter the valid choice!!!\n");
            break;
        }

    }while(op != 4);

	return 0;
}
