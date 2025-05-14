#include "car.h"

namespace {
#define DIM 9
#define EDIM 9
#define MEDIM 9
typedef void (*Hfun)(double *, double *, double *);

double mass;

void set_mass(double x){ mass = x;}

double rotational_inertia;

void set_rotational_inertia(double x){ rotational_inertia = x;}

double center_to_front;

void set_center_to_front(double x){ center_to_front = x;}

double center_to_rear;

void set_center_to_rear(double x){ center_to_rear = x;}

double stiffness_front;

void set_stiffness_front(double x){ stiffness_front = x;}

double stiffness_rear;

void set_stiffness_rear(double x){ stiffness_rear = x;}
const static double MAHA_THRESH_25 = 3.8414588206941227;
const static double MAHA_THRESH_24 = 5.991464547107981;
const static double MAHA_THRESH_30 = 3.8414588206941227;
const static double MAHA_THRESH_26 = 3.8414588206941227;
const static double MAHA_THRESH_27 = 3.8414588206941227;
const static double MAHA_THRESH_29 = 3.8414588206941227;
const static double MAHA_THRESH_28 = 3.8414588206941227;
const static double MAHA_THRESH_31 = 3.8414588206941227;

/******************************************************************************
 *                       Code generated with SymPy 1.12                       *
 *                                                                            *
 *              See http://www.sympy.org/ for more information.               *
 *                                                                            *
 *                         This file is part of 'ekf'                         *
 ******************************************************************************/
void err_fun(double *nom_x, double *delta_x, double *out_7615378422295250943) {
   out_7615378422295250943[0] = delta_x[0] + nom_x[0];
   out_7615378422295250943[1] = delta_x[1] + nom_x[1];
   out_7615378422295250943[2] = delta_x[2] + nom_x[2];
   out_7615378422295250943[3] = delta_x[3] + nom_x[3];
   out_7615378422295250943[4] = delta_x[4] + nom_x[4];
   out_7615378422295250943[5] = delta_x[5] + nom_x[5];
   out_7615378422295250943[6] = delta_x[6] + nom_x[6];
   out_7615378422295250943[7] = delta_x[7] + nom_x[7];
   out_7615378422295250943[8] = delta_x[8] + nom_x[8];
}
void inv_err_fun(double *nom_x, double *true_x, double *out_7234727336485135895) {
   out_7234727336485135895[0] = -nom_x[0] + true_x[0];
   out_7234727336485135895[1] = -nom_x[1] + true_x[1];
   out_7234727336485135895[2] = -nom_x[2] + true_x[2];
   out_7234727336485135895[3] = -nom_x[3] + true_x[3];
   out_7234727336485135895[4] = -nom_x[4] + true_x[4];
   out_7234727336485135895[5] = -nom_x[5] + true_x[5];
   out_7234727336485135895[6] = -nom_x[6] + true_x[6];
   out_7234727336485135895[7] = -nom_x[7] + true_x[7];
   out_7234727336485135895[8] = -nom_x[8] + true_x[8];
}
void H_mod_fun(double *state, double *out_1842480468963748569) {
   out_1842480468963748569[0] = 1.0;
   out_1842480468963748569[1] = 0;
   out_1842480468963748569[2] = 0;
   out_1842480468963748569[3] = 0;
   out_1842480468963748569[4] = 0;
   out_1842480468963748569[5] = 0;
   out_1842480468963748569[6] = 0;
   out_1842480468963748569[7] = 0;
   out_1842480468963748569[8] = 0;
   out_1842480468963748569[9] = 0;
   out_1842480468963748569[10] = 1.0;
   out_1842480468963748569[11] = 0;
   out_1842480468963748569[12] = 0;
   out_1842480468963748569[13] = 0;
   out_1842480468963748569[14] = 0;
   out_1842480468963748569[15] = 0;
   out_1842480468963748569[16] = 0;
   out_1842480468963748569[17] = 0;
   out_1842480468963748569[18] = 0;
   out_1842480468963748569[19] = 0;
   out_1842480468963748569[20] = 1.0;
   out_1842480468963748569[21] = 0;
   out_1842480468963748569[22] = 0;
   out_1842480468963748569[23] = 0;
   out_1842480468963748569[24] = 0;
   out_1842480468963748569[25] = 0;
   out_1842480468963748569[26] = 0;
   out_1842480468963748569[27] = 0;
   out_1842480468963748569[28] = 0;
   out_1842480468963748569[29] = 0;
   out_1842480468963748569[30] = 1.0;
   out_1842480468963748569[31] = 0;
   out_1842480468963748569[32] = 0;
   out_1842480468963748569[33] = 0;
   out_1842480468963748569[34] = 0;
   out_1842480468963748569[35] = 0;
   out_1842480468963748569[36] = 0;
   out_1842480468963748569[37] = 0;
   out_1842480468963748569[38] = 0;
   out_1842480468963748569[39] = 0;
   out_1842480468963748569[40] = 1.0;
   out_1842480468963748569[41] = 0;
   out_1842480468963748569[42] = 0;
   out_1842480468963748569[43] = 0;
   out_1842480468963748569[44] = 0;
   out_1842480468963748569[45] = 0;
   out_1842480468963748569[46] = 0;
   out_1842480468963748569[47] = 0;
   out_1842480468963748569[48] = 0;
   out_1842480468963748569[49] = 0;
   out_1842480468963748569[50] = 1.0;
   out_1842480468963748569[51] = 0;
   out_1842480468963748569[52] = 0;
   out_1842480468963748569[53] = 0;
   out_1842480468963748569[54] = 0;
   out_1842480468963748569[55] = 0;
   out_1842480468963748569[56] = 0;
   out_1842480468963748569[57] = 0;
   out_1842480468963748569[58] = 0;
   out_1842480468963748569[59] = 0;
   out_1842480468963748569[60] = 1.0;
   out_1842480468963748569[61] = 0;
   out_1842480468963748569[62] = 0;
   out_1842480468963748569[63] = 0;
   out_1842480468963748569[64] = 0;
   out_1842480468963748569[65] = 0;
   out_1842480468963748569[66] = 0;
   out_1842480468963748569[67] = 0;
   out_1842480468963748569[68] = 0;
   out_1842480468963748569[69] = 0;
   out_1842480468963748569[70] = 1.0;
   out_1842480468963748569[71] = 0;
   out_1842480468963748569[72] = 0;
   out_1842480468963748569[73] = 0;
   out_1842480468963748569[74] = 0;
   out_1842480468963748569[75] = 0;
   out_1842480468963748569[76] = 0;
   out_1842480468963748569[77] = 0;
   out_1842480468963748569[78] = 0;
   out_1842480468963748569[79] = 0;
   out_1842480468963748569[80] = 1.0;
}
void f_fun(double *state, double dt, double *out_842551885572076045) {
   out_842551885572076045[0] = state[0];
   out_842551885572076045[1] = state[1];
   out_842551885572076045[2] = state[2];
   out_842551885572076045[3] = state[3];
   out_842551885572076045[4] = state[4];
   out_842551885572076045[5] = dt*((-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]))*state[6] - 9.8000000000000007*state[8] + stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*state[1]) + (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*state[4])) + state[5];
   out_842551885572076045[6] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*state[4])) + state[6];
   out_842551885572076045[7] = state[7];
   out_842551885572076045[8] = state[8];
}
void F_fun(double *state, double dt, double *out_3512251755428273731) {
   out_3512251755428273731[0] = 1;
   out_3512251755428273731[1] = 0;
   out_3512251755428273731[2] = 0;
   out_3512251755428273731[3] = 0;
   out_3512251755428273731[4] = 0;
   out_3512251755428273731[5] = 0;
   out_3512251755428273731[6] = 0;
   out_3512251755428273731[7] = 0;
   out_3512251755428273731[8] = 0;
   out_3512251755428273731[9] = 0;
   out_3512251755428273731[10] = 1;
   out_3512251755428273731[11] = 0;
   out_3512251755428273731[12] = 0;
   out_3512251755428273731[13] = 0;
   out_3512251755428273731[14] = 0;
   out_3512251755428273731[15] = 0;
   out_3512251755428273731[16] = 0;
   out_3512251755428273731[17] = 0;
   out_3512251755428273731[18] = 0;
   out_3512251755428273731[19] = 0;
   out_3512251755428273731[20] = 1;
   out_3512251755428273731[21] = 0;
   out_3512251755428273731[22] = 0;
   out_3512251755428273731[23] = 0;
   out_3512251755428273731[24] = 0;
   out_3512251755428273731[25] = 0;
   out_3512251755428273731[26] = 0;
   out_3512251755428273731[27] = 0;
   out_3512251755428273731[28] = 0;
   out_3512251755428273731[29] = 0;
   out_3512251755428273731[30] = 1;
   out_3512251755428273731[31] = 0;
   out_3512251755428273731[32] = 0;
   out_3512251755428273731[33] = 0;
   out_3512251755428273731[34] = 0;
   out_3512251755428273731[35] = 0;
   out_3512251755428273731[36] = 0;
   out_3512251755428273731[37] = 0;
   out_3512251755428273731[38] = 0;
   out_3512251755428273731[39] = 0;
   out_3512251755428273731[40] = 1;
   out_3512251755428273731[41] = 0;
   out_3512251755428273731[42] = 0;
   out_3512251755428273731[43] = 0;
   out_3512251755428273731[44] = 0;
   out_3512251755428273731[45] = dt*(stiffness_front*(-state[2] - state[3] + state[7])/(mass*state[1]) + (-stiffness_front - stiffness_rear)*state[5]/(mass*state[4]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[6]/(mass*state[4]));
   out_3512251755428273731[46] = -dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(mass*pow(state[1], 2));
   out_3512251755428273731[47] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3512251755428273731[48] = -dt*stiffness_front*state[0]/(mass*state[1]);
   out_3512251755428273731[49] = dt*((-1 - (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*pow(state[4], 2)))*state[6] - (-stiffness_front*state[0] - stiffness_rear*state[0])*state[5]/(mass*pow(state[4], 2)));
   out_3512251755428273731[50] = dt*(-stiffness_front*state[0] - stiffness_rear*state[0])/(mass*state[4]) + 1;
   out_3512251755428273731[51] = dt*(-state[4] + (-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(mass*state[4]));
   out_3512251755428273731[52] = dt*stiffness_front*state[0]/(mass*state[1]);
   out_3512251755428273731[53] = -9.8000000000000007*dt;
   out_3512251755428273731[54] = dt*(center_to_front*stiffness_front*(-state[2] - state[3] + state[7])/(rotational_inertia*state[1]) + (-center_to_front*stiffness_front + center_to_rear*stiffness_rear)*state[5]/(rotational_inertia*state[4]) + (-pow(center_to_front, 2)*stiffness_front - pow(center_to_rear, 2)*stiffness_rear)*state[6]/(rotational_inertia*state[4]));
   out_3512251755428273731[55] = -center_to_front*dt*stiffness_front*(-state[2] - state[3] + state[7])*state[0]/(rotational_inertia*pow(state[1], 2));
   out_3512251755428273731[56] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3512251755428273731[57] = -center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3512251755428273731[58] = dt*(-(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])*state[5]/(rotational_inertia*pow(state[4], 2)) - (-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])*state[6]/(rotational_inertia*pow(state[4], 2)));
   out_3512251755428273731[59] = dt*(-center_to_front*stiffness_front*state[0] + center_to_rear*stiffness_rear*state[0])/(rotational_inertia*state[4]);
   out_3512251755428273731[60] = dt*(-pow(center_to_front, 2)*stiffness_front*state[0] - pow(center_to_rear, 2)*stiffness_rear*state[0])/(rotational_inertia*state[4]) + 1;
   out_3512251755428273731[61] = center_to_front*dt*stiffness_front*state[0]/(rotational_inertia*state[1]);
   out_3512251755428273731[62] = 0;
   out_3512251755428273731[63] = 0;
   out_3512251755428273731[64] = 0;
   out_3512251755428273731[65] = 0;
   out_3512251755428273731[66] = 0;
   out_3512251755428273731[67] = 0;
   out_3512251755428273731[68] = 0;
   out_3512251755428273731[69] = 0;
   out_3512251755428273731[70] = 1;
   out_3512251755428273731[71] = 0;
   out_3512251755428273731[72] = 0;
   out_3512251755428273731[73] = 0;
   out_3512251755428273731[74] = 0;
   out_3512251755428273731[75] = 0;
   out_3512251755428273731[76] = 0;
   out_3512251755428273731[77] = 0;
   out_3512251755428273731[78] = 0;
   out_3512251755428273731[79] = 0;
   out_3512251755428273731[80] = 1;
}
void h_25(double *state, double *unused, double *out_3509543787442081958) {
   out_3509543787442081958[0] = state[6];
}
void H_25(double *state, double *unused, double *out_7903859779247712057) {
   out_7903859779247712057[0] = 0;
   out_7903859779247712057[1] = 0;
   out_7903859779247712057[2] = 0;
   out_7903859779247712057[3] = 0;
   out_7903859779247712057[4] = 0;
   out_7903859779247712057[5] = 0;
   out_7903859779247712057[6] = 1;
   out_7903859779247712057[7] = 0;
   out_7903859779247712057[8] = 0;
}
void h_24(double *state, double *unused, double *out_2255043970042255686) {
   out_2255043970042255686[0] = state[4];
   out_2255043970042255686[1] = state[5];
}
void H_24(double *state, double *unused, double *out_1324205406821483168) {
   out_1324205406821483168[0] = 0;
   out_1324205406821483168[1] = 0;
   out_1324205406821483168[2] = 0;
   out_1324205406821483168[3] = 0;
   out_1324205406821483168[4] = 1;
   out_1324205406821483168[5] = 0;
   out_1324205406821483168[6] = 0;
   out_1324205406821483168[7] = 0;
   out_1324205406821483168[8] = 0;
   out_1324205406821483168[9] = 0;
   out_1324205406821483168[10] = 0;
   out_1324205406821483168[11] = 0;
   out_1324205406821483168[12] = 0;
   out_1324205406821483168[13] = 0;
   out_1324205406821483168[14] = 1;
   out_1324205406821483168[15] = 0;
   out_1324205406821483168[16] = 0;
   out_1324205406821483168[17] = 0;
}
void h_30(double *state, double *unused, double *out_5799483001583618476) {
   out_5799483001583618476[0] = state[4];
}
void H_30(double *state, double *unused, double *out_6015187964334231361) {
   out_6015187964334231361[0] = 0;
   out_6015187964334231361[1] = 0;
   out_6015187964334231361[2] = 0;
   out_6015187964334231361[3] = 0;
   out_6015187964334231361[4] = 1;
   out_6015187964334231361[5] = 0;
   out_6015187964334231361[6] = 0;
   out_6015187964334231361[7] = 0;
   out_6015187964334231361[8] = 0;
}
void h_26(double *state, double *unused, double *out_5212117637697232327) {
   out_5212117637697232327[0] = state[7];
}
void H_26(double *state, double *unused, double *out_6801380975587783335) {
   out_6801380975587783335[0] = 0;
   out_6801380975587783335[1] = 0;
   out_6801380975587783335[2] = 0;
   out_6801380975587783335[3] = 0;
   out_6801380975587783335[4] = 0;
   out_6801380975587783335[5] = 0;
   out_6801380975587783335[6] = 0;
   out_6801380975587783335[7] = 1;
   out_6801380975587783335[8] = 0;
}
void h_27(double *state, double *unused, double *out_1716363428393242989) {
   out_1716363428393242989[0] = state[3];
}
void H_27(double *state, double *unused, double *out_3840424652533806450) {
   out_3840424652533806450[0] = 0;
   out_3840424652533806450[1] = 0;
   out_3840424652533806450[2] = 0;
   out_3840424652533806450[3] = 1;
   out_3840424652533806450[4] = 0;
   out_3840424652533806450[5] = 0;
   out_3840424652533806450[6] = 0;
   out_3840424652533806450[7] = 0;
   out_3840424652533806450[8] = 0;
}
void h_29(double *state, double *unused, double *out_5353812956647265339) {
   out_5353812956647265339[0] = state[1];
}
void H_29(double *state, double *unused, double *out_6525419308648623545) {
   out_6525419308648623545[0] = 0;
   out_6525419308648623545[1] = 1;
   out_6525419308648623545[2] = 0;
   out_6525419308648623545[3] = 0;
   out_6525419308648623545[4] = 0;
   out_6525419308648623545[5] = 0;
   out_6525419308648623545[6] = 0;
   out_6525419308648623545[7] = 0;
   out_6525419308648623545[8] = 0;
}
void h_28(double *state, double *unused, double *out_9022403054223609326) {
   out_9022403054223609326[0] = state[0];
}
void H_28(double *state, double *unused, double *out_1443020291579092971) {
   out_1443020291579092971[0] = 1;
   out_1443020291579092971[1] = 0;
   out_1443020291579092971[2] = 0;
   out_1443020291579092971[3] = 0;
   out_1443020291579092971[4] = 0;
   out_1443020291579092971[5] = 0;
   out_1443020291579092971[6] = 0;
   out_1443020291579092971[7] = 0;
   out_1443020291579092971[8] = 0;
}
void h_31(double *state, double *unused, double *out_406924308367068240) {
   out_406924308367068240[0] = state[8];
}
void H_31(double *state, double *unused, double *out_6175172873354431859) {
   out_6175172873354431859[0] = 0;
   out_6175172873354431859[1] = 0;
   out_6175172873354431859[2] = 0;
   out_6175172873354431859[3] = 0;
   out_6175172873354431859[4] = 0;
   out_6175172873354431859[5] = 0;
   out_6175172873354431859[6] = 0;
   out_6175172873354431859[7] = 0;
   out_6175172873354431859[8] = 1;
}
#include <eigen3/Eigen/Dense>
#include <iostream>

