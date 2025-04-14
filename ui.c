// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"
#include "ui_helpers.h"
#include <Arduino.h>
#include "esp_system.h"
extern uint8_t left_inj;
extern uint8_t right_inj;
extern bool conf_complete;
extern uint8_t right_total_inj;
extern uint8_t left_total_inj;
extern bool restart_left_timer;
extern bool restart_right_timer;
extern bool start_left_timer;
extern bool start_right_timer;
///////////////////// VARIABLES ////////////////////
void arc_Value_Animation(lv_obj_t * TargetObject, int delay , int returnValue);
void tutorial_Animation(lv_obj_t * TargetObject, int delay);
void logo_Animation(lv_obj_t * TargetObject, int delay);
void logoY_Animation(lv_obj_t * TargetObject, int delay);
void textLogo_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_DashboardSC
void ui_DashboardSC_screen_init(void);
void ui_event_DashboardSC(lv_event_t * e);
void ui_event_DashboardSC(lv_event_t * e);
void ui_event_resetButton(lv_event_t * e);
void ui_event_ui_resetcancelButton(lv_event_t * e);
lv_obj_t * ui_DashboardSC;
lv_obj_t * ui_batteryArc;
lv_obj_t * ui_temperatureArc;
lv_obj_t * ui_leftArc;
lv_obj_t * ui_rightArc;
lv_obj_t * ui_BATlabel;
lv_obj_t * ui_BATimage;
lv_obj_t * ui_TEMPlabel;
lv_obj_t * ui_TEMPimage;
lv_obj_t * ui_RIGHTlabel;
lv_obj_t * ui_LEFTlabel;
lv_obj_t * ui_Label14;
lv_obj_t * ui_Label19;
lv_obj_t * ui_Panel1;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Image4;
lv_obj_t * ui_Image10;
lv_obj_t * ui_Image12;
lv_obj_t * ui_Resetpanel;
lv_obj_t * ui_resetLabel1;
lv_obj_t * ui_resetLabe2;
lv_obj_t * ui_resetButton;
lv_obj_t * ui_resetButtonLabel;
lv_obj_t * ui_resetcancelButton;
lv_obj_t * ui_resetCancelLabel;


// SCREEN: ui_SettingsSC
void ui_SettingsSC_screen_init(void);
void ui_event_SettingsSC(lv_event_t * e);
lv_obj_t * ui_SettingsSC;
void ui_event_Arc3(lv_event_t * e);
lv_obj_t * ui_Arc3;
void ui_event_Button4(lv_event_t * e);
lv_obj_t * ui_Button4;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label2;
void ui_event_Roller2(lv_event_t * e);
lv_obj_t * ui_Roller2;


// SCREEN: ui_RightSC
void ui_RightSC_screen_init(void);
void ui_event_RightSC(lv_event_t * e);
lv_obj_t * ui_RightSC;
lv_obj_t * ui_rightArc2;
lv_obj_t * ui_RIGHTlabel2;
void ui_event_Button2(lv_event_t * e);
lv_obj_t * ui_Button2;
lv_obj_t * ui_RIGHTlabel3;
void ui_event_Button3(lv_event_t * e);
lv_obj_t * ui_Button3;
lv_obj_t * ui_RIGHTlabel4;


// SCREEN: ui_LeftSC
void ui_LeftSC_screen_init(void);
void ui_event_LeftSC(lv_event_t * e);
lv_obj_t * ui_LeftSC;
lv_obj_t * ui_leftArc2;
lv_obj_t * ui_LEFTlabel2;
void ui_event_Button5(lv_event_t * e);
lv_obj_t * ui_Button5;
lv_obj_t * ui_leftlabel6;
void ui_event_Button6(lv_event_t * e);
lv_obj_t * ui_Button6;
lv_obj_t * ui_leftlabel7;


// SCREEN: ui_TutorialSC
void ui_TutorialSC_screen_init(void);
void ui_event_TutorialSC(lv_event_t * e);
lv_obj_t * ui_TutorialSC;
lv_obj_t * ui_Image5;
lv_obj_t * ui_Panel2;
lv_obj_t * ui_Panel4;
lv_obj_t * ui_Label1;
void ui_event_Button7(lv_event_t * e);
lv_obj_t * ui_Button7;
lv_obj_t * ui_Label5;


