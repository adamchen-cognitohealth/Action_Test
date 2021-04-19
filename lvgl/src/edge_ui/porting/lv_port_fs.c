/**
 * @file lv_fs_if.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "lv_port_fs.h"

#if LV_USE_FS_IF

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
#if LV_FS_IF_FATFS != '\0'
void lv_fs_if_fatfs_init(void);
#endif

#if LV_FS_IF_PC != '\0'
void lv_fs_if_pc_init(void);
#endif

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * Register driver(s) for the File system interface
 */
void lv_port_fs_init(void)
{
#if LV_FS_IF_FATFS != '\0'
	lv_fs_if_fatfs_init();
#endif

#if LV_FS_IF_PC != '\0'
	lv_fs_if_pc_init();
#endif

}

/**********************
 *   STATIC FUNCTIONS
 **********************/
void my_lvgl_fs_test(void) 
{
	lv_fs_file_t lv_file;
  	lv_fs_res_t  lv_res;

  	lv_res = lv_fs_open( &lv_file, "F:/mnt/card/rgb888/mainpage_warning.bin", LV_FS_MODE_RD );
  	if ( lv_res != LV_FS_RES_OK ) {
    	printf( "LVGL FS open error. (%d)\n", lv_res );
  	} else 
  		printf( "LVGL FS open Ok\n" );
	lv_fs_close(&lv_file);
}


#endif
