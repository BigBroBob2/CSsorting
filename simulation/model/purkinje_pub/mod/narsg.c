/* Created by Language version: 7.7.0 */
/* NOT VECTORIZED */
#define NRN_VECTORIZED 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "mech_api.h"
#undef PI
#define nil 0
#include "md1redef.h"
#include "section.h"
#include "nrniv_mf.h"
#include "md2redef.h"
 
#if METHOD3
extern int _method3;
#endif

#if !NRNGPU
#undef exp
#define exp hoc_Exp
extern double hoc_Exp(double);
#endif
 
#define nrn_init _nrn_init__naRsg
#define _nrn_initial _nrn_initial__naRsg
#define nrn_cur _nrn_cur__naRsg
#define _nrn_current _nrn_current__naRsg
#define nrn_jacob _nrn_jacob__naRsg
#define nrn_state _nrn_state__naRsg
#define _net_receive _net_receive__naRsg 
#define activation activation__naRsg 
#define rates rates__naRsg 
 
#define _threadargscomma_ /**/
#define _threadargsprotocomma_ /**/
#define _threadargs_ /**/
#define _threadargsproto_ /**/
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 static double *_p; static Datum *_ppvar;
 
#define t nrn_threads->_t
#define dt nrn_threads->_dt
#define gbar _p[0]
#define gbar_columnindex 0
#define alpha _p[1]
#define alpha_columnindex 1
#define epsilon _p[2]
#define epsilon_columnindex 2
#define zeta _p[3]
#define zeta_columnindex 3
#define x1 _p[4]
#define x1_columnindex 4
#define x2 _p[5]
#define x2_columnindex 5
#define vshifta _p[6]
#define vshifta_columnindex 6
#define vshifti _p[7]
#define vshifti_columnindex 7
#define vshiftk _p[8]
#define vshiftk_columnindex 8
#define f04 _p[9]
#define f04_columnindex 9
#define ina _p[10]
#define ina_columnindex 10
#define g _p[11]
#define g_columnindex 11
#define C1 _p[12]
#define C1_columnindex 12
#define C2 _p[13]
#define C2_columnindex 13
#define C3 _p[14]
#define C3_columnindex 14
#define C4 _p[15]
#define C4_columnindex 15
#define C5 _p[16]
#define C5_columnindex 16
#define I1 _p[17]
#define I1_columnindex 17
#define I2 _p[18]
#define I2_columnindex 18
#define I3 _p[19]
#define I3_columnindex 19
#define I4 _p[20]
#define I4_columnindex 20
#define I5 _p[21]
#define I5_columnindex 21
#define O _p[22]
#define O_columnindex 22
#define B _p[23]
#define B_columnindex 23
#define I6 _p[24]
#define I6_columnindex 24
#define Ca _p[25]
#define Ca_columnindex 25
#define Ia _p[26]
#define Ia_columnindex 26
#define alfac _p[27]
#define alfac_columnindex 27
#define btfac _p[28]
#define btfac_columnindex 28
#define f01 _p[29]
#define f01_columnindex 29
#define f02 _p[30]
#define f02_columnindex 30
#define f03 _p[31]
#define f03_columnindex 31
#define f0O _p[32]
#define f0O_columnindex 32
#define fip _p[33]
#define fip_columnindex 33
#define f11 _p[34]
#define f11_columnindex 34
#define f12 _p[35]
#define f12_columnindex 35
#define f13 _p[36]
#define f13_columnindex 36
#define f14 _p[37]
#define f14_columnindex 37
#define f1n _p[38]
#define f1n_columnindex 38
#define fi1 _p[39]
#define fi1_columnindex 39
#define fi2 _p[40]
#define fi2_columnindex 40
#define fi3 _p[41]
#define fi3_columnindex 41
#define fi4 _p[42]
#define fi4_columnindex 42
#define fi5 _p[43]
#define fi5_columnindex 43
#define fin _p[44]
#define fin_columnindex 44
#define b01 _p[45]
#define b01_columnindex 45
#define b02 _p[46]
#define b02_columnindex 46
#define b03 _p[47]
#define b03_columnindex 47
#define b04 _p[48]
#define b04_columnindex 48
#define b0O _p[49]
#define b0O_columnindex 49
#define bip _p[50]
#define bip_columnindex 50
#define b11 _p[51]
#define b11_columnindex 51
#define b12 _p[52]
#define b12_columnindex 52
#define b13 _p[53]
#define b13_columnindex 53
#define b14 _p[54]
#define b14_columnindex 54
#define b1n _p[55]
#define b1n_columnindex 55
#define bi1 _p[56]
#define bi1_columnindex 56
#define bi2 _p[57]
#define bi2_columnindex 57
#define bi3 _p[58]
#define bi3_columnindex 58
#define bi4 _p[59]
#define bi4_columnindex 59
#define bi5 _p[60]
#define bi5_columnindex 60
#define bin _p[61]
#define bin_columnindex 61
#define ena _p[62]
#define ena_columnindex 62
#define qt _p[63]
#define qt_columnindex 63
#define DC1 _p[64]
#define DC1_columnindex 64
#define DC2 _p[65]
#define DC2_columnindex 65
#define DC3 _p[66]
#define DC3_columnindex 66
#define DC4 _p[67]
#define DC4_columnindex 67
#define DC5 _p[68]
#define DC5_columnindex 68
#define DI1 _p[69]
#define DI1_columnindex 69
#define DI2 _p[70]
#define DI2_columnindex 70
#define DI3 _p[71]
#define DI3_columnindex 71
#define DI4 _p[72]
#define DI4_columnindex 72
#define DI5 _p[73]
#define DI5_columnindex 73
#define DO _p[74]
#define DO_columnindex 74
#define DB _p[75]
#define DB_columnindex 75
#define DI6 _p[76]
#define DI6_columnindex 76
#define DCa _p[77]
#define DCa_columnindex 77
#define DIa _p[78]
#define DIa_columnindex 78
#define _g _p[79]
#define _g_columnindex 79
#define _ion_ena	*_ppvar[0]._pval
#define _ion_ina	*_ppvar[1]._pval
#define _ion_dinadv	*_ppvar[2]._pval
 
#if MAC
#if !defined(v)
#define v _mlhv
#endif
#if !defined(h)
#define h _mlhh
#endif
#endif
 
