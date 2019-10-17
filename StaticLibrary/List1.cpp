//
// Created by vladead on 15.10.2019.
//

#include <iostream>
#include <stdexcept>
#include "List1.h"

List1::List1() : head(nullptr), current(nullptr), tail(nullptr) {

}

List1::~List1() {
    if (!this->isEmpty()) {
        Node *temp;

        while (head) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
}

void List1::push_back(int value) {
    try {
        auto temp = new Node;

        if (head != nullptr) {
            tail->next = temp;
            tail = temp;
            tail->next = nullptr;
        } else {
            head = tail = temp;
        }
        this->tail->value = value;
    }
    catch (const std::bad_alloc &) {
        std::cerr << "Something bad happened with memory allocation " << std::endl;
        exit(-1);
    }
}

void List1::push_back(List1 &list) {
    tail->next = list.head;
    tail = list.tail;
    list.head = nullptr;
    list.tail = nullptr;
}

void List1::push_front(int value) {
    try {
        auto temp = new Node;

        if (head != nullptr) {
            temp->next = head;
            head = temp;
        } else {
            head = tail = temp;
        }
        this->head->value = value;
    }
    catch (const std::bad_alloc &) {
        std::cerr << "Something bad happened with memory allocation " << std::endl;
        exit(-1);
    }
}

void List1::pop_back() {
    if (this->isEmpty()) {
        try {
            throw std::runtime_error("There is nothing to delete");
        }
        catch (const std::runtime_error &) {
            std::cerr << "There is nothing to delete" << std::endl;
            exit(-1);
        }
    }

    current = head;

    if (this->get_size() > 1) {
        while (current->next != tail) {
            current = current->next;
        }

        delete tail;
        tail = current;
        tail->next = nullptr;
    } else {
        delete head;
        head = nullptr;
        current = nullptr;
        tail = nullptr;
    }
}

void List1::pop_front() {
    if (this->isEmpty()) {
        try {
            throw std::runtime_error("There is nothing to delete");
        }
        catch (const std::runtime_error &) {
            std::cerr << "There is nothing to delete" << std::endl;
            exit(-1);
        }
    }

    current = head->next;
    delete head;
    head = current;
}

void List1::insert(size_t indexOfElement, int value) {
    if (indexOfElement > this->get_size() - 1) {
        throw std::range_error("The index is out of range");
    }

    try {
        auto temp = new Node;

        current = head;
        if (indexOfElement != 0) {
            for (size_t i = 0; i < indexOfElement - 1; i++) {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
            current->next->value = value;
        }
        if (indexOfElement == 0) {
            temp->next = head;
            head = temp;
            head->value = value;
        }


    }
    catch (const std::bad_alloc &) {
        std::cerr << "Something bad happened with memory allocation " << std::endl;
        exit(-1);
    }
    catch (const std::range_error &) {
        std::cerr << "The index is out of range " << std::endl;
        exit(-1);
    }
}

int List1::at(size_t indexOfElement) {
    if (indexOfElement > this->get_size() - 1) {
        try {
            throw std::range_error("The index is out of range");
        }
        catch (const std::range_error &) {
            std::cerr << "The index is out of range " << std::endl;
            exit(-1);
        }
    }

    int returnValue = 0;

    current = head;

    for (size_t i = 0; i < indexOfElement; i++) {
        current = current->next;
    }

    returnValue = current->value;

    return returnValue;
}

void List1::remove(size_t indexOfElement) {
    if (indexOfElement > this->get_size() - 1) {
        try {
            throw std::range_error("The index is out of range");
        }
        catch (const std::range_error &) {
            std::cerr << "The index is out of range " << std::endl;
            exit(-1);
        }
    }

    current = head;
    if (indexOfElement != 0) {
        for (size_t i = 0; i < indexOfElement - 1; i++) {
            current = current->next;
        }

        Node *temp;
        if (current->next->next != nullptr) {
            temp = current->next;
            current->next = temp->next;
            delete temp;
        } else {
            tail = current;
            delete current->next;
            tail->next = nullptr;
        }
    } else {
        current = head->next;
        delete head;
        head = current;
    }
}

size_t List1::get_size() noexcept {
    size_t sizeOfList = 1;

    auto temp = current;
    if (this->isEmpty()) {
        sizeOfList = 0;
    } else {
        current = head;
        while (current != tail) {
            sizeOfList++;
            current = current->next;
        }
    }
    current = temp;

    return sizeOfList;
}

void List1::print_to_console() noexcept {
    current = head;

    std::cout << std::endl;
    while (current != nullptr) {
        std::cout << current->value << std::endl;
        current = current->next;
    }
    std::cout << std::endl;
}

void List1::clear() noexcept {
    if (!this->isEmpty()) {
        Node *temp;

        while (head) {
            temp = head->next;
            delete head;
            head = temp;
        }
    }
}

void List1::set(size_t indexOfElement, int value) {
    if (indexOfElement > this->get_size() - 1) {
        try {
            throw std::range_error("The index is out of range");
        }
        catch (const std::range_error &) {
            std::cerr << "The index is out of range " << std::endl;
            exit(-1);
        }
    }

    current = head;
    for (size_t i = 0; i < indexOfElement; i++) {
        current = current->next;
    }
    current->value = value;
}

bool List1::isEmpty() noexcept {
    bool listIsEmpty;

    listIsEmpty = (head == nullptr);

    return listIsEmpty;
}
