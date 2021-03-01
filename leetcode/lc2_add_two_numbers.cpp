/*
 * Leetcode Problem N°2
 * Add Two Numbers
 * First version: 01/03/2021
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode()
    {
        val = 0;
        next = nullptr;
    }
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

/*
 * SOLUTION TO THE PROBLEM
 */ 

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr && l2 == nullptr)
        {
            return nullptr;
        }

        ListNode *node = new ListNode();
        if (l1 != nullptr && l2 != nullptr)
        {
            bool cflag = false;
            node->val = (((l1->val) + (l2->val)) % 10);
            if ((((l1->val) + (l2->val)) / 10) > 0)
            {
                cflag = true;
            }
            if (cflag)
            {
                if (l1->next != nullptr || l2->next != nullptr)
                {
                    if (l1->next != nullptr)
                    {
                        l1->next->val += ((l1->val + l2->val) / 10);
                    }
                    else
                    {
                        l2->next->val += ((l1->val + l2->val) / 10);
                    }
                }
                else
                {
                    node->next = new ListNode(1);
                    return node;
                }
            }

            node->next = addTwoNumbers(l1->next, l2->next);
        }
        else
        {
            if (l1 != nullptr)
            {
                bool cflag = false;
                if (((l1->val) / 10) > 0)
                {
                    l1->val -= 10;
                    cflag = true;
                }
                node->val = l1->val;
                if (l1->next != nullptr)
                {
                    if (cflag)
                    {
                        l1->next->val += 1;
                    }
                    node->next = addTwoNumbers(l1->next, nullptr);
                }
                else
                {
                    if (cflag)
                    {
                        node->next = new ListNode(1);
                    }
                }
            }
            else
            {
                bool cflag = false;
                if (((l2->val) / 10) > 0)
                {
                    l2->val -= 10;
                    cflag = true;
                }
                node->val = l2->val;
                if (l2->next != nullptr)
                {
                    if (cflag)
                    {
                        l2->next->val += 1;
                    }
                    node->next = addTwoNumbers(nullptr, l2->next);
                }
                else
                {
                    if (cflag)
                    {
                        node->next = new ListNode(1);
                    }
                }
            }
        }
        return node;
    }
};