#if defined(__cplusplus)
extern "C" {
#endif
 static int hoc_nrnpointerindex =  -1;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_rates(void);
 static int _mechtype;
extern void _nrn_cacheloop_reg(int, int);
extern void hoc_register_prop_size(int, int, int);
extern void hoc_register_limits(int, HocParmLimits*);
extern void hoc_register_units(int, HocParmUnits*);
extern void nrn_promote(Prop*, int, int);
extern Memb_func* memb_func;
 
#define NMODL_TEXT 1
#if NMODL_TEXT
static const char* nmodl_file_text;
static const char* nmodl_filename;
extern void hoc_reg_nmodl_text(int, const char*);
extern void hoc_reg_nmodl_filename(int, const char*);
#endif

 extern void _nrn_setdata_reg(int, void(*)(Prop*));
 static void _setdata(Prop* _prop) {
 _p = _prop->param; _ppvar = _prop->dparam;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_naRsg", _hoc_setdata,
 "rates_naRsg", _hoc_rates,
 0, 0
};
 /* declare global and static user variables */
#define Coff Coff_naRsg
 double Coff = 0.5;
#define Con Con_naRsg
 double Con = 0.005;
#define Ooff Ooff_naRsg
 double Ooff = 0.005;
#define Oon Oon_naRsg
 double Oon = 0.75;
#define beta beta_naRsg
 double beta = 3;
#define delta delta_naRsg
 double delta = 40;
#define gamma gamma_naRsg
 double gamma = 150;
#define x6 x6_naRsg
 double x6 = -25;
#define x5 x5_naRsg
 double x5 = 1e+12;
#define x4 x4_naRsg
 double x4 = -1e+12;
#define x3 x3_naRsg
 double x3 = 1e+12;
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "Con_naRsg", "/ms",
 "Coff_naRsg", "/ms",
 "Oon_naRsg", "/ms",
 "Ooff_naRsg", "/ms",
 "beta_naRsg", "/ms",
 "gamma_naRsg", "/ms",
 "delta_naRsg", "/ms",
 "x3_naRsg", "mV",
 "x4_naRsg", "mV",
 "x5_naRsg", "mV",
 "x6_naRsg", "mV",
 "gbar_naRsg", "S/cm2",
 "alpha_naRsg", "/ms",
 "epsilon_naRsg", "/ms",
 "zeta_naRsg", "/ms",
 "x1_naRsg", "mV",
 "x2_naRsg", "mV",
 "vshifta_naRsg", "mV",
 "vshifti_naRsg", "mV",
 "f04_naRsg", "/ms",
 "ina_naRsg", "milliamp/cm2",
 "g_naRsg", "S/cm2",
 0,0
};
 static double B0 = 0;
 static double Ca0 = 0;
 static double C50 = 0;
 static double C40 = 0;
 static double C30 = 0;
 static double C20 = 0;
 static double C10 = 0;
 static double Ia0 = 0;
 static double I60 = 0;
 static double I50 = 0;
 static double I40 = 0;
 static double I30 = 0;
 static double I20 = 0;
 static double I10 = 0;
 static double O0 = 0;
 static double delta_t = 0.01;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "Con_naRsg", &Con_naRsg,
 "Coff_naRsg", &Coff_naRsg,
 "Oon_naRsg", &Oon_naRsg,
 "Ooff_naRsg", &Ooff_naRsg,
 "beta_naRsg", &beta_naRsg,
 "gamma_naRsg", &gamma_naRsg,
 "delta_naRsg", &delta_naRsg,
 "x3_naRsg", &x3_naRsg,
 "x4_naRsg", &x4_naRsg,
 "x5_naRsg", &x5_naRsg,
 "x6_naRsg", &x6_naRsg,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 0,0,0
};
 static double _sav_indep;
 static void nrn_alloc(Prop*);
static void  nrn_init(NrnThread*, _Memb_list*, int);
static void nrn_state(NrnThread*, _Memb_list*, int);
 static void nrn_cur(NrnThread*, _Memb_list*, int);
static void  nrn_jacob(NrnThread*, _Memb_list*, int);
 
static int _ode_count(int);
static void _ode_map(int, double**, double**, double*, Datum*, double*, int);
static void _ode_spec(NrnThread*, _Memb_list*, int);
static void _ode_matsol(NrnThread*, _Memb_list*, int);
 
