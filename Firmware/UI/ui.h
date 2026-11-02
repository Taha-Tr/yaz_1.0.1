// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#ifndef _YAZ_1_28_2_UI_H
#define _YAZ_1_28_2_UI_H

#ifdef __cplusplus
extern "C" {
#endif

#if defined __has_include
#if __has_include("lvgl.h")
#include "lvgl.h"
#elif __has_include("lvgl/lvgl.h")
#include "lvgl/lvgl.h"
#else
#include "lvgl.h"
#endif
#else
#include "lvgl.h"
#endif

#include "ui_helpers.h"
#include "ui_events.h"
void arc_Value_Animation(lv_obj_t * TargetObject, int delay , int returnValue);
void tutorial_Animation(lv_obj_t * TargetObject, int delay);
void logo_Animation(lv_obj_t * TargetObject, int delay);
void logoY_Animation(lv_obj_t * TargetObject, int delay);
void textLogo_Animation(lv_obj_t * TargetObject, int delay);
// SCREEN: ui_DashboardSC
void ui_DashboardSC_screen_init(void);
void ui_event_DashboardSC(lv_event_t * e);
void ui_event_resetButton(lv_event_t * e);
void ui_event_ui_resetcancelButton(lv_event_t * e);
extern lv_obj_t * ui_DashboardSC;
extern lv_obj_t * ui_batteryArc;
extern lv_obj_t * ui_temperatureArc;
extern lv_obj_t * ui_leftArc;
extern lv_obj_t * ui_rightArc;
extern lv_obj_t * ui_BATlabel;
extern lv_obj_t * ui_BATimage;
extern lv_obj_t * ui_TEMPlabel;
extern lv_obj_t * ui_TEMPimage;
extern lv_obj_t * ui_RIGHTlabel;
extern lv_obj_t * ui_LEFTlabel;
extern lv_obj_t * ui_Label14;
extern lv_obj_t * ui_Label19;
extern lv_obj_t * ui_Panel1;
extern lv_obj_t * ui_Image3;
extern lv_obj_t * ui_Image2;
extern lv_obj_t * ui_Image4;
extern lv_obj_t * ui_Image10;
extern lv_obj_t * ui_Image12;
extern lv_obj_t * ui_Resetpanel;
extern lv_obj_t * ui_resetLabel1;
extern lv_obj_t * ui_resetLabe2;
extern lv_obj_t * ui_resetButton;
extern lv_obj_t * ui_resetButtonLabel;
extern lv_obj_t * ui_resetcancelButton;
extern lv_obj_t * ui_resetCancelLabel;
// SCREEN: ui_SettingsSC
void ui_SettingsSC_screen_init(void);
void ui_event_SettingsSC(lv_event_t * e);
extern lv_obj_t * ui_SettingsSC;
void ui_event_Arc3(lv_event_t * e);
extern lv_obj_t * ui_Arc3;
void ui_event_Button4(lv_event_t * e);
extern lv_obj_t * ui_Button4;
extern lv_obj_t * ui_Label3;
extern lv_obj_t * ui_Label2;
void ui_event_Roller2(lv_event_t * e);
extern lv_obj_t * ui_Roller2;
// SCREEN: ui_RightSC
void ui_RightSC_screen_init(void);
void ui_event_RightSC(lv_event_t * e);
extern lv_obj_t * ui_RightSC;
extern lv_obj_t * ui_rightArc2;
extern lv_obj_t * ui_RIGHTlabel2;
void ui_event_Button2(lv_event_t * e);
extern lv_obj_t * ui_Button2;
extern lv_obj_t * ui_RIGHTlabel3;
void ui_event_Button3(lv_event_t * e);
extern lv_obj_t * ui_Button3;
extern lv_obj_t * ui_RIGHTlabel4;
// SCREEN: ui_LeftSC
void ui_LeftSC_screen_init(void);
void ui_event_LeftSC(lv_event_t * e);
extern lv_obj_t * ui_LeftSC;
extern lv_obj_t * ui_leftArc2;
extern lv_obj_t * ui_LEFTlabel2;
void ui_event_Button5(lv_event_t * e);
extern lv_obj_t * ui_Button5;
extern lv_obj_t * ui_leftlabel6;
void ui_event_Button6(lv_event_t * e);
extern lv_obj_t * ui_Button6;
extern lv_obj_t * ui_leftlabel7;
// SCREEN: ui_TutorialSC
void ui_TutorialSC_screen_init(void);
void ui_event_TutorialSC(lv_event_t * e);
extern lv_obj_t * ui_TutorialSC;
extern lv_obj_t * ui_Image5;
extern lv_obj_t * ui_Panel2;
extern lv_obj_t * ui_Panel4;
extern lv_obj_t * ui_Label1;
void ui_event_Button7(lv_event_t * e);
extern lv_obj_t * ui_Button7;
extern lv_obj_t * ui_Label5;
// SCREEN: ui_ColoSC
void ui_ColoSC_screen_init(void);
extern lv_obj_t * ui_ColoSC;
void ui_event_Button1(lv_event_t * e);
extern lv_obj_t * ui_Button1;
extern lv_obj_t * ui_Image6;
void ui_event_Button9(lv_event_t * e);
extern lv_obj_t * ui_Button9;
extern lv_obj_t * ui_Image7;
void ui_event_Button10(lv_event_t * e);
extern lv_obj_t * ui_Button10;
extern lv_obj_t * ui_Image8;
extern lv_obj_t * ui_Label6;
extern lv_obj_t * ui_leftArc3;
void ui_event_Button11(lv_event_t * e);
extern lv_obj_t * ui_Button11;
extern lv_obj_t * ui_leftlabel2;
void ui_event_Button12(lv_event_t * e);
extern lv_obj_t * ui_Button12;
extern lv_obj_t * ui_leftlabel3;
extern lv_obj_t * ui_Label7;
void ui_event_Button20(lv_event_t * e);
extern lv_obj_t * ui_Button20;
extern lv_obj_t * ui_Label15;
// SCREEN: ui_LevelSC
void ui_LevelSC_screen_init(void);
extern lv_obj_t * ui_LevelSC;
void ui_event_Arc2(lv_event_t * e);
extern lv_obj_t * ui_Arc2;
void ui_event_Button13(lv_event_t * e);
extern lv_obj_t * ui_Button13;
extern lv_obj_t * ui_leftlabel4;
void ui_event_Button14(lv_event_t * e);
extern lv_obj_t * ui_Button14;
extern lv_obj_t * ui_leftlabel5;
extern lv_obj_t * ui_Label8;
extern lv_obj_t * ui_LEFTlabel3;
extern lv_obj_t * ui_Label9;
void ui_event_Button21(lv_event_t * e);
extern lv_obj_t * ui_Button21;
extern lv_obj_t * ui_Label16;
// SCREEN: ui_DoseSC
void ui_DoseSC_screen_init(void);
extern lv_obj_t * ui_DoseSC;
extern lv_obj_t * ui_Label10;
extern lv_obj_t * ui_LEFTlabel4;
void ui_event_Button15(lv_event_t * e);
extern lv_obj_t * ui_Button15;
extern lv_obj_t * ui_leftlabel8;
void ui_event_Button16(lv_event_t * e);
extern lv_obj_t * ui_Button16;
extern lv_obj_t * ui_leftlabel9;
extern lv_obj_t * ui_Label11;
void ui_event_Button17(lv_event_t * e);
extern lv_obj_t * ui_Button17;
extern lv_obj_t * ui_LEFTlabel5;
void ui_event_Button18(lv_event_t * e);
extern lv_obj_t * ui_Button18;
extern lv_obj_t * ui_LEFTlabel6;
void ui_event_Button22(lv_event_t * e);
extern lv_obj_t * ui_Button22;
extern lv_obj_t * ui_Label17;
// SCREEN: ui_NotificationSC
void ui_NotificationSC_screen_init(void);
extern lv_obj_t * ui_NotificationSC;
extern lv_obj_t * ui_Label12;
extern lv_obj_t * ui_Image1;
void ui_event_Button19(lv_event_t * e);
extern lv_obj_t * ui_Button19;
extern lv_obj_t * ui_Label13;
// SCREEN: ui_LogoSC
void ui_LogoSC_screen_init(void);
void ui_event_LogoSC(lv_event_t * e);
extern lv_obj_t * ui_LogoSC;
extern lv_obj_t * ui_Image9;
extern lv_obj_t * ui_Label4;
extern lv_obj_t * ui____initial_actions0;

LV_IMG_DECLARE(ui_img_280010739);    // assets\bolt (1).png
LV_IMG_DECLARE(ui_img_376876256);    // assets\thermometer (1).png
LV_IMG_DECLARE(ui_img_643638925);    // assets\injection (1).png
LV_IMG_DECLARE(ui_img_565349050);    // assets\lien (1).png
LV_IMG_DECLARE(ui_img_269970686);    // assets\diagonal-line.png
LV_IMG_DECLARE(ui_img_200725706);    // assets\Capture_d_écran_2025-01-26_200358-removebg-preview (1).png
LV_IMG_DECLARE(ui_img_946096303);    // assets\reverifier (1).png
LV_IMG_DECLARE(ui_img_logo_yaz_png);    // assets\LOGO_YAZ.png



void ui_init(void);

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif
