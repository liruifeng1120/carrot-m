#pragma once
#include "rednose/helpers/ekf.h"
extern "C" {
void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea);
void car_err_fun(double *nom_x, double *delta_x, double *out_7615378422295250943);
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7234727336485135895);
void car_H_mod_fun(double *state, double *out_1842480468963748569);
void car_f_fun(double *state, double dt, double *out_842551885572076045);
void car_F_fun(double *state, double dt, double *out_3512251755428273731);
void car_h_25(double *state, double *unused, double *out_3509543787442081958);
void car_H_25(double *state, double *unused, double *out_7903859779247712057);
void car_h_24(double *state, double *unused, double *out_2255043970042255686);
void car_H_24(double *state, double *unused, double *out_1324205406821483168);
void car_h_30(double *state, double *unused, double *out_5799483001583618476);
void car_H_30(double *state, double *unused, double *out_6015187964334231361);
void car_h_26(double *state, double *unused, double *out_5212117637697232327);
void car_H_26(double *state, double *unused, double *out_6801380975587783335);
void car_h_27(double *state, double *unused, double *out_1716363428393242989);
void car_H_27(double *state, double *unused, double *out_3840424652533806450);
void car_h_29(double *state, double *unused, double *out_5353812956647265339);
void car_H_29(double *state, double *unused, double *out_6525419308648623545);
void car_h_28(double *state, double *unused, double *out_9022403054223609326);
void car_H_28(double *state, double *unused, double *out_1443020291579092971);
void car_h_31(double *state, double *unused, double *out_406924308367068240);
void car_H_31(double *state, double *unused, double *out_6175172873354431859);
void car_predict(double *in_x, double *in_P, double *in_Q, double dt);
void car_set_mass(double x);
void car_set_rotational_inertia(double x);
void car_set_center_to_front(double x);
void car_set_center_to_rear(double x);
void car_set_stiffness_front(double x);
void car_set_stiffness_rear(double x);
}