//
//  main.cpp
//  Factory
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#include <iostream>
#include "Fruit.hpp"
#include "FruitFactory.hpp"

#include "AppleFactory.hpp"
#include "OrangeFactory.hpp"
#include "PearFactory.hpp"


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    /*
     Fruit *apple = FruitFactory::createFruit(Apple);
     apple->eat();
     delete apple;
     
     Fruit *orange = FruitFactory::createFruit(Orange);
     orange->eat();
     delete orange;
     
     Fruit *pear = FruitFactory::createFruit(Pear);
     pear->eat();
     delete pear;
     */
    
    FruitFactory *appleFactory = new AppleFactory();
    Fruit *apple = appleFactory->createFruit();
    apple->eat();
    delete appleFactory;
    delete apple;
    
    FruitFactory *orangeFactory = new OrangeFactory();
    Fruit *orange = orangeFactory->createFruit();
    orange->eat();
    delete orangeFactory;
    delete orange;
    
    FruitFactory *pearFactory = new PearFactory();
    Fruit *pear = pearFactory->createFruit();
    pear->eat();
    delete pearFactory;
    delete pear;
    
    
    return 0;
}
