#include "page_home.h"

uint8_t num = 0; 

static void event_task_cb(lv_task_t* task) {
    // TODO 抽換成TCP Server即可
    f_get_home_attr f[17] = {
        &get_home_attr_not_on_bed, 
        &get_home_attr_on_bed,
        &get_home_attr_immobilization,
        &get_home_attr_stirring,
        &get_home_attr_sitting_up,
        &get_home_attr_leaving,
        &get_home_attr_out_of_bed,
        &get_home_attr_return,
        &get_home_attr_leave_too_long,
        &get_home_attr_reposition,
        &get_home_attr_reposition_off,
        &get_home_attr_pad_disconnected,
        &get_home_attr_pad_replaced,
        &get_home_attr_pad_damaged,
        &get_home_attr_res_disconnected,
        &get_home_attr_nurse_mode_on,
        &get_home_attr_nurse_mode_off
    };

    edge_home_attr_t *event = (edge_home_attr_t*)task->user_data;
    *event = f[num]();
    num = num + 1;

    if(edge_menu_obj.this_page !=NULL){
        edge_menu_obj.attr->prev = NULL;
        lv_event_send(edge_menu_obj.this_page, LV_EVENT_LEAVE, NULL);
    }
    lv_event_send_refresh(lv_scr_act());

    if(num == 16)
        num = 0;
}

/**********************
 * Navigation
 **********************/