// SCREEN: ui_ColoSC
void ui_ColoSC_screen_init(void);
lv_obj_t * ui_ColoSC;
void ui_event_Button1(lv_event_t * e);
lv_obj_t * ui_Button1;
lv_obj_t * ui_Image6;
void ui_event_Button9(lv_event_t * e);
lv_obj_t * ui_Button9;
lv_obj_t * ui_Image7;
void ui_event_Button10(lv_event_t * e);
lv_obj_t * ui_Button10;
lv_obj_t * ui_Image8;
lv_obj_t * ui_Label6;
lv_obj_t * ui_leftArc3;
void ui_event_Button11(lv_event_t * e);
lv_obj_t * ui_Button11;
lv_obj_t * ui_leftlabel2;
void ui_event_Button12(lv_event_t * e);
lv_obj_t * ui_Button12;
lv_obj_t * ui_leftlabel3;
lv_obj_t * ui_Label7;
void ui_event_Button20(lv_event_t * e);
lv_obj_t * ui_Button20;
lv_obj_t * ui_Label15;


// SCREEN: ui_LevelSC
void ui_LevelSC_screen_init(void);
lv_obj_t * ui_LevelSC;
void ui_event_Arc2(lv_event_t * e);
lv_obj_t * ui_Arc2;
void ui_event_Button13(lv_event_t * e);
lv_obj_t * ui_Button13;
lv_obj_t * ui_leftlabel4;
void ui_event_Button14(lv_event_t * e);
lv_obj_t * ui_Button14;
lv_obj_t * ui_leftlabel5;
lv_obj_t * ui_Label8;
lv_obj_t * ui_LEFTlabel3;
lv_obj_t * ui_Label9;
void ui_event_Button21(lv_event_t * e);
lv_obj_t * ui_Button21;
lv_obj_t * ui_Label16;


// SCREEN: ui_DoseSC
void ui_DoseSC_screen_init(void);
lv_obj_t * ui_DoseSC;
lv_obj_t * ui_Label10;
lv_obj_t * ui_LEFTlabel4;
void ui_event_Button15(lv_event_t * e);
lv_obj_t * ui_Button15;
lv_obj_t * ui_leftlabel8;
void ui_event_Button16(lv_event_t * e);
lv_obj_t * ui_Button16;
lv_obj_t * ui_leftlabel9;
lv_obj_t * ui_Label11;
void ui_event_Button17(lv_event_t * e);
lv_obj_t * ui_Button17;
lv_obj_t * ui_LEFTlabel5;
void ui_event_Button18(lv_event_t * e);
lv_obj_t * ui_Button18;
lv_obj_t * ui_LEFTlabel6;
void ui_event_Button22(lv_event_t * e);
lv_obj_t * ui_Button22;
lv_obj_t * ui_Label17;


// SCREEN: ui_NotificationSC
void ui_NotificationSC_screen_init(void);
lv_obj_t * ui_NotificationSC;
lv_obj_t * ui_Label12;
lv_obj_t * ui_Image1;
void ui_event_Button19(lv_event_t * e);
lv_obj_t * ui_Button19;
lv_obj_t * ui_Label13;


// SCREEN: ui_LogoSC
void ui_LogoSC_screen_init(void);
void ui_event_LogoSC(lv_event_t * e);
lv_obj_t * ui_LogoSC;
lv_obj_t * ui_Image9;
lv_obj_t * ui_Label4;
lv_obj_t * ui____initial_actions0;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void tutorial_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 500);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_opacity);
    lv_anim_set_values(&PropertyAnimation_0, 0, 255);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_linear);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 1000);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 1000);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 5);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 1000);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}
void logo_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_zoom);
    lv_anim_set_values(&PropertyAnimation_0, 255, 100);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}
