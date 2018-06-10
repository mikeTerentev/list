#include "List.h"

void f(List<int> const& v)
{
    v.front();
}
void f(List<int>::iterator i,List<int>::const_iterator j)
{
    i==j;
    j==i;
}
void f(List<int>::iterator const& i)
{
    i == i;
}