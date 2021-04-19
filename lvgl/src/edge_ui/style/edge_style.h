#ifndef EDGE_STYLE_H_
#define EDGE_STYLE_H_

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


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/
lv_style_t home_scr_style;
lv_style_t home_title_style;
lv_style_t home_counter_style;
lv_style_t menu_btn_style;

void edge_style_init(void);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* EDGE_STYLE_H_ */