typedef Eigen::Matrix<double, DIM, DIM, Eigen::RowMajor> DDM;
typedef Eigen::Matrix<double, EDIM, EDIM, Eigen::RowMajor> EEM;
typedef Eigen::Matrix<double, DIM, EDIM, Eigen::RowMajor> DEM;

void predict(double *in_x, double *in_P, double *in_Q, double dt) {
  typedef Eigen::Matrix<double, MEDIM, MEDIM, Eigen::RowMajor> RRM;

  double nx[DIM] = {0};
  double in_F[EDIM*EDIM] = {0};

  // functions from sympy
  f_fun(in_x, dt, nx);
  F_fun(in_x, dt, in_F);


  EEM F(in_F);
  EEM P(in_P);
  EEM Q(in_Q);

  RRM F_main = F.topLeftCorner(MEDIM, MEDIM);
  P.topLeftCorner(MEDIM, MEDIM) = (F_main * P.topLeftCorner(MEDIM, MEDIM)) * F_main.transpose();
  P.topRightCorner(MEDIM, EDIM - MEDIM) = F_main * P.topRightCorner(MEDIM, EDIM - MEDIM);
  P.bottomLeftCorner(EDIM - MEDIM, MEDIM) = P.bottomLeftCorner(EDIM - MEDIM, MEDIM) * F_main.transpose();

  P = P + dt*Q;

  // copy out state
  memcpy(in_x, nx, DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
}

// note: extra_args dim only correct when null space projecting
// otherwise 1
template <int ZDIM, int EADIM, bool MAHA_TEST>
void update(double *in_x, double *in_P, Hfun h_fun, Hfun H_fun, Hfun Hea_fun, double *in_z, double *in_R, double *in_ea, double MAHA_THRESHOLD) {
  typedef Eigen::Matrix<double, ZDIM, ZDIM, Eigen::RowMajor> ZZM;
  typedef Eigen::Matrix<double, ZDIM, DIM, Eigen::RowMajor> ZDM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, EDIM, Eigen::RowMajor> XEM;
  //typedef Eigen::Matrix<double, EDIM, ZDIM, Eigen::RowMajor> EZM;
  typedef Eigen::Matrix<double, Eigen::Dynamic, 1> X1M;
  typedef Eigen::Matrix<double, Eigen::Dynamic, Eigen::Dynamic, Eigen::RowMajor> XXM;

  double in_hx[ZDIM] = {0};
  double in_H[ZDIM * DIM] = {0};
  double in_H_mod[EDIM * DIM] = {0};
  double delta_x[EDIM] = {0};
  double x_new[DIM] = {0};


  // state x, P
  Eigen::Matrix<double, ZDIM, 1> z(in_z);
  EEM P(in_P);
  ZZM pre_R(in_R);

  // functions from sympy
  h_fun(in_x, in_ea, in_hx);
  H_fun(in_x, in_ea, in_H);
  ZDM pre_H(in_H);

  // get y (y = z - hx)
  Eigen::Matrix<double, ZDIM, 1> pre_y(in_hx); pre_y = z - pre_y;
  X1M y; XXM H; XXM R;
  if (Hea_fun){
    typedef Eigen::Matrix<double, ZDIM, EADIM, Eigen::RowMajor> ZAM;
    double in_Hea[ZDIM * EADIM] = {0};
    Hea_fun(in_x, in_ea, in_Hea);
    ZAM Hea(in_Hea);
    XXM A = Hea.transpose().fullPivLu().kernel();


    y = A.transpose() * pre_y;
    H = A.transpose() * pre_H;
    R = A.transpose() * pre_R * A;
  } else {
    y = pre_y;
    H = pre_H;
    R = pre_R;
  }
  // get modified H
  H_mod_fun(in_x, in_H_mod);
  DEM H_mod(in_H_mod);
  XEM H_err = H * H_mod;

  // Do mahalobis distance test
  if (MAHA_TEST){
    XXM a = (H_err * P * H_err.transpose() + R).inverse();
    double maha_dist = y.transpose() * a * y;
    if (maha_dist > MAHA_THRESHOLD){
      R = 1.0e16 * R;
    }
  }

  // Outlier resilient weighting
  double weight = 1;//(1.5)/(1 + y.squaredNorm()/R.sum());

  // kalman gains and I_KH
  XXM S = ((H_err * P) * H_err.transpose()) + R/weight;
  XEM KT = S.fullPivLu().solve(H_err * P.transpose());
  //EZM K = KT.transpose(); TODO: WHY DOES THIS NOT COMPILE?
  //EZM K = S.fullPivLu().solve(H_err * P.transpose()).transpose();
  //std::cout << "Here is the matrix rot:\n" << K << std::endl;
  EEM I_KH = Eigen::Matrix<double, EDIM, EDIM>::Identity() - (KT.transpose() * H_err);

  // update state by injecting dx
  Eigen::Matrix<double, EDIM, 1> dx(delta_x);
  dx  = (KT.transpose() * y);
  memcpy(delta_x, dx.data(), EDIM * sizeof(double));
  err_fun(in_x, delta_x, x_new);
  Eigen::Matrix<double, DIM, 1> x(x_new);

  // update cov
  P = ((I_KH * P) * I_KH.transpose()) + ((KT.transpose() * R) * KT);

  // copy out state
  memcpy(in_x, x.data(), DIM * sizeof(double));
  memcpy(in_P, P.data(), EDIM * EDIM * sizeof(double));
  memcpy(in_z, y.data(), y.rows() * sizeof(double));
}




}
extern "C" {

void car_update_25(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_25, H_25, NULL, in_z, in_R, in_ea, MAHA_THRESH_25);
}
void car_update_24(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<2, 3, 0>(in_x, in_P, h_24, H_24, NULL, in_z, in_R, in_ea, MAHA_THRESH_24);
}
void car_update_30(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_30, H_30, NULL, in_z, in_R, in_ea, MAHA_THRESH_30);
}
void car_update_26(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_26, H_26, NULL, in_z, in_R, in_ea, MAHA_THRESH_26);
}
void car_update_27(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_27, H_27, NULL, in_z, in_R, in_ea, MAHA_THRESH_27);
}
void car_update_29(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_29, H_29, NULL, in_z, in_R, in_ea, MAHA_THRESH_29);
}
void car_update_28(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_28, H_28, NULL, in_z, in_R, in_ea, MAHA_THRESH_28);
}
void car_update_31(double *in_x, double *in_P, double *in_z, double *in_R, double *in_ea) {
  update<1, 3, 0>(in_x, in_P, h_31, H_31, NULL, in_z, in_R, in_ea, MAHA_THRESH_31);
}
void car_err_fun(double *nom_x, double *delta_x, double *out_7615378422295250943) {
  err_fun(nom_x, delta_x, out_7615378422295250943);
}
void car_inv_err_fun(double *nom_x, double *true_x, double *out_7234727336485135895) {
  inv_err_fun(nom_x, true_x, out_7234727336485135895);
}
void car_H_mod_fun(double *state, double *out_1842480468963748569) {
  H_mod_fun(state, out_1842480468963748569);
}
void car_f_fun(double *state, double dt, double *out_842551885572076045) {
  f_fun(state,  dt, out_842551885572076045);
}
void car_F_fun(double *state, double dt, double *out_3512251755428273731) {
  F_fun(state,  dt, out_3512251755428273731);
}
void car_h_25(double *state, double *unused, double *out_3509543787442081958) {
  h_25(state, unused, out_3509543787442081958);
}
void car_H_25(double *state, double *unused, double *out_7903859779247712057) {
  H_25(state, unused, out_7903859779247712057);
}
void car_h_24(double *state, double *unused, double *out_2255043970042255686) {
  h_24(state, unused, out_2255043970042255686);
}
void car_H_24(double *state, double *unused, double *out_1324205406821483168) {
  H_24(state, unused, out_1324205406821483168);
}
void car_h_30(double *state, double *unused, double *out_5799483001583618476) {
  h_30(state, unused, out_5799483001583618476);
}
void car_H_30(double *state, double *unused, double *out_6015187964334231361) {
  H_30(state, unused, out_6015187964334231361);
}
void car_h_26(double *state, double *unused, double *out_5212117637697232327) {
  h_26(state, unused, out_5212117637697232327);
}
void car_H_26(double *state, double *unused, double *out_6801380975587783335) {
  H_26(state, unused, out_6801380975587783335);
}
void car_h_27(double *state, double *unused, double *out_1716363428393242989) {
  h_27(state, unused, out_1716363428393242989);
}
void car_H_27(double *state, double *unused, double *out_3840424652533806450) {
  H_27(state, unused, out_3840424652533806450);
}
void car_h_29(double *state, double *unused, double *out_5353812956647265339) {
  h_29(state, unused, out_5353812956647265339);
}
void car_H_29(double *state, double *unused, double *out_6525419308648623545) {
  H_29(state, unused, out_6525419308648623545);
}
void car_h_28(double *state, double *unused, double *out_9022403054223609326) {
  h_28(state, unused, out_9022403054223609326);
}
void car_H_28(double *state, double *unused, double *out_1443020291579092971) {
  H_28(state, unused, out_1443020291579092971);
}
void car_h_31(double *state, double *unused, double *out_406924308367068240) {
  h_31(state, unused, out_406924308367068240);
}
void car_H_31(double *state, double *unused, double *out_6175172873354431859) {
  H_31(state, unused, out_6175172873354431859);
}
void car_predict(double *in_x, double *in_P, double *in_Q, double dt) {
  predict(in_x, in_P, in_Q, dt);
}
void car_set_mass(double x) {
  set_mass(x);
}
void car_set_rotational_inertia(double x) {
  set_rotational_inertia(x);
}
void car_set_center_to_front(double x) {
  set_center_to_front(x);
}
void car_set_center_to_rear(double x) {
  set_center_to_rear(x);
}
void car_set_stiffness_front(double x) {
  set_stiffness_front(x);
}
void car_set_stiffness_rear(double x) {
  set_stiffness_rear(x);
}
}

