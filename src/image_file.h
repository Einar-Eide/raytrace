#pragma once

#include <iostream>
#include <fstream>
#include <string>

#include "color.h"

/**
 * @file
 * @brief A class for handeling and holding the data for an image file
 */

class image_file{
public:

    /**
     * @param[in] name the name of the file
     * @param[in] w image width
     * @param[in] h image height
     */
    image_file(std::string name, int w, int h) : name(name), width{w}, height{h} {
        content = "P3\n\n" + std::to_string(width) +  " " + std::to_string(height) +  "\n255\n";
        path += name;
    }

    /**
     * @brief Write the next pixel to the file, left to write row by row
     * @param[in] c Color of the written pixel
     */
    void write_pixel(color c){
        if ( !is_complete() ) {
            content += c.bmp_text();
            pixel_write_counter++;
        } else {
            std::cerr << "ERROR: can not add pixel to completed image" << std::endl;
        }
    }

    /**
     * @brief Exports an .ppm image
     */
    void export_ppm(){
        output_file.open(path);

        if ( !output_file.is_open() ) {
            std::cerr << "Error: Could not open file: " << path << std::endl;
        } else {
            output_file << content;
            output_file.close();
            std::cout << name << " exported" << std::endl;
        }
    }

    /**
     * @return Number of pixels in the finnished image
     */
    int pixels() {
        return width * height;
    }

    /**
     * @return Count of pixels written to the image 
     */
    int pixel_write_count(){
        return pixel_write_counter;
    }

    /**
     * @return True if all pixels in the image are written
     */
    bool is_complete(){
        return pixels() == pixel_write_count();
    }

private:

    int width;
    int height;
    int pixel_write_counter = 0;

    std::string content;
    std::string name;
    std::string path = "../images/";
    std::ofstream output_file;
};