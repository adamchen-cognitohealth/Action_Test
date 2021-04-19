#include "model_menu_attr.h"

edge_menu_attr_t get_default_menu_attr(lv_event_cb_t event_cb){
    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_SETTING,
        {
            MENU_ITEMS_VOLUME,
            MENU_ITEMS_BRIGHTNESS,
            MENU_ITEMS_LEAVE_TIME,
            MENU_ITEMS_REPOSITION_SETTING,
            MENU_ITEMS_ALERT_LANGUAGE,
            MENU_ITEMS_INTERFACE_LANGUAGE,
            MENU_ITEMS_CABLE_ORIENTATION,
            MENU_ITEMS_WIFI_INFO
        },
        NULL,
        event_cb,
        NULL
    };
    return tmp_attr;
}

edge_menu_attr_t get_menu_volume_attr(lv_event_cb_t event_cb){
    menu_attr_default.last_focused = MENU_ITEMS_VOLUME;

    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_VOLUME,
        {
            MENU_ITEMS_VOLUME_MUTE,
            MENU_ITEMS_VOLUME_NORMAL,
            MENU_ITEMS_VOLUME_LOUD
        },
        NULL,
        event_cb,
        &menu_attr_default
    };
    return tmp_attr;
}

edge_menu_attr_t get_menu_brightness_attr(lv_event_cb_t event_cb){
    menu_attr_default.last_focused = MENU_ITEMS_BRIGHTNESS;

    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_BRIGHTNESS,
        {
            MENU_ITEMS_BRIGHTNESS_OFF,
            MENU_ITEMS_BRIGHTNESS_DIM,
            MENU_ITEMS_BRIGHTNESS_BRIGHT
        },
        NULL,
        event_cb,
        &menu_attr_default
    };
    return tmp_attr;
}
edge_menu_attr_t get_menu_leave_time_attr(lv_event_cb_t event_cb){
    menu_attr_default.last_focused = MENU_ITEMS_LEAVE_TIME;

    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_LEAVE_TIME,
        {
            MENU_ITEMS_LEAVE_TIME_5,
            MENU_ITEMS_LEAVE_TIME_10,
            MENU_ITEMS_LEAVE_TIME_15,
            MENU_ITEMS_LEAVE_TIME_20,
            MENU_ITEMS_LEAVE_TIME_30,
            MENU_ITEMS_LEAVE_TIME_60
        },
        NULL,
        event_cb,
        &menu_attr_default
    };
    return tmp_attr;
}
edge_menu_attr_t get_menu_reposition_setting_attr(lv_event_cb_t event_cb){
    menu_attr_default.last_focused = MENU_ITEMS_REPOSITION_SETTING;

    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_REPOSITION_SETTING,
        {
            MENU_ITEMS_REPOSITION_SETTING_30,
            MENU_ITEMS_REPOSITION_SETTING_60,
            MENU_ITEMS_REPOSITION_SETTING_90,
            MENU_ITEMS_REPOSITION_SETTING_120
        },
        NULL,
        event_cb,
        &menu_attr_default
    };
    return tmp_attr;
}
edge_menu_attr_t get_menu_alert_language_attr(lv_event_cb_t event_cb){
    menu_attr_default.last_focused = MENU_ITEMS_ALERT_LANGUAGE;

    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_ALERT_LANGUAGE,
        {
            MENU_ITEMS_ALERT_LANGUAGE_MUSIC,
            MENU_ITEMS_ALERT_LANGUAGE_ENGLISH,
            MENU_ITEMS_ALERT_LANGUAGE_CHINESE,
            MENU_ITEMS_ALERT_LANGUAGE_TAIWANESE,
            MENU_ITEMS_ALERT_LANGUAGE_JAPANESE,
            MENU_ITEMS_ALERT_LANGUAGE_SPANISH
        },
        NULL,
        event_cb,
        &menu_attr_default
        
    };
    return tmp_attr;
}
edge_menu_attr_t get_menu_interface_language_attr(lv_event_cb_t event_cb){
    menu_attr_default.last_focused = MENU_ITEMS_INTERFACE_LANGUAGE;

    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_INTERFACE_LANGUAGE,
        {
            MENU_ITEMS_INTERFACE_LANGUAGE_ENGLISH,
            MENU_ITEMS_INTERFACE_LANGUAGE_CHINESE,
            MENU_ITEMS_INTERFACE_LANGUAGE_JAPANESE,
            MENU_ITEMS_INTERFACE_LANGUAGE_SPANISH
        },
        NULL,
        event_cb,
        &menu_attr_default
    };
    return tmp_attr;
}

edge_menu_attr_t get_menu_cable_orientation_attr(lv_event_cb_t event_cb){
    menu_attr_default.last_focused = MENU_ITEMS_CABLE_ORIENTATION;

    edge_menu_attr_t tmp_attr = {
        MENU_TITLE_CABLE_ORIENTATION,
        {
            MENU_ITEMS_CABLE_ORIENTATION_LEFT,
            MENU_ITEMS_CABLE_ORIENTATION_RIGHT
        },
        NULL,
        event_cb,
        &menu_attr_default
    };
    return tmp_attr;
}



