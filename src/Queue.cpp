#include "../include/Queue.hpp"

bool Queue::isEmpty()
{
    return frontNode == nullptr;
}

void Queue::enqueue(int value)
{
    Node *newNode = new Node(value);

    if (isEmpty())
    {
        frontNode = newNode;
        rearNode = newNode;
    }
    else
    {
        rearNode->next = newNode;
        rearNode = newNode;
    }
}

void Queue::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return;
    }

    Node *temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
}

int Queue::front()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty." << std::endl;
        return -1; // Return a special value to indicate error
    }
    return frontNode->data;
}