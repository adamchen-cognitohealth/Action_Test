#include "edge_task.h"

// uint8_t test_data = 0;

// static void time_task_cb(lv_task_t* task) {
// 	struct timeval tv;
//     gettimeofday(&tv, NULL);


// 	uint8_t *dat = (uint8_t*)task->user_data;
// 	printf("tick: %d test_data %d\n",lv_tick_get(),*dat);
// 	printf("tv_sec; %ld\n", (tv.tv_sec - 1616999806));
// 	(*dat)++;
// 	if(*dat == 100)
// 		lv_task_del(task);
// }

// void lv_time_task(void) {
//     lv_task_t * time_task = lv_task_create(time_task_cb, 1000, LV_TASK_PRIO_MID, &test_data);
// }




// static void event_task_cb(lv_task_t* task) {

// }

// void lv_event_task(void) {
// 	lv_task_t * event_task = lv_task_create(event_task_cb, 1000, LV_TASK_PRIO_MID, &test_data);
// }