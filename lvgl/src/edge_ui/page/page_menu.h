#ifndef PAGE_MENU_H_
#define PAGE_MENU_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include <string.h>
#include "../../lvgl.h"
#include "../model/model_menu_attr.h"
#include "../porting/lv_port_indev.h"
#include "../style/edge_color.h"
#include "../style/edge_style.h"

/*********************
 *      DEFINES
 *********************/
#define EVENT_TASK_INTERVAL 10000

/**********************
 *      TYPEDEFS
 **********************/
typedef struct edge_menu_obj {
	lv_obj_t* prev_page;
	lv_obj_t* this_page;
	lv_group_t* group;
	lv_obj_t* label;
	lv_obj_t* list;
	edge_menu_attr_t* attr;
} edge_menu_obj_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/
edge_menu_obj_t edge_menu_obj;

edge_menu_obj_t edge_menu_page_create(lv_obj_t* scr);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* PAGE_MENU_H_ */