//
// Created by Andrei Nistor on 31.10.2021.
//

#ifndef ALGORITMI_STRUCTURI_DATE_LINKEDLIST_HPP
#define ALGORITMI_STRUCTURI_DATE_LINKEDLIST_HPP

template<typename T>
class LinkedList {
public:
    class Iterator;

    LinkedList();

    Iterator before_begin();

    Iterator begin() const;

    Iterator end() const;

    bool empty();

    T &front();

    void push_front(T value);

    LinkedList<T>::Iterator insert_after(const Iterator &pos, const T value) {
        Node *n = new Node;
        n->data = value;
        n->next = pos.currentNode->next;
        pos.currentNode->next = n;

        return Iterator(n);
    }
    LinkedList<T>::Iterator erase_after(const Iterator &pos) {
        Node *n = pos.currentNode->next;
        pos.currentNode->next = n->next;
        delete n;
        return Iterator(pos.currentNode->next);
    }

    void remove(const T val) {
        for (auto it = this->before_begin(); it != this->end(); ++it) {
            auto t = it;
            t++;
            if (t != this->end()) {
                if (*t == val) {
                    this->erase_after(it);
                }
            }
        }
    }
private:
    struct Node;
    Node *head;
    Node *tail;
};

template<typename T>
struct LinkedList<T>::Node {
    friend class LinkedList<T>::Iterator;

    T data;
    Node *next;
};

template<typename T>
class LinkedList<T>::Iterator {
    friend class LinkedList;

public:
    Iterator(LinkedList::Node *node) : currentNode(node) {}

    T operator*() { return currentNode->data; }

    Iterator &operator++() {
        if (currentNode)
            currentNode = currentNode->next;
        return *this;
    }

    Iterator operator++(T) {
        Iterator iterator = *this;
        ++*this;
        return iterator;
    }

    bool operator==(const Iterator &other) const {
        return this->currentNode == other.currentNode;
    }
protected:
    LinkedList::Node *currentNode;
};

template<typename T>
void LinkedList<T>::push_front(T value) {
    auto n = new Node;

    n->data = value;
    n->next = head->next;
    head->next = n;
}

template<typename T>
LinkedList<T>::LinkedList() {
    head = new Node();
    tail = nullptr;
    head->next = tail;
}

template<typename T>
bool LinkedList<T>::empty() {
    return head->next == tail;
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::begin() const {
    return LinkedList::Iterator(head->next);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::before_begin() {
    return LinkedList::Iterator(head);
}

template<typename T>
typename LinkedList<T>::Iterator LinkedList<T>::end() const {
    return LinkedList::Iterator(tail);
}

template<typename T>
T &LinkedList<T>::front() {
    return head->next->data;
}

template <typename T>
std::ostream& operator<<(std::ostream& stream, const LinkedList<T> &ll) {
    std::string sep;

    stream << "[ ";
    for (auto it = ll.begin(); it != ll.end(); ++it) {
        stream << sep << *it;
        sep = " -> ";
    }
    stream << " ]";
    return stream;
}

#endif //ALGORITMI_STRUCTURI_DATE_LINKEDLIST_HPP
