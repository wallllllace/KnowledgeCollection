//
//  Character.hpp
//  Lexi
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include "Glyph.hpp"
#include <vector>

class Character: public Glyph {
private:
    char c;
        
public:
    Character(char c): c(c){
        r = {0, 0, 2, 3};
    }
    // 表现
    void draw(Window *w) override {
        w->drawCharacter(c);
    }
    
};

#endif /* Character_hpp */
