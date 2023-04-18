#include <iostream>

struct Boof {
    int data;
    Boof* next;
};

Boof* add_node (int data, Boof * const head){
    return new Boof{data, head};
}

void print(Boof* head, int n) {
    auto tmp = head;
    for (int i = 0; i < n; ++i) {
        std::cout << tmp->data << std::endl;
        tmp = tmp->next;
    }
}

void remove_after (Boof** head, Boof* ptr){
    auto h = ptr->next;
    ptr->next = ptr->next->next;
    delete h;
    *head = ptr->next;
}

Boof* Josephus(Boof* head, int size, int step){
    while (size > 1) {
        auto h = head;
        for (int i = 0; i < step - 2; ++i) {
            h = h->next;
        }
        remove_after(&head, h);
        size--;
    }
    return head;
}

Boof* new_list(int n) {
    Boof* head = add_node(n, nullptr);
    auto tmp = head;
    for (int i = 1; i < n; i++) {
        head = add_node(n - i, head);
    }
    tmp->next = head;
    return head;
}

int main() {
    Boof* head = Josephus(new_list(13), 13, 3);
    std::cout << head->data;
    return 0;
}


