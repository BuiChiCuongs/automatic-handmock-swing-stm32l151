/**
 ******************************************************************************
 * @author: Nark
 * @date:   06/06/2024
 ******************************************************************************
**/

#include "task_sm.h"

#include "stk.h"
#include "message.h"
#include "timer.h"

#include "io_cfg.h"
#include "console.h"
#include "platform.h"

#include "app.h"
#include "link_phy.h"
#include "task_list.h"
#include "task_pid.h"
#include "task_display.h"
#include "task_safety.h"

#include "screen_main.h"

void task_sm_handler(stk_msg_t* msg) {
    switch (msg->sig) {
    case SIG_SM_REQ_CHECK_WIFI_CONNECT:
        APP_PRINT("[TASK_SM] SIG_SM_REQ_CHECK_WIFI_CONNECT\n");
        LINK_PHY_FORWARD_MSG_OUT(TASK_SM_ID, SIG_SM_REQ_CHECK_WIFI_CONNECT);
        break;

    case SIG_SM_RES_WIFI_CONNECTED:
        APP_PRINT("[TASK_SM] SIG_SM_RES_WIFI_CONNECTED\n");
        main_screen_info.wifi_status = WIFI_CONNECTED;
        break;

    case SIG_SM_RES_WIFI_DISCONNECTED:
        APP_PRINT("[TASK_SM] SIG_SM_RES_WIFI_DISCONNECTED\n");
        main_screen_info.wifi_status = WIFI_DISCONNECTED;
        break;

    default:
        break;
    }
}