void logoY_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, 0, 33);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}
void textLogo_Animation(lv_obj_t * TargetObject, int delay)
{
    ui_anim_user_data_t * PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
    PropertyAnimation_0_user_data->target = TargetObject;
    PropertyAnimation_0_user_data->val = -1;
    lv_anim_t PropertyAnimation_0;
    lv_anim_init(&PropertyAnimation_0);
    lv_anim_set_time(&PropertyAnimation_0, 1000);
    lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
    lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y);
    lv_anim_set_values(&PropertyAnimation_0, -145, -33);
    lv_anim_set_path_cb(&PropertyAnimation_0, lv_anim_path_overshoot);
    lv_anim_set_delay(&PropertyAnimation_0, delay + 0);
    lv_anim_set_deleted_cb(&PropertyAnimation_0, _ui_anim_callback_free_user_data);
    lv_anim_set_playback_time(&PropertyAnimation_0, 0);
    lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
    lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
    lv_anim_set_early_apply(&PropertyAnimation_0, true);
    lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_DashboardSC(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_SettingsSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, &ui_SettingsSC_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_RightSC, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 300, &ui_RightSC_screen_init);
    }
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_LeftSC, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 300, &ui_LeftSC_screen_init);
    }    
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP) {
        lv_indev_wait_release(lv_indev_get_act());
        lv_obj_clear_flag(ui_Resetpanel, LV_OBJ_FLAG_HIDDEN);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        play_dashboard_anim(e);
        lv_arc_set_range(ui_rightArc,0,right_total_inj);
        lv_arc_set_range(ui_rightArc,0,right_total_inj);
    }
}
void ui_event_resetButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_LONG_PRESSED) {
      esp_restart();
    }
}
void ui_event_ui_resetcancelButton(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
    lv_obj_add_flag(ui_Resetpanel, LV_OBJ_FLAG_HIDDEN);
    }
}
void ui_event_SettingsSC(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        play_settings_anim(e);
    }
}
void ui_event_Arc3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        control_brightness(e);
    }
}
void ui_event_Button4(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_DashboardSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 300, &ui_DashboardSC_screen_init);
    }
}
void ui_event_Roller2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_VALUE_CHANGED) {
        control_timeout(e);
    }
}
void ui_event_RightSC(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_DashboardSC, LV_SCR_LOAD_ANIM_MOVE_RIGHT, 200, 300, &ui_DashboardSC_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        play_right_anim(e);
        lv_arc_set_range(ui_rightArc2, 0, right_total_inj);
    }
}
void ui_event_Button2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_arc_increment(ui_rightArc2, 1);
    }
    if(event_code == LV_EVENT_CLICKED) {
        inc_right(e);
        restart_right_timer = true;
        start_right_timer = true;
    }
}
void ui_event_Button3(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
      if(right_inj > 0){
        _ui_arc_increment(ui_rightArc2, -1);
      }
    }
    if(event_code == LV_EVENT_CLICKED) {
        dec_right(e);
    }
}
void ui_event_LeftSC(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT) {
        lv_indev_wait_release(lv_indev_get_act());
        _ui_screen_change(&ui_DashboardSC, LV_SCR_LOAD_ANIM_MOVE_LEFT, 200, 300, &ui_DashboardSC_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        play_left_anim(e);
        lv_arc_set_range(ui_leftArc2, 0, left_total_inj);
    }
}
void ui_event_Button5(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
      if(left_inj > 0){
      _ui_arc_increment(ui_leftArc2, -1);
      }
    }
    if(event_code == LV_EVENT_CLICKED) {
        dec_left(e);
    }
}
void ui_event_Button6(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_arc_increment(ui_leftArc2, 1);
    }
    if(event_code == LV_EVENT_CLICKED) {
        inc_left(e);
        restart_left_timer = true;
        start_left_timer = true;
    }
}
void ui_event_TutorialSC(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        tutorial_Animation(ui_Panel2, 500);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        tutorial_Animation(ui_Panel4, 500);
    }
}
void ui_event_Button7(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ColoSC, LV_SCR_LOAD_ANIM_NONE, 0, 200, &ui_ColoSC_screen_init);
    }
}
void ui_event_Button1(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button9, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button10, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button11, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button12, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        orange_selected(e);
    }
}
void ui_event_Button9(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button1, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button10, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button11, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button12, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        blue_selected(e);
    }
}
void ui_event_Button10(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button1, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button9, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button11, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button12, LV_STATE_DISABLED, _UI_MODIFY_STATE_TOGGLE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        grey_selected(e);
    }
}
void ui_event_Button11(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_ColoSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, &ui_ColoSC_screen_init);
        lv_label_set_text(ui_Label6, "Select the color of the \nleft Syringe");
        lv_obj_add_flag(ui_Button11 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Button12 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Label7 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_Button20 , LV_OBJ_FLAG_HIDDEN);
    }
    if(event_code == LV_EVENT_CLICKED) {
        different_colors(e);
    }
}
void ui_event_Button12(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_LevelSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, &ui_LevelSC_screen_init);
    }
    if(event_code == LV_EVENT_CLICKED) {
        same_color(e);
    }
}
void ui_event_Button20(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_LevelSC, LV_SCR_LOAD_ANIM_NONE, 0, 200, &ui_LevelSC_screen_init);
    }
}
void ui_event_Arc2(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    uint16_t arc_value = lv_arc_get_value(ui_Arc2);
    if(event_code == LV_EVENT_RELEASED && arc_value >= 20) {
        _ui_state_modify(ui_Button13, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event_code == LV_EVENT_RELEASED && arc_value >= 20) {
        _ui_state_modify(ui_Button14, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event_code == LV_EVENT_VALUE_CHANGED && arc_value >= 20) {
        get_level(e);
    }
}
void ui_event_Button13(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_LevelSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, &ui_LevelSC_screen_init);
        lv_label_set_text(ui_Label8, "Set the level of the \nleft Syringe ");
        lv_obj_add_flag(ui_Button13 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Button14 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Label9 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_Button21 , LV_OBJ_FLAG_HIDDEN);
    }
    if(event_code == LV_EVENT_CLICKED) {
        different_levels(e);
    }
}
void ui_event_Button14(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_DoseSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, &ui_DoseSC_screen_init);
    }
    if(event_code == LV_EVENT_CLICKED) {
        same_level(e);
    }
}
void ui_event_Button21(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_DoseSC, LV_SCR_LOAD_ANIM_NONE, 0, 200, &ui_DoseSC_screen_init);
    }
}
void ui_event_Button15(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_DoseSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, &ui_DoseSC_screen_init);
        lv_label_set_text(ui_Label10, "Set the dose level of the\nleft Syringe");
        lv_obj_add_flag(ui_Label11 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Button15 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(ui_Button16 , LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(ui_Button22 , LV_OBJ_FLAG_HIDDEN);
    }
    if(event_code == LV_EVENT_CLICKED) {
        doses_are_different(e);
    }
}
void ui_event_Button16(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_NotificationSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 200, &ui_NotificationSC_screen_init);
    }
    if(event_code == LV_EVENT_CLICKED) {
        same_dose(e);
    }
}
void ui_event_Button17(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button16, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        _ui_state_modify(ui_Button15, LV_STATE_DISABLED, _UI_MODIFY_STATE_REMOVE);
    }
    if(event_code == LV_EVENT_CLICKED) {
        inc_dose(e);
    }
}
void ui_event_Button18(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        dec_dose(e);
    }
}
void ui_event_Button22(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_NotificationSC, LV_SCR_LOAD_ANIM_NONE, 0, 200, &ui_NotificationSC_screen_init);
    }
}
void ui_event_Button19(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_CLICKED) {
        _ui_screen_change(&ui_DashboardSC, LV_SCR_LOAD_ANIM_NONE, 0, 200, &ui_DashboardSC_screen_init);
    }
    if(event_code == LV_EVENT_CLICKED) {
        configuration_complete(e);
    }
}
void ui_event_LogoSC(lv_event_t * e)
{
    lv_event_code_t event_code = lv_event_get_code(e);
    lv_obj_t * target = lv_event_get_target(e);
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        _ui_screen_change(&ui_TutorialSC, LV_SCR_LOAD_ANIM_FADE_ON, 200, 3500, &ui_TutorialSC_screen_init);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        logoY_Animation(ui_Image9, 1000);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        logo_Animation(ui_Image9, 1000);
    }
    if(event_code == LV_EVENT_SCREEN_LOADED) {
        textLogo_Animation(ui_Label4, 1000);
    }
}

///////////////////// SCREENS ////////////////////

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               false, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_DashboardSC_screen_init();
    ui_SettingsSC_screen_init();
    ui_RightSC_screen_init();
    ui_LeftSC_screen_init();
    ui_TutorialSC_screen_init();
    ui_ColoSC_screen_init();
    ui_LevelSC_screen_init();
    ui_DoseSC_screen_init();
    ui_NotificationSC_screen_init();
    ui_LogoSC_screen_init();
    ui____initial_actions0 = lv_obj_create(NULL);
    if(conf_complete){
    lv_disp_load_scr(ui_DashboardSC);
    } else {
      lv_disp_load_scr(ui_LogoSC);
    }
}
