#ifndef LINKED_LIST

template <typename T> class Node {
    private:
        T data;
        Node<T>* next;
        template<typename U>friend class LinkedList;
    public:
        Node() {
            this->next = nullptr;
        }

        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }

        Node(T data, Node* next) {
            this->data = data;
            this->next = next;
        }
};

template <typename T> class LinkedList {
    public:
        class Iterator;

    private:
        Node<T>* head;
        Node<T>* tail;
        Node<T>* cur;
        int length;
    
    private:
        void goTo(int index) {
            if(index >= this->length) {
                this->cur = tail;
                return;
            }

            Node<T>* walker = this->head;
            for(int i = 0; i < index; i++) {
                walker = walker->next;
            }
            this->cur = walker;
        }

    public:
        LinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
            this->cur = nullptr;
            this->length = 0;
        }

        ~LinkedList() {
            Node<T>* walker = this->head;
            while(walker != nullptr) {
                Node<T>*next = walker->next;
                delete walker;
                walker = next;
            }
        }

        Iterator begin() {
            return Iterator(this->head);
        }

        Iterator end() {
            return Iterator(this->tail->next);
        }

        void push_back(T item) {
            Node<T>* init = new Node<T>;
            init->data = item;
            
            if(this->length == 0) {
                this->head = init;
                this->tail = init;
                this->cur = init;
            } else {
                this->tail->next = init;
                tail = init;
            }

            this->length++;
        }

        int size() {
            return this->length;
        }

        void push_front(T item) {
            Node<T>* init = new Node<T>(item);

            if(this->length == 0) {
                this->head = init;
                this->tail = init;
                this->cur = init;
            } else {
                init->next = this->head;
                this->head = init;
            }

            this->length++;
        }

        void pop_back() {
            Node<T>* walker = this->head;
            this->goTo(this->length - 2);
            this->cur->next = nullptr;
            delete this->tail;
            this->tail = cur;
            this->length--;
        }

        void pop_front() {
            Node<T>* walker = this->head;
            this->goTo(1);
            this->head->next = nullptr;
            delete this->head;
            this->head = cur;
            this->length--;
        }

        void insert(T data, int index) {
            if(index == 0) {
                this->push_front(data);
            } else if(index == this->length) {
                this->push_back(data);
            } else if(index > 0 && index < length) {
                this->goTo(index - 1);
                Node<T>* init = new Node<T>(data);
                init->next = this->cur->next;
                this->cur->next = init;
                this->length++;
            } else {
                try {
                    throw std::invalid_argument("Index is invalid!");
                }
                catch(const std::invalid_argument& exception) {
                    std::cout << "Index is invalid!\n";
                }
            }
        }

        T back() {
            return this->tail->data;
        }

        T front() {
            return this->head->data;
        }

        bool empty() {
            return this->length == 0;
        }

        void merge(const LinkedList<T> &another) {
            Node<T> *walker = another.head;
            while(walker != nullptr) {
                this->push_back(walker->data);
                walker = walker->next;
            }
        }

        void print() {
            Node<T>* walker = this->head;
            while(walker != nullptr) {
                walker == this->head ? std::cout << walker->data : std::cout << " " << walker->data;
                walker = walker->next;
            }
        }

        void sort() {
            Node<T>* walker = this->head;
            Node<T>* next = nullptr;
            
            if(this->head == nullptr) {
                return;
            }

            while(walker != nullptr) {
                next = walker->next;
                while (next != nullptr)
                {
                    if(walker->data > next->data) {
                        T temp = walker->data;
                        walker->data = next->data;
                        next->data = temp;
                    }
                    next = next->next;
                }
                walker = walker->next;
            }
        }

        void reserve() {
            Node<T>* walker = this->head;
            Node<T>* prev = nullptr;
            Node<T>* next = nullptr;
            while(walker != nullptr) {
                next = walker->next;
                walker->next = prev;
                prev = walker;
                walker = next;
            }

            swap(this->head, this->tail);
        }

        class Iterator {
            private:
                Node<T>* pointer;
            public:
                Iterator() {
                    this->pointer = nullptr;
                }

                Iterator(Node<T>* pointer) {
                    this->pointer = pointer;
                }

                Iterator& operator=(const Iterator &another) {
                    this->pointer = another.pointer;
                    return *this;
                }

                Iterator& operator++() {
                    if(this->pointer) {
                        this->pointer = this->pointer->next;
                    }
                    return *this;
                }

                Iterator operator++(int) {
                    Iterator iterator = *this;
                    ++*this;
                    return iterator;
                }

                bool operator!=(const Iterator& another) {
                    return this->pointer != another.pointer;
                }

                T operator*() {
                    return this->pointer->data;
                }
        };
};

#endif 