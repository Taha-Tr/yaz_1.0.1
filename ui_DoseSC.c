// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"

void ui_DoseSC_screen_init(void)
{
    ui_DoseSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_DoseSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_DoseSC, lv_color_hex(0xC5C6C5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_DoseSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    ui_Label10 = lv_label_create(ui_DoseSC);
    lv_obj_set_width(ui_Label10, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label10, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label10, 0);
    lv_obj_set_y(ui_Label10, -60);
    lv_obj_set_align(ui_Label10, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label10, "Set the dose level of the\nright Syringe");
    lv_obj_set_style_text_align(ui_Label10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LEFTlabel4 = lv_label_create(ui_DoseSC);
    lv_obj_set_width(ui_LEFTlabel4, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LEFTlabel4, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LEFTlabel4, 0);
    lv_obj_set_y(ui_LEFTlabel4, -11);
    lv_obj_set_align(ui_LEFTlabel4, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LEFTlabel4, "0");
    lv_obj_set_style_text_color(ui_LEFTlabel4, lv_color_hex(0x393939), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LEFTlabel4, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LEFTlabel4, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button15 = lv_btn_create(ui_DoseSC);
    lv_obj_set_width(ui_Button15, 117);
    lv_obj_set_height(ui_Button15, 71);
    lv_obj_set_x(ui_Button15, 59);
    lv_obj_set_y(ui_Button15, 101);
    lv_obj_set_align(ui_Button15, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Button15, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_Button15, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button15, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button15, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button15, lv_color_hex(0x41855A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button15, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel8 = lv_label_create(ui_Button15);
    lv_obj_set_width(ui_leftlabel8, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel8, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel8, -27);
    lv_obj_set_y(ui_leftlabel8, -9);
    lv_obj_set_align(ui_leftlabel8, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel8, "NO");
    lv_obj_set_style_text_color(ui_leftlabel8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel8, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button16 = lv_btn_create(ui_DoseSC);
    lv_obj_set_width(ui_Button16, 117);
    lv_obj_set_height(ui_Button16, 71);
    lv_obj_set_x(ui_Button16, -59);
    lv_obj_set_y(ui_Button16, 101);
    lv_obj_set_align(ui_Button16, LV_ALIGN_CENTER);
    lv_obj_add_state(ui_Button16, LV_STATE_DISABLED);       /// States
    lv_obj_add_flag(ui_Button16, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button16, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button16, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button16, lv_color_hex(0x41855A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button16, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_leftlabel9 = lv_label_create(ui_Button16);
    lv_obj_set_width(ui_leftlabel9, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_leftlabel9, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_leftlabel9, 23);
    lv_obj_set_y(ui_leftlabel9, -10);
    lv_obj_set_align(ui_leftlabel9, LV_ALIGN_CENTER);
    lv_label_set_text(ui_leftlabel9, "YES");
    lv_obj_set_style_text_color(ui_leftlabel9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_leftlabel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_leftlabel9, &lv_font_montserrat_24, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label11 = lv_label_create(ui_DoseSC);
    lv_obj_set_width(ui_Label11, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label11, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label11, 0);
    lv_obj_set_y(ui_Label11, 41);
    lv_obj_set_align(ui_Label11, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label11, "Same dose as the left \nSyringe ?");
    lv_obj_set_style_text_align(ui_Label11, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button17 = lv_btn_create(ui_DoseSC);
    lv_obj_set_width(ui_Button17, 67);
    lv_obj_set_height(ui_Button17, 56);
    lv_obj_set_x(ui_Button17, 71);
    lv_obj_set_y(ui_Button17, -10);
    lv_obj_set_align(ui_Button17, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button17, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button17, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button17, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LEFTlabel5 = lv_label_create(ui_Button17);
    lv_obj_set_width(ui_LEFTlabel5, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LEFTlabel5, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_align(ui_LEFTlabel5, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LEFTlabel5, "+");
    lv_obj_set_style_text_color(ui_LEFTlabel5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LEFTlabel5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LEFTlabel5, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button18 = lv_btn_create(ui_DoseSC);
    lv_obj_set_width(ui_Button18, 67);
    lv_obj_set_height(ui_Button18, 56);
    lv_obj_set_x(ui_Button18, -71);
    lv_obj_set_y(ui_Button18, -10);
    lv_obj_set_align(ui_Button18, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button18, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button18, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button18, 20, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LEFTlabel6 = lv_label_create(ui_Button18);
    lv_obj_set_width(ui_LEFTlabel6, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LEFTlabel6, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LEFTlabel6, 0);
    lv_obj_set_y(ui_LEFTlabel6, -3);
    lv_obj_set_align(ui_LEFTlabel6, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LEFTlabel6, "-");
    lv_obj_set_style_text_color(ui_LEFTlabel6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_LEFTlabel6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_LEFTlabel6, &lv_font_montserrat_48, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Button22 = lv_btn_create(ui_DoseSC);
    lv_obj_set_width(ui_Button22, 232);
    lv_obj_set_height(ui_Button22, 117);
    lv_obj_set_x(ui_Button22, 0);
    lv_obj_set_y(ui_Button22, 122);
    lv_obj_set_align(ui_Button22, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button22, LV_OBJ_FLAG_HIDDEN | LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button22, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button22, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button22, lv_color_hex(0x43875A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button22, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label17 = lv_label_create(ui_Button22);
    lv_obj_set_width(ui_Label17, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label17, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label17, 0);
    lv_obj_set_y(ui_Label17, -29);
    lv_obj_set_align(ui_Label17, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label17, "Next");
    lv_obj_set_style_text_color(ui_Label17, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label17, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label17, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button15, ui_event_Button15, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button16, ui_event_Button16, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button17, ui_event_Button17, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button18, ui_event_Button18, LV_EVENT_ALL, NULL);
    lv_obj_add_event_cb(ui_Button22, ui_event_Button22, LV_EVENT_ALL, NULL);

}
