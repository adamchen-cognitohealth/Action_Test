#include "edge_ui.h"

void page_menu_test(void)
{
    /* Create a home screen */
    edge_home_obj_t home_obj = edge_home_page_create();
    
    /* Start home page */
    lv_event_send_refresh(home_obj.this_page);
}

