//
//  AppleFactory.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef AppleFactory_hpp
#define AppleFactory_hpp

#include <stdio.h>
#include "FruitFactory.hpp"
#include "AppleFruit.hpp"

class AppleFactory: public FruitFactory {
    
public:
    Fruit * createFruit() override {
        return new AppleFruit();
    }
};

#endif /* AppleFactory_hpp */
