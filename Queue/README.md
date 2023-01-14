# Queue

## Create a node class

```cpp
class Node
{
public:
   int data;
   Node *link;
};
```

![creatNode.png](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/creatNode.png)

## Create a Queue class

```cpp
class Queue{
public:
   Node *front;
   Node *near;
public:
   Queue(){
      front = NULL;
      near = NULL;
   }
   ...
};
```

![queueOrnek.png](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/queueOrnek.png)

## Explanation of the enqueue function

```cpp
void Queue::enqueue(int data){
   if (front != NULL){
      Node *temp = new Node();
      temp->data = data;
      near->link = temp;
      near = temp;
   }
   else{
      Node *temp = new Node();
      temp->data = data;
      front = temp;
      near = temp;
   }
};
```

![if the queue is empty (data is 17)
used else case because front==NULL
create temp, sync data to 17
temp is new front and new near
](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/firstElement.png)

if the queue is empty (data is 17)
used else case because front==NULL
create temp, sync data to 17
temp is new front and new near

![if the queue is not empty (data is 10)
used if case because front ≠ NULL
1) create temp, sync data to 10
2) near's link should point to temp
3) new near should be the temp](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/secondElement.png)

if the queue is not empty (data is 10)
used if case because front ≠ NULL
1) create temp, sync data to 10
2) near's link should point to temp
3) new near should be the temp

## Explanation of the dequeue function

```cpp
void Queue::dequeue()
{
   if (queueEmpty()){cout << "The Queue is empty!" << endl;}
   else
   {
      Node *temp = front->link;
      free(front);
      front = temp;
      cout << "The first element was deleted." << endl;
   }
};
```

![if the queue is not empty used else case 
1) create a temp that points to the next of front
2) free the front
3) new front should be the temp](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/dequeue.png)

if the queue is not empty used else case 
1) create a temp that points to the next of front
2) free the front
3) new front should be the temp

## Explanation of the queuePrint function

```cpp
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
```

![if a front of queue equal NULL this queue is empty but our queue not empty. so used if case.
create a temp from front
use the while loop and print data of temp until you reach the last element of the queue. while loop runs three times 
print data of temp one more time outside the loop for the last element](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/print.png)

if a front of queue equal NULL this queue is empty but our queue not empty. so used if case.
create a temp from front
use the while loop and print data of temp until you reach the last element of the queue. while loop runs three times 
print data of temp one more time outside the loop for the last element

## Explanation of the queueSize function

```cpp
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
```

![create a counter and start from zero
if queue is empty, return counter(0) but our queue is not empty used if case
create a temp from front
use the while loop and increment the counter until you reach the last element of the queue. while loop runs three times 
increment the counter one time outside the loop for the last element
**return the counter**](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/print%201.png)

create a counter and start from zero
if queue is empty, return counter(0) but our queue is not empty used if case
create a temp from front
use the while loop and increment the counter until you reach the last element of the queue. while loop runs three times 
increment the counter one time outside the loop for the last element
**return the counter**

## Explanation of the maxElement function

```cpp
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
```

![1) create a temp from front and an integer max whose value is front's data **(max = 17)**
2) use the while loop and compare the max with the data of the next node until you reach the last element of the queue.
2.1) temp points to the second node. temp's data is less than the max. **the max is still 17**
2.2) temp points to the third node. the max is less than temp's data . **the new max is equal to 34**
3) the while loop has ended and we need to make an compare for the last node. the max is less than near’s data. **the new max is equal to 41
return the max**
](https://github.com/EslemKurt/DataStructures/blob/main/Queue/QueueImages/max.png)

1) create a temp from front and an integer max whose value is front's data **(max = 17)**
2) use the while loop and compare the max with the data of the next node until you reach the last element of the queue.
2.1) temp points to the second node. temp's data is less than the max. **the max is still 17**
2.2) temp points to the third node. the max is less than temp's data . **the new max is equal to 34**
3) the while loop has ended and we need to make an compare for the last node. the max is less than near’s data. **the new max is equal to 41
return the max**
