class Node
{
public:
    int key;
    int value;
    Node *next;
    Node *back;

    Node(int data1, int data2)
    {
        key = data1;
        value = data2;
        next = nullptr;
        back = nullptr;
    }
};

class LRUCache
{
private:
    unordered_map<int, Node *> mpp;
    int capacity;
    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    void insertAfterHead(Node *node)
    {
        Node *nextNode = head->next;
        head->next = node;
        node->back = head;
        node->next = nextNode;
        nextNode->back = node;
    }

    void deleteNode(Node *node)
    {
        Node *prevNode = node->back;
        Node *nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->back = prevNode;
    }

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        mpp.clear();
        head->next = tail;
        tail->back = head;
    }

    int get(int key)
    {
        if (!mpp.count(key))
            return -1;

        Node *node = mpp[key];
        deleteNode(node);
        insertAfterHead(node);
        return node->value;
    }

    void put(int key, int value)
    {
        if (mpp.count(key))
        {
            Node *node = mpp[key];
            deleteNode(node);
            node->value = value;
            insertAfterHead(node);
        }
        else
        {
            if (mpp.size() == capacity)
            {
                Node *delNode = tail->back;
                mpp.erase(delNode->key);
                deleteNode(delNode);
            }
            Node *newNode = new Node(key, value);
            mpp[key] = newNode;
            insertAfterHead(newNode);
        }
    }
};
