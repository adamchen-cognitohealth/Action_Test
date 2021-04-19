#ifndef MODEL_MENU_ATTR_H_
#define MODEL_MENU_ATTR_H_

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
#define MENU_LIST_SIZE							10

#define MENU_TITLE_SETTING						"Settings"
#define MENU_ITEMS_VOLUME 						"Volume"
#define MENU_ITEMS_BRIGHTNESS 					"Brightness"
#define MENU_ITEMS_LEAVE_TIME 					"Leave time"
#define MENU_ITEMS_REPOSITION_SETTING			"Reposition setting"
#define MENU_ITEMS_ALERT_LANGUAGE				"Alert language"
#define MENU_ITEMS_INTERFACE_LANGUAGE			"Interface language"
#define MENU_ITEMS_CABLE_ORIENTATION			"Cable orientation"
#define MENU_ITEMS_WIFI_INFO					"WiFi info"

#define MENU_TITLE_VOLUME 						"Settings- Volume"
#define MENU_ITEMS_VOLUME_MUTE					"Mute"				
#define MENU_ITEMS_VOLUME_NORMAL				"Normal"
#define MENU_ITEMS_VOLUME_LOUD					"Loud"

#define MENU_TITLE_BRIGHTNESS 					"Settings- Brightness"
#define MENU_ITEMS_BRIGHTNESS_OFF				"Off"
#define MENU_ITEMS_BRIGHTNESS_DIM				"Dim"
#define MENU_ITEMS_BRIGHTNESS_BRIGHT			"Bright"

#define MENU_TITLE_LEAVE_TIME 					"Settings- Leave time"
#define MENU_ITEMS_LEAVE_TIME_5					"5 mins"
#define MENU_ITEMS_LEAVE_TIME_10				"10 mins"
#define MENU_ITEMS_LEAVE_TIME_15				"15 mins"
#define MENU_ITEMS_LEAVE_TIME_20				"20 mins"
#define MENU_ITEMS_LEAVE_TIME_30				"30 mins"
#define MENU_ITEMS_LEAVE_TIME_60				"60 mins"

#define MENU_TITLE_REPOSITION_SETTING			"Settings- Reposition setting"
#define MENU_ITEMS_REPOSITION_SETTING_30		"30 mins"
#define MENU_ITEMS_REPOSITION_SETTING_60		"60 mins"
#define MENU_ITEMS_REPOSITION_SETTING_90		"90 mins"
#define MENU_ITEMS_REPOSITION_SETTING_120		"120 mins"

#define MENU_TITLE_ALERT_LANGUAGE				"Settings- Alert language"
#define MENU_ITEMS_ALERT_LANGUAGE_MUSIC			"Music"
#define MENU_ITEMS_ALERT_LANGUAGE_ENGLISH		"English"
#define MENU_ITEMS_ALERT_LANGUAGE_CHINESE		"Chinese"
#define MENU_ITEMS_ALERT_LANGUAGE_TAIWANESE		"Taiwanese"
#define MENU_ITEMS_ALERT_LANGUAGE_JAPANESE		"Japanese"
#define MENU_ITEMS_ALERT_LANGUAGE_SPANISH		"Spanish"

#define MENU_TITLE_INTERFACE_LANGUAGE			"Settings- Interface language"
#define MENU_ITEMS_INTERFACE_LANGUAGE_ENGLISH	"English"
#define MENU_ITEMS_INTERFACE_LANGUAGE_CHINESE	"Chinese"
#define MENU_ITEMS_INTERFACE_LANGUAGE_JAPANESE	"Taiwanese"
#define MENU_ITEMS_INTERFACE_LANGUAGE_SPANISH	"Spanish"

#define MENU_TITLE_CABLE_ORIENTATION			"Settings- Cable orientation"
#define MENU_ITEMS_CABLE_ORIENTATION_LEFT		"Left"		
#define MENU_ITEMS_CABLE_ORIENTATION_RIGHT		"Right"		


#define MENU_TITLE_WIFI_INFO					"Settings- WiFi info"


/**********************
 *      TYPEDEFS
 **********************/
typedef struct edge_menu_attr {
	char* title;
	char* items[MENU_LIST_SIZE];
	char* last_focused;
	lv_event_cb_t event_cb;
	struct edge_menu_attr* prev;
} edge_menu_attr_t;


/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/
edge_menu_attr_t menu_attr_default;
edge_menu_attr_t menu_attr_volume;
edge_menu_attr_t menu_attr_brightness;
edge_menu_attr_t menu_attr_leave_time;
edge_menu_attr_t menu_attr_reposition_setting;
edge_menu_attr_t menu_attr_alert_language;
edge_menu_attr_t menu_attr_interface_language;
edge_menu_attr_t menu_attr_cable_orientation;
edge_menu_attr_t menu_attr_wifi_info;

edge_menu_attr_t get_default_menu_attr(lv_event_cb_t event_cb);
edge_menu_attr_t get_menu_volume_attr(lv_event_cb_t event_cb);
edge_menu_attr_t get_menu_brightness_attr(lv_event_cb_t event_cb);
edge_menu_attr_t get_menu_leave_time_attr(lv_event_cb_t event_cb);
edge_menu_attr_t get_menu_reposition_setting_attr(lv_event_cb_t event_cb);
edge_menu_attr_t get_menu_alert_language_attr(lv_event_cb_t event_cb);
edge_menu_attr_t get_menu_interface_language_attr(lv_event_cb_t event_cb);
edge_menu_attr_t get_menu_cable_orientation_attr(lv_event_cb_t event_cb);

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* MODEL_MENU_ATTR_H_ */
