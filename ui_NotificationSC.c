// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "ui.h"

void ui_NotificationSC_screen_init(void)
{
    ui_NotificationSC = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_NotificationSC, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_NotificationSC, lv_color_hex(0xC5C6C5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_NotificationSC, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label12 = lv_label_create(ui_NotificationSC);
    lv_obj_set_width(ui_Label12, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label12, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label12, 0);
    lv_obj_set_y(ui_Label12, 10);
    lv_obj_set_align(ui_Label12, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label12, "The device configuration has \nbeen completed successfully !");
    lv_obj_set_style_text_align(ui_Label12, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Image1 = lv_img_create(ui_NotificationSC);
    lv_img_set_src(ui_Image1, &ui_img_946096303);
    lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 64
    lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 64
    lv_obj_set_x(ui_Image1, 0);
    lv_obj_set_y(ui_Image1, -57);
    lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_Button19 = lv_btn_create(ui_NotificationSC);
    lv_obj_set_width(ui_Button19, 232);
    lv_obj_set_height(ui_Button19, 117);
    lv_obj_set_x(ui_Button19, 0);
    lv_obj_set_y(ui_Button19, 122);
    lv_obj_set_align(ui_Button19, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_Button19, LV_OBJ_FLAG_FLOATING | LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_clear_flag(ui_Button19, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Button19, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Button19, lv_color_hex(0x43875A), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Button19, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Label13 = lv_label_create(ui_Button19);
    lv_obj_set_width(ui_Label13, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_Label13, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_Label13, 0);
    lv_obj_set_y(ui_Label13, -29);
    lv_obj_set_align(ui_Label13, LV_ALIGN_CENTER);
    lv_label_set_text(ui_Label13, "OK");
    lv_obj_set_style_text_color(ui_Label13, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui_Label13, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_Label13, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_Button19, ui_event_Button19, LV_EVENT_ALL, NULL);

}
