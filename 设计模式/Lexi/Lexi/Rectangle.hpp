//
//  Rectangle.hpp
//  Lexi
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>
#include "Glyph.hpp"

class Rectangle: public Glyph {
        
public:
    Rectangle(Rect r) {
        this->r = r;
    }
    
    // 表现
    void draw(Window *w) override {
        w->drawRect(r.x, r.y, r.width, r.height);
    }
    
};

#endif /* Rectangle_hpp */