void go_to_menu_page(){
    lv_style_set_bg_color(&home_scr_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
    lv_style_set_text_color(&home_scr_style, LV_STATE_DEFAULT, EDGE_COLOR_GRAY);
    lv_obj_add_style(edge_home_obj.this_page, LV_OBJ_PART_MAIN, &home_scr_style);  

    /* Create a menu container */
    edge_menu_obj = edge_menu_page_create(edge_home_obj.this_page);
    lv_event_send_refresh(edge_menu_obj.this_page);
}

// Refresh page by attr
void refresh_home_page(){
	/* 1. Refresh widget*/
    // Background (Only change style when focus this page)
    if(edge_menu_obj.this_page == NULL){
        lv_style_set_bg_color(&home_scr_style, LV_STATE_DEFAULT, edge_home_obj.attr->bg_color);

        if(is_same_color(edge_home_obj.attr->bg_color, EDGE_COLOR_WHITE)){
            lv_style_set_text_color(&home_scr_style, LV_STATE_DEFAULT, EDGE_COLOR_GRAY);
        } else {
            lv_style_set_text_color(&home_scr_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
        }
        lv_obj_add_style(edge_home_obj.this_page, LV_OBJ_PART_MAIN, &home_scr_style);  


        // Title
        lv_label_set_text(edge_home_obj.label, edge_home_obj.attr->event_name);

        if(edge_home_obj.attr->mode == NORMAL_MODE || edge_home_obj.attr->mode == COUNTER_MODE){
            lv_obj_align(edge_home_obj.label, NULL, LV_ALIGN_CENTER, 0, -60);
            lv_style_set_text_font(&home_title_style, LV_STATE_DEFAULT, &lv_font_montserrat_42);
            lv_style_set_text_opa(&home_title_style, LV_STATE_DEFAULT, LV_OPA_COVER);
            if(is_same_color(edge_home_obj.attr->bg_color, EDGE_COLOR_WHITE)){
                lv_style_set_text_color(&home_title_style, LV_STATE_DEFAULT, EDGE_COLOR_PURPLE);
            } else {
                lv_style_set_text_color(&home_title_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
            }
        } else if(edge_home_obj.attr->mode == GRAY_COUNTER_MODE) {
            lv_obj_align(edge_home_obj.label, NULL, LV_ALIGN_CENTER, 0, -60);
            lv_style_set_text_font(&home_title_style, LV_STATE_DEFAULT, &lv_font_montserrat_42);
            lv_style_set_text_color(&home_title_style, LV_STATE_DEFAULT, EDGE_COLOR_GRAY);
            lv_style_set_text_opa(&home_title_style, LV_STATE_DEFAULT, LV_OPA_50);
        } else if(edge_home_obj.attr->mode == NURSE_MODE) {
            lv_obj_align(edge_home_obj.label, NULL, LV_ALIGN_CENTER, 0, -60);
            lv_style_set_text_font(&home_title_style, LV_STATE_DEFAULT, &lv_font_montserrat_42);
            lv_style_set_text_color(&home_title_style, LV_STATE_DEFAULT, EDGE_COLOR_ROYAL_BLUE);
            lv_style_set_text_opa(&home_title_style, LV_STATE_DEFAULT, LV_OPA_COVER);
        } else {
            lv_obj_align(edge_home_obj.label, NULL, LV_ALIGN_CENTER, 0, 25);
            lv_style_set_text_font(&home_title_style, LV_STATE_DEFAULT, &lv_font_montserrat_30);
            lv_style_set_text_color(&home_title_style, LV_STATE_DEFAULT, LV_COLOR_GRAY);
            lv_style_set_text_opa(&home_title_style, LV_STATE_DEFAULT, LV_OPA_COVER);
        }
        lv_obj_add_style(edge_home_obj.label, LV_OBJ_PART_MAIN, &home_title_style);

        // Counter
        lv_style_set_bg_opa(&home_counter_style, LV_STATE_DEFAULT, LV_OPA_COVER);
        lv_style_set_text_font(&home_counter_style, LV_STATE_DEFAULT, &lv_font_montserrat_36);
        
        if(edge_home_obj.attr->mode == COUNTER_MODE){
            lv_obj_set_hidden(edge_home_obj.counter, false);
            lv_label_set_text(edge_home_obj.counter, edge_home_obj.attr->counter_value);
            lv_style_set_text_color(&home_counter_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
            lv_style_set_bg_color(&home_counter_style, LV_STATE_DEFAULT, EDGE_COLOR_PURPLE);
        } else if(edge_home_obj.attr->mode == GRAY_COUNTER_MODE) {
            lv_obj_set_hidden(edge_home_obj.counter, false);
            lv_label_set_text(edge_home_obj.counter, edge_home_obj.attr->counter_value);
            lv_style_set_text_color(&home_counter_style, LV_STATE_DEFAULT, LV_COLOR_WHITE);
            lv_style_set_bg_color(&home_counter_style, LV_STATE_DEFAULT, EDGE_COLOR_GRAY);
            lv_style_set_bg_opa(&home_counter_style, LV_STATE_DEFAULT, LV_OPA_50);
        } else {
            lv_obj_set_hidden(edge_home_obj.counter, true);
        }
        lv_obj_add_style(edge_home_obj.counter, LV_OBJ_PART_MAIN, &home_counter_style);
        
        
        // Image
        if(edge_home_obj.attr->mode == NORMAL_MODE || edge_home_obj.attr-> mode == NURSE_MODE){
            lv_obj_set_hidden(edge_home_obj.image, false);
            lv_img_set_src(edge_home_obj.image, edge_home_obj.attr->img_src);
            lv_obj_align(edge_home_obj.image, NULL, LV_ALIGN_CENTER, 0, 15);
        } else if (edge_home_obj.attr->mode == ALERT_MODE){
            lv_obj_set_hidden(edge_home_obj.image, false);
            lv_img_set_src(edge_home_obj.image, edge_home_obj.attr->img_src);
            lv_obj_align(edge_home_obj.image, NULL, LV_ALIGN_CENTER, 0, -50);

        } else {
            lv_obj_set_hidden(edge_home_obj.image, true);
        }
    }

	/* 2. Reset group */
    lv_group_remove_all_objs(edge_home_obj.group);
    lv_group_add_obj(edge_home_obj.group, edge_home_obj.this_page);
}

static void home_page_cb(lv_obj_t* obj, lv_event_t event){
	if(event == LV_EVENT_REFRESH){
		refresh_home_page();	
	}
	else if (event == LV_EVENT_LONG_PRESSED){
		go_to_menu_page();
	}
}

/**********************
 * Extern
 **********************/

// Create home page
edge_home_obj_t edge_home_page_create(){
	// 1. Setup screen
    lv_obj_t* home_scr = lv_obj_create(NULL, NULL);
    lv_obj_set_size(home_scr, 320, 240);
    lv_scr_load(home_scr);
    lv_obj_set_event_cb(home_scr, home_page_cb);
    edge_style_init();

    // 2. Setup group
    lv_group_t* home_group = lv_group_create();
    lv_group_set_editing(home_group, false);
    lv_indev_t* indev_keypad = get_indev();
    lv_indev_set_group(indev_keypad, home_group);

    // 3. Create UI element
    /* Create a label */
    lv_obj_t* home_label = lv_label_create(home_scr, NULL);
    lv_label_set_align(home_label, LV_LABEL_ALIGN_CENTER);
    lv_obj_set_auto_realign(home_label, true);

    /* Creat counter */
    lv_obj_t* home_counter = lv_label_create(home_scr, NULL);
    lv_label_set_long_mode(home_counter, LV_LABEL_LONG_DOT);
    lv_obj_set_size(home_counter, 296, 42);
    lv_label_set_align(home_counter, LV_LABEL_ALIGN_CENTER);
    lv_obj_align(home_counter, NULL, LV_ALIGN_CENTER, 0, -15);
    lv_obj_set_auto_realign(home_counter, true);

    /* Creat image */
    lv_obj_t* home_image = lv_img_create(home_scr, NULL);
    edge_bottom_bar_create(home_scr);

    // 4. Save as object
    current_home_attr = get_home_attr_leaving();

    edge_home_obj.group = home_group;
    edge_home_obj.this_page = home_scr;
    edge_home_obj.label = home_label;
    edge_home_obj.counter = home_counter;
    edge_home_obj.image = home_image;
    edge_home_obj.attr = &current_home_attr;

    // Add task to rotate event
    lv_task_create(event_task_cb, EVENT_TASK_INTERVAL, LV_TASK_PRIO_MID, &current_home_attr);

    return edge_home_obj;
}