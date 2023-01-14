# Stack

## Create a node class

```cpp
class Node
{
public:
   int data;
   Node *address;
};
```

![Node.png](Stack%20677ebb66338f496f80bbfb43bf638230/Node.png)

## Create a stack class

```cpp
class Stack
{
public:
   Node *top;

public:
   Stack()
   {
      top = NULL;
   }
   ...
};
```

![it is a stack example](Stack%20677ebb66338f496f80bbfb43bf638230/StackOrnek.png)

it is a stack example

## Explanation of the pushStack function

```cpp
void Stack::pushStack(int data){
   if (top != NULL){
      Node *temp = new Node();
      temp->data = data;
      temp->address = top;
      top = temp;
   }
   else{
      Node *temp = new Node();
      temp->data = data;
      top = temp;
   }
};
```

## Explanation of the stackEmpty function

```cpp
bool Stack::stackEmpty(){
   return top == NULL;
};
```

if a stack has not a top this stack is empty, else is not empty

![first time use, data is 70.
used else case, top==NULL
create temp, sync data to data
temp is new top](Stack%20677ebb66338f496f80bbfb43bf638230/aNodeStack.png)

first time use, data is 70.
used else case, top==NULL
create temp, sync data to data
temp is new top

![second time use, data is 60.
used if case 
create temp, sync data to data
temp's address should point to top
new top is temp](Stack%20677ebb66338f496f80bbfb43bf638230/pushTwo.png)

second time use, data is 60.
used if case 
create temp, sync data to data
temp's address should point to top
new top is temp

## Explanation of the popStack function

```cpp
void Stack::popStack(){
   if (stackEmpty()){
      cout << "Stack is empty!" << endl;
   }
   else{
      Node *temp;
      temp = top;
      top = top->address;
      temp = NULL;
   }
};
```

![stack is not empty used else case
create temp, sync temp to top
new TOP points to the element one below
temp becomes NULL](Stack%20677ebb66338f496f80bbfb43bf638230/pop.png)

stack is not empty used else case
create temp, sync temp to top
new TOP points to the element one below
temp becomes NULL

## Explanation of the topStack function

```cpp
int Stack::topStack(){
   if (top != NULL){
      return top->data;
   }
   else{
      return 0;
   }
};
```

![top is not NULL, use if case
the node marked by top is clear
return data of top pointer (50)](Stack%20677ebb66338f496f80bbfb43bf638230/StackOrnek%201.png)

top is not NULL, use if case
the node marked by top is clear
return data of top pointer (50)

## Explanation of the sizeStack function

```cpp
int Stack::sizeStack(){
   int count = 0;
   if (!stackEmpty()){
      Node *iNode = top;
      while (iNode->address != NULL){
         count = count + 1;
         iNode = iNode->address;}
			count = count + 1;
      cout << "Size of stack: " << count << endl;
      return count;
   }
   else{
      cout << "Size of stack: " << count << endl;
      return count;}
};
```

![create a counter and start from zero
if stack is empty, return counter(0) but our stack is not empty used if case
create iNode from top
use the while loop and increment the counter until you reach the last element of the stack. while loop runs three times 
increment the counter 1 time outside the loop for the last element
return the counter](Stack%20677ebb66338f496f80bbfb43bf638230/size.png)

create a counter and start from zero
if stack is empty, return counter(0) but our stack is not empty used if case
create iNode from top
use the while loop and increment the counter until you reach the last element of the stack. while loop runs three times 
increment the counter 1 time outside the loop for the last element
return the counter

## Explanation of the printStack function

```cpp
void Stack::printStack(){
   Node *iNode = top;
   if (top != NULL){
      while (iNode->address != NULL){
         cout << iNode->data << "\n";
         iNode = iNode->address;
      }
      cout << iNode->data << "\n"<< endl;
   }
   else{
      cout << "Stack is empty " << endl;
   }
};
```

![
create iNode from top
if a top of stack equal NULL this stack is empty but our stack not
use the while loop and print data of iNode until you reach the last element of the stack. while loop runs three times 
print data of iNode 1 more time outside the loop for the last element](Stack%20677ebb66338f496f80bbfb43bf638230/size.png)

create iNode from top
if a top of stack equal NULL this stack is empty but our stack not
use the while loop and print data of iNode until you reach the last element of the stack. while loop runs three times 
print data of iNode 1 more time outside the loop for the last element

- output: 40 — 50 — 60 — 70

## Explanation of the createNewStack  function

```cpp
Stack createNewStack(Stack sA, Stack sB){
   Stack a = sA; Stack b = sB; Stack c;Stack sC;
   while (a.topStack() != 0 && b.topStack() != 0){
      if (a.topStack() < b.topStack()){
         c.pushStack(a.topStack());
         a.popStack();
      }
      else{
         c.pushStack(b.topStack());
         b.popStack();
      }
   }
   if (a.topStack() == 0){
      while (b.topStack() != 0){
         c.pushStack(b.topStack());
         b.popStack();
      }
   }
   else{
      while (a.topStack() != 0){
         c.pushStack(a.topStack());
         a.popStack();
      }
   }

   while (!c.stackEmpty()){
      sC.pushStack(c.topStack());
      c.popStack();
   }
   return sC;
};
```

![newStack.png](Stack%20677ebb66338f496f80bbfb43bf638230/newStack.png)