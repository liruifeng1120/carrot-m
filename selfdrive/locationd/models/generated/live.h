#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void live_update_4(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_9(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_10(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_12(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_35(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_32(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_13(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_14(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_update_33(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void live_H(double *in_vec, double *out_5793530707302572510);
void live_err_fun(double *nom_x, double *delta_x, double *out_1214688403342656825);
void live_inv_err_fun(double *nom_x, double *true_x, double *out_3257702950316542504);
void live_H_mod_fun(double *state, double *out_4709813071124051432);
void live_f_fun(double *state, double dt, double *out_1990716952789367245);
void live_F_fun(double *state, double dt, double *out_5325022922921810440);
void live_h_4(double *state, double *unused, double *out_8371499554220503236);
void live_H_4(double *state, double *unused, double *out_7365410750467341944);
void live_h_9(double *state, double *unused, double *out_8267198379020774987);
void live_H_9(double *state, double *unused, double *out_78191815202894474);
void live_h_10(double *state, double *unused, double *out_7178958128489283624);
void live_H_10(double *state, double *unused, double *out_3160421032674071933);
void live_h_12(double *state, double *unused, double *out_3412228830927701944);
void live_H_12(double *state, double *unused, double *out_2345954342435380149);
void live_h_35(double *state, double *unused, double *out_8821431152175878516);
void live_H_35(double *state, double *unused, double *out_3998748693094734568);
void live_h_32(double *state, double *unused, double *out_6673114869571748174);
void live_H_32(double *state, double *unused, double *out_3867583908153994099);
void live_h_13(double *state, double *unused, double *out_1003329658823533627);
void live_H_13(double *state, double *unused, double *out_832303475480031799);
void live_h_14(double *state, double *unused, double *out_8267198379020774987);
void live_H_14(double *state, double *unused, double *out_78191815202894474);
void live_h_33(double *state, double *unused, double *out_8230696858354358933);
void live_H_33(double *state, double *unused, double *out_848191688455876964);
void live_predict(double *in_x, double *in_P, double *in_Q, double dt);
}