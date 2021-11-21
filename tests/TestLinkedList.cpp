//
// Created by Andrei Nistor on 31.10.2021.
//

#include <gtest/gtest.h>
#include "LinkedList.hpp"
#include <iostream>

class LinkedListTest : public ::testing::Test {
protected:
    void SetUp() override {
        l.push_front(5);
        l.push_front(4);
        l.push_front(3);
        l.push_front(2);
        l.push_front(1);
    }

    LinkedList<int> l;
};

TEST_F(LinkedListTest, empty) {
    auto l = LinkedList<int>();

    EXPECT_EQ(l.empty(), true);

    l.push_front(1);

    EXPECT_EQ(l.empty(), false);
}

TEST_F(LinkedListTest, push_front) {
    auto l = LinkedList<int>();
    l.push_front(1);
    l.push_front(2);
    l.push_front(3);
}

TEST_F(LinkedListTest, front) {
    auto l = LinkedList<int>();
    l.push_front(10);

    EXPECT_EQ(l.front(), 10);

    l.front() = 20;

    EXPECT_EQ(l.front(), 20);
}


TEST_F(LinkedListTest, iterator_equality) {
    auto it = l.begin();
    EXPECT_EQ(it, l.begin());
}

TEST_F(LinkedListTest, iterator_pre_increment) {
    auto it = l.before_begin();
    EXPECT_EQ(*(++it), 1);
    EXPECT_EQ(*(++it), 2);
    EXPECT_EQ(*(++it), 3);
    EXPECT_EQ(*(++it), 4);
    EXPECT_EQ(*(++it), 5);
}

TEST_F(LinkedListTest, iterator_post_increment) {
    auto it = l.begin();
    EXPECT_EQ(*(it++), 1);
    EXPECT_EQ(*(it++), 2);
    EXPECT_EQ(*(it++), 3);
    EXPECT_EQ(*(it++), 4);
    EXPECT_EQ(*(it++), 5);
}
TEST_F(LinkedListTest, begin) {
    EXPECT_EQ(*l.begin(), 1);
}

TEST_F(LinkedListTest, end) {
    EXPECT_EQ(l.end(), LinkedList<int>::Iterator(nullptr));
}

TEST_F(LinkedListTest, insert_after) {
    auto it = l.before_begin();

    l.insert_after(it, 10);
    EXPECT_EQ(l.front(), 10);
}

TEST_F(LinkedListTest, erase_after) {
    auto it = l.begin();

    it = l.erase_after(it);
    EXPECT_EQ(*l.begin(), 1);
    EXPECT_EQ(*it, 3);
}

TEST_F(LinkedListTest, remove){
    l.remove(3);

    auto it = l.begin();
    EXPECT_EQ(*it++, 1);
    EXPECT_EQ(*it++, 2);
    EXPECT_EQ(*it++, 4);
    EXPECT_EQ(*it++, 5);
}

TEST_F(LinkedListTest, ostream) {
    std::stringstream ss;
    ss << l;
    EXPECT_EQ(ss.str(), "[ 1 -> 2 -> 3 -> 4 -> 5 ]");
}

