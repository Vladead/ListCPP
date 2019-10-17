//
// Created by vladead on 13.10.2019.
//

#include <gtest/gtest.h>
#include "List1.h"

class List1Fixture : public ::testing::Test {
public:
    ~List1Fixture() override {
        l1.clear();
    }

protected:
    void SetUp() override {
        l1.push_back(0);
        l1.push_back(1);
        l1.push_back(2);
        l1.push_back(3);
        l1.push_back(4);
    }

    List1 l1;
};


TEST_F(List1Fixture, push_back_value_test) {
    l1.push_back(38);
    ASSERT_EQ(38, l1.at(5));
    l1.pop_back();
}

TEST_F(List1Fixture, push_front_test) {
    l1.push_front(55);
    ASSERT_EQ(55, l1.at(0));
    l1.pop_front();
}

TEST_F(List1Fixture, pop_back_test) {
    l1.push_back(45);
    l1.pop_back();
    ASSERT_EQ(4, l1.at(4));
}

TEST_F(List1Fixture, pop_front_test) {
    l1.push_front(33);
    l1.pop_front();
    ASSERT_EQ(0,l1.at(0));
}

TEST_F(List1Fixture, insert_test) {
    l1.insert(0, 45);
    ASSERT_EQ(45, l1.at(0));
    l1.pop_front();
    ASSERT_EQ(0, l1.at(0));

    l1.insert(2, 45);
    ASSERT_EQ(45, l1.at(2));
    l1.remove(2);
    ASSERT_EQ(2, l1.at(2));
}

TEST_F(List1Fixture, at_test) {
    ASSERT_EQ(0, l1.at(0));
    ASSERT_EQ(1, l1.at(1));
    ASSERT_EQ(4, l1.at(4));
}

TEST_F(List1Fixture, remove_test) {
    l1.push_front(33);
    l1.remove(0);
    ASSERT_EQ(0, l1.at(0));
}

TEST_F(List1Fixture, get_size_test) {
    ASSERT_EQ(5, l1.get_size());
    ASSERT_NO_THROW(l1.get_size());
}

TEST_F(List1Fixture, print_to_console_test) {
    ASSERT_NO_THROW(l1.print_to_console());
}

TEST_F(List1Fixture, clear_test) {
    l1.clear();
    ASSERT_TRUE(l1.isEmpty());
    SetUp();
    ASSERT_NO_THROW(l1.clear());
}

TEST_F(List1Fixture, set_test) {
    l1.set(4, 5);
    ASSERT_EQ(5, l1.at(4));
}

TEST_F(List1Fixture, IsEmpty_test) {
    ASSERT_EQ(false, l1.isEmpty());
    ASSERT_FALSE(l1.isEmpty());
    ASSERT_NO_THROW(l1.isEmpty());
}

TEST_F(List1Fixture, push_back_list_test) {
    List1 l2;
    l2.push_back(3423);
    l2.push_back(1234534);
    l2.push_back(64536);
    l2.push_back(1234);

    l1.push_back(l2);
    ASSERT_EQ(3423, l1.at(5));
    ASSERT_EQ(1234534, l1.at(6));
    ASSERT_EQ(64536, l1.at(7));
    ASSERT_EQ(1234, l1.at(8));
}
