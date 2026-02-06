#include <string>

/**
 * @file
 * @brief A class for holding rgb colors
 */

class color{
public:
    color(int r, int g, int b): red{r}, green{g}, blue{b} {}

    /**
     * @return The red intensity
     */
    int r(){
        return red;
    }

    /**
     * @return The green intensity
     */
    int g(){
        return green;
    }

    /**
     * @return The blue intensity
     */
    int b(){
        return blue;
    }

    /**
     * @return Color as a string on the format: "red, green, blue" with a lineshift (\\n) at the end
     */
    std::string bmp_text(){
        return std::to_string(red) + ' ' + std::to_string(green) + ' ' + std::to_string(blue) + '\n';
    }

private:
    int red;
    int green;
    int blue;

};