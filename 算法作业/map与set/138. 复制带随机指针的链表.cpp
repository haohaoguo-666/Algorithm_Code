//https://leetcode.cn/problems/copy-list-with-random-pointer/description/
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> copyNodemap;
        Node* cur = head;
        Node* copyhead,*copytail;
        copyhead = copytail = nullptr;
        while(cur)
        {
            Node* copy = new Node(cur->val);
            copyNodemap[cur] = copy;//将原链表的节点与新链表的节点进行key/value
            if(copytail == nullptr)
            {
                copytail = copyhead = copy;
            }
            else
            {
                copytail->next = copy;
                copytail = copytail->next;
            }

            cur = cur->next;
        }

        cur = head;
        Node* copy = copyhead;

        while(cur)
        {
            if(cur->random == nullptr)
            {
                copy->random = nullptr;
            }
            else
            {
                copy->random = copyNodemap[cur->random];//找到原链表的random节点对应的新链表的节点
            }

            cur = cur->next;
            copy = copy->next;
        }

        return copyhead;
    }
};