//
// Created by zaqaler.zhao on 2021/11/4.
//
#include <stdio.h>
#include <iostream>
#include "test.h"

typedef void (test::*handler_cb)(int a, int b);
typedef struct {
    int a;
    int b;
    handler_cb func;
}tableItem;

static tableItem table[4] = {
    { 1, 2, &test::handler1 },
    { 2, 3, &test::handler2 },
    { 3, 4, &test::handler3 },
    { 4, 5, &test::handler4 },
};


test::test(Handler* h)
{
    registerCb(std::bind(&Handler::Listen, h, std::placeholders::_1, std::placeholders::_2));
}

void test::handler1(int a, int b)
{
    printf("%d + %d = %d\n", a, b, a + b);
}

void test::handler2(int a, int b)
{
    printf("%d - %d = %d\n", a, b, a - b);
}

void test::handler3(int a, int b)
{
    printf("%d * %d = %d\n", a, b, a * b);
}

void test::handler4(int a, int b)
{
    printf("%d / %d = %d\n", a, b, a / b);
}

void test::handler()
{
    for (int i = 0; i < 4; ++i) {
        (this->*table[i].func)(table[i].a, table[i].b);
    }
}

void test::handlerCB(int a, int b)
{
    this->cb(a, b);
}