#include "edge_color.h"

bool is_same_color(lv_color_t color1, lv_color_t color2){
    return lv_color_to32(color1) == lv_color_to32(color2);
}