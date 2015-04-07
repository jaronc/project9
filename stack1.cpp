#include <iostream>
#include "stack.h"

Stack::Stack(int a)
{
  max = a;
  top = -1;
  actual = 0;
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
      for(int i = top; i < actual; i++)
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
       actual = s.actual;
       if(top == -1)
	 {
	   data = new char[max];
	 }
       else
	 {
	   data = new char[max];
	   for(int i = top; i < actual; i++)
	     {
	       data[i] = s.data[i];
	     }
	 }
    }
  return *this;
}

bool Stack::push(char a)
{
  if(actual == max)
    {
      return false;
    }
  if(top == -1)
    {
      top++;
      data[top] = a;
      actual++;
      return true;
    }
  else
    {
      for(int i = actual; i > top; i--)
	{
	  data[i] = data[i-1];
	}
      data[top] = a;
      actual++;
      return true;
    }
}

bool Stack::pop(char &a)
{
  if(top == -1)
    {
      return false;
    }
  a = data[top];
  for(int i = top; i < actual; i++)
    {
      data[i] = data[i+1];
    }
  actual--;
  if(actual == 0)
    {
      top = -1;
    }
  return true;
}

bool Stack::empty() const
{
  if(actual == 0 && top == -1)
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
  if(actual == max)
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
  actual = 0;
  top = -1;
  return true;
}

bool Stack::operator==(const Stack &s) const
{
  if(max != s.max)
    {
      return false;
    }
  if(actual != s.actual)
    {
      return false;
    }
  for(int i = top; i < actual; i++)
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
      for(int i = s.top; i < s.actual; i++)
	{
	  os << s.data[i] << ' ';
	}
      os << endl;
      return os;
    }
}


