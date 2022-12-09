#include "SeqList.h"

void sumlist(list *L,const list*L2)
{
     for (int i=1;i<=L2->last;i++)
     {
          for(int j=1;j<=L->last;j++)
          {
               if(L2->element[i]>=L->element[j])
               {
                    Insert(L2->element[i],j,L);
                    break;
               }
          }
     }
}
