// ------------------------------------------------------------
// Project: [yaz_1.0.1]
// Author: Taha Traidi
// Copyright (C) 2025 Taha Traidi
// All Rights Reserved. Unauthorized use, reproduction, or
// distribution of this code is strictly prohibited.
// Contact: [taha.traidi.tt@gmail.com]
// ------------------------------------------------------------
#include "Arduino.h"
#include "ui.h"
#include "Pin_def.h"
#include "ui_helpers.h"

extern bool conf_complete;
extern uint16_t brightness_level;
extern uint8_t left_inj;
extern uint8_t right_inj;
extern uint8_t commun_inj;
extern bool orange;
extern bool blue;
extern bool grey;
extern uint8_t left_dose_level;
extern uint8_t right_dose_level;
extern uint8_t left_color;
extern uint8_t right_color;
extern bool conf_same_color;
extern bool conf_same_level;
extern bool conf_same_dose;
extern uint16_t left_syringe_level;
extern uint16_t right_syringe_level;
extern float lastTemperature;
extern int bat_percentage;
extern uint8_t right_total_inj;
extern uint8_t left_total_inj;
extern uint8_t right_remaining_inj;
extern uint8_t left_remaining_inj;
bool o_selected = false;
bool b_selected = false;
bool g_selected = false;
bool conf_color_right_complete = false;
bool conf_level_right_complete = false;
bool conf_dose_right_complete = false;
bool right_color_done = false;
bool right_level_done = false;
bool right_dose_done = false;
int32_t arc_value;
char arc_val[10];
int temperature =30; 

void set_arc_value(lv_obj_t * arc, int start_value, int end_value) {
    // Set the arc range from 0 to 100
    lv_arc_set_value(arc, start_value);  // Initial value is the start_value
    // Set animation from start_value to end_value
    lv_anim_t a1;
    lv_anim_init(&a1);
    lv_anim_set_var(&a1, arc);
    lv_anim_set_values(&a1, start_value, end_value);
    lv_anim_set_time(&a1, 500);
    lv_anim_set_exec_cb(&a1, (lv_anim_exec_xcb_t) lv_arc_set_value);
    lv_anim_start(&a1);
}

uint16_t calculate_level(uint16_t level){
  uint16_t _level = (level * 300) / 100;
  return _level;
}

void TFT_SET_BL(uint8_t Value) {
    pinMode(BL, OUTPUT);
    if (Value < 0 || Value > 100) {
        printf("TFT_SET_BL Error \r\n");
    } else {
        analogWrite(BL, Value * 2.55);
    }
}

uint8_t calculate_total_injections(uint16_t syringe_level , uint8_t dose){
  uint8_t _total_inj = syringe_level / dose;
  return _total_inj;
}

void control_brightness(lv_event_t * e)
{
	 int32_t arc_level;
   arc_level = lv_arc_get_value(ui_Arc3);
   brightness_level = arc_level;
   TFT_SET_BL(brightness_level);
}

void play_settings_anim(lv_event_t * e)
{
  set_arc_value(ui_Arc3 , 0 , brightness_level);
}

void control_timeout(lv_event_t * e)
{
	// Your code here
}

void play_right_anim(lv_event_t * e)
{
	set_arc_value(ui_rightArc2 , 0 , right_inj);
}

void inc_right(lv_event_t * e)
{
  char right[10];
	right_inj += 1;
  right_remaining_inj -= 1;
  sprintf(right,"%d",right_inj);
  lv_label_set_text(ui_RIGHTlabel2, right);
  lv_label_set_text(ui_RIGHTlabel, right);
}

void dec_right(lv_event_t * e)
{
  char right[10];
  if(right_inj <= 0){
    right_inj = 0;
    sprintf(right,"%d",right_inj);
    lv_label_set_text(ui_RIGHTlabel2, right);
    lv_label_set_text(ui_RIGHTlabel, right);
  } else {
  right_inj -= 1;
  right_remaining_inj += 1;
  sprintf(right,"%d",right_inj);
  lv_label_set_text(ui_RIGHTlabel2, right);
  lv_label_set_text(ui_RIGHTlabel, right);
  }
}

void play_left_anim(lv_event_t * e)
{
	set_arc_value(ui_leftArc2 , 0 , left_inj);
}

void dec_left(lv_event_t * e)
{
  char left[10];
  if(left_inj <= 0){
    left_inj = 0;
    sprintf(left,"%d",left_inj);
    lv_label_set_text(ui_LEFTlabel, left);
    lv_label_set_text(ui_LEFTlabel2, left);
  } else {
  left_inj -= 1;
  left_remaining_inj += 1;
  sprintf(left,"%d",left_inj);
  lv_label_set_text(ui_LEFTlabel, left);
  lv_label_set_text(ui_LEFTlabel2, left);
  }
}

void inc_left(lv_event_t * e)
{
  char left[10];
	left_inj += 1;
  left_remaining_inj -= 1;
  sprintf(left,"%d",left_inj);
  lv_label_set_text(ui_LEFTlabel, left);
  lv_label_set_text(ui_LEFTlabel2, left);
}

