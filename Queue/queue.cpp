#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *link;
};

class Queue
{
public:
   Node *front;
   Node *near;

public:
   Queue()
   {
      front = NULL;
      near = NULL;
   }
   void enqueue(int data);
   void dequeue();
   void queuePrint();
   int queueSize();
   bool queueEmpty();
   int maxElement();
};

void Queue::queuePrint()
{
   if (front != NULL)
   {
      Node *temp = front;
      while (temp->link != NULL)
      {
         cout << temp->data << " ";
         temp = temp->link;
      }
      cout << temp->data << endl;
   }
   else
   {
      cout << "The Queue is empty " << endl;
   }
};
void Queue::enqueue(int data)
{
   if (front != NULL)
   {
      Node *temp = new Node();
      temp->data = data;
      near->link = temp;
      near = temp;
   }
   else
   {
      Node *temp = new Node();
      temp->data = data;
      front = temp;
      near = temp;
   }
};
void Queue::dequeue()
{
   if (queueEmpty())
   {
      cout << "The Queue is empty!" << endl;
   }
   else
   {
      Node *temp = front->link;
      free(front);
      front = temp;
      cout << "The first element was deleted." << endl;
   }
};
bool Queue::queueEmpty()
{
   return front == NULL;
};
int Queue::queueSize()
{
   int count = 0;
   if (!queueEmpty())
   {
      Node *temp = front;
      while (temp->link != NULL)
      {
         count = count + 1;
         temp = temp->link;
      }
      count = count + 1;
      return count;
   }
   else
   {
      return count;
   }
};
int Queue::maxElement()
{
   int max = front->data;
   Node *temp = front;
   while (temp->link != NULL)
   {
      if (max < temp->data)
      {
         max = temp->data;
      }
      temp = temp->link;
   }
   if (max < near->data)
   {
      max = near->data;
   }
   return max;
};

int main()
{
   Queue QueueA;
   QueueA.queueEmpty() ? cout << "The queue is empty" << endl : cout << "The queue is not empty" << endl;
   QueueA.enqueue(17);
   QueueA.enqueue(10);
   QueueA.enqueue(34);
   QueueA.enqueue(41);
   QueueA.enqueue(65);
   QueueA.enqueue(25);
   QueueA.enqueue(51);
   QueueA.enqueue(73);
   QueueA.enqueue(5);
   QueueA.queuePrint();
   QueueA.queueEmpty() ? cout << "The queue is empty" << endl : cout << "The queue is not empty" << endl;
   cout << "Size of the Queue: " << QueueA.queueSize() << endl;
   QueueA.dequeue();
   QueueA.queuePrint();
   cout << "Size of the Queue: " << QueueA.queueSize() << endl;
   cout << "The max element of the queue: " << QueueA.maxElement() << endl;
   return 0;
}