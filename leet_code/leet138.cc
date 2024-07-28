#include <unordered_map>
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
// offer上的标准解法还是要刷一下！！！！
class Solution
{
public:
    // hash 解法，主要是拷贝所有节点，然后random对应的新的节点位置，自然能确定下来
    Node *copyRandomList(Node *head)
    {
        std::unordered_map<Node *, Node *> hash;
        Node *cur = head;
        while (cur)
        {
            // hash.insert(cur, new Node(cur->val));
            hash[cur] = new Node(cur->val);
            cur = cur->next;
        }
        Node dummy(0);
        Node *pre = &dummy;
        cur = head;
        while (cur)
        {
            pre->next = hash.find(cur)->second;
            if (cur->random)
            {
                pre->next->random = hash.find(cur->random)->second;
            }
            pre = pre->next;
            cur = cur->next;
        }
        return dummy.next;
    }

    Node *copyRandomList2(Node *head)
    {
        Node *pre = head;
        while (pre)
        {
            Node *pnext = pre->next;
            // 断开
            pre->next = new Node(pre->val);
            // 连接
            pre->next->next = pnext;
            // 下一个
            pre = pnext;
        }
        // 然后建立连接
        pre = head;
        Node dummy(0);
        Node *pd = &dummy;
        while (pre)
        {
            // 一次跳2个节点

            Node *p_origin_next = pre->next ? pre->next->next : nullptr;
            // pd->next = pre->next;
            // random 的copy 都在下一个节点
            Node *new_node = pre->next;
            if (new_node && pre->random)
            {
                new_node->random = pre->random->next;
            }
            // pd = pd->next;
            pre = p_origin_next;
            // pre = p_origin_next;
        }
        pre = head;
        while (pre)
        {
            Node *p_origin_next = pre->next->next;
            pd->next = pre->next;
            pd = pd->next;
            pre->next = p_origin_next;
            pre = p_origin_next;
        }
        return dummy.next;
    }
};