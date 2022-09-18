//
//  PearFruit.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef PearFruit_hpp
#define PearFruit_hpp

#include <stdio.h>
#include "Fruit.hpp"

class PearFruit: public Fruit {
public:
    void eat() override {
        printf("eat pear\n");
    }
    ~PearFruit() override {
        printf("析构PearFruit\n");
    }
};

#endif /* PearFruit_hpp */