#define _cvode_ieq _ppvar[3]._i
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"naRsg",
 "gbar_naRsg",
 "alpha_naRsg",
 "epsilon_naRsg",
 "zeta_naRsg",
 "x1_naRsg",
 "x2_naRsg",
 "vshifta_naRsg",
 "vshifti_naRsg",
 "vshiftk_naRsg",
 0,
 "f04_naRsg",
 "ina_naRsg",
 "g_naRsg",
 0,
 "C1_naRsg",
 "C2_naRsg",
 "C3_naRsg",
 "C4_naRsg",
 "C5_naRsg",
 "I1_naRsg",
 "I2_naRsg",
 "I3_naRsg",
 "I4_naRsg",
 "I5_naRsg",
 "O_naRsg",
 "B_naRsg",
 "I6_naRsg",
 "Ca_naRsg",
 "Ia_naRsg",
 0,
 0};
 static Symbol* _na_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 80, _prop);
 	/*initialize range parameters*/
 	gbar = 0.015;
 	alpha = 150;
 	epsilon = 1.75;
 	zeta = 0.03;
 	x1 = 20;
 	x2 = -20;
 	vshifta = 0;
 	vshifti = 0;
 	vshiftk = 0;
 	_prop->param = _p;
 	_prop->param_size = 80;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_na_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ena */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ina */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dinadv */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _narsg_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("na", -10000.);
 	_na_sym = hoc_lookup("na_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 80, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "na_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 naRsg narsg.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double q10 = 2.7;
static int _reset;
static char *modelname = "Rsg sodium channel";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(double);
 extern double *_getelm();
 
#define _MATELM1(_row,_col)	*(_getelm(_row + 1, _col + 1))
 
#define _RHS1(_arg) _coef1[_arg + 1]
 static double *_coef1;
 
#define _linmat1  1
 static void* _sparseobj1;
 static void* _cvsparseobj1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 
#define _RHS2(arg) _coef2[arg][13]
 static int _slist2[13];static double **_coef2;
 static void seqinitial();
 static int _slist1[13], _dlist1[13]; static double *_temp1;
 static int activation();
 
static int activation ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=1;_i<13;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
   /* ~ C1 <-> C2 ( f01 , b01 )*/
 f_flux =  f01 * C1 ;
 b_flux =  b01 * C2 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 5) += (f_flux - b_flux);
 
 _term =  f01 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  b01 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C3 ( f02 , b02 )*/
 f_flux =  f02 * C2 ;
 b_flux =  b02 * C3 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 4) += (f_flux - b_flux);
 
 _term =  f02 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  b02 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ C3 <-> C4 ( f03 , b03 )*/
 f_flux =  f03 * C3 ;
 b_flux =  b03 * C4 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 3) += (f_flux - b_flux);
 
 _term =  f03 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  b03 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C4 <-> C5 ( f04 , b04 )*/
 f_flux =  f04 * C4 ;
 b_flux =  b04 * C5 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 2) += (f_flux - b_flux);
 
 _term =  f04 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  b04 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C5 <-> O ( f0O , b0O )*/
 f_flux =  f0O * C5 ;
 b_flux =  b0O * O ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 12) += (f_flux - b_flux);
 
 _term =  f0O ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 12 ,2)  -= _term;
 _term =  b0O ;
 _MATELM1( 2 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ O <-> B ( fip , bip )*/
 f_flux =  fip * O ;
 b_flux =  bip * B ;
 _RHS1( 12) -= (f_flux - b_flux);
 _RHS1( 1) += (f_flux - b_flux);
 
 _term =  fip ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 1 ,12)  -= _term;
 _term =  bip ;
 _MATELM1( 12 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ O <-> I6 ( fin , bin )*/
 f_flux =  fin * O ;
 b_flux =  bin * I6 ;
 _RHS1( 12) -= (f_flux - b_flux);
 
 _term =  fin ;
 _MATELM1( 12 ,12)  += _term;
 _term =  bin ;
 _MATELM1( 12 ,0)  -= _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( f11 , b11 )*/
 f_flux =  f11 * I1 ;
 b_flux =  b11 * I2 ;
 _RHS1( 11) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  f11 ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  b11 ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ I2 <-> I3 ( f12 , b12 )*/
 f_flux =  f12 * I2 ;
 b_flux =  b12 * I3 ;
 _RHS1( 10) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  f12 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  b12 ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ I3 <-> I4 ( f13 , b13 )*/
 f_flux =  f13 * I3 ;
 b_flux =  b13 * I4 ;
 _RHS1( 9) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  f13 ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  b13 ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ I4 <-> I5 ( f14 , b14 )*/
 f_flux =  f14 * I4 ;
 b_flux =  b14 * I5 ;
 _RHS1( 8) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  f14 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  b14 ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ I5 <-> I6 ( f1n , b1n )*/
 f_flux =  f1n * I5 ;
 b_flux =  b1n * I6 ;
 _RHS1( 7) -= (f_flux - b_flux);
 
 _term =  f1n ;
 _MATELM1( 7 ,7)  += _term;
 _term =  b1n ;
 _MATELM1( 7 ,0)  -= _term;
 /*REACTION*/
  /* ~ C1 <-> I1 ( fi1 , bi1 )*/
 f_flux =  fi1 * C1 ;
 b_flux =  bi1 * I1 ;
 _RHS1( 6) -= (f_flux - b_flux);
 _RHS1( 11) += (f_flux - b_flux);
 
 _term =  fi1 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 11 ,6)  -= _term;
 _term =  bi1 ;
 _MATELM1( 6 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ C2 <-> I2 ( fi2 , bi2 )*/
 f_flux =  fi2 * C2 ;
 b_flux =  bi2 * I2 ;
 _RHS1( 5) -= (f_flux - b_flux);
 _RHS1( 10) += (f_flux - b_flux);
 
 _term =  fi2 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 10 ,5)  -= _term;
 _term =  bi2 ;
 _MATELM1( 5 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ C3 <-> I3 ( fi3 , bi3 )*/
 f_flux =  fi3 * C3 ;
 b_flux =  bi3 * I3 ;
 _RHS1( 4) -= (f_flux - b_flux);
 _RHS1( 9) += (f_flux - b_flux);
 
 _term =  fi3 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 9 ,4)  -= _term;
 _term =  bi3 ;
 _MATELM1( 4 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ C4 <-> I4 ( fi4 , bi4 )*/
 f_flux =  fi4 * C4 ;
 b_flux =  bi4 * I4 ;
 _RHS1( 3) -= (f_flux - b_flux);
 _RHS1( 8) += (f_flux - b_flux);
 
 _term =  fi4 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 8 ,3)  -= _term;
 _term =  bi4 ;
 _MATELM1( 3 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ C5 <-> I5 ( fi5 , bi5 )*/
 f_flux =  fi5 * C5 ;
 b_flux =  bi5 * I5 ;
 _RHS1( 2) -= (f_flux - b_flux);
 _RHS1( 7) += (f_flux - b_flux);
 
 _term =  fi5 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 7 ,2)  -= _term;
 _term =  bi5 ;
 _MATELM1( 2 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  Ca = C1 + C2 + C3 + C4 + C5 ;
   Ia = I1 + I2 + I3 + I4 + I5 ;
    /* C1 + C2 + C3 + C4 + C5 + O + B + I1 + I2 + I3 + I4 + I5 + I6 = 1.0 */
 _RHS1(0) =  1.0;
 _MATELM1(0, 0) = 1;
 _RHS1(0) -= I6 ;
 _MATELM1(0, 7) = 1;
 _RHS1(0) -= I5 ;
 _MATELM1(0, 8) = 1;
 _RHS1(0) -= I4 ;
 _MATELM1(0, 9) = 1;
 _RHS1(0) -= I3 ;
 _MATELM1(0, 10) = 1;
 _RHS1(0) -= I2 ;
 _MATELM1(0, 11) = 1;
 _RHS1(0) -= I1 ;
 _MATELM1(0, 1) = 1;
 _RHS1(0) -= B ;
 _MATELM1(0, 12) = 1;
 _RHS1(0) -= O ;
 _MATELM1(0, 2) = 1;
 _RHS1(0) -= C5 ;
 _MATELM1(0, 3) = 1;
 _RHS1(0) -= C4 ;
 _MATELM1(0, 4) = 1;
 _RHS1(0) -= C3 ;
 _MATELM1(0, 5) = 1;
 _RHS1(0) -= C2 ;
 _MATELM1(0, 6) = 1;
 _RHS1(0) -= C1 ;
 /*CONSERVATION*/
   } return _reset;
 }
 
