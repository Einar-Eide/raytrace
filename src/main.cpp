#include <iostream>

#include "image_file.h"

/**
* @file
* @brief This is the main file!
*/

int main(){

    color c1(255,0,0);
    color c2(0,0,255);

    image_file img("test.ppm", 5, 5);

    while (!img.is_complete()) {
        img.write_pixel(c1);
        if (!img.is_complete()){
            img.write_pixel(c2);
        }
    }

    img.export_ppm();

    return 0;
}