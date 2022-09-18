//
//  OrangeFruit.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef OrangeFruit_hpp
#define OrangeFruit_hpp

#include <stdio.h>
#include "Fruit.hpp"

class OrangeFruit: public Fruit {
    
public:
    void eat() override {
        printf("eat orange\n");
    }
    ~OrangeFruit() override {
        printf("析构OrangeFruit\n");
    }
};

#endif /* OrangeFruit_hpp */
