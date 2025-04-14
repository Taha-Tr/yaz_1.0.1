// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"
extern float lastTemperature;
extern int bat_percentage;
extern uint8_t right_inj;
extern uint8_t left_inj;
extern uint8_t right_total_inj;
extern uint8_t left_total_inj;
extern uint16_t left_syringe_level;
extern uint16_t right_syringe_level;
extern uint16_t calculate_level(uint16_t level);

void ui_DashboardSC_screen_init(void)
{
    ui_DashboardSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DashboardSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DashboardSC, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DashboardSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_batteryArc = lv_arc_create(ui_DashboardSC);
    lv_obj_set_width(ui_batteryArc, 240);
    lv_obj_set_height(ui_batteryArc, 240);
    lv_obj_set_align(ui_batteryArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_batteryArc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK |
                      LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_value(ui_batteryArc, bat_percentage);
    lv_arc_set_bg_angles(ui_batteryArc, 240, 290);
    lv_arc_set_mode(ui_batteryArc, LV_ARC_MODE_REVERSE);
    lv_arc_set_rotation(ui_batteryArc, 50);
    lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0x685B25), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_batteryArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_batteryArc, lv_color_hex(0xE7C93A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_batteryArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_batteryArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_temperatureArc = lv_arc_create(ui_DashboardSC);
    lv_obj_set_width(ui_temperatureArc, 240);
    lv_obj_set_height(ui_temperatureArc, 240);
    lv_arc_set_range(ui_temperatureArc, 0, 50);
    lv_obj_set_align(ui_temperatureArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_temperatureArc,
                      LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_value(ui_temperatureArc, lastTemperature);
    lv_arc_set_bg_angles(ui_temperatureArc, 250, 300);
    lv_arc_set_rotation(ui_temperatureArc, -50);
    lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0x730505), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_temperatureArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_temperatureArc, lv_color_hex(0xF43031), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_temperatureArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_temperatureArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_leftArc = lv_arc_create(ui_DashboardSC);
    lv_obj_set_width(ui_leftArc, 240);
    lv_obj_set_height(ui_leftArc, 240);
    lv_arc_set_range(ui_leftArc,0,left_total_inj);
    lv_obj_set_align(ui_leftArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_leftArc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK |
                      LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_value(ui_leftArc, left_inj);
    lv_arc_set_bg_angles(ui_leftArc, 240, 290);
    lv_arc_set_rotation(ui_leftArc, -130);
    lv_obj_set_style_arc_color(ui_leftArc, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_leftArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_leftArc, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_leftArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_leftArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_rightArc = lv_arc_create(ui_DashboardSC);
    lv_obj_set_width(ui_rightArc, 240);
    lv_obj_set_height(ui_rightArc, 240);
    lv_arc_set_range(ui_rightArc,0,right_total_inj);
    lv_obj_set_align(ui_rightArc, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_rightArc, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK |
                      LV_OBJ_FLAG_CLICK_FOCUSABLE);      /// Flags
    lv_arc_set_value(ui_rightArc, right_inj);
    lv_arc_set_bg_angles(ui_rightArc, 250, 300);
    lv_arc_set_mode(ui_rightArc, LV_ARC_MODE_REVERSE);
    lv_arc_set_rotation(ui_rightArc, 130);
    lv_obj_set_style_arc_color(ui_rightArc, lv_color_hex(0x295031), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_rightArc, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_rightArc, lv_color_hex(0x41B65A), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_rightArc, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_opa(ui_rightArc, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_BATlabel = lv_label_create(ui_DashboardSC);
    lv_obj_set_width(ui_BATlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_BATlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_BATlabel, 40);
    lv_obj_set_y(ui_BATlabel, -72);
    lv_obj_set_align(ui_BATlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_BATlabel, "50%");
    lv_obj_set_style_text_color(ui_BATlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_BATlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_BATlabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_BATimage = lv_img_create(ui_DashboardSC);
    lv_img_set_src(ui_BATimage, &ui_img_280010739);
    lv_obj_set_width(ui_BATimage, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_BATimage, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_BATimage, 39);
    lv_obj_set_y(ui_BATimage, -44);
    lv_obj_set_align(ui_BATimage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_BATimage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_BATimage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_BATimage, lv_color_hex(0xE6CA39), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_BATimage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TEMPlabel = lv_label_create(ui_DashboardSC);
    lv_obj_set_width(ui_TEMPlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_TEMPlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_TEMPlabel, -40);
    lv_obj_set_y(ui_TEMPlabel, -72);
    lv_obj_set_align(ui_TEMPlabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_TEMPlabel, "30C");
    lv_obj_set_style_text_color(ui_TEMPlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_TEMPlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_TEMPlabel, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_TEMPimage = lv_img_create(ui_DashboardSC);
    lv_img_set_src(ui_TEMPimage, &ui_img_376876256);
    lv_obj_set_width(ui_TEMPimage, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_TEMPimage, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_TEMPimage, -39);
    lv_obj_set_y(ui_TEMPimage, -44);
    lv_obj_set_align(ui_TEMPimage, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_TEMPimage, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_TEMPimage, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_img_set_zoom(ui_TEMPimage, 150);
    lv_obj_set_style_img_recolor(ui_TEMPimage, lv_color_hex(0xFF1818), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_TEMPimage, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_RIGHTlabel = lv_label_create(ui_DashboardSC);
    lv_obj_set_width(ui_RIGHTlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_RIGHTlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_RIGHTlabel, 43);
    lv_obj_set_y(ui_RIGHTlabel, 70);
    lv_obj_set_align(ui_RIGHTlabel, LV_ALIGN_CENTER);
    char right[10];
    sprintf(right,"%d",right_inj);
    lv_label_set_text(ui_RIGHTlabel, right);
    lv_obj_set_style_text_color(ui_RIGHTlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_RIGHTlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_RIGHTlabel, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LEFTlabel = lv_label_create(ui_DashboardSC);
    lv_obj_set_width(ui_LEFTlabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LEFTlabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LEFTlabel, -43);
    lv_obj_set_y(ui_LEFTlabel, 70);
    lv_obj_set_align(ui_LEFTlabel, LV_ALIGN_CENTER);
    char left[10];
    sprintf(left,"%d",left_inj);
    lv_label_set_text(ui_LEFTlabel, left);
    lv_obj_set_style_text_color(ui_LEFTlabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LEFTlabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LEFTlabel, &lv_font_montserrat_46, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label14 = lv_label_create(ui_DashboardSC);
    lv_obj_set_width(ui_Label14, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label14, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label14, 43);
    lv_obj_set_y(ui_Label14, 33);
    lv_obj_set_align(ui_Label14, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label14, "0H : 0M");
    lv_obj_set_style_text_color(ui_Label14, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label14, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label14, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label19 = lv_label_create(ui_DashboardSC);
    lv_obj_set_width(ui_Label19, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label19, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label19, -43);
    lv_obj_set_y(ui_Label19, 33);
    lv_obj_set_align(ui_Label19, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label19, "0H : 0M");
    lv_obj_set_style_text_color(ui_Label19, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label19, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label19, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel1 = lv_obj_create(ui_DashboardSC);
    lv_obj_set_width(ui_Panel1, 227);
    lv_obj_set_height(ui_Panel1, 42);
    lv_obj_set_x(ui_Panel1, 0);
    lv_obj_set_y(ui_Panel1, -4);
    lv_obj_set_align(ui_Panel1, LV_ALIGN_CENTER);
    lv_obj_clear_flag(ui_Panel1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel1, lv_color_hex(0x4B4B4B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Panel1, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image3 = lv_img_create(ui_Panel1);
    lv_img_set_src(ui_Image3, &ui_img_643638925);
    lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_Image3, 73);
    lv_obj_set_y(ui_Image3, 0);
    lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Image3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image3, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image2 = lv_img_create(ui_Panel1);
    lv_img_set_src(ui_Image2, &ui_img_643638925);
    lv_obj_set_width(ui_Image2, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_Image2, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_x(ui_Image2, -73);
    lv_obj_set_y(ui_Image2, 0);
    lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Image2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image4 = lv_img_create(ui_Panel1);
    lv_img_set_src(ui_Image4, &ui_img_565349050);
    lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);   /// 32
    lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);    /// 32
    lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_img_recolor(ui_Image4, lv_color_hex(0xfd0c0d), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui_Image4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image10 = lv_img_create(ui_Panel1);
    lv_img_set_src(ui_Image10, &ui_img_269970686);
    lv_obj_set_width(ui_Image10, LV_SIZE_CONTENT);   /// 24
    lv_obj_set_height(ui_Image10, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_x(ui_Image10, -74);
    lv_obj_set_y(ui_Image10, 2);
    lv_obj_set_align(ui_Image10, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image10, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image10, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Image12 = lv_img_create(ui_Panel1);
    lv_img_set_src(ui_Image12, &ui_img_269970686);
    lv_obj_set_width(ui_Image12, LV_SIZE_CONTENT);   /// 24
    lv_obj_set_height(ui_Image12, LV_SIZE_CONTENT);    /// 24
    lv_obj_set_x(ui_Image12, 74);
    lv_obj_set_y(ui_Image12, 2);
    lv_obj_set_align(ui_Image12, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image12, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image12, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Resetpanel = lv_obj_create(ui_DashboardSC);
    lv_obj_set_width(ui_Resetpanel, 245);
    lv_obj_set_height(ui_Resetpanel, 245);
    lv_obj_set_align(ui_Resetpanel, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Resetpanel, LV_OBJ_FLAG_HIDDEN);      /// Flags
    lv_obj_clear_flag(ui_Resetpanel, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Resetpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Resetpanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Resetpanel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_Resetpanel, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetLabel1 = lv_label_create(ui_Resetpanel);
    lv_obj_set_width(ui_resetLabel1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_resetLabel1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_resetLabel1, 0);
    lv_obj_set_y(ui_resetLabel1, -80);
    lv_obj_set_align(ui_resetLabel1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_resetLabel1, "Factory Reset");
    lv_obj_set_style_text_color(ui_resetLabel1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetLabel1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetLabel1, &lv_font_montserrat_18, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetLabe2 = lv_label_create(ui_Resetpanel);
    lv_obj_set_width(ui_resetLabe2, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_resetLabe2, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_resetLabe2, 0);
    lv_obj_set_y(ui_resetLabe2, 25);
    lv_obj_set_align(ui_resetLabe2, LV_ALIGN_CENTER);
    lv_label_set_text(ui_resetLabe2, "Hold the \"RESET\" button \nto reset the device");
    lv_obj_set_style_text_color(ui_resetLabe2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetLabe2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui_resetLabe2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetLabe2, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetButton = lv_btn_create(ui_Resetpanel);
    lv_obj_set_width(ui_resetButton, 115);
    lv_obj_set_height(ui_resetButton, 54);
    lv_obj_set_x(ui_resetButton, 0);
    lv_obj_set_y(ui_resetButton, -30);
    lv_obj_set_align(ui_resetButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_resetButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_resetButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_resetButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_resetButton, lv_color_hex(0xF91B1B), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_resetButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui_resetButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_spread(ui_resetButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetButtonLabel = lv_label_create(ui_resetButton);
    lv_obj_set_width(ui_resetButtonLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_resetButtonLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_resetButtonLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_resetButtonLabel, "RESET");
    lv_obj_set_style_text_color(ui_resetButtonLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetButtonLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetButtonLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetcancelButton = lv_btn_create(ui_Resetpanel);
    lv_obj_set_width(ui_resetcancelButton, 220);
    lv_obj_set_height(ui_resetcancelButton, 56);
    lv_obj_set_x(ui_resetcancelButton, 0);
    lv_obj_set_y(ui_resetcancelButton, 95);
    lv_obj_set_align(ui_resetcancelButton, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_resetcancelButton, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_resetcancelButton, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_resetcancelButton, lv_color_hex(0x327449), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_resetcancelButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_resetCancelLabel = lv_label_create(ui_resetcancelButton);
    lv_obj_set_width(ui_resetCancelLabel, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_resetCancelLabel, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_resetCancelLabel, 0);
    lv_obj_set_y(ui_resetCancelLabel, -2);
    lv_obj_set_align(ui_resetCancelLabel, LV_ALIGN_CENTER);
    lv_label_set_text(ui_resetCancelLabel, "Cancel");
    lv_obj_set_style_text_color(ui_resetCancelLabel, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_resetCancelLabel, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_resetCancelLabel, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_DashboardSC, ui_event_DashboardSC, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_resetButton, ui_event_resetButton, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_resetcancelButton, ui_event_ui_resetcancelButton, LV_EVENT_ALL, NULL);

}
