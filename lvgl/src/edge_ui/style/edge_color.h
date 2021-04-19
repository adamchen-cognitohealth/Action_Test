#ifndef EDGE_COLOR_H_
#define EDGE_COLOR_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../lvgl.h"

/*********************
 *      DEFINES
 *********************/
#define EDGE_COLOR_WHITE		LV_COLOR_MAKE(0xED, 0xF1, 0xF9)
#define EDGE_COLOR_GRAY			LV_COLOR_MAKE(0x55, 0x55, 0x55)
#define EDGE_COLOR_RED			LV_COLOR_MAKE(0xEE, 0x45, 0x32)
#define EDGE_COLOR_GREEN		LV_COLOR_MAKE(0x26, 0xB3, 0x34)
#define EDGE_COLOR_YELLOW		LV_COLOR_MAKE(0xF6, 0xB0, 0x00)
#define EDGE_COLOR_PURPLE		LV_COLOR_MAKE(0x3C, 0x01, 0x78)
#define EDGE_COLOR_BLUE			LV_COLOR_MAKE(0x46, 0x33, 0xBD)
#define EDGE_COLOR_LIGHT_BLUE	LV_COLOR_MAKE(0x94, 0xAB, 0xDB)
#define EDGE_COLOR_ROYAL_BLUE	LV_COLOR_MAKE(0x00, 0x71, 0xBC)

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/
bool is_same_color(lv_color_t color1, lv_color_t color2);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* EDGE_COLOR_H_ */