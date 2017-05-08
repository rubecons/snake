/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ElementCorps.h"

namespace etats
{
ElementCorps::ElementCorps (){}
ElementCorps::~ElementCorps (){}
ElementCorps::ElementCorps (int i, int j, Direction orientation, bool visi): Element(i,j,orientation)
{
    visible=visi;
}

}