const EKF car = {
  .name = "car",
  .kinds = { 25, 24, 30, 26, 27, 29, 28, 31 },
  .feature_kinds = {  },
  .f_fun = car_f_fun,
  .F_fun = car_F_fun,
  .err_fun = car_err_fun,
  .inv_err_fun = car_inv_err_fun,
  .H_mod_fun = car_H_mod_fun,
  .predict = car_predict,
  .hs = {
    { 25, car_h_25 },
    { 24, car_h_24 },
    { 30, car_h_30 },
    { 26, car_h_26 },
    { 27, car_h_27 },
    { 29, car_h_29 },
    { 28, car_h_28 },
    { 31, car_h_31 },
  },
  .Hs = {
    { 25, car_H_25 },
    { 24, car_H_24 },
    { 30, car_H_30 },
    { 26, car_H_26 },
    { 27, car_H_27 },
    { 29, car_H_29 },
    { 28, car_H_28 },
    { 31, car_H_31 },
  },
  .updates = {
    { 25, car_update_25 },
    { 24, car_update_24 },
    { 30, car_update_30 },
    { 26, car_update_26 },
    { 27, car_update_27 },
    { 29, car_update_29 },
    { 28, car_update_28 },
    { 31, car_update_31 },
  },
  .Hes = {
  },
  .sets = {
    { "mass", car_set_mass },
    { "rotational_inertia", car_set_rotational_inertia },
    { "center_to_front", car_set_center_to_front },
    { "center_to_rear", car_set_center_to_rear },
    { "stiffness_front", car_set_stiffness_front },
    { "stiffness_rear", car_set_stiffness_rear },
  },
  .extra_routines = {
  },
};

ekf_lib_init(car)
