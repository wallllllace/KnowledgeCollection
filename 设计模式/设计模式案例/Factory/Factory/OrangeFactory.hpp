//
//  OrangeFactory.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef OrangeFactory_hpp
#define OrangeFactory_hpp

#include <stdio.h>
#include "FruitFactory.hpp"
#include "OrangeFruit.hpp"

class OrangeFactory: public FruitFactory {
    
public:
    Fruit * createFruit() override {
        return new OrangeFruit();
    }
};
#endif /* OrangeFactory_hpp */
