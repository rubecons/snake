/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Element.h"

namespace etats
{
    Element::Element ()
    {}
    
    Element::Element (int i, int j, Direction orientation)
    {
        this->i=i;
        this->j=j;
        this->orientation=orientation;
    }
    
    Element::~Element ()
    {}
    
}