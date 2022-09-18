//
//  Row.hpp
//  Lexi
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef Row_hpp
#define Row_hpp

#include <stdio.h>
#include "Glyph.hpp"

class Row: public Glyph {
    
public:
//    Row(Rect r) {
//        this->r = r;
//    }
    
    // 表现
    void draw(Window *w) override {
        for (auto g : this->children) {
            g->draw(w);
        }
    }
};

#endif /* Row_hpp */
