#pragma once

#include "vec3.h"

class camera{
public:

    camera() {
        positon.set(0,0,0);
        direction.set(0,0,1);
        folcal_length = 1;
        aspect_ratio = 16.0/9.0;

        screen_height = 200;
        screen_width = screen_height * aspect_ratio;

        screen_width_vec.set(1,0,0);
        screen_height_vec.set(0,-1,0);

        screen_width_step_vec = screen_width_vec / screen_width;
        screen_height_step_vec = screen_width_vec / screen_height;

        screen_width_vec = screen_width_vec * aspect_ratio;

        pixel_00 = (direction * folcal_length) - 0.5 * ( screen_width_vec + screen_height_vec - screen_width_step_vec - screen_height_step_vec);
    }

private:

    pos positon;
    vec3 direction;
    vec3 pixel_00;

    vec3 screen_width_vec;
    vec3 screen_height_vec;

    vec3 screen_width_step_vec;
    vec3 screen_height_step_vec;

    double folcal_length;
    double aspect_ratio;

    int screen_width;
    int screen_height;

};