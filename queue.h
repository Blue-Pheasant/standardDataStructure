#ifndef QUEUE
#define MAX_QUEUE 1000

template<typename T> class Queue {
    private:
        int front;
        int rear;
        int count;
        T queue[MAX_QUEUE];
    
    public:
        Queue() {
            this->count = 0;
            this->rear = MAX_QUEUE - 1;
            this->front = 0;
        }

        void append(const T &item) {
            this->rear = ((this->rear + 1) == MAX_QUEUE ? 0 : rear + 1);
            this->queue[this->rear] = item;
            this->count++;
        }

        void serve() {
            if(this->count <= 0) return;
            this->front = ((this->front + 1 == MAX_QUEUE ? 0 : front + 1));
            this->count--;
        }

        void clear() {
            this->count = 0;
            this->rear = MAX_QUEUE - 1;
            this->front = 0;
        }
        
        void print() {
            for(int i = this->rear; i >= this->front; i--) {
                i == this->rear ? std::cout << queue[i] : std::cout << " " << queue[i];
            }
        }

        int size() {
            return this->count;
        }

        bool empty() {
            return this->count == 0;
        }

};


#endif