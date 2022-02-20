#include "Utils.cpp"
class L086PartitionList
{
private:
    /* data */
public:
    L086PartitionList(/* args */);
    ~L086PartitionList();

    ListNode *partition(ListNode *head, int x)
    {
        ListNode *less = nullptr, *l = nullptr, *greater = nullptr, *g = nullptr, *p = head;
        while (p != nullptr) {
            if (p->val < x) {
                if (less == nullptr) {
                    less = p;
                    l = p;
                    p = p->next;
                } else {
                    l->next = p;
                    l = l->next;
                    p = p->next;
                }
                l->next = nullptr;
            } else {
                if (greater == nullptr) {
                    greater = p;
                    g = p;
                    p = p->next;
                } else {
                    g->next = p;
                    g = g->next;
                    p = p->next;
                }
                g->next = nullptr;
            }
        }
        if (less == nullptr) {
            return greater;
        } else {
            l->next = greater;
            return less;
        }
    }
};

L086PartitionList::L086PartitionList(/* args */) {}

L086PartitionList::~L086PartitionList() {}
