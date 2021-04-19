#include "page_menu.h"

void clear_menu_obj(edge_menu_obj_t * obj){
    obj->prev_page = NULL;
    obj->this_page = NULL;
    obj->group = NULL;
    obj->label = NULL;
    obj->list = NULL;
    obj->attr = NULL;
}

/**********************
 * Navigation
 **********************/
static void items_event_handler(lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_SHORT_CLICKED) {
        const char* btn_text = lv_list_get_btn_text(obj);
        printf("Setting clicked: %s\n", btn_text);

        lv_event_send(edge_menu_obj.this_page, LV_EVENT_LEAVE, NULL);
    }
	else if (event == LV_EVENT_CANCEL){
		lv_event_send(edge_menu_obj.this_page, LV_EVENT_LEAVE, NULL);
	}
}

static void menu_event_handler(lv_obj_t* obj, lv_event_t event)
{
    if(event == LV_EVENT_SHORT_CLICKED) {
        const char* btn_text = lv_list_get_btn_text(obj);
        printf("Clicked: %s\n", btn_text);

        if(strcmp(btn_text, MENU_ITEMS_VOLUME)==0) {
        	menu_attr_volume = get_menu_volume_attr(items_event_handler);
       		edge_menu_obj.attr = &menu_attr_volume;

        	// TODO Setup according to settings
        	// edge_menu_obj.attr.last_focused = get_focused_by_setting(MENU_ITEMS_VOLUME);
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
        else if(strcmp(btn_text, MENU_ITEMS_BRIGHTNESS)==0) {
        	// TODO Setup according to settings
        	// edge_menu_obj.attr.last_focused = get_focused_by_setting(MENU_ITEMS_VOLUME);
        	menu_attr_brightness = get_menu_brightness_attr(items_event_handler);
        	edge_menu_obj.attr = &menu_attr_brightness;
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
        else if(strcmp(btn_text, MENU_ITEMS_LEAVE_TIME)==0) {
        	// TODO Setup according to settings
        	// edge_menu_obj.attr.last_focused = get_focused_by_setting(MENU_ITEMS_VOLUME);
        	menu_attr_leave_time = get_menu_leave_time_attr(items_event_handler);
        	edge_menu_obj.attr = &menu_attr_leave_time;
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
        else if(strcmp(btn_text, MENU_ITEMS_REPOSITION_SETTING)==0) {
        	// TODO Setup according to settings
        	// edge_menu_obj.attr.last_focused = get_focused_by_setting(MENU_ITEMS_VOLUME);
        	menu_attr_reposition_setting = get_menu_reposition_setting_attr(items_event_handler);
        	edge_menu_obj.attr = &menu_attr_reposition_setting;
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
        else if(strcmp(btn_text, MENU_ITEMS_ALERT_LANGUAGE)==0) {
        	// TODO Setup according to settings
        	// edge_menu_obj.attr.last_focused = get_focused_by_setting(MENU_ITEMS_VOLUME);
        	menu_attr_alert_language = get_menu_alert_language_attr(items_event_handler);
        	edge_menu_obj.attr = &menu_attr_alert_language;
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
        else if(strcmp(btn_text, MENU_ITEMS_INTERFACE_LANGUAGE)==0) {
        	// TODO Setup according to settings
        	// edge_menu_obj.attr.last_focused = get_focused_by_setting(MENU_ITEMS_VOLUME);
        	menu_attr_interface_language = get_menu_interface_language_attr(items_event_handler);
        	edge_menu_obj.attr = &menu_attr_interface_language;
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
        else if(strcmp(btn_text, MENU_ITEMS_CABLE_ORIENTATION)==0) {
        	// TODO Setup according to settings
        	// edge_menu_obj.attr.last_focused = get_focused_by_setting(MENU_ITEMS_VOLUME);
        	menu_attr_cable_orientation = get_menu_cable_orientation_attr(items_event_handler);
        	edge_menu_obj.attr = &menu_attr_cable_orientation;
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
        else if(strcmp(btn_text, MENU_ITEMS_WIFI_INFO)==0) {
        	// TODO
        	// edge_menu_obj.attr = get_menu_volume_attr(items_event_handler);
        	lv_event_send_refresh(edge_menu_obj.this_page);
        }
    }
	else if (event == LV_EVENT_CANCEL){
		lv_event_send(edge_menu_obj.this_page, LV_EVENT_LEAVE, NULL);
        lv_event_send_refresh(lv_scr_act());
	}
}

/**********************
 * Navigation
 **********************/
void back_to_home(){
	// Reset to parent group
	lv_group_t* parent_group = lv_obj_get_group(edge_menu_obj.prev_page);
    lv_indev_t* indev_keypad = get_indev();
    lv_indev_set_group(indev_keypad, parent_group);

    // Delete current page
    lv_obj_del(edge_menu_obj.this_page);
    clear_menu_obj(&edge_menu_obj);
}

// TODO: Can send data to make custom page while go back?
// It maybe can be adopted to focus specific group item.
// So as refresh_menu_page()
void menu_page_go_back(){
	if (edge_menu_obj.attr->prev == NULL){
		back_to_home();
	}
	else {
		edge_menu_obj.attr = edge_menu_obj.attr->prev;
		lv_event_send_refresh(edge_menu_obj.this_page);
	}
}

// Reload page by attr
void refresh_menu_page(){
	/* 1. Refresh Title */
	lv_label_set_text(edge_menu_obj.label, edge_menu_obj.attr->title);
	
	/* 2. Refresh List */
	// Clean list and group
	lv_list_clean(edge_menu_obj.list);
	lv_group_remove_all_objs(edge_menu_obj.group);
	if (edge_menu_obj.attr->items != NULL){
	    static lv_obj_t* list_btn;
	    for (size_t i = 0; i < MENU_LIST_SIZE; ++i) {
	        if(edge_menu_obj.attr->items[i] == NULL){
	            break;
	        }
	        list_btn = lv_list_add_btn(edge_menu_obj.list, NULL, edge_menu_obj.attr->items[i]);
	        lv_obj_set_event_cb(list_btn, edge_menu_obj.attr->event_cb);
	        lv_obj_add_style(list_btn, LV_BTN_PART_MAIN, &menu_btn_style);
	        lv_group_add_obj(edge_menu_obj.group ,list_btn);

	        if(edge_menu_obj.attr->items[i] == edge_menu_obj.attr->last_focused){
	        	lv_group_focus_obj(list_btn);
	        }
	    }
	}
}

static void menu_page_cb(lv_obj_t* obj, lv_event_t event){
	if(event == LV_EVENT_REFRESH){
		refresh_menu_page();	
	}
	else if (event == LV_EVENT_LEAVE){
		menu_page_go_back();
	}
}

static void list_group_focus_cb(lv_group_t* group)
{
    lv_obj_t* f = lv_group_get_focused(group);
    lv_list_focus(f, LV_ANIM_ON);
}

/**********************
 * Extern
 **********************/

// Create menu page(scr)
edge_menu_obj_t edge_menu_page_create(lv_obj_t* scr){
	/* Create button style */
	lv_style_set_bg_color(&menu_btn_style, LV_STATE_FOCUSED, LV_COLOR_BLACK);
	lv_style_set_text_color(&menu_btn_style, LV_STATE_FOCUSED, LV_COLOR_WHITE);
	lv_style_set_image_recolor(&menu_btn_style, LV_STATE_FOCUSED, LV_COLOR_WHITE);
	lv_style_set_bg_opa(&menu_btn_style, LV_STATE_FOCUSED, LV_OPA_COVER);
	lv_style_set_line_width(&menu_btn_style, LV_STATE_FOCUSED, 0);

	// 1. Setup
	lv_obj_t* menu_container = lv_cont_create(scr, NULL);
	lv_obj_set_size(menu_container, 320, 210);
    lv_obj_set_pos(menu_container, 0, 0);
    lv_obj_set_event_cb(menu_container, menu_page_cb);

	/* Make group scrollable */
	lv_group_t* menu_group = lv_group_create();
    lv_group_set_focus_cb(menu_group, list_group_focus_cb);
    lv_group_set_editing(menu_group, false);
    lv_indev_t* indev_keypad = get_indev();
    lv_indev_set_group(indev_keypad, menu_group);


    // 2. Create UI element
    /* Create a label */
    lv_obj_t* menu_label = lv_label_create(menu_container, NULL);
    lv_obj_set_size(menu_label, 310, 16);
    lv_obj_set_pos(menu_label, 10, 7);

    /* Create a list */
    lv_obj_t* menu_list = lv_list_create(menu_container, NULL);
    lv_obj_set_size(menu_list, 320, 180);
    lv_obj_set_pos(menu_list, 0, 30);
    lv_list_set_scrollbar_mode(menu_list, LV_SCROLLBAR_MODE_AUTO);

    // 3. Save as object
    menu_attr_default = get_default_menu_attr(menu_event_handler);
    edge_menu_obj.prev_page = scr;
    edge_menu_obj.this_page = menu_container;
    edge_menu_obj.group = menu_group;
    edge_menu_obj.label = menu_label;
    edge_menu_obj.list = menu_list;
    edge_menu_obj.attr = &menu_attr_default;

    return edge_menu_obj;
}