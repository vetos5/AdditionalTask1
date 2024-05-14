#pragma once

#include <iostream>

using namespace std;

template<typename T>
class ListNode {
public:
    T data;
    ListNode<T> *next;

    explicit ListNode(T value) : data(value), next(nullptr) {}

};

template<typename T>
class [[maybe_unused]] LinkedList {
private:
    ListNode<T> *head;
    ListNode<T> *tail;
public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    void push_front(T value) {
        auto *newNode = new ListNode<T>(value);
        newNode->next = head;
        head = newNode;
        if (!tail) {
            tail = head;
        }
    }

    void push_back(T value) {
        auto *newNode = new ListNode<T>(value);
        if (!head) {
            head = newNode;
            tail = head;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void pop_front() {
        if (head) {
            ListNode<T> *temp = head;
            head = head->next;
            if (!head) {
                tail = nullptr;
            }
            delete temp;
        } else {
            throw out_of_range("List is empty");
        }
    }

    [[maybe_unused]] void pop_back() {
        if (head) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            } else {
                ListNode<T> *current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                delete tail;
                tail = current;
                tail->next = nullptr;
            }
        } else {
            throw out_of_range("List is empty");
        }
    }

    [[maybe_unused]] void insert(int index, T value) {
        if (index < 0 or index > size()) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            push_front(value);
        } else if (index == size()) {
            push_back(value);
        } else {
            auto *newNode = new ListNode<T>(value);
            ListNode<T> *current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
        }
    }

    [[maybe_unused]] void remove(int index) {
        if (index < 0 or index >= size()) {
            throw out_of_range("Index out of range");
        }

        if (index == 0) {
            pop_front();
        } else {
            ListNode<T> *current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            ListNode<T> *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    [[maybe_unused]] void clear() {
        while (head) {
            ListNode<T> *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }


    template<typename Func>
    [[maybe_unused]] void foreach(Func func) const {
        ListNode<T> *current = head;
        while (current) {
            func(current->data);
            current = current->next;
        }
    }


    [[nodiscard]] int size() const {
        int count = 0;
        ListNode<T> *current = head;
        while (current) {
            ++count;
            current = current->next;
        }
        return count;
    }

    [[maybe_unused]] void print() const {
        ListNode<T> *current = head;
        while (current) {
            cout << *(current->data) << " ";
            current = current->next;
            cout << endl;
        }
        cout << endl;
    }

    [[maybe_unused]] ListNode<T> *getHead() const {
        return head;
    }

    [[maybe_unused]] ListNode<T> *getTail() const {
        return tail;
    }

    [[maybe_unused]] [[nodiscard]] bool empty() const {
        return head == nullptr;
    }

    T &operator[](int index) {
        ListNode<T> *current = head;
        int count = 0;
        while (current) {
            if (count == index) {
                return current->data;
            }
            current = current->next;
            count++;

        }
        cerr << "Index out of range: " << index << endl;
        return head->data;
    }


    class Iterator {
    private:
        ListNode<T> *current;
    public:
        explicit Iterator(ListNode<T> *node) : current(node) {}

        bool operator==(const Iterator &other) const {
            return current == other.current;
        }

        bool operator!=(const Iterator &other) const {
            return !(*this == other);
        }

        Iterator &operator++() {
            current = current->next;
            return *this;
        }

        T &operator*() const {
            return current->data;
        }
    };

    Iterator begin() const {
        return Iterator(head);
    }

    Iterator end() const {
        return Iterator(nullptr);
    }

    ~LinkedList() {
        while (head) {
            ListNode<T> *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
    }
};