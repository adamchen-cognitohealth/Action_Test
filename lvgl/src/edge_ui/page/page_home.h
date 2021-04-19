#ifndef PAGE_HOME_H_
#define PAGE_HOME_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
// #include <string.h>
#include "../../lvgl.h"
#include "../model/model_home_attr.h"
#include "../porting/lv_port_indev.h"
#include "../style/edge_color.h"
#include "../style/edge_style.h"
#include "page_menu.h"
#include "widget_bottom_bar.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
typedef struct edge_home_obj {
	lv_group_t* group;
	lv_obj_t* this_page;
	lv_obj_t* label;
	lv_obj_t* counter;
	lv_obj_t* image;
	edge_home_attr_t* attr;
} edge_home_obj_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/
edge_menu_obj_t edge_menu_obj;
edge_home_obj_t edge_home_obj;

edge_home_obj_t edge_home_page_create(void);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* PAGE_HOME_H_ */