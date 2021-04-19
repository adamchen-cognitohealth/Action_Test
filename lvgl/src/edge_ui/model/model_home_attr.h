#ifndef MODEL_HOME_ATTR_H_
#define MODEL_HOME_ATTR_H_

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "../../lvgl.h"
#include "../style/edge_color.h"

/*********************
 *      DEFINES
 *********************/
typedef enum {
	EDGE_EVENT_NOT_ON_BED 			= 200101,
	EDGE_EVENT_ON_BED 				= 200102,
	EDGE_EVENT_IMMOBILIZATION 		= 200103,
	EDGE_EVENT_STIRRING 			= 200104,
	EDGE_EVENT_SITTING_UP 			= 200105,
	EDGE_EVENT_LEAVING 				= 200106,
	EDGE_EVENT_OUT_OF_BED 			= 200107,
	EDGE_EVENT_RETURN 				= 200108, // On bed
	EDGE_EVENT_LEAVE_TOO_LONG 		= 200111,
	EDGE_EVENT_REPOSITION 			= 200201,
	EDGE_EVENT_REPOSITION_OFF 		= 200202,
	EDGE_EVENT_PAD_DISCONNECTED 	= 100102,
	EDGE_EVENT_PAD_REPLACED 		= 100103,
	EDGE_EVENT_PAD_DAMAGED 			= 100104,
	EDGE_EVENT_RES_DISCONNECTED 	= 100106,
	EDGE_EVENT_NURSE_MODE_ON 		= 100601,
	EDGE_EVENT_NURSE_MODE_OFF 		= 100602
} edge_event_t;

typedef enum {
	NORMAL_MODE,
	COUNTER_MODE,
	GRAY_COUNTER_MODE,
	ALERT_MODE,
	NURSE_MODE
} home_mode_t;


/**********************
 *      TYPEDEFS
 **********************/
typedef struct edge_home_attr {
	char* event_name;
	char* counter_value;
	char* img_src;
	home_mode_t mode;
	lv_color_t bg_color;
} edge_home_attr_t;

typedef edge_home_attr_t (*f_get_home_attr)(void);
/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/
edge_home_attr_t current_home_attr;

edge_home_attr_t get_home_attr_not_on_bed(void);
edge_home_attr_t get_home_attr_on_bed(void);
edge_home_attr_t get_home_attr_immobilization(void);
edge_home_attr_t get_home_attr_stirring(void);
edge_home_attr_t get_home_attr_sitting_up(void);
edge_home_attr_t get_home_attr_leaving(void);
edge_home_attr_t get_home_attr_out_of_bed(void);
edge_home_attr_t get_home_attr_return(void);
edge_home_attr_t get_home_attr_leave_too_long(void);
edge_home_attr_t get_home_attr_reposition(void);
edge_home_attr_t get_home_attr_reposition_off(void);
edge_home_attr_t get_home_attr_pad_disconnected(void);
edge_home_attr_t get_home_attr_pad_replaced(void);
edge_home_attr_t get_home_attr_pad_damaged(void);
edge_home_attr_t get_home_attr_res_disconnected(void);
edge_home_attr_t get_home_attr_nurse_mode_on(void);
edge_home_attr_t get_home_attr_nurse_mode_off(void);


#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MODEL_HOME_ATTR_H_ */
