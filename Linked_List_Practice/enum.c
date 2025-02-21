#include <stdio.h>
#include <string.h>

// Enum for Passenger Types
typedef enum {
    VIP=1,
    SENIOR_CITIZEN,
    GENERAL
} PassengerType;

// Structure to represent each passenger
typedef struct {
    int id;
    PassengerType type;
    char name[50];
} Passenger;

// Queue structure to store passengers
#define MAX_QUEUE_SIZE 100

typedef struct {
    Passenger queue[MAX_QUEUE_SIZE];
    int front;
    int rear;
} TicketQueue;

// Function prototypes
void initializeQueue(TicketQueue* q);
int isQueueFull(TicketQueue* q);
int isQueueEmpty(TicketQueue* q);
void enqueue(TicketQueue* q, Passenger p);
Passenger dequeue(TicketQueue* q);
void displayQueue(TicketQueue* q);
void servePassenger(Passenger p);

int main() {
    TicketQueue queue;
    initializeQueue(&queue);

    int n; // Number of operations
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int operation;
        scanf("%d", &operation);

        if (operation == 1) {  // Enqueue operation
            int id;
            char name[50];
            char typeStr[20];
            Passenger p;

            scanf("%d,%s,%s", &id, name, typeStr);

            // Set the passenger details
            p.id = id;
            strcpy(p.name, name);

            // Set the passenger type based on input string
            if (strcmp(typeStr, "VIP") == 0) {
                p.type = VIP;
            } else if (strcmp(typeStr, "SENIOR_CITIZEN") == 0) {
                p.type = SENIOR_CITIZEN;
            } else {
                p.type = GENERAL;
            }

            // Add passenger to the queue
            enqueue(&queue, p);
        } else if (operation == 2) {  // Dequeue operation (serve next passenger)
            if (!isQueueEmpty(&queue)) {
                Passenger served = dequeue(&queue);
                servePassenger(served);
            } else {
                printf("Queue is empty, no passengers to serve.\n");
            }
        } else if (operation == 3) {  // Display Queue operation
            displayQueue(&queue);
        }
    }

    return 0;
}

// Initialize the queue
void initializeQueue(TicketQueue* q) {
    q->front = 0;
    q->rear = 0;
}

// Check if the queue is full
int isQueueFull(TicketQueue* q) {
    return q->rear == MAX_QUEUE_SIZE;
}

// Check if the queue is empty
int isQueueEmpty(TicketQueue* q) {
    return q->front == q->rear;
}

// Add a passenger to the queue
void enqueue(TicketQueue* q, Passenger p) {
    if (isQueueFull(q)) {
        printf("Queue is full, cannot add more passengers.\n");
        return;
    }

    // Insert passenger based on priority
    int i = q->rear - 1;
    while (i >= q->front) {
        if (p.type < q->queue[i].type) {
            q->queue[i + 1] = q->queue[i];  // Shift the passenger down the queue
        } else {
            break;
        }
        i--;
    }

    // Add the new passenger in the correct position
    q->queue[i + 1] = p;
    q->rear++;
}

// Serve the next passenger (dequeue)
Passenger dequeue(TicketQueue* q) {
    if (isQueueEmpty(q)) {
        printf("Queue is empty, no passengers to serve.\n");
        return (Passenger){-1, GENERAL, ""};
    }

    return q->queue[q->front++];
}

// Display all waiting passengers
void displayQueue(TicketQueue* q) {
    if (isQueueEmpty(q)) {
        printf("No passengers in queue.\n");
        return;
    }

    printf("Waiting Passengers:\n");
    for (int i = q->front; i < q->rear; i++) {
        printf("ID %d, Name: %s, Type: %s\n", q->queue[i].id, q->queue[i].name,
               (q->queue[i].type == VIP) ? "VIP" :
               (q->queue[i].type == SENIOR_CITIZEN) ? "SENIOR_CITIZEN" : "GENERAL");
    }
}

// Display the served passenger
void servePassenger(Passenger p) {
    if (p.id != -1) {
        printf("Serving Passenger: ID %d, Name: %s, Type: %s\n", p.id, p.name,
               (p.type == VIP) ? "VIP" :
               (p.type == SENIOR_CITIZEN) ? "SENIOR_CITIZEN" : "GENERAL");
    }
}
