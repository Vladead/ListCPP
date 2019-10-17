//
// Created by vladead on 15.10.2019.
//

#ifndef PROGRAM1_NODE_H
#define PROGRAM1_NODE_H


class Node {
private:
    int value;
    Node *next;
public:
    Node();

    ~Node();

    friend class List1;
};


#endif //PROGRAM1_NODE_H