void orange_selected(lv_event_t * e)
{
	orange = true;
  blue = false;
  grey = false;
  if(!o_selected){
  lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0xFF6D18), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  set_arc_value(ui_leftArc3 , 0 , 100);
  if(!right_color_done){
    right_color = 1;
  } else {
    left_color = 1;
  }
  o_selected = true;
  } else if(o_selected){
  lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0xc5c6c5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  set_arc_value(ui_leftArc3 , 0 , 100);
  if(!right_color_done){
    right_color = 0;
  } else {
    left_color = 0;
  }
  o_selected = false;
  }
}

void blue_selected(lv_event_t * e)
{
	blue = true;
  orange = false;
  grey = false;
  if(!b_selected){
  lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0x2095f6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  set_arc_value(ui_leftArc3 , 0 , 100);
  if(!right_color_done){
    right_color = 2;
  } else {
    left_color = 2;
  }
  b_selected = true;
  } else if(b_selected){
  lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0xc5c6c5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  set_arc_value(ui_leftArc3 , 0 , 100);
  if(!right_color_done){
    right_color = 0;
  } else{
    left_color = 0;
  }
  b_selected = false;
  }
}

void grey_selected(lv_event_t * e)
{
	grey = true;
  orange = false;
  blue = false;
  if(!g_selected){
  lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0x636363), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  set_arc_value(ui_leftArc3 , 0 , 100);
  if(!right_color_done){
    right_color = 3;
  } else {
    left_color = 3;
  }
  g_selected = true;
  } else if(g_selected){
  lv_obj_set_style_arc_color(ui_leftArc3, lv_color_hex(0xc5c6c5), LV_PART_INDICATOR | LV_STATE_DEFAULT);
  set_arc_value(ui_leftArc3 , 0 , 100);
  if(!right_color_done){
    right_color = 0;
  } else {
    left_color = 0;
  }
  g_selected = false;
  }
}

void different_colors(lv_event_t * e)
{
	conf_same_color = false;
  right_color_done = true;
}


void same_color(lv_event_t * e)
{
	conf_same_color = true;
  left_color = right_color;
}

void get_level(lv_event_t * e)
{
  arc_value = lv_arc_get_value(ui_Arc2);
  sprintf(arc_val,"%d",arc_value);
  if(arc_value <= 0){
    arc_value = 0;
    lv_label_set_text(ui_LEFTlabel3, arc_val);
  } else {
    lv_label_set_text(ui_LEFTlabel3, arc_val);
  }
  if(!right_level_done){
    //right_syringe_level = arc_value;
    uint16_t _level_right = arc_value;
    right_syringe_level = calculate_level(_level_right);
  } else {
    //left_syringe_level = arc_value;
    uint16_t _level_left = arc_value;
    left_syringe_level = calculate_level(_level_left);
  }
}

void different_levels(lv_event_t * e)
{
	conf_same_level = false;
  right_level_done = true;
}

void same_level(lv_event_t * e)
{
	conf_same_level = true;
  left_syringe_level = right_syringe_level;
}

void doses_are_different(lv_event_t * e)
{
  conf_same_dose = false;
  right_dose_done = true;
  lv_label_set_text(ui_LEFTlabel4 , "0");
}

void same_dose(lv_event_t * e)
{
  conf_same_dose = true;
  left_dose_level = right_dose_level;
}

void inc_dose(lv_event_t * e)
{
	char right_dose[5];
  char left_dose[5];
  if(!right_dose_done){
    right_dose_level += 1;
    sprintf(right_dose,"%d",right_dose_level);
    lv_label_set_text(ui_LEFTlabel4,right_dose);
  } else{
    left_dose_level += 1;
    sprintf(left_dose,"%d", left_dose_level);
    lv_label_set_text(ui_LEFTlabel4, left_dose);
  }
}

void dec_dose(lv_event_t * e)
{
  char right_dose[5];
  char left_dose[5];
  if(!right_dose_done){
    if(right_dose_level <= 0){
    right_dose_level = 0;
    sprintf(right_dose,"%d",right_dose_level);
    lv_label_set_text(ui_LEFTlabel4,right_dose);
    } else
    right_dose_level -= 1;
    sprintf(right_dose,"%d",right_dose_level);
    lv_label_set_text(ui_LEFTlabel4,right_dose);
  } else{
    if(left_dose_level <= 0){
    left_dose_level = 0;
    sprintf(left_dose,"%d",left_dose_level);
    lv_label_set_text(ui_LEFTlabel4,left_dose);
    } else
    left_dose_level -= 1;
    sprintf(left_dose,"%d", left_dose_level);
    lv_label_set_text(ui_LEFTlabel4, left_dose);
  }
}

void configuration_complete(lv_event_t * e)
{
	conf_complete = true;
}

void play_dashboard_anim(lv_event_t * e)
{
  temperature = (int) lastTemperature;
  right_total_inj = calculate_total_injections(right_syringe_level , right_dose_level);
  left_total_inj = calculate_total_injections(left_syringe_level , left_dose_level);
  right_remaining_inj = right_total_inj - right_inj;
  left_remaining_inj = left_total_inj - left_inj;
	//set_arc_value(ui_temperatureArc , 0 , temperature);
  //set_arc_value(ui_batteryArc , 0 , bat_percentage);
  set_arc_value(ui_leftArc , left_total_inj , left_remaining_inj);
  set_arc_value(ui_rightArc , right_total_inj , right_remaining_inj);
}