static void seqinitial ()
 {
   zero_matrix(_coef2, 13, 14);
{
  int _counte = -1;
  ++_counte;
 _coef2[_counte][0] -=  1.0 * bi1 ;
 _coef2[_counte][1] -=  1.0 * b01 ;
 _coef2[_counte][2] +=  1.0 * ( fi1 + f01 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][2] -=  1.0 * f01 ;
 _coef2[_counte][3] -=  1.0 * bi2 ;
 _coef2[_counte][4] -=  1.0 * b02 ;
 _coef2[_counte][1] +=  1.0 * ( b01 + fi2 + f02 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][1] -=  1.0 * f02 ;
 _coef2[_counte][5] -=  1.0 * bi3 ;
 _coef2[_counte][6] -=  1.0 * b03 ;
 _coef2[_counte][4] +=  1.0 * ( b02 + fi3 + f03 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][4] -=  1.0 * f03 ;
 _coef2[_counte][7] -=  1.0 * bi4 ;
 _coef2[_counte][8] -=  1.0 * b04 ;
 _coef2[_counte][6] +=  1.0 * ( b03 + fi4 + f04 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][6] -=  1.0 * f04 ;
 _coef2[_counte][9] -=  1.0 * bi5 ;
 _coef2[_counte][10] -=  1.0 * b0O ;
 _coef2[_counte][8] +=  1.0 * ( b04 + fi5 + f0O ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][8] -=  1.0 * f0O ;
 _coef2[_counte][11] -=  1.0 * bip ;
 _coef2[_counte][12] -=  1.0 * bin ;
 _coef2[_counte][10] +=  1.0 * ( b0O + fip + fin ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][10] -=  1.0 * fip ;
 _coef2[_counte][11] -=  1.0 * bip ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][2] -=  1.0 * fi1 ;
 _coef2[_counte][3] -=  1.0 * b11 ;
 _coef2[_counte][0] +=  1.0 * ( bi1 + f11 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][0] -=  1.0 * f11 ;
 _coef2[_counte][1] -=  1.0 * fi2 ;
 _coef2[_counte][5] -=  1.0 * b12 ;
 _coef2[_counte][3] +=  1.0 * ( b11 + bi2 + f12 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][3] -=  1.0 * f12 ;
 _coef2[_counte][4] -=  1.0 * fi3 ;
 _coef2[_counte][7] -=  1.0 * bi3 ;
 _coef2[_counte][5] +=  1.0 * ( b12 + bi3 + f13 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][5] -=  1.0 * f13 ;
 _coef2[_counte][6] -=  1.0 * fi4 ;
 _coef2[_counte][9] -=  1.0 * b14 ;
 _coef2[_counte][7] +=  1.0 * ( b13 + bi4 + f14 ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][7] -=  1.0 * f14 ;
 _coef2[_counte][8] -=  1.0 * fi5 ;
 _coef2[_counte][12] -=  1.0 * b1n ;
 _coef2[_counte][9] +=  1.0 * ( b14 + bi5 + f1n ) ;
 _RHS2(_counte) -=  0.0 ;
   ;
  ++_counte;
 _coef2[_counte][2] -=  1.0 ;
 _coef2[_counte][1] -=  1.0 ;
 _coef2[_counte][4] -=  1.0 ;
 _coef2[_counte][6] -=  1.0 ;
 _coef2[_counte][8] -=  1.0 ;
 _coef2[_counte][10] -=  1.0 ;
 _coef2[_counte][11] -=  1.0 ;
 _coef2[_counte][0] -=  1.0 ;
 _coef2[_counte][3] -=  1.0 ;
 _coef2[_counte][5] -=  1.0 ;
 _coef2[_counte][7] -=  1.0 ;
 _coef2[_counte][9] -=  1.0 ;
 _coef2[_counte][12] -=  1.0 ;
 _RHS2(_counte) -=  1.0 ;
   ;
 
}
 }
 
