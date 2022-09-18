//
//  PearFactory.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef PearFactory_hpp
#define PearFactory_hpp

#include <stdio.h>
#include "FruitFactory.hpp"
#include "PearFruit.hpp"

class PearFactory: public FruitFactory {
    
public:
    Fruit * createFruit() override {
        return new PearFruit();
    }
};

#endif /* PearFactory_hpp */
