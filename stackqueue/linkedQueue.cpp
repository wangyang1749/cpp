template <class T>
class Queue
{
public:                         // 队列的运算集
    void clear();               // 变为空队列
    bool enQueue(const T item); // item入队，插入队尾，成功则返回真否则返回假
    bool deQueue(T item);       // 返回队头元素并从队列中删除，成功则返回真
    bool front(T *item);        // 返回队头元素，但不删除，成功则返回真
    bool isEmpty();             // 返回真，若队列已空
    bool isFull();              // 返回真，若队列已满
    void print();
};

template <class T>
class Link
{
public:
    T data;     // 用于保存结点元素的内容
    Link *next; // 指向后继结点的指针
    Link(const T info, Link *nextValue = NULL);
    Link(Link *nextValue = NULL);
};

template <class T>
class lnkQueue : public Queue<T>
{
private:
    int size;       // 队列中当前元素的个数
    Link<T> *front; // 表示队头的指针
    Link<T> *rear;  // 表示队尾的指针
public:             // 队列的运算集
    lnkQueue(int size);
    ~lnkQueue();
    void clear();
    bool enQueue(const T item);
    bool deQueue(T *item);
    bool getFront(T *item);
    void print();
};
