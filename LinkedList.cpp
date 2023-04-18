#include <iostream>

struct LinkedList {
     int data;
     LinkedList* next;
};

void print(LinkedList* head, int n) {
    auto tmp = head;
    for (int i = 0; i < n; ++i) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

LinkedList* add_node (int data, LinkedList * const head){
    return new LinkedList{data, head};
}

LinkedList* insert_after(LinkedList* const current, int data) {
    if (current != nullptr) {
        LinkedList* new_node = add_node(data, current->next);
        current->next = new_node;
        return new_node;
    }
    else {
        LinkedList* new_node = add_node(data, nullptr);
        return new_node;
    }
}

LinkedList* remove_after(LinkedList * const current) {
    if (current != nullptr) {
        LinkedList* const tmp = current->next->next;
        delete[] current->next;
        current->next = tmp;
        return tmp;
    }
    else {
        return nullptr;
    }
}

void erase(LinkedList * const head) {
    auto i = head;
    while (i != nullptr) {
        auto tmp = i->next;
        delete [] i;
        i = tmp;
    }
}

LinkedList* reverse_rec(LinkedList * const head, LinkedList * prev = nullptr) {
    auto curr = head;
    auto next = head->next;
    head->next = prev;
    prev = curr;
    if (next == nullptr) {
        return curr;
    }
    reverse_rec(next, prev);
}

LinkedList* reverse_itr(LinkedList* head) {
    auto next = head->next;
    LinkedList * prev = head;
    head->next = nullptr;
    head = next;
    while (next != nullptr) {
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

LinkedList* new_list(int n) {
    LinkedList* head = add_node (0, nullptr);
    for (int i = 1; i < n; i++) {
        head = add_node (i, head);
    }
    return head;
}

int main() {
    LinkedList* head = new_list(5);
    print(head, 5);
    head = reverse_rec(head);
    print(head, 5);
    return 0;
}
