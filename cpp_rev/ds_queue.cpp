/*
 Queue
 - FIFO (first in first out)
 - enqueue, dequeue
*/

#include <iostream>
#define MAX_SIZE 5

class Queue{

    private:
    int items[MAX_SIZE],front,rear;

    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isFull();
    bool isEmpty();
    void enQueue(int x);
    int deQueue();
    void displayQ();
};


bool Queue::isFull(){
    if(front==0 && rear==MAX_SIZE-1){
        return true;
    }else{
        return false;
    }
}

bool Queue::isEmpty(){
    if(front == -1)
        return true;
    else
        return false;   
}

void Queue::enQueue(int x){

    if(isFull()){
        std::cout << "Queue is full!\n";
    }else{
        if(isEmpty())front = 0;
        rear++;
        items[rear] = x;
        std::cout << x << " added to queue.\n";
    }
}

int Queue::deQueue(){

    if(isEmpty()){
        std::cout << "Queue is empty!\n";
        return -1;
    }

    int x;
    x = items[front];
    if(front == rear){
        front = -1;
        rear = -1;
    }else{
        front++;
    }

    std::cout << x << " removed from queue.\n";

    return x;
}

void Queue::displayQ(){
    
    if(isEmpty()){
        std::cout << "Queue is empty!\n";
    }else{
        std::cout << "Front index: " << front << std::endl;

        std::cout << "Items: \n";

        for(int i=front; i<=rear; i++){
            std::cout << items[i] << " ";
        }

        std::cout << "\nRear index: " << rear << std::endl;
    }
}


int main(){
    Queue my_q;

    my_q.deQueue();

    my_q.enQueue(1);
    my_q.enQueue(2);
    my_q.enQueue(3);
    my_q.enQueue(4);
    my_q.enQueue(5);

    my_q.enQueue(6);

    my_q.deQueue();

    my_q.displayQ();

    return 0;

}