static int  rates (  double _lv ) {
   alfac = pow( ( Oon / Con ) , ( 1.0 / 4.0 ) ) ;
   btfac = pow( ( Ooff / Coff ) , ( 1.0 / 4.0 ) ) ;
   f01 = 4.0 * alpha * exp ( ( _lv ) / ( x1 ) ) * qt ;
   f02 = 3.0 * alpha * exp ( ( _lv ) / ( x1 ) ) * qt ;
   f03 = 2.0 * alpha * exp ( ( _lv ) / ( x1 ) ) * qt ;
   f04 = 1.0 * alpha * exp ( ( _lv ) / ( x1 ) ) * qt ;
   f0O = gamma * qt ;
   fip = epsilon * qt ;
   f11 = 4.0 * alpha * alfac * exp ( ( _lv + vshifti ) / x1 ) * qt ;
   f12 = 3.0 * alpha * alfac * exp ( ( _lv + vshifti ) / x1 ) * qt ;
   f13 = 2.0 * alpha * alfac * exp ( ( _lv + vshifti ) / x1 ) * qt ;
   f14 = 1.0 * alpha * alfac * exp ( ( _lv + vshifti ) / x1 ) * qt ;
   f1n = gamma * qt ;
   fi1 = Con * qt ;
   fi2 = Con * alfac * qt ;
   fi3 = Con * pow( alfac , 2.0 ) * qt ;
   fi4 = Con * pow( alfac , 3.0 ) * qt ;
   fi5 = Con * pow( alfac , 4.0 ) * qt ;
   fin = Oon * qt ;
   b01 = 1.0 * beta * exp ( ( _lv + vshifta ) / ( x2 + vshiftk ) ) * qt ;
   b02 = 2.0 * beta * exp ( ( _lv + vshifta ) / ( x2 + vshiftk ) ) * qt ;
   b03 = 3.0 * beta * exp ( ( _lv + vshifta ) / ( x2 + vshiftk ) ) * qt ;
   b04 = 4.0 * beta * exp ( ( _lv + vshifta ) / ( x2 + vshiftk ) ) * qt ;
   b0O = delta * qt ;
   bip = zeta * exp ( _lv / x6 ) * qt ;
   b11 = 1.0 * beta * btfac * exp ( ( _lv + vshifti ) / x2 ) * qt ;
   b12 = 2.0 * beta * btfac * exp ( ( _lv + vshifti ) / x2 ) * qt ;
   b13 = 3.0 * beta * btfac * exp ( ( _lv + vshifti ) / x2 ) * qt ;
   b14 = 4.0 * beta * btfac * exp ( ( _lv + vshifti ) / x2 ) * qt ;
   b1n = delta * qt ;
   bi1 = Coff * qt ;
   bi2 = Coff * btfac * qt ;
   bi3 = Coff * pow( btfac , 2.0 ) * qt ;
   bi4 = Coff * pow( btfac , 3.0 ) * qt ;
   bi5 = Coff * pow( btfac , 4.0 ) * qt ;
   bin = Ooff * qt ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   _r = 1.;
 rates (  *getarg(1) );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<13;_i++) _p[_dlist1[_i]] = 0.0;}
 rates ( _threadargscomma_ v ) ;
 /* ~ C1 <-> C2 ( f01 , b01 )*/
 f_flux =  f01 * C1 ;
 b_flux =  b01 * C2 ;
 DC1 -= (f_flux - b_flux);
 DC2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> C3 ( f02 , b02 )*/
 f_flux =  f02 * C2 ;
 b_flux =  b02 * C3 ;
 DC2 -= (f_flux - b_flux);
 DC3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> C4 ( f03 , b03 )*/
 f_flux =  f03 * C3 ;
 b_flux =  b03 * C4 ;
 DC3 -= (f_flux - b_flux);
 DC4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C4 <-> C5 ( f04 , b04 )*/
 f_flux =  f04 * C4 ;
 b_flux =  b04 * C5 ;
 DC4 -= (f_flux - b_flux);
 DC5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C5 <-> O ( f0O , b0O )*/
 f_flux =  f0O * C5 ;
 b_flux =  b0O * O ;
 DC5 -= (f_flux - b_flux);
 DO += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ O <-> B ( fip , bip )*/
 f_flux =  fip * O ;
 b_flux =  bip * B ;
 DO -= (f_flux - b_flux);
 DB += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ O <-> I6 ( fin , bin )*/
 f_flux =  fin * O ;
 b_flux =  bin * I6 ;
 DO -= (f_flux - b_flux);
 DI6 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I1 <-> I2 ( f11 , b11 )*/
 f_flux =  f11 * I1 ;
 b_flux =  b11 * I2 ;
 DI1 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I2 <-> I3 ( f12 , b12 )*/
 f_flux =  f12 * I2 ;
 b_flux =  b12 * I3 ;
 DI2 -= (f_flux - b_flux);
 DI3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I3 <-> I4 ( f13 , b13 )*/
 f_flux =  f13 * I3 ;
 b_flux =  b13 * I4 ;
 DI3 -= (f_flux - b_flux);
 DI4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I4 <-> I5 ( f14 , b14 )*/
 f_flux =  f14 * I4 ;
 b_flux =  b14 * I5 ;
 DI4 -= (f_flux - b_flux);
 DI5 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ I5 <-> I6 ( f1n , b1n )*/
 f_flux =  f1n * I5 ;
 b_flux =  b1n * I6 ;
 DI5 -= (f_flux - b_flux);
 DI6 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C1 <-> I1 ( fi1 , bi1 )*/
 f_flux =  fi1 * C1 ;
 b_flux =  bi1 * I1 ;
 DC1 -= (f_flux - b_flux);
 DI1 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C2 <-> I2 ( fi2 , bi2 )*/
 f_flux =  fi2 * C2 ;
 b_flux =  bi2 * I2 ;
 DC2 -= (f_flux - b_flux);
 DI2 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C3 <-> I3 ( fi3 , bi3 )*/
 f_flux =  fi3 * C3 ;
 b_flux =  bi3 * I3 ;
 DC3 -= (f_flux - b_flux);
 DI3 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C4 <-> I4 ( fi4 , bi4 )*/
 f_flux =  fi4 * C4 ;
 b_flux =  bi4 * I4 ;
 DC4 -= (f_flux - b_flux);
 DI4 += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ C5 <-> I5 ( fi5 , bi5 )*/
 f_flux =  fi5 * C5 ;
 b_flux =  bi5 * I5 ;
 DC5 -= (f_flux - b_flux);
 DI5 += (f_flux - b_flux);
 
 /*REACTION*/
  Ca = C1 + C2 + C3 + C4 + C5 ;
 Ia = I1 + I2 + I3 + I4 + I5 ;
  /* C1 + C2 + C3 + C4 + C5 + O + B + I1 + I2 + I3 + I4 + I5 + I6 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<13;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} }
 rates ( _threadargscomma_ v ) ;
 /* ~ C1 <-> C2 ( f01 , b01 )*/
 _term =  f01 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 5 ,6)  -= _term;
 _term =  b01 ;
 _MATELM1( 6 ,5)  -= _term;
 _MATELM1( 5 ,5)  += _term;
 /*REACTION*/
  /* ~ C2 <-> C3 ( f02 , b02 )*/
 _term =  f02 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 4 ,5)  -= _term;
 _term =  b02 ;
 _MATELM1( 5 ,4)  -= _term;
 _MATELM1( 4 ,4)  += _term;
 /*REACTION*/
  /* ~ C3 <-> C4 ( f03 , b03 )*/
 _term =  f03 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 3 ,4)  -= _term;
 _term =  b03 ;
 _MATELM1( 4 ,3)  -= _term;
 _MATELM1( 3 ,3)  += _term;
 /*REACTION*/
  /* ~ C4 <-> C5 ( f04 , b04 )*/
 _term =  f04 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 2 ,3)  -= _term;
 _term =  b04 ;
 _MATELM1( 3 ,2)  -= _term;
 _MATELM1( 2 ,2)  += _term;
 /*REACTION*/
  /* ~ C5 <-> O ( f0O , b0O )*/
 _term =  f0O ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 12 ,2)  -= _term;
 _term =  b0O ;
 _MATELM1( 2 ,12)  -= _term;
 _MATELM1( 12 ,12)  += _term;
 /*REACTION*/
  /* ~ O <-> B ( fip , bip )*/
 _term =  fip ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 1 ,12)  -= _term;
 _term =  bip ;
 _MATELM1( 12 ,1)  -= _term;
 _MATELM1( 1 ,1)  += _term;
 /*REACTION*/
  /* ~ O <-> I6 ( fin , bin )*/
 _term =  fin ;
 _MATELM1( 12 ,12)  += _term;
 _MATELM1( 0 ,12)  -= _term;
 _term =  bin ;
 _MATELM1( 12 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ I1 <-> I2 ( f11 , b11 )*/
 _term =  f11 ;
 _MATELM1( 11 ,11)  += _term;
 _MATELM1( 10 ,11)  -= _term;
 _term =  b11 ;
 _MATELM1( 11 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ I2 <-> I3 ( f12 , b12 )*/
 _term =  f12 ;
 _MATELM1( 10 ,10)  += _term;
 _MATELM1( 9 ,10)  -= _term;
 _term =  b12 ;
 _MATELM1( 10 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ I3 <-> I4 ( f13 , b13 )*/
 _term =  f13 ;
 _MATELM1( 9 ,9)  += _term;
 _MATELM1( 8 ,9)  -= _term;
 _term =  b13 ;
 _MATELM1( 9 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ I4 <-> I5 ( f14 , b14 )*/
 _term =  f14 ;
 _MATELM1( 8 ,8)  += _term;
 _MATELM1( 7 ,8)  -= _term;
 _term =  b14 ;
 _MATELM1( 8 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  /* ~ I5 <-> I6 ( f1n , b1n )*/
 _term =  f1n ;
 _MATELM1( 7 ,7)  += _term;
 _MATELM1( 0 ,7)  -= _term;
 _term =  b1n ;
 _MATELM1( 7 ,0)  -= _term;
 _MATELM1( 0 ,0)  += _term;
 /*REACTION*/
  /* ~ C1 <-> I1 ( fi1 , bi1 )*/
 _term =  fi1 ;
 _MATELM1( 6 ,6)  += _term;
 _MATELM1( 11 ,6)  -= _term;
 _term =  bi1 ;
 _MATELM1( 6 ,11)  -= _term;
 _MATELM1( 11 ,11)  += _term;
 /*REACTION*/
  /* ~ C2 <-> I2 ( fi2 , bi2 )*/
 _term =  fi2 ;
 _MATELM1( 5 ,5)  += _term;
 _MATELM1( 10 ,5)  -= _term;
 _term =  bi2 ;
 _MATELM1( 5 ,10)  -= _term;
 _MATELM1( 10 ,10)  += _term;
 /*REACTION*/
  /* ~ C3 <-> I3 ( fi3 , bi3 )*/
 _term =  fi3 ;
 _MATELM1( 4 ,4)  += _term;
 _MATELM1( 9 ,4)  -= _term;
 _term =  bi3 ;
 _MATELM1( 4 ,9)  -= _term;
 _MATELM1( 9 ,9)  += _term;
 /*REACTION*/
  /* ~ C4 <-> I4 ( fi4 , bi4 )*/
 _term =  fi4 ;
 _MATELM1( 3 ,3)  += _term;
 _MATELM1( 8 ,3)  -= _term;
 _term =  bi4 ;
 _MATELM1( 3 ,8)  -= _term;
 _MATELM1( 8 ,8)  += _term;
 /*REACTION*/
  /* ~ C5 <-> I5 ( fi5 , bi5 )*/
 _term =  fi5 ;
 _MATELM1( 2 ,2)  += _term;
 _MATELM1( 7 ,2)  -= _term;
 _term =  bi5 ;
 _MATELM1( 2 ,7)  -= _term;
 _MATELM1( 7 ,7)  += _term;
 /*REACTION*/
  Ca = C1 + C2 + C3 + C4 + C5 ;
 Ia = I1 + I2 + I3 + I4 + I5 ;
  /* C1 + C2 + C3 + C4 + C5 + O + B + I1 + I2 + I3 + I4 + I5 + I6 = 1.0 */
 /*CONSERVATION*/
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 13;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
     _ode_spec1 ();
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 13; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 13, _dlist1, _p, _ode_matsol1, &_coef1);
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ena = _ion_ena;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_na_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_na_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_na_sym, _ppvar, 2, 4);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  B = B0;
  Ca = Ca0;
  C5 = C50;
  C4 = C40;
  C3 = C30;
  C2 = C20;
  C1 = C10;
  Ia = Ia0;
  I6 = I60;
  I5 = I50;
  I4 = I40;
  I3 = I30;
  I2 = I20;
  I1 = I10;
  O = O0;
 {
   qt = pow( q10 , ( ( celsius - 22.0 ) / 10.0 ) ) ;
   rates ( _threadargscomma_ v ) ;
   error =  0; seqinitial();
 error = simeq(13, _coef2, _p, _slist2);
 if(error){fprintf(stderr,"at line 123 in file narsg.mod:\n SOLVE seqinitial\n"); nrn_complain(_p); abort_run(error);}
 }
  _sav_indep = t; t = _save;

}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v = _v;
  ena = _ion_ena;
 initmodel();
 }}

