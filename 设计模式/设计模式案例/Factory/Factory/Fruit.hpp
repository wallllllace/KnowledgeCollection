//
//  Fruit.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef Fruit_hpp
#define Fruit_hpp

#include <stdio.h>
#include <string>

class Fruit {
public:
    virtual void eat() = 0;
    
    virtual ~Fruit() ;
};

#endif /* Fruit_hpp */
