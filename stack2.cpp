#include <iostream>
#include "stack.h"

Stack::Stack(int a)
{
  max = a;
  top = -1;
  data = new char[max];
}

Stack::Stack(const Stack &s)
{
  max = s.max;
  top = s.top;
  actual = s.actual;
  if(top == -1)
    {
      data = new char[max];
    }
  else
    {
      data = new char[max];
      for(int i = top; i >= 0; i--)
	{
	  data[i] = s.data[i];
	}
    }
}

Stack::~Stack()
{
  max = 0;
  top = 0;
  actual = 0;
  if(data != NULL)
    {
      delete[] data;
      data = NULL;
    }
}

Stack& Stack::operator=(const Stack &s)
{
  if(&s != this)
    {
       max = s.max;
       top = s.top;
       if(top == -1)
	 {
	   data = new char[max];
	 }
       else
	 {
	   data = new char[max];
	   for(int i = top; i >= 0; i--)
	     {
	       data[i] = s.data[i];
	     }
	 }
    }
  return *this;
}

bool Stack::push(char a)
{
  if(top == max-1)
    {
      return false;
    }
  top++;
  data[top] = a;
  return true;
}

bool Stack::pop(char &a)
{
  if(top == -1)
    {
      return false;
    }
  a = data[top];
  top--;
  return true;
}

bool Stack::empty() const
{
  if(top == -1)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Stack::full() const
{
  if(top == max-1)
    {
      return true;
    }
  else
    {
      return false;
    }
}

bool Stack::clear()
{
  top = -1;
  return true;
}

bool Stack::operator==(const Stack &s) const
{
  if(max != s.max)
    {
      return false;
    }
  if(top != s.top)
    {
      return false;
    }
  for(int i = top; i >= 0; i--)
    {
      if(data[i] != s.data[i])
	{
	  return false;
	}
    }
  return true;
}

ostream& operator<<(ostream& os, const Stack &s)
{
  if(s.top == -1)
    {
      return os;
    }
  else
    {
      for(int i = s.top; i >= 0; i--)
	{
	  os << s.data[i] << ' ';
	}
      os << endl;
      return os;
    }
}


