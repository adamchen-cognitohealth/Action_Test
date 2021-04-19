#include "widget_bottom_bar.h"

void edge_bottom_bar_create(lv_obj_t* scr){
	lv_obj_t* bottom_device_label = lv_label_create(scr, NULL);
    lv_obj_set_pos(bottom_device_label, 10, 217);
    lv_obj_set_size(bottom_device_label, 60, 16);

    lv_label_set_text(bottom_device_label, "Bed 601");
    lv_label_set_align(bottom_device_label, LV_LABEL_ALIGN_LEFT);

    lv_obj_t* bottom_wifi_label = lv_label_create(scr, NULL);
    lv_label_set_long_mode(bottom_wifi_label, LV_LABEL_LONG_BREAK);
    lv_obj_set_pos(bottom_wifi_label, 70, 217);
    lv_obj_set_size(bottom_wifi_label, 240, 16);

    lv_label_set_text(bottom_wifi_label, "Wi-Fi " LV_SYMBOL_WIFI);
    lv_label_set_align(bottom_wifi_label, LV_LABEL_ALIGN_RIGHT);
}