static double _nrn_current(double _v){double _current=0.;v=_v;{ {
   g = gbar * O ;
   ina = g * ( v - ena ) ;
   }
 _current += ina;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
  ena = _ion_ena;
 _g = _nrn_current(_v + .001);
 	{ double _dina;
  _dina = ina;
 _rhs = _nrn_current(_v);
  _ion_dinadv += (_dina - ina)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ina += ina ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml];
#if CACHEVEC
  if (use_cachevec) {
	VEC_D(_ni[_iml]) += _g;
  }else
#endif
  {
     _nd = _ml->_nodelist[_iml];
	NODED(_nd) += _g;
  }
 
}}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type){
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
double _dtsav = dt;
if (secondorder) { dt *= 0.5; }
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
for (_iml = 0; _iml < _cntml; ++_iml) {
 _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
 _nd = _ml->_nodelist[_iml];
#if CACHEVEC
  if (use_cachevec) {
    _v = VEC_V(_ni[_iml]);
  }else
#endif
  {
    _nd = _ml->_nodelist[_iml];
    _v = NODEV(_nd);
  }
 v=_v;
{
  ena = _ion_ena;
 { error = sparse(&_sparseobj1, 13, _slist1, _dlist1, _p, &t, dt, activation,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 115 in file narsg.mod:\n SOLVE activation METHOD sparse\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 13; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } }}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 _slist2[0] = I1_columnindex;
 _slist2[1] = C2_columnindex;
 _slist2[2] = C1_columnindex;
 _slist2[3] = I2_columnindex;
 _slist2[4] = C3_columnindex;
 _slist2[5] = I3_columnindex;
 _slist2[6] = C4_columnindex;
 _slist2[7] = I4_columnindex;
 _slist2[8] = C5_columnindex;
 _slist2[9] = I5_columnindex;
 _slist2[10] = O_columnindex;
 _slist2[11] = B_columnindex;
 _slist2[12] = I6_columnindex;
 if (_first) _coef2 = makematrix(13, 14);
 _slist1[0] = I6_columnindex;  _dlist1[0] = DI6_columnindex;
 _slist1[1] = B_columnindex;  _dlist1[1] = DB_columnindex;
 _slist1[2] = C5_columnindex;  _dlist1[2] = DC5_columnindex;
 _slist1[3] = C4_columnindex;  _dlist1[3] = DC4_columnindex;
 _slist1[4] = C3_columnindex;  _dlist1[4] = DC3_columnindex;
 _slist1[5] = C2_columnindex;  _dlist1[5] = DC2_columnindex;
 _slist1[6] = C1_columnindex;  _dlist1[6] = DC1_columnindex;
 _slist1[7] = I5_columnindex;  _dlist1[7] = DI5_columnindex;
 _slist1[8] = I4_columnindex;  _dlist1[8] = DI4_columnindex;
 _slist1[9] = I3_columnindex;  _dlist1[9] = DI3_columnindex;
 _slist1[10] = I2_columnindex;  _dlist1[10] = DI2_columnindex;
 _slist1[11] = I1_columnindex;  _dlist1[11] = DI1_columnindex;
 _slist1[12] = O_columnindex;  _dlist1[12] = DO_columnindex;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "narsg.mod";
static const char* nmodl_file_text = 
  "TITLE Rsg sodium channel\n"
  ": Resurgent sodium channel (with blocking particle)\n"
  ": with updated kinetic parameters from Raman and Bean  \n"
  "\n"
  "NEURON {\n"
  "  SUFFIX naRsg\n"
  "  USEION na READ ena WRITE ina\n"
  "  RANGE g, gbar,vshift,f04,ina,epsilon,zeta,x1,x2,alpha\n"
  "  RANGE vshifta,vshifti,vshiftk\n"
  ":      THREADSAFE\n"
  "}\n"
  "\n"
  "UNITS { \n"
  "	(mV) = (millivolt)\n"
  "	(S) = (siemens)\n"
  "}\n"
  "CONSTANT {\n"
  "	q10 = 2.7\n"
  "\n"
  "}\n"
  "PARAMETER {\n"
  "	gbar = .015			(S/cm2)\n"
  ":    ena= 65 (mV)\n"
  "	: kinetic parameters\n"
  "	Con = 0.005			(/ms)					: closed -> inactivated transitions\n"
  "	Coff = 0.5			(/ms)					: inactivated -> closed transitions\n"
  "	Oon = .75			(/ms)					: open -> Ineg transition\n"
  "	Ooff = 0.005		(/ms)					: Ineg -> open transition,set to 0 to eliminate the persistent component\n"
  "	alpha = 150			(/ms)					: activation\n"
  "	beta = 3			(/ms)					: deactivation\n"
  "	gamma = 150			(/ms)					: opening\n"
  "	delta = 40			(/ms)					: closing, greater than BEAN/KUO = 0.2\n"
  "	epsilon = 1.75		(/ms)					: open -> Iplus for tau = 0.3 ms at +30 with x5\n"
  "	zeta = 0.03			(/ms)					: Iplus -> open for tau = 25 ms at -30 with x6\n"
  "\n"
  "	: Vdep\n"
  "	x1 = 20				(mV)								: Vdep of activation (alpha)\n"
  "	x2 = -20			(mV)								: Vdep of deactivation (beta)\n"
  "	x3 = 1e12			(mV)								: Vdep of opening (gamma)\n"
  "	x4 = -1e12			(mV)								: Vdep of closing (delta)\n"
  "	x5 = 1e12			(mV)								: Vdep into Ipos (epsilon)\n"
  "	x6 = -25			(mV)								: Vdep out of Ipos (zeta)\n"
  "	vshifta = 0 			(mV)                            : steady state activation curve\n"
  "	vshifti = 0             (mV)                            : steady state inactivation curve\n"
  "    vshiftk = 0\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	alfac   				: microscopic reversibility factors\n"
  "	btfac				\n"
  "\n"
  "	: rates\n"
  "	f01  		(/ms)\n"
  "	f02  		(/ms)\n"
  "	f03 		(/ms)\n"
  "	f04			(/ms)\n"
  "	f0O 		(/ms)\n"
  "	fip 		(/ms)\n"
  "	f11 		(/ms)\n"
  "	f12 		(/ms)\n"
  "	f13 		(/ms)\n"
  "	f14 		(/ms)\n"
  "	f1n 		(/ms)\n"
  "	fi1 		(/ms)\n"
  "	fi2 		(/ms)\n"
  "	fi3 		(/ms)\n"
  "	fi4 		(/ms)\n"
  "	fi5 		(/ms)\n"
  "	fin 		(/ms)\n"
  "\n"
  "	b01 		(/ms)\n"
  "	b02 		(/ms)\n"
  "	b03 		(/ms)\n"
  "	b04		(/ms)\n"
  "	b0O 		(/ms)\n"
  "	bip 		(/ms)\n"
  "	b11  		(/ms)\n"
  "	b12 		(/ms)\n"
  "	b13 		(/ms)\n"
  "	b14 		(/ms)\n"
  "	b1n 		(/ms)\n"
  "	bi1 		(/ms)\n"
  "	bi2 		(/ms)\n"
  "	bi3 		(/ms)\n"
  "	bi4 		(/ms)\n"
  "	bi5 		(/ms)\n"
  "	bin 		(/ms)\n"
  "	\n"
  "	v					(mV)\n"
  " 	ena					(mV)\n"
  "	ina 					(milliamp/cm2)\n"
  "	g					(S/cm2)\n"
  "	qt\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	C1 FROM 0 TO 1\n"
  "	C2 FROM 0 TO 1\n"
  "	C3 FROM 0 TO 1\n"
  "	C4 FROM 0 TO 1\n"
  "	C5 FROM 0 TO 1\n"
  "	I1 FROM 0 TO 1\n"
  "	I2 FROM 0 TO 1\n"
  "	I3 FROM 0 TO 1\n"
  "	I4 FROM 0 TO 1\n"
  "	I5 FROM 0 TO 1\n"
  "	O FROM 0 TO 1\n"
  "	B FROM 0 TO 1\n"
  "	I6 FROM 0 TO 1\n"
  "	Ca FROM 0 TO 1\n"
  "	Ia FROM 0 TO 1\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  " SOLVE activation METHOD sparse\n"
  " g = gbar * O\n"
  " ina = g * (v - ena)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "qt = q10^((celsius-22 (degC))/10 (degC))\n"
  " rates(v)\n"
  " SOLVE seqinitial\n"
  "}\n"
  "\n"
  "KINETIC activation\n"
  "{\n"
  "	rates(v)\n"
  "	~ C1 <-> C2					(f01,b01)\n"
  "	~ C2 <-> C3					(f02,b02)\n"
  "	~ C3 <-> C4					(f03,b03)\n"
  "	~ C4 <-> C5					(f04,b04)\n"
  "	~ C5 <-> O					(f0O,b0O)\n"
  "	~ O <-> B					(fip,bip)\n"
  "	~ O <-> I6					(fin,bin)\n"
  "	~ I1 <-> I2					(f11,b11)\n"
  "	~ I2 <-> I3					(f12,b12)\n"
  "	~ I3 <-> I4					(f13,b13)\n"
  "	~ I4 <-> I5					(f14,b14)\n"
  "	~ I5 <-> I6					(f1n,b1n)\n"
  "	~ C1 <-> I1					(fi1,bi1)\n"
  "	~ C2 <-> I2					(fi2,bi2)\n"
  "	~ C3 <-> I3					(fi3,bi3)\n"
  " 	~ C4 <-> I4					(fi4,bi4)\n"
  " 	~ C5 <-> I5					(fi5,bi5)\n"
  " 	 Ca = C1 + C2 + C3 + C4 + C5\n"
  " Ia = I1 + I2 + I3 + I4 + I5\n"
  "\n"
  "CONSERVE C1 + C2 + C3 + C4 + C5 + O + B + I1 + I2 + I3 + I4 + I5 + I6 = 1\n"
  "}\n"
  "\n"
  "LINEAR seqinitial { : sets initial equilibrium\n"
  " ~          I1*bi1 + C2*b01 - C1*(    fi1+f01) = 0\n"
  " ~ C1*f01 + I2*bi2 + C3*b02 - C2*(b01+fi2+f02) = 0\n"
  " ~ C2*f02 + I3*bi3 + C4*b03 - C3*(b02+fi3+f03) = 0\n"
  " ~ C3*f03 + I4*bi4 + C5*b04 - C4*(b03+fi4+f04) = 0\n"
  " ~ C4*f04 + I5*bi5 + O*b0O - C5*(b04+fi5+f0O) = 0\n"
  " ~ C5*f0O + B*bip + I6*bin - O*(b0O+fip+fin) = 0\n"
  " ~ O*fip + B*bip = 0\n"
  "\n"
  " ~          C1*fi1 + I2*b11 - I1*(    bi1+f11) = 0\n"
  " ~ I1*f11 + C2*fi2 + I3*b12 - I2*(b11+bi2+f12) = 0\n"
  " ~ I2*f12 + C3*fi3 + I4*bi3 - I3*(b12+bi3+f13) = 0\n"
  " ~ I3*f13 + C4*fi4 + I5*b14 - I4*(b13+bi4+f14) = 0\n"
  " ~ I4*f14 + C5*fi5 + I6*b1n - I5*(b14+bi5+f1n) = 0\n"
  " \n"
  " ~ C1 + C2 + C3 + C4 + C5 + O + B + I1 + I2 + I3 + I4 + I5 + I6 = 1\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v(mV) )\n"
  "{\n"
  "\n"
  "\n"
  " alfac = (Oon/Con)^(1/4)\n"
  " btfac = (Ooff/Coff)^(1/4) \n"
  "\n"
  " f01 = 4 * alpha * exp((v)/(x1)) * qt\n"
  " f02 = 3 * alpha * exp((v)/(x1)) * qt\n"
  " f03 = 2 * alpha * exp((v)/(x1)) * qt\n"
  " f04 = 1 * alpha * exp((v)/(x1)) * qt\n"
  " f0O = gamma * qt : * exp(v/x3) - since x3 is infinity\n"
  " fip = epsilon * qt : * exp(v/x5)\n"
  " f11 = 4 * alpha * alfac * exp((v+vshifti)/x1) * qt\n"
  " f12 = 3 * alpha * alfac * exp((v+vshifti)/x1) * qt\n"
  " f13 = 2 * alpha * alfac * exp((v+vshifti)/x1) * qt\n"
  " f14 = 1 * alpha * alfac * exp((v+vshifti)/x1) * qt\n"
  " f1n = gamma * qt : * exp(v/x3) dito\n"
  " fi1 = Con * qt\n"
  " fi2 = Con * alfac * qt\n"
  " fi3 = Con * alfac^2 * qt\n"
  " fi4 = Con * alfac^3 * qt\n"
  " fi5 = Con * alfac^4 * qt\n"
  " fin = Oon * qt\n"
  "\n"
  " b01 = 1 * beta * exp((v+vshifta)/(x2+vshiftk)) * qt\n"
  " b02 = 2 * beta * exp((v+vshifta)/(x2+vshiftk)) * qt\n"
  " b03 = 3 * beta * exp((v+vshifta)/(x2+vshiftk)) * qt\n"
  " b04 = 4 * beta * exp((v+vshifta)/(x2+vshiftk)) * qt\n"
  " \n"
  " b0O = delta * qt : * exp(v/x4)\n"
  " bip = zeta * exp(v/x6) * qt\n"
  " b11 = 1 * beta * btfac * exp((v+vshifti)/x2) * qt\n"
  " b12 = 2 * beta * btfac * exp((v+vshifti)/x2) * qt\n"
  " b13 = 3 * beta * btfac * exp((v+vshifti)/x2) * qt\n"
  " b14 = 4 * beta * btfac * exp((v+vshifti)/x2) * qt\n"
  " b1n = delta * qt : * exp(v/x4)\n"
  " bi1 = Coff * qt\n"
  " bi2 = Coff * btfac * qt\n"
  " bi3 = Coff * btfac^2 * qt\n"
  " bi4 = Coff * btfac^3 * qt\n"
  " bi5 = Coff * btfac^4 * qt\n"
  " bin = Ooff * qt\n"
  "}\n"
  "\n"
  ;
#endif
