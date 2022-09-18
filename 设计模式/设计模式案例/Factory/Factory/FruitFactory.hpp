//
//  FruitFactory.hpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef FruitFactory_hpp
#define FruitFactory_hpp

#include <stdio.h>
#include "Fruit.hpp"
#include "AppleFruit.hpp"
#include "OrangeFruit.hpp"
#include "PearFruit.hpp"

// 缺点：
// 1. 违背开闭原则，添加类型会修改创建方法和枚举
// 2. 违背单一职责原则，工厂创建方法创建了很多类，有很多逻辑

//typedef enum : int {
//    Apple = 1,
//    Orange,
//    Pear,
// 需要添加类型
//} FruitType;

//class FruitFactory {
//
//public:
//    static Fruit *createFruit(FruitType type) {
//        Fruit* fruit;
//        switch (type) {
//            case Apple:
//                fruit = new AppleFruit();
//                break;
//
//            case Orange:
//                fruit = new OrangeFruit();
//
//            case Pear:
//                fruit = new PearFruit();

//             取消添加处理...
//
//            default:
//                break;
//        }
//        return fruit;
//    }
//
//};

// 设计成抽象类，子类继承他实现各个具体类的工程类
class FruitFactory {
    
public:
    virtual Fruit *createFruit() = 0;
    
    virtual ~FruitFactory();
};

#endif /* FruitFactory_hpp */
