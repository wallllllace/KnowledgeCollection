//
//  AppleFruit.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef AppleFruit_hpp
#define AppleFruit_hpp

#include <stdio.h>
#include "Fruit.hpp"

class AppleFruit: public Fruit {

public:
    void eat() override {
        printf("eat apple\n");
    }
    
    ~AppleFruit() override {
        printf("析构AppleFruit\n");
    }
};

#endif /* AppleFruit_hpp */
