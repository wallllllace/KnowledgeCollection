//
//  Glyph.hpp
//  Lexi
//
//  Created by wangxiaorui19 on 2022/9/18.
//

#ifndef Glyph_hpp
#define Glyph_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "Window.hpp"
#include "PrefixHeader.hpp"

class Glyph {
protected:
    Rect r;
    std::vector<Glyph *> children;
    
public:
    Glyph *parent;

    virtual void draw(Window*);
    
    void bounds(Rect& r) {
        r = this->r;
    }
    
    // 点击检测
    bool intersects(const Point& p) {
        if (p.x >= r.x && p.x <= r.x + r.width && p.y >= r.y && p.y <= r.y + r.height) {
            return true;
        }
        return false;
    }
    
    // 结构
    void insert(Glyph *g, int index) {
        g->parent = this;
        children.insert(children.begin() + index, g);
    }
    void remove(Glyph *g) {
        std::vector<Glyph *>::iterator it = children.begin();
        while (it != children.end()) {
            if (*it == g) {
                break;
            }
        }
        children.erase(it);
    }
    
    Glyph* child(int index) {
        return children[index];
    }
};

#endif /* Glyph_hpp */
