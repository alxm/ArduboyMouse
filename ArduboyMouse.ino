/*
    Copyright 2017 Alex Margarit <http://www.alxm.org/>
    ArduboyMouse - Use your Arduboy as a 2-button mouse!

    ArduboyMouse is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    ArduboyMouse is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with ArduboyMouse.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <Arduboy2.h>
#include <Mouse.h>

// Generate with `python3 ArduboyImage.py mouse.png mouse > mousegfx.h`
#include "mousegfx.h"

static Arduboy2 arduboy;

void setup()
{
    arduboy.begin();
    arduboy.setFrameRate(30);

    arduboy.drawBitmap(0, 0, gfx_mouse_data, gfx_mouse_w, gfx_mouse_h, WHITE);
    arduboy.display();

    Mouse.begin();
}

void loop()
{
    if(!arduboy.nextFrame()) {
        return;
    }

    #define MAX_SPEED  8
    #define ACCELERATE 1
    #define DECELERATE 2

    static signed char moveX = 0;
    static signed char moveY = 0;

    arduboy.pollButtons();

    if(arduboy.pressed(LEFT_BUTTON)) {
        moveX = max(moveX - ACCELERATE, -MAX_SPEED);
    } else if(arduboy.pressed(RIGHT_BUTTON)) {
        moveX = min(moveX + ACCELERATE, MAX_SPEED);
    } else if(moveX < 0) {
        moveX = min(moveX + DECELERATE, 0);
    } else if(moveX > 0) {
        moveX = max(moveX - DECELERATE, 0);
    }

    if(arduboy.pressed(UP_BUTTON)) {
        moveY = max(moveY - ACCELERATE, -MAX_SPEED);
    } else if(arduboy.pressed(DOWN_BUTTON)) {
        moveY = min(moveY + ACCELERATE, MAX_SPEED);
    } else if(moveY < 0) {
        moveY = min(moveY + DECELERATE, 0);
    } else if(moveY > 0) {
        moveY = max(moveY - DECELERATE, 0);
    }

    if(moveX != 0 || moveY != 0) {
        Mouse.move(moveX, moveY, 0);
    }

    if(arduboy.justPressed(A_BUTTON)) {
        Mouse.press(MOUSE_LEFT);
    } else if(arduboy.justReleased(A_BUTTON)) {
        Mouse.release(MOUSE_LEFT);
    }

    if(arduboy.justPressed(B_BUTTON)) {
        Mouse.press(MOUSE_RIGHT);
    } else if(arduboy.justReleased(B_BUTTON)) {
        Mouse.release(MOUSE_RIGHT);
    }
}
