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

// array-base queue
template <class T>
class arrQueue : class Queue<T>
{
private:
    int mSize;   // 存放队列的数组的大小
    int front;   // 表示队头所在位置的下标
    int rear;    // 表示队尾所在位置的下标
    T *qu；      // 存放类型为T的队列元素的数组
public :
    arrQueue(int size);
    ~arrQueue();
    void clear();
    bool enQueue(T item);
    bool deQueue(T &item);
    bool front(T &item);
};
