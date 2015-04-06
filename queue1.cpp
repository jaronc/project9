#include <iostream>
#include "queue.h"

Queue::Queue(int a)
{
  max = a;
  front = -1;
  rear = -1;
  data = new int[max];
}

Queue::Queue(const Queue &q)
{
  max = q.max;
  front = q.front;
  rear = q.rear;
  data = new int[max];
  for(int i = 0; i < max; i++)
    {
      data[i] = q.data[i];
    }
}

Queue::~Queue()
{
  max = 0;
  front = 0;
  rear = 0;
  if(data != NULL)
    {
      delete[] data;
    }
}

Queue& Queue::operator=(const Queue &q)
{
  if(&q != this)
    {
      max = q.max;
      front = q.front;
      rear = q.rear;
      data = new int[max];
      for(int i = 0; i < max; i++)
	{
	  data[i] = q.data[i];
	}
    }
  return *this;
}

bool Queue::enqueue(int a)
{
  if(rear == max-1)
    {
      return false;
    }
  if(front == -1)
    {
      front++;
      rear++;
      data[front] = a;
      return true;
    }
  else
    {
      rear++;
      data[rear] = a;
      return true;
    }
}

bool Queue::dequeue(int &a)
{
  a = data[front];
  for(int i = front; i < rear; i++)
    {
      data[i] = data[i+1];
    }
  rear--;
  if(rear == -1)
    {
      front = -1;
    }
}

bool Queue::empty() const
{
  if(front == -1 && rear == -1)
    return true;
  else 
    return false;
}

bool Queue::full() const
{
  if(rear == max-1)
    return true;
  else 
    return false;
}

bool Queue::clear()
{
  front = -1;
  rear = -1;
}

bool Queue::operator==(const Queue &q) const
{
  if(max != q.max && front != q.front && rear != q.rear)
    return false;
  for(int i = front; i <= rear; i++)
    {
      if(data[i] != q.data[i])
	return false;
    }
  return true;
}

ostream& operator<<(ostream &os, const Queue &q)
{
  for(int i = q.front; i <= q.rear; i++)
    {
      os << q.data[i] << ' ';
    }
  os << endl;
  return os;
}
  
