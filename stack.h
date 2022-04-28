#ifndef STACK

#define MAX_STACK 1000

template<typename T> class Stack {
    private:
        int count;
        T stack[MAX_STACK];
    public:
        Stack() {
            this->count = 0;
        }

        bool empty() {
            return this->count == 0;
        }

        void push(const T &item) {
            this->stack[this->count] = item;
            this->count++;
        }

        void pop() {
            this->count--;
        }

        T top() {
            return this->stack[this->count - 1];
        }

        void clear() {
            this->count = 0;
        }

        void print() {
            for(int i = this->count - 1; i > 0; i--) {
                i == this->count - 1 ? std::cout << this->stack[i] : std::cout << '\n' << this->stack[i];
            }
        }
};

#endif 