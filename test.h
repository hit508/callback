//
// Created by zaqaler.zhao on 2021/11/4.
//

#ifndef UNTITLED_TEST_H
#define UNTITLED_TEST_H
#include <functional>

class Handler {
public:
    void Listen(int a, int b) {
        std::cout << a << b << std::endl;
    }
};

class test {
    typedef std::function<void(int a, int b)> callback;
public:
    test(Handler* h);
    virtual ~test() {}

    void handler1(int a, int b);
    void handler4(int a, int b);
    void handler2(int a, int b);
    void handler3(int a, int b);
    void handler();

    void registerCb(callback cb) {
        this->cb = std::move(cb);
    }
    void handlerCB(int a, int b);
private:
    callback cb;
};


#endif //UNTITLED_TEST_H
