/**
 * @file lv_fs_if.h
 *
 */

#ifndef LV_FS_IF_H
#define LV_FS_IF_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "../../lvgl.h"

#if LV_USE_FS_IF

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Register driver(s) for the File system interface
 */
void lv_port_fs_init(void);
void my_lvgl_fs_test(void);

/**********************
 *      MACROS
 **********************/

#endif	/*LV_USE_FS_IF*/

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /*LV_FS_IF_H*/

