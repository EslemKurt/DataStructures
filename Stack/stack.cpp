#include <iostream>
using namespace std;

class Node
{
public:
   int data;
   Node *address;
};

class Stack
{
public:
   Node *top;

public:
   Stack()
   {
      top = NULL;
   }
   void pushStack(int data);
   void popStack();
   int topStack();
   void printStack();
   int sizeStack();
   bool stackEmpty();
   Stack createNewStack(Stack A, Stack B);
};

void Stack::printStack()
{
   Node *iNode = top;
   if (top != NULL)
   {
      while (iNode->address != NULL)
      {
         cout << iNode->data << "\n";
         iNode = iNode->address;
      }
      cout << iNode->data << "\n"
           << endl;
   }
   else
   {
      cout << "List is empty " << endl;
   }
};

void Stack::pushStack(int data)
{
   if (top != NULL)
   {
      Node *temp = new Node();
      temp->data = data;
      temp->address = top;
      top = temp;
   }
   else
   {
      Node *temp = new Node();
      temp->data = data;
      top = temp;
   }
   // cout << "Push!" << endl;
};

int Stack::topStack()
{
   if (top != NULL)
   {
      // cout << "Top data: " << top->data << endl;
      return top->data;
   }
   else
   {
      // cout << "Stack is empty!" << endl;
      return 0;
   }
};

void Stack::popStack()
{
   if (stackEmpty())
   {
      cout << "Stack is empty!" << endl;
   }
   else
   {
      Node *temp;
      temp = top;
      top = top->address;
      temp = NULL;
      // cout << "Pop!" << endl;
   }
};
int Stack::sizeStack()
{
   int count = 0;
   if (!stackEmpty())
   {
      Node *iNode = top;
      while (iNode->address != NULL)
      {
         count = count + 1;
         iNode = iNode->address;
      }
      count = count + 1;
      cout << count << endl;
      return count;
   }
   else
   {
      cout << "Size of stack: " << count << endl;
      return count;
   }
};

bool Stack::stackEmpty()
{
   return top == NULL;
};

Stack createNewStack(Stack sA, Stack sB)
{
   Stack a = sA;
   Stack b = sB;
   Stack c;
   Stack sC;
   while (a.topStack() != 0 && b.topStack() != 0)
   {

      if (a.topStack() <= b.topStack())
      {
         c.pushStack(a.topStack());
         a.popStack();
      }
      else
      {
         c.pushStack(b.topStack());
         b.popStack();
      }
   }
   if (a.topStack() == 0)
   {
      while (b.topStack() != 0)
      {
         c.pushStack(b.topStack());
         b.popStack();
      }
   }
   else
   {
      while (a.topStack() != 0)
      {
         c.pushStack(a.topStack());
         a.popStack();
      }
   }

   while (!c.stackEmpty())
   {
      sC.pushStack(c.topStack());
      c.popStack();
   }
   return sC;
};

int main()
{
   // create a stack to try the functions
   Stack tryFunctions;
   // stackEmpty function
   cout << "The stack is empty: ";
   cout << tryFunctions.stackEmpty() << endl;
   tryFunctions.pushStack(99);
   tryFunctions.pushStack(89);
   tryFunctions.pushStack(79);
   tryFunctions.pushStack(69);
   tryFunctions.pushStack(59);
   tryFunctions.pushStack(49);
   // stackEmpty function
   cout << "The stack is empty: ";
   cout << tryFunctions.stackEmpty() << endl;
   // printStack function
   cout << "Stack:" << endl;
   tryFunctions.printStack();
   // topStack function
   cout << "Top element of the stack:" << endl;
   cout << tryFunctions.topStack() << endl;
   // sizeStack function
   cout << "Size of the stack:" << endl;
   tryFunctions.sizeStack();
   // popStack function
   cout << "Using pop function and new top element:" << endl;
   tryFunctions.popStack();
   cout << tryFunctions.topStack() << "\n"
        << endl;
   // sizeStack function
   cout << "Size of the new stack:" << endl;
   tryFunctions.sizeStack();
   // printStack function
   cout << "New stack:" << endl;
   tryFunctions.printStack();

   // creat A stack
   Stack stackA;
   stackA.pushStack(70);
   stackA.pushStack(60);
   stackA.pushStack(50);
   stackA.pushStack(40);
   stackA.pushStack(30);
   stackA.pushStack(20);
   stackA.pushStack(10);
   cout << "First Stack, Stack A:" << endl;
   stackA.printStack();

   // creat B stack
   Stack stackB;
   stackB.pushStack(45);
   stackB.pushStack(32);
   stackB.pushStack(27);
   stackB.pushStack(22);
   stackB.pushStack(15);
   cout << "Secend Stack, Stack B:" << endl;
   stackB.printStack();

   // merger of two stacks (min on top) A and B
   Stack stackC = createNewStack(stackA, stackB);
   cout << "A New Stack, Stack C:" << endl;
   stackC.printStack();

   // merger of two stacks (min on top)
   Stack stackK = createNewStack(stackA, tryFunctions);
   cout << "A New Stack, Stack K:" << endl;
   stackK.printStack();

   // merger of two stacks (min on top)
   Stack stackT = createNewStack(stackB, tryFunctions);
   cout << "A New Stack, Stack T:" << endl;
   stackT.printStack();

   return 0;
}
