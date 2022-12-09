#include "LinkList.h"

void Sort(position head) {
    if (head == NULL || head->next == NULL)return;
    for (int i = 1; i <= End(head); i++)
    {
        for (int j = 1; j <= End(head) - i; j++)
        {
            position pj = Locate_index(j, head);
            if (pj->next->element <= pj->element)
                swap(j, j + 1, head);
        }
    }
}