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
 
#define nrn_init _nrn_init__cdpAIS
#define _nrn_initial _nrn_initial__cdpAIS
#define nrn_cur _nrn_cur__cdpAIS
#define _nrn_current _nrn_current__cdpAIS
#define nrn_jacob _nrn_jacob__cdpAIS
#define nrn_state _nrn_state__cdpAIS
#define _net_receive _net_receive__cdpAIS 
#define factors factors__cdpAIS 
#define state state__cdpAIS 
 
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
#define ica_pmp _p[0]
#define ica_pmp_columnindex 0
#define ca1 _p[1]
#define ca1_columnindex 1
#define ca2 _p[2]
#define ca2_columnindex 2
#define ca3 _p[3]
#define ca3_columnindex 3
#define ca4 _p[4]
#define ca4_columnindex 4
#define ca5 _p[5]
#define ca5_columnindex 5
#define ca9 _p[6]
#define ca9_columnindex 6
#define ca (_p + 7)
#define ca_columnindex 7
#define mg (_p + 17)
#define mg_columnindex 17
#define CB (_p + 27)
#define CB_columnindex 27
#define CB_f_ca (_p + 37)
#define CB_f_ca_columnindex 37
#define CB_ca_s (_p + 47)
#define CB_ca_s_columnindex 47
#define CB_ca_ca (_p + 57)
#define CB_ca_ca_columnindex 57
#define iCB (_p + 67)
#define iCB_columnindex 67
#define iCB_f_ca (_p + 77)
#define iCB_f_ca_columnindex 77
#define iCB_ca_s (_p + 87)
#define iCB_ca_s_columnindex 87
#define iCB_ca_ca (_p + 97)
#define iCB_ca_ca_columnindex 97
#define PV (_p + 107)
#define PV_columnindex 107
#define PV_ca (_p + 117)
#define PV_ca_columnindex 117
#define PV_mg (_p + 127)
#define PV_mg_columnindex 127
#define pump _p[137]
#define pump_columnindex 137
#define pumpca _p[138]
#define pumpca_columnindex 138
#define ica _p[139]
#define ica_columnindex 139
#define ibg _p[140]
#define ibg_columnindex 140
#define parea _p[141]
#define parea_columnindex 141
#define cai _p[142]
#define cai_columnindex 142
#define cao _p[143]
#define cao_columnindex 143
#define mgi _p[144]
#define mgi_columnindex 144
#define Dca (_p + 145)
#define Dca_columnindex 145
#define Dmg (_p + 155)
#define Dmg_columnindex 155
#define DCB (_p + 165)
#define DCB_columnindex 165
#define DCB_f_ca (_p + 175)
#define DCB_f_ca_columnindex 175
#define DCB_ca_s (_p + 185)
#define DCB_ca_s_columnindex 185
#define DCB_ca_ca (_p + 195)
#define DCB_ca_ca_columnindex 195
#define DiCB (_p + 205)
#define DiCB_columnindex 205
#define DiCB_f_ca (_p + 215)
#define DiCB_f_ca_columnindex 215
#define DiCB_ca_s (_p + 225)
#define DiCB_ca_s_columnindex 225
#define DiCB_ca_ca (_p + 235)
#define DiCB_ca_ca_columnindex 235
#define DPV (_p + 245)
#define DPV_columnindex 245
#define DPV_ca (_p + 255)
#define DPV_ca_columnindex 255
#define DPV_mg (_p + 265)
#define DPV_mg_columnindex 265
#define Dpump _p[275]
#define Dpump_columnindex 275
#define Dpumpca _p[276]
#define Dpumpca_columnindex 276
#define _g _p[277]
#define _g_columnindex 277
#define _ion_cao	*_ppvar[0]._pval
#define _ion_cai	*_ppvar[1]._pval
#define _ion_ica	*_ppvar[2]._pval
#define _style_ca	*((int*)_ppvar[3]._pvoid)
#define diam	*_ppvar[4]._pval
 
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
 static void _hoc_factors(void);
 static void _hoc_kdm(void);
 static void _hoc_kdc(void);
 static void _hoc_kds(void);
 static void _hoc_kdf(void);
 static void _hoc_ssPVmg(void);
 static void _hoc_ssPVca(void);
 static void _hoc_ssPV(void);
 static void _hoc_ssCBca(void);
 static void _hoc_ssCBslow(void);
 static void _hoc_ssCBfast(void);
 static void _hoc_ssCB(void);
 static void _hoc_u(void);
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
 "setdata_cdpAIS", _hoc_setdata,
 "factors_cdpAIS", _hoc_factors,
 "kdm_cdpAIS", _hoc_kdm,
 "kdc_cdpAIS", _hoc_kdc,
 "kds_cdpAIS", _hoc_kds,
 "kdf_cdpAIS", _hoc_kdf,
 "ssPVmg_cdpAIS", _hoc_ssPVmg,
 "ssPVca_cdpAIS", _hoc_ssPVca,
 "ssPV_cdpAIS", _hoc_ssPV,
 "ssCBca_cdpAIS", _hoc_ssCBca,
 "ssCBslow_cdpAIS", _hoc_ssCBslow,
 "ssCBfast_cdpAIS", _hoc_ssCBfast,
 "ssCB_cdpAIS", _hoc_ssCB,
 "u_cdpAIS", _hoc_u,
 0, 0
};
#define kdm kdm_cdpAIS
#define kdc kdc_cdpAIS
#define kds kds_cdpAIS
#define kdf kdf_cdpAIS
#define ssPVmg ssPVmg_cdpAIS
#define ssPVca ssPVca_cdpAIS
#define ssPV ssPV_cdpAIS
#define ssCBca ssCBca_cdpAIS
#define ssCBslow ssCBslow_cdpAIS
#define ssCBfast ssCBfast_cdpAIS
#define ssCB ssCB_cdpAIS
#define u u_cdpAIS
 extern double kdm( );
 extern double kdc( );
 extern double kds( );
 extern double kdf( );
 extern double ssPVmg( double , double );
 extern double ssPVca( double , double );
 extern double ssPV( double , double );
 extern double ssCBca( double , double );
 extern double ssCBslow( double , double );
 extern double ssCBfast( double , double );
 extern double ssCB( double , double );
 extern double u( double , double );
 /* declare global and static user variables */
#define CBnull CBnull_cdpAIS
 double CBnull = 0.08;
#define Dpar Dpar_cdpAIS
 double Dpar = 0.043;
#define Dcbd2 Dcbd2_cdpAIS
 double Dcbd2 = 0;
#define Dcbd1 Dcbd1_cdpAIS
 double Dcbd1 = 0.028;
#define Ddmnpe Ddmnpe_cdpAIS
 double Ddmnpe = 0.08;
#define Dbtc Dbtc_cdpAIS
 double Dbtc = 0.007;
#define DCa DCa_cdpAIS
 double DCa = 0.233;
#define Kp Kp_cdpAIS
 double Kp = 0.0027;
#define PVnull PVnull_cdpAIS
 double PVnull = 0.04;
#define TotalPump TotalPump_cdpAIS
 double TotalPump = 1e-15;
#define beta beta_cdpAIS
 double beta = 1;
#define cainull cainull_cdpAIS
 double cainull = 4.5e-05;
#define kpmp3 kpmp3_cdpAIS
 double kpmp3 = 72.55;
#define kpmp2 kpmp2_cdpAIS
 double kpmp2 = 17.5;
#define kpmp1 kpmp1_cdpAIS
 double kpmp1 = 3000;
#define m2 m2_cdpAIS
 double m2 = 0.00095;
#define m1 m1_cdpAIS
 double m1 = 107;
#define mginull mginull_cdpAIS
 double mginull = 0.59;
#define ns2 ns2_cdpAIS
 double ns2 = 0.0026;
#define ns1 ns1_cdpAIS
 double ns1 = 5.5;
#define nf2 nf2_cdpAIS
 double nf2 = 0.0358;
#define nf1 nf1_cdpAIS
 double nf1 = 43.5;
#define p2 p2_cdpAIS
 double p2 = 0.025;
#define p1 p1_cdpAIS
 double p1 = 0.8;
#define vmax vmax_cdpAIS
 double vmax = 0.1;
#define vrat vrat_cdpAIS
 double vrat[10];
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "cainull_cdpAIS", "mM",
 "mginull_cdpAIS", "mM",
 "DCa_cdpAIS", "um2/ms",
 "Dbtc_cdpAIS", "um2/ms",
 "Ddmnpe_cdpAIS", "um2/ms",
 "Dcbd1_cdpAIS", "um2/ms",
 "Dcbd2_cdpAIS", "um2/ms",
 "Dpar_cdpAIS", "um2/ms",
 "CBnull_cdpAIS", "mM",
 "nf1_cdpAIS", "/ms",
 "nf2_cdpAIS", "/ms",
 "ns1_cdpAIS", "/ms",
 "ns2_cdpAIS", "/ms",
 "PVnull_cdpAIS", "mM",
 "m1_cdpAIS", "/ms",
 "m2_cdpAIS", "/ms",
 "p1_cdpAIS", "/ms",
 "p2_cdpAIS", "/ms",
 "kpmp1_cdpAIS", "/mM-ms",
 "kpmp2_cdpAIS", "/ms",
 "kpmp3_cdpAIS", "/ms",
 "beta_cdpAIS", "1",
 "Kp_cdpAIS", "mM",
 "vrat_cdpAIS", "1",
 "ca_cdpAIS", "mM",
 "mg_cdpAIS", "mM",
 "CB_cdpAIS", "mM",
 "CB_f_ca_cdpAIS", "mM",
 "CB_ca_s_cdpAIS", "mM",
 "CB_ca_ca_cdpAIS", "mM",
 "iCB_cdpAIS", "mM",
 "iCB_f_ca_cdpAIS", "mM",
 "iCB_ca_s_cdpAIS", "mM",
 "iCB_ca_ca_cdpAIS", "mM",
 "PV_cdpAIS", "mM",
 "PV_ca_cdpAIS", "mM",
 "PV_mg_cdpAIS", "mM",
 "pump_cdpAIS", "mol/cm2",
 "pumpca_cdpAIS", "mol/cm2",
 "ica_pmp_cdpAIS", "mA/cm2",
 0,0
};
 static double CB_ca_ca0 = 0;
 static double CB_ca_s0 = 0;
 static double CB_f_ca0 = 0;
 static double CB0 = 0;
 static double PV_mg0 = 0;
 static double PV_ca0 = 0;
 static double PV0 = 0;
 static double ca0 = 0;
 static double delta_t = 0.01;
 static double iCB_ca_ca0 = 0;
 static double iCB_ca_s0 = 0;
 static double iCB_f_ca0 = 0;
 static double iCB0 = 0;
 static double mg0 = 0;
 static double pumpca0 = 0;
 static double pump0 = 0;
 static double v = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
 "cainull_cdpAIS", &cainull_cdpAIS,
 "mginull_cdpAIS", &mginull_cdpAIS,
 "DCa_cdpAIS", &DCa_cdpAIS,
 "Dbtc_cdpAIS", &Dbtc_cdpAIS,
 "Ddmnpe_cdpAIS", &Ddmnpe_cdpAIS,
 "Dcbd1_cdpAIS", &Dcbd1_cdpAIS,
 "Dcbd2_cdpAIS", &Dcbd2_cdpAIS,
 "Dpar_cdpAIS", &Dpar_cdpAIS,
 "CBnull_cdpAIS", &CBnull_cdpAIS,
 "nf1_cdpAIS", &nf1_cdpAIS,
 "nf2_cdpAIS", &nf2_cdpAIS,
 "ns1_cdpAIS", &ns1_cdpAIS,
 "ns2_cdpAIS", &ns2_cdpAIS,
 "PVnull_cdpAIS", &PVnull_cdpAIS,
 "m1_cdpAIS", &m1_cdpAIS,
 "m2_cdpAIS", &m2_cdpAIS,
 "p1_cdpAIS", &p1_cdpAIS,
 "p2_cdpAIS", &p2_cdpAIS,
 "kpmp1_cdpAIS", &kpmp1_cdpAIS,
 "kpmp2_cdpAIS", &kpmp2_cdpAIS,
 "kpmp3_cdpAIS", &kpmp3_cdpAIS,
 "TotalPump_cdpAIS", &TotalPump_cdpAIS,
 "beta_cdpAIS", &beta_cdpAIS,
 "vmax_cdpAIS", &vmax_cdpAIS,
 "Kp_cdpAIS", &Kp_cdpAIS,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 "vrat_cdpAIS", vrat_cdpAIS, 10,
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
 
#define _cvode_ieq _ppvar[5]._i
 static void _ode_synonym(int, double**, Datum**);
 static void _ode_matsol_instance1(_threadargsproto_);
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"cdpAIS",
 0,
 "ica_pmp_cdpAIS",
 "ca1_cdpAIS",
 "ca2_cdpAIS",
 "ca3_cdpAIS",
 "ca4_cdpAIS",
 "ca5_cdpAIS",
 "ca9_cdpAIS",
 0,
 "ca_cdpAIS[10]",
 "mg_cdpAIS[10]",
 "CB_cdpAIS[10]",
 "CB_f_ca_cdpAIS[10]",
 "CB_ca_s_cdpAIS[10]",
 "CB_ca_ca_cdpAIS[10]",
 "iCB_cdpAIS[10]",
 "iCB_f_ca_cdpAIS[10]",
 "iCB_ca_s_cdpAIS[10]",
 "iCB_ca_ca_cdpAIS[10]",
 "PV_cdpAIS[10]",
 "PV_ca_cdpAIS[10]",
 "PV_mg_cdpAIS[10]",
 "pump_cdpAIS",
 "pumpca_cdpAIS",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 278, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 278;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 6, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_morphology_sym);
 	_ppvar[4]._pval = &prop_ion->param[0]; /* diam */
 prop_ion = need_memb(_ca_sym);
 nrn_check_conc_write(_prop, prop_ion, 1);
 nrn_promote(prop_ion, 3, 0);
 	_ppvar[0]._pval = &prop_ion->param[2]; /* cao */
 	_ppvar[1]._pval = &prop_ion->param[1]; /* cai */
 	_ppvar[2]._pval = &prop_ion->param[3]; /* ica */
 	_ppvar[3]._pvoid = (void*)(&(prop_ion->dparam[0]._i)); /* iontype for ca */
 
}
 static void _initlists();
  /* some states have an absolute tolerance */
 static Symbol** _atollist;
 static HocStateTolerance _hoc_state_tol[] = {
 "mg_cdpAIS", 1e-07,
 "pump_cdpAIS", 1e-15,
 "pumpca_cdpAIS", 1e-15,
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _cdp_AIS_reg() {
	int _vectorized = 0;
  _initlists();
 	ion_reg("ca", -10000.);
 	_morphology_sym = hoc_lookup("morphology");
 	_ca_sym = hoc_lookup("ca_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 278, 6);
  hoc_register_dparam_semantics(_mechtype, 0, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "ca_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "#ca_ion");
  hoc_register_dparam_semantics(_mechtype, 5, "cvodeieq");
  hoc_register_dparam_semantics(_mechtype, 4, "diam");
 	nrn_writes_conc(_mechtype, 0);
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_synonym(_mechtype, _ode_synonym);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 cdpAIS /home/cbao/Purkinje19b972_ephys/purkinje_pub/cdp_AIS.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define FARADAY _nrnunit_FARADAY[_nrnunit_use_legacy_]
static double _nrnunit_FARADAY[2] = {0x1.34c0c8b92a9b7p+3, 9.64853}; /* 9.64853321233100125 */
 
#define PI _nrnunit_PI[_nrnunit_use_legacy_]
static double _nrnunit_PI[2] = {0x1.921fb54442d18p+1, 3.14159}; /* 3.14159265358979312 */
 static double _zfactors_done ;
 static double _zfrat [ 10 ] ;
 static double _zdsq , _zdsqvol ;
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int factors();
 extern double *_getelm();
 
#define _MATELM1(_row,_col)	*(_getelm(_row + 1, _col + 1))
 
#define _RHS1(_arg) _coef1[_arg + 1]
 static double *_coef1;
 
#define _linmat1  0
 static void* _sparseobj1;
 static void* _cvsparseobj1;
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[130], _dlist1[130]; static double *_temp1;
 static int state();
 
static int  factors (  ) {
   double _lr , _ldr2 ;
 _lr = 1.0 / 2.0 ;
   _ldr2 = _lr / ( 10.0 - 1.0 ) / 2.0 ;
   vrat [ 0 ] = 0.0 ;
   _zfrat [ 0 ] = 2.0 * _lr ;
   {int  _li ;for ( _li = 0 ; _li <= 10 - 2 ; _li ++ ) {
     vrat [ _li ] = vrat [ _li ] + PI * ( _lr - _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
     _lr = _lr - _ldr2 ;
     _zfrat [ _li + 1 ] = 2.0 * PI * _lr / ( 2.0 * _ldr2 ) ;
     _lr = _lr - _ldr2 ;
     vrat [ _li + 1 ] = PI * ( _lr + _ldr2 / 2.0 ) * 2.0 * _ldr2 ;
     } }
    return 0; }
 
static void _hoc_factors(void) {
  double _r;
   _r = 1.;
 factors (  );
 hoc_retpushx(_r);
}
 
static int state ()
 {_reset=0;
 {
   double b_flux, f_flux, _term; int _i;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<130;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 0) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 0, _i + 0) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 10) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 10, _i + 10) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 20) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 20, _i + 20) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 30) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 30, _i + 30) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 40) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 40, _i + 40) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 50) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 50, _i + 50) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 60) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 60, _i + 60) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 70) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 70, _i + 70) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 80) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 80, _i + 80) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 90) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 90, _i + 90) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 100) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 100, _i + 100) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 110) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 110, _i + 110) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 120) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 120, _i + 120) *= ( diam * diam * vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
     ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg }
   */
 /* COMPARTMENT ( 1e10 ) * parea {
     pump pumpca }
   */
 /* ~ ca [ 0 ] < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 70 +  0) += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 10 - 1 ; _li ++ ) {
     /* ~ ca [ _li ] < < ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 70 +  _li) += (b_flux =   ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) ) );
 /*FLUX*/
  } }
   {int  _li ;for ( _li = 0 ; _li <= 10 - 2 ; _li ++ ) {
     /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li + 1] ;
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li + 1) += (f_flux - b_flux);
 
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li + 1 ,70 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 70 +  _li ,70 +  _li + 1)  -= _term;
 _MATELM1( 70 +  _li + 1 ,70 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] <-> mg [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * mg [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * mg [ _li + 1] ;
 _RHS1( 120 +  _li) -= (f_flux - b_flux);
 _RHS1( 120 +  _li + 1) += (f_flux - b_flux);
 
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 120 +  _li ,120 +  _li + 1)  -= _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB [ _li ] <-> CB [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB [ _li + 1] ;
 _RHS1( 30 +  _li) -= (f_flux - b_flux);
 _RHS1( 30 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 30 +  _li ,30 +  _li)  += _term;
 _MATELM1( 30 +  _li + 1 ,30 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 30 +  _li ,30 +  _li + 1)  -= _term;
 _MATELM1( 30 +  _li + 1 ,30 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_f_ca [ _li ] <-> CB_f_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_f_ca [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_f_ca [ _li + 1] ;
 _RHS1( 20 +  _li) -= (f_flux - b_flux);
 _RHS1( 20 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li + 1)  -= _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_ca_s [ _li ] <-> CB_ca_s [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_s [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_s [ _li + 1] ;
 _RHS1( 10 +  _li) -= (f_flux - b_flux);
 _RHS1( 10 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 10 +  _li ,10 +  _li)  += _term;
 _MATELM1( 10 +  _li + 1 ,10 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 10 +  _li ,10 +  _li + 1)  -= _term;
 _MATELM1( 10 +  _li + 1 ,10 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_ca_ca [ _li ] <-> CB_ca_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_ca [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_ca [ _li + 1] ;
 _RHS1( 0 +  _li) -= (f_flux - b_flux);
 _RHS1( 0 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 _MATELM1( 0 +  _li + 1 ,0 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 0 +  _li ,0 +  _li + 1)  -= _term;
 _MATELM1( 0 +  _li + 1 ,0 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV [ _li ] <-> PV [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV [ _li + 1] ;
 _RHS1( 60 +  _li) -= (f_flux - b_flux);
 _RHS1( 60 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li + 1)  -= _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_ca [ _li ] <-> PV_ca [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV_ca [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV_ca [ _li + 1] ;
 _RHS1( 50 +  _li) -= (f_flux - b_flux);
 _RHS1( 50 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 50 +  _li ,50 +  _li)  += _term;
 _MATELM1( 50 +  _li + 1 ,50 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 50 +  _li ,50 +  _li + 1)  -= _term;
 _MATELM1( 50 +  _li + 1 ,50 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_mg [ _li ] <-> PV_mg [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV_mg [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV_mg [ _li + 1] ;
 _RHS1( 40 +  _li) -= (f_flux - b_flux);
 _RHS1( 40 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li + 1)  -= _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li + 1)  += _term;
 /*REACTION*/
  } }
   _zdsq = diam * diam ;
   {int  _li ;for ( _li = 0 ; _li <= 10 - 1 ; _li ++ ) {
     _zdsqvol = _zdsq * vrat [ _li ] ;
     /* ~ ca [ _li ] + CB [ _li ] <-> CB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * CB [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * CB_ca_s [ _li] ;
 _RHS1( 30 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 10 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 30 +  _li ,30 +  _li)  += _term;
 _MATELM1( 70 +  _li ,30 +  _li)  += _term;
 _MATELM1( 10 +  _li ,30 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 30 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 10 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 30 +  _li ,10 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,10 +  _li)  -= _term;
 _MATELM1( 10 +  _li ,10 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB [ _li ] <-> CB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * CB [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * CB_f_ca [ _li] ;
 _RHS1( 30 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 20 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 30 +  _li ,30 +  _li)  += _term;
 _MATELM1( 70 +  _li ,30 +  _li)  += _term;
 _MATELM1( 20 +  _li ,30 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 30 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 20 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 30 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_f_ca [ _li ] <-> CB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * CB_f_ca [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * CB_ca_ca [ _li] ;
 _RHS1( 20 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 0 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 70 +  _li ,20 +  _li)  += _term;
 _MATELM1( 0 +  _li ,20 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB_f_ca [ _li] ;
 _MATELM1( 20 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 0 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 20 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_ca_s [ _li ] <-> CB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * CB_ca_s [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * CB_ca_ca [ _li] ;
 _RHS1( 10 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 0 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 10 +  _li ,10 +  _li)  += _term;
 _MATELM1( 70 +  _li ,10 +  _li)  += _term;
 _MATELM1( 0 +  _li ,10 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB_ca_s [ _li] ;
 _MATELM1( 10 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 0 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 10 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * iCB [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * iCB_ca_s [ _li] ;
 _RHS1( 110 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 90 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 110 +  _li ,110 +  _li)  += _term;
 _MATELM1( 70 +  _li ,110 +  _li)  += _term;
 _MATELM1( 90 +  _li ,110 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 110 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 90 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 110 +  _li ,90 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,90 +  _li)  -= _term;
 _MATELM1( 90 +  _li ,90 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * iCB [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * iCB_f_ca [ _li] ;
 _RHS1( 110 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 100 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 110 +  _li ,110 +  _li)  += _term;
 _MATELM1( 70 +  _li ,110 +  _li)  += _term;
 _MATELM1( 100 +  _li ,110 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 110 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 100 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 110 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_f_ca [ _li ] <-> iCB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * iCB_f_ca [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * iCB_ca_ca [ _li] ;
 _RHS1( 100 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 80 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 _MATELM1( 70 +  _li ,100 +  _li)  += _term;
 _MATELM1( 80 +  _li ,100 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB_f_ca [ _li] ;
 _MATELM1( 100 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 80 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 100 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_ca_s [ _li ] <-> iCB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * iCB_ca_s [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * iCB_ca_ca [ _li] ;
 _RHS1( 90 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 80 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 90 +  _li ,90 +  _li)  += _term;
 _MATELM1( 70 +  _li ,90 +  _li)  += _term;
 _MATELM1( 80 +  _li ,90 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB_ca_s [ _li] ;
 _MATELM1( 90 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 80 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 90 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + PV [ _li ] <-> PV_ca [ _li ] ( m1 * _zdsqvol , m2 * _zdsqvol )*/
 f_flux =  m1 * _zdsqvol * PV [ _li] * ca [ _li] ;
 b_flux =  m2 * _zdsqvol * PV_ca [ _li] ;
 _RHS1( 60 +  _li) -= (f_flux - b_flux);
 _RHS1( 70 +  _li) -= (f_flux - b_flux);
 _RHS1( 50 +  _li) += (f_flux - b_flux);
 
 _term =  m1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 70 +  _li ,60 +  _li)  += _term;
 _MATELM1( 50 +  _li ,60 +  _li)  -= _term;
 _term =  m1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 60 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 50 +  _li ,70 +  _li)  -= _term;
 _term =  m2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,50 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,50 +  _li)  -= _term;
 _MATELM1( 50 +  _li ,50 +  _li)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] + PV [ _li ] <-> PV_mg [ _li ] ( p1 * _zdsqvol , p2 * _zdsqvol )*/
 f_flux =  p1 * _zdsqvol * PV [ _li] * mg [ _li] ;
 b_flux =  p2 * _zdsqvol * PV_mg [ _li] ;
 _RHS1( 60 +  _li) -= (f_flux - b_flux);
 _RHS1( 120 +  _li) -= (f_flux - b_flux);
 _RHS1( 40 +  _li) += (f_flux - b_flux);
 
 _term =  p1 * _zdsqvol * mg [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 120 +  _li ,60 +  _li)  += _term;
 _MATELM1( 40 +  _li ,60 +  _li)  -= _term;
 _term =  p1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 60 +  _li ,120 +  _li)  += _term;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 40 +  _li ,120 +  _li)  -= _term;
 _term =  p2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 120 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 /*REACTION*/
  } }
   cai = ca [ 0 ] ;
   ca1 = ca [ 1 ] ;
   ca2 = ca [ 2 ] ;
   ca3 = ca [ 3 ] ;
   ca4 = ca [ 4 ] ;
   ca5 = ca [ 5 ] ;
   ca9 = ca [ 9 ] ;
   mgi = mg [ 0 ] ;
     } return _reset;
 }
 
double ssCB (  double _lkdf , double _lkds ) {
   double _lssCB;
 _lssCB = CBnull / ( 1.0 + kdf ( _threadargs_ ) + kds ( _threadargs_ ) + ( kdf ( _threadargs_ ) * kds ( _threadargs_ ) ) ) ;
   
return _lssCB;
 }
 
static void _hoc_ssCB(void) {
  double _r;
   _r =  ssCB (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double ssCBfast (  double _lkdf , double _lkds ) {
   double _lssCBfast;
 _lssCBfast = ( CBnull * kds ( _threadargs_ ) ) / ( 1.0 + kdf ( _threadargs_ ) + kds ( _threadargs_ ) + ( kdf ( _threadargs_ ) * kds ( _threadargs_ ) ) ) ;
   
return _lssCBfast;
 }
 
static void _hoc_ssCBfast(void) {
  double _r;
   _r =  ssCBfast (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double ssCBslow (  double _lkdf , double _lkds ) {
   double _lssCBslow;
 _lssCBslow = ( CBnull * kdf ( _threadargs_ ) ) / ( 1.0 + kdf ( _threadargs_ ) + kds ( _threadargs_ ) + ( kdf ( _threadargs_ ) * kds ( _threadargs_ ) ) ) ;
   
return _lssCBslow;
 }
 
static void _hoc_ssCBslow(void) {
  double _r;
   _r =  ssCBslow (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double ssCBca (  double _lkdf , double _lkds ) {
   double _lssCBca;
 _lssCBca = ( CBnull * kdf ( _threadargs_ ) * kds ( _threadargs_ ) ) / ( 1.0 + kdf ( _threadargs_ ) + kds ( _threadargs_ ) + ( kdf ( _threadargs_ ) * kds ( _threadargs_ ) ) ) ;
   
return _lssCBca;
 }
 
static void _hoc_ssCBca(void) {
  double _r;
   _r =  ssCBca (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double kdf (  ) {
   double _lkdf;
 _lkdf = ( cainull * nf1 ) / nf2 ;
   
return _lkdf;
 }
 
static void _hoc_kdf(void) {
  double _r;
   _r =  kdf (  );
 hoc_retpushx(_r);
}
 
double kds (  ) {
   double _lkds;
 _lkds = ( cainull * ns1 ) / ns2 ;
   
return _lkds;
 }
 
static void _hoc_kds(void) {
  double _r;
   _r =  kds (  );
 hoc_retpushx(_r);
}
 
double kdc (  ) {
   double _lkdc;
 _lkdc = ( cainull * m1 ) / m2 ;
   
return _lkdc;
 }
 
static void _hoc_kdc(void) {
  double _r;
   _r =  kdc (  );
 hoc_retpushx(_r);
}
 
double kdm (  ) {
   double _lkdm;
 _lkdm = ( mginull * p1 ) / p2 ;
   
return _lkdm;
 }
 
static void _hoc_kdm(void) {
  double _r;
   _r =  kdm (  );
 hoc_retpushx(_r);
}
 
double ssPV (  double _lkdc , double _lkdm ) {
   double _lssPV;
 _lssPV = PVnull / ( 1.0 + kdc ( _threadargs_ ) + kdm ( _threadargs_ ) ) ;
   
return _lssPV;
 }
 
static void _hoc_ssPV(void) {
  double _r;
   _r =  ssPV (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double ssPVca (  double _lkdc , double _lkdm ) {
   double _lssPVca;
 _lssPVca = ( PVnull * _lkdc ) / ( 1.0 + _lkdc + _lkdm ) ;
   
return _lssPVca;
 }
 
static void _hoc_ssPVca(void) {
  double _r;
   _r =  ssPVca (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double ssPVmg (  double _lkdc , double _lkdm ) {
   double _lssPVmg;
 _lssPVmg = ( PVnull * kdm ( _threadargs_ ) ) / ( 1.0 + kdc ( _threadargs_ ) + kdm ( _threadargs_ ) ) ;
   
return _lssPVmg;
 }
 
static void _hoc_ssPVmg(void) {
  double _r;
   _r =  ssPVmg (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
double u (  double _lx , double _lth ) {
   double _lu;
 if ( _lx < _lth ) {
     _lu = 1.0 ;
     }
   else {
     _lu = 0.0 ;
     }
   
return _lu;
 }
 
static void _hoc_u(void) {
  double _r;
   _r =  u (  *getarg(1) , *getarg(2) );
 hoc_retpushx(_r);
}
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<130;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
   ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
   pump pumpca }
 */
 /* ~ ca [ 0 ] < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 Dca [ 0] += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 10 - 1 ; _li ++ ) {
   /* ~ ca [ _li ] < < ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) )*/
 f_flux = b_flux = 0.;
 Dca [ _li] += (b_flux =   ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) ) );
 /*FLUX*/
  } }
 {int  _li ;for ( _li = 0 ; _li <= 10 - 2 ; _li ++ ) {
   /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li + 1] ;
 Dca [ _li] -= (f_flux - b_flux);
 Dca [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ mg [ _li ] <-> mg [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * mg [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * mg [ _li + 1] ;
 Dmg [ _li] -= (f_flux - b_flux);
 Dmg [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ CB [ _li ] <-> CB [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB [ _li + 1] ;
 DCB [ _li] -= (f_flux - b_flux);
 DCB [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ CB_f_ca [ _li ] <-> CB_f_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_f_ca [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_f_ca [ _li + 1] ;
 DCB_f_ca [ _li] -= (f_flux - b_flux);
 DCB_f_ca [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ CB_ca_s [ _li ] <-> CB_ca_s [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_s [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_s [ _li + 1] ;
 DCB_ca_s [ _li] -= (f_flux - b_flux);
 DCB_ca_s [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ CB_ca_ca [ _li ] <-> CB_ca_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_ca [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_ca [ _li + 1] ;
 DCB_ca_ca [ _li] -= (f_flux - b_flux);
 DCB_ca_ca [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ PV [ _li ] <-> PV [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV [ _li + 1] ;
 DPV [ _li] -= (f_flux - b_flux);
 DPV [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ PV_ca [ _li ] <-> PV_ca [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV_ca [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV_ca [ _li + 1] ;
 DPV_ca [ _li] -= (f_flux - b_flux);
 DPV_ca [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ PV_mg [ _li ] <-> PV_mg [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV_mg [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV_mg [ _li + 1] ;
 DPV_mg [ _li] -= (f_flux - b_flux);
 DPV_mg [ _li + 1] += (f_flux - b_flux);
 
 /*REACTION*/
  } }
 _zdsq = diam * diam ;
 {int  _li ;for ( _li = 0 ; _li <= 10 - 1 ; _li ++ ) {
   _zdsqvol = _zdsq * vrat [ _li ] ;
   /* ~ ca [ _li ] + CB [ _li ] <-> CB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * CB [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * CB_ca_s [ _li] ;
 DCB [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DCB_ca_s [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + CB [ _li ] <-> CB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * CB [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * CB_f_ca [ _li] ;
 DCB [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DCB_f_ca [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + CB_f_ca [ _li ] <-> CB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * CB_f_ca [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * CB_ca_ca [ _li] ;
 DCB_f_ca [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DCB_ca_ca [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + CB_ca_s [ _li ] <-> CB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * CB_ca_s [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * CB_ca_ca [ _li] ;
 DCB_ca_s [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DCB_ca_ca [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * iCB [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * iCB_ca_s [ _li] ;
 DiCB [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DiCB_ca_s [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * iCB [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * iCB_f_ca [ _li] ;
 DiCB [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DiCB_f_ca [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_f_ca [ _li ] <-> iCB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * iCB_f_ca [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * iCB_ca_ca [ _li] ;
 DiCB_f_ca [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DiCB_ca_ca [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_ca_s [ _li ] <-> iCB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * iCB_ca_s [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * iCB_ca_ca [ _li] ;
 DiCB_ca_s [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DiCB_ca_ca [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ ca [ _li ] + PV [ _li ] <-> PV_ca [ _li ] ( m1 * _zdsqvol , m2 * _zdsqvol )*/
 f_flux =  m1 * _zdsqvol * PV [ _li] * ca [ _li] ;
 b_flux =  m2 * _zdsqvol * PV_ca [ _li] ;
 DPV [ _li] -= (f_flux - b_flux);
 Dca [ _li] -= (f_flux - b_flux);
 DPV_ca [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  /* ~ mg [ _li ] + PV [ _li ] <-> PV_mg [ _li ] ( p1 * _zdsqvol , p2 * _zdsqvol )*/
 f_flux =  p1 * _zdsqvol * PV [ _li] * mg [ _li] ;
 b_flux =  p2 * _zdsqvol * PV_mg [ _li] ;
 DPV [ _li] -= (f_flux - b_flux);
 Dmg [ _li] -= (f_flux - b_flux);
 DPV_mg [ _li] += (f_flux - b_flux);
 
 /*REACTION*/
  } }
 cai = ca [ 0 ] ;
 ca1 = ca [ 1 ] ;
 ca2 = ca [ 2 ] ;
 ca3 = ca [ 3 ] ;
 ca4 = ca [ 4 ] ;
 ca5 = ca [ 5 ] ;
 ca9 = ca [ 9 ] ;
 mgi = mg [ 0 ] ;
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 0]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 10]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 20]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 30]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 40]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 50]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 60]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 70]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 80]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 90]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 100]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 110]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 10; _i++) { _p[_dlist1[_i + 120]] /= ( diam * diam * vrat [ ((int) _i ) ]);}
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<130;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 0) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 0, _i + 0) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 10) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 10, _i + 10) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 20) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 20, _i + 20) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 30) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 30, _i + 30) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 40) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 40, _i + 40) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 50) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 50, _i + 50) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 60) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 60, _i + 60) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 70) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 70, _i + 70) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 80) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 80, _i + 80) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 90) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 90, _i + 90) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 100) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 100, _i + 100) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 110) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 110, _i + 110) *= ( diam * diam * vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 10; _i++) {
  	_RHS1(_i + 120) *= ( diam * diam * vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 120, _i + 120) *= ( diam * diam * vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , diam * diam * vrat [ ((int) _i ) ] {
 ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
 pump pumpca }
 */
 /* ~ ca [ 0 ] < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 10 - 1 ; _li ++ ) {
 /* ~ ca [ _li ] < < ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) )*/
 /*FLUX*/
  } }
 {int  _li ;for ( _li = 0 ; _li <= 10 - 2 ; _li ++ ) {
 /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li + 1 ,70 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 70 +  _li ,70 +  _li + 1)  -= _term;
 _MATELM1( 70 +  _li + 1 ,70 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] <-> mg [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 120 +  _li ,120 +  _li + 1)  -= _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB [ _li ] <-> CB [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 30 +  _li ,30 +  _li)  += _term;
 _MATELM1( 30 +  _li + 1 ,30 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 30 +  _li ,30 +  _li + 1)  -= _term;
 _MATELM1( 30 +  _li + 1 ,30 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_f_ca [ _li ] <-> CB_f_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li + 1)  -= _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_ca_s [ _li ] <-> CB_ca_s [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 10 +  _li ,10 +  _li)  += _term;
 _MATELM1( 10 +  _li + 1 ,10 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 10 +  _li ,10 +  _li + 1)  -= _term;
 _MATELM1( 10 +  _li + 1 ,10 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_ca_ca [ _li ] <-> CB_ca_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 _MATELM1( 0 +  _li + 1 ,0 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 0 +  _li ,0 +  _li + 1)  -= _term;
 _MATELM1( 0 +  _li + 1 ,0 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV [ _li ] <-> PV [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li + 1)  -= _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_ca [ _li ] <-> PV_ca [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 50 +  _li ,50 +  _li)  += _term;
 _MATELM1( 50 +  _li + 1 ,50 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 50 +  _li ,50 +  _li + 1)  -= _term;
 _MATELM1( 50 +  _li + 1 ,50 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_mg [ _li ] <-> PV_mg [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li + 1)  -= _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li + 1)  += _term;
 /*REACTION*/
  } }
 _zdsq = diam * diam ;
 {int  _li ;for ( _li = 0 ; _li <= 10 - 1 ; _li ++ ) {
 _zdsqvol = _zdsq * vrat [ _li ] ;
 /* ~ ca [ _li ] + CB [ _li ] <-> CB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 30 +  _li ,30 +  _li)  += _term;
 _MATELM1( 70 +  _li ,30 +  _li)  += _term;
 _MATELM1( 10 +  _li ,30 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 30 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 10 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 30 +  _li ,10 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,10 +  _li)  -= _term;
 _MATELM1( 10 +  _li ,10 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB [ _li ] <-> CB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 30 +  _li ,30 +  _li)  += _term;
 _MATELM1( 70 +  _li ,30 +  _li)  += _term;
 _MATELM1( 20 +  _li ,30 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 30 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 20 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 30 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_f_ca [ _li ] <-> CB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 70 +  _li ,20 +  _li)  += _term;
 _MATELM1( 0 +  _li ,20 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB_f_ca [ _li] ;
 _MATELM1( 20 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 0 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 20 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_ca_s [ _li ] <-> CB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 10 +  _li ,10 +  _li)  += _term;
 _MATELM1( 70 +  _li ,10 +  _li)  += _term;
 _MATELM1( 0 +  _li ,10 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB_ca_s [ _li] ;
 _MATELM1( 10 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 0 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 10 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 110 +  _li ,110 +  _li)  += _term;
 _MATELM1( 70 +  _li ,110 +  _li)  += _term;
 _MATELM1( 90 +  _li ,110 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 110 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 90 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 110 +  _li ,90 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,90 +  _li)  -= _term;
 _MATELM1( 90 +  _li ,90 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 110 +  _li ,110 +  _li)  += _term;
 _MATELM1( 70 +  _li ,110 +  _li)  += _term;
 _MATELM1( 100 +  _li ,110 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 110 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 100 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 110 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_f_ca [ _li ] <-> iCB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 _MATELM1( 70 +  _li ,100 +  _li)  += _term;
 _MATELM1( 80 +  _li ,100 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB_f_ca [ _li] ;
 _MATELM1( 100 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 80 +  _li ,70 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 100 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_ca_s [ _li ] <-> iCB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 90 +  _li ,90 +  _li)  += _term;
 _MATELM1( 70 +  _li ,90 +  _li)  += _term;
 _MATELM1( 80 +  _li ,90 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB_ca_s [ _li] ;
 _MATELM1( 90 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 80 +  _li ,70 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 90 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + PV [ _li ] <-> PV_ca [ _li ] ( m1 * _zdsqvol , m2 * _zdsqvol )*/
 _term =  m1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 70 +  _li ,60 +  _li)  += _term;
 _MATELM1( 50 +  _li ,60 +  _li)  -= _term;
 _term =  m1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 60 +  _li ,70 +  _li)  += _term;
 _MATELM1( 70 +  _li ,70 +  _li)  += _term;
 _MATELM1( 50 +  _li ,70 +  _li)  -= _term;
 _term =  m2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,50 +  _li)  -= _term;
 _MATELM1( 70 +  _li ,50 +  _li)  -= _term;
 _MATELM1( 50 +  _li ,50 +  _li)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] + PV [ _li ] <-> PV_mg [ _li ] ( p1 * _zdsqvol , p2 * _zdsqvol )*/
 _term =  p1 * _zdsqvol * mg [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 120 +  _li ,60 +  _li)  += _term;
 _MATELM1( 40 +  _li ,60 +  _li)  -= _term;
 _term =  p1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 60 +  _li ,120 +  _li)  += _term;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 40 +  _li ,120 +  _li)  -= _term;
 _term =  p2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 120 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 /*REACTION*/
  } }
 cai = ca [ 0 ] ;
 ca1 = ca [ 1 ] ;
 ca2 = ca [ 2 ] ;
 ca3 = ca [ 3 ] ;
 ca4 = ca [ 4 ] ;
 ca5 = ca [ 5 ] ;
 ca9 = ca [ 9 ] ;
 mgi = mg [ 0 ] ;
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 130;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
     _ode_spec1 ();
  _ion_cai = cai;
 }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 130; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 static void _ode_synonym(int _cnt, double** _pp, Datum** _ppd) { 
 	int _i; 
	for (_i=0; _i < _cnt; ++_i) {_p = _pp[_i]; _ppvar = _ppd[_i];
 _ion_cai =  ca [ 0 ] ;
 }}
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _cvode_sparse(&_cvsparseobj1, 130, _dlist1, _p, _ode_matsol1, &_coef1);
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
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_ca_sym, _ppvar, 0, 2);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 1, 1);
   nrn_update_ion_pointer(_ca_sym, _ppvar, 2, 3);
 }

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
 for (_i=0; _i<10; _i++) CB_ca_ca[_i] = CB_ca_ca0;
 for (_i=0; _i<10; _i++) CB_ca_s[_i] = CB_ca_s0;
 for (_i=0; _i<10; _i++) CB_f_ca[_i] = CB_f_ca0;
 for (_i=0; _i<10; _i++) CB[_i] = CB0;
 for (_i=0; _i<10; _i++) PV_mg[_i] = PV_mg0;
 for (_i=0; _i<10; _i++) PV_ca[_i] = PV_ca0;
 for (_i=0; _i<10; _i++) PV[_i] = PV0;
 for (_i=0; _i<10; _i++) ca[_i] = ca0;
 for (_i=0; _i<10; _i++) iCB_ca_ca[_i] = iCB_ca_ca0;
 for (_i=0; _i<10; _i++) iCB_ca_s[_i] = iCB_ca_s0;
 for (_i=0; _i<10; _i++) iCB_f_ca[_i] = iCB_f_ca0;
 for (_i=0; _i<10; _i++) iCB[_i] = iCB0;
 for (_i=0; _i<10; _i++) mg[_i] = mg0;
  pumpca = pumpca0;
  pump = pump0;
 {
   if ( _zfactors_done  == 0.0 ) {
     _zfactors_done = 1.0 ;
     factors ( _threadargs_ ) ;
     }
   {int  _li ;for ( _li = 0 ; _li <= 10 - 1 ; _li ++ ) {
     ca [ _li ] = cainull ;
     mg [ _li ] = mginull ;
     CB [ _li ] = 0.8 * ssCB ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     CB_f_ca [ _li ] = 0.8 * ssCBfast ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     CB_ca_s [ _li ] = 0.8 * ssCBslow ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     CB_ca_ca [ _li ] = 0.8 * ssCBca ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     iCB [ _li ] = 0.2 * ssCB ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     iCB_f_ca [ _li ] = 0.2 * ssCBfast ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     iCB_ca_s [ _li ] = 0.2 * ssCBslow ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     iCB_ca_ca [ _li ] = 0.2 * ssCBca ( _threadargscomma_ kdf ( _threadargs_ ) , kds ( _threadargs_ ) ) ;
     PV [ _li ] = ssPV ( _threadargscomma_ kdc ( _threadargs_ ) , kdm ( _threadargs_ ) ) ;
     PV_ca [ _li ] = ssPVca ( _threadargscomma_ kdc ( _threadargs_ ) , kdm ( _threadargs_ ) ) ;
     PV_mg [ _li ] = ssPVmg ( _threadargscomma_ kdc ( _threadargs_ ) , kdm ( _threadargs_ ) ) ;
     } }
   parea = PI * diam ;
   ica = 0.0 ;
   ica_pmp = 0.0 ;
   pump = TotalPump ;
   pumpca = 0.0 ;
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
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 initmodel();
  _ion_cai = cai;
  nrn_wrote_conc(_ca_sym, (&(_ion_cai)) - 1, _style_ca);
}}

static double _nrn_current(double _v){double _current=0.;v=_v;{
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
  cao = _ion_cao;
  cai = _ion_cai;
  ica = _ion_ica;
  cai = _ion_cai;
 { error = sparse(&_sparseobj1, 130, _slist1, _dlist1, _p, &t, dt, state,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 133 in file cdp_AIS.mod:\n:	ica = ica_pmp\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 130; ++_i) {
      _p[_slist1[_i]] += dt*_p[_dlist1[_i]];
    }}
 } {
   }
  _ion_cai = cai;
}}
 dt = _dtsav;
}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
 for(_i=0;_i<10;_i++){_slist1[0+_i] = CB_ca_ca_columnindex + _i;  _dlist1[0+_i] = DCB_ca_ca_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[10+_i] = CB_ca_s_columnindex + _i;  _dlist1[10+_i] = DCB_ca_s_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[20+_i] = CB_f_ca_columnindex + _i;  _dlist1[20+_i] = DCB_f_ca_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[30+_i] = CB_columnindex + _i;  _dlist1[30+_i] = DCB_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[40+_i] = PV_mg_columnindex + _i;  _dlist1[40+_i] = DPV_mg_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[50+_i] = PV_ca_columnindex + _i;  _dlist1[50+_i] = DPV_ca_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[60+_i] = PV_columnindex + _i;  _dlist1[60+_i] = DPV_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[70+_i] = ca_columnindex + _i;  _dlist1[70+_i] = Dca_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[80+_i] = iCB_ca_ca_columnindex + _i;  _dlist1[80+_i] = DiCB_ca_ca_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[90+_i] = iCB_ca_s_columnindex + _i;  _dlist1[90+_i] = DiCB_ca_s_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[100+_i] = iCB_f_ca_columnindex + _i;  _dlist1[100+_i] = DiCB_f_ca_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[110+_i] = iCB_columnindex + _i;  _dlist1[110+_i] = DiCB_columnindex + _i;}
 for(_i=0;_i<10;_i++){_slist1[120+_i] = mg_columnindex + _i;  _dlist1[120+_i] = Dmg_columnindex + _i;}
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "/home/cbao/Purkinje19b972_ephys/purkinje_pub/cdp_AIS.mod";
static const char* nmodl_file_text = 
  ": Calcium ion accumulation with radial and longitudinal diffusion and pump\n"
  "\n"
  "NEURON {\n"
  "  SUFFIX cdpAIS\n"
  "  USEION ca READ cao, cai, ica WRITE cai\n"
  "  RANGE ica_pmp,ca1,ca2,ca3,ca4,ca5,ca9\n"
  ":RANGE pump_0  \n"
  "GLOBAL vrat, TotalPump\n"
  "    : vrat must be GLOBAL--see INITIAL block\n"
  "    : however TotalBuffer and TotalPump may be RANGE\n"
  ":    THREADSAFE\n"
  "}\n"
  "\n"
  "DEFINE Nannuli 10\n"
  "\n"
  "UNITS {\n"
  "	(mol)   = (1)\n"
  "	(molar) = (1/liter)\n"
  "	(mM)    = (millimolar)\n"
  "	(um)    = (micron)\n"
  "	(mA)    = (milliamp)\n"
  "	FARADAY = (faraday)  (10000 coulomb)\n"
  "	PI      = (pi)       (1)\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "    v\n"
  "	celsius =34     (degC)\n"
  "        \n"
  "	:cainull =2.5e-4 (mM)\n"
  "	cainull = 45e-6 (mM)\n"
  "        mginull =.59    (mM)\n"
  "\n"
  "        DCa     = .233  (um2/ms)\n"
  "	Dbtc 	= 0.007 (um2/ms)\n"
  "       Ddmnpe = 0.08	(um2/ms)\n"
  "	\n"
  "	Dcbd1   = .028  (um2/ms)\n"
  "        Dcbd2   = 0     (um2/ms)\n"
  "        Dpar    = .043  (um2/ms)\n"
  "\n"
  ":	values for benzothiazole coumarin (BTC)\n"
  ":	BTCnull = 0	(mM)\n"
  ":	b1 = 5.33	(/ms mM)\n"
  ":	b2 = 0.08	(/ms)\n"
  "\n"
  ":	values for caged compound DMNPE-4\n"
  ":	DMNPEnull = 0	(mM)\n"
  ":	c1 = 5.63	(/ms mM)\n"
  ":	c2 = 0.107e-3	(/ms)\n"
  "\n"
  ":       values for Calbindin (2 high and 2 low affinity binding sites)\n"
  "\n"
  ":        CBnull=	.16             (mM)\n"
  "         CBnull=	.08             (mM)       \n"
  "        nf1   =43.5           (/ms mM)\n"
  "        nf2   =3.58e-2        (/ms)\n"
  "        ns1   =5.5            (/ms mM)\n"
  "        ns2   =0.26e-2        (/ms)\n"
  "\n"
  ":       values for Parvalbumin\n"
  "\n"
  ":        PVnull  = 0.08           (mM)\n"
  "        PVnull  = 0.04           (mM)\n"
  "        m1    = 1.07e2        (/ms mM)\n"
  "        m2    = 9.5e-4                (/ms)\n"
  "        p1    = 0.8           (/ms mM)\n"
  "        p2    = 2.5e-2                (/ms)        \n"
  "    \n"
  "  	kpmp1    = 3e3       (/mM-ms)\n"
  "  	kpmp2    = 1.75e1   (/ms)\n"
  "  	kpmp3    = 7.255e1  (/ms)\n"
  "  : to eliminate pump, set TotalPump to 0 in hoc\n"
  "	TotalPump = 1e-15\n"
  ":	TotalPump = 1e-8\n"
  "	beta  = 1(1)           :introducing beta to take care of other ER mechanisms(SERCA and leak channel density)\n"
  "    vmax =0.1\n"
  "    :Kp = 0.27e-3 (mM)\n"
  "    Kp = 2.7e-3 (mM)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	diam      (um)\n"
  "	ica       (mA/cm2)\n"
  "	ica_pmp   (mA/cm2)\n"
  "	ibg     :background calcium current\n"
  ":	ica_pmp_last   (mA/cm2)\n"
  "	parea     (um)     : pump area per unit length\n"
  "	cai       (mM)\n"
  "	cao       (mM)\n"
  "	ca1\n"
  "	ca2\n"
  "	ca3\n"
  "	ca4\n"
  "	ca5\n"
  "	ca9\n"
  "	mgi	(mM)	\n"
  "	vrat[Nannuli]  (1) : dimensionless\n"
  "                     : numeric value of vrat[i] equals the volume \n"
  "                     : of annulus i of a 1um diameter cylinder\n"
  "                     : multiply by diam^2 to get volume per um length\n"
  "	\n"
  "}\n"
  "\n"
  "STATE {\n"
  "	: ca[0] is equivalent to cai\n"
  "	: ca[] are very small, so specify absolute tolerance\n"
  "	: let it be ~1.5 - 2 orders of magnitude smaller than baseline level\n"
  "	ca[Nannuli]		(mM)\n"
  "	mg[Nannuli]		(mM)	<1e-7>\n"
  "\n"
  "        CB[Nannuli]		(mM)\n"
  "        CB_f_ca[Nannuli]	(mM)\n"
  "        CB_ca_s[Nannuli]	(mM)\n"
  "        CB_ca_ca[Nannuli]	(mM)\n"
  "\n"
  "        iCB[Nannuli]		(mM)\n"
  "        iCB_f_ca[Nannuli]	(mM)\n"
  "        iCB_ca_s[Nannuli]	(mM)\n"
  "        iCB_ca_ca[Nannuli]	(mM)\n"
  "\n"
  "        PV[Nannuli]		(mM)\n"
  "        PV_ca[Nannuli]		(mM)\n"
  "        PV_mg[Nannuli]		(mM)\n"
  "	\n"
  "	pump			(mol/cm2) <1e-15>\n"
  "	pumpca			(mol/cm2) <1e-15>\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE state METHOD sparse\n"
  ":	ica_pmp_last = ica_pmp\n"
  ":	ica = ica_pmp\n"
  "}\n"
  "\n"
  "LOCAL factors_done\n"
  "\n"
  "INITIAL {\n"
  "	if (factors_done == 0) {  : flag becomes 1 in the first segment\n"
  "		factors_done = 1       :   all subsequent segments will have\n"
  "		factors()              :   vrat = 0 unless vrat is GLOBAL\n"
  "	}\n"
  "	FROM i=0 TO Nannuli-1 {\n"
  "		ca[i] = cainull\n"
  "		mg[i] = mginull\n"
  "\n"
  "\n"
  "		CB[i] = 0.8*ssCB( kdf(), kds())   \n"
  "	        CB_f_ca[i] = 0.8*ssCBfast( kdf(), kds())\n"
  "       	 	CB_ca_s[i] = 0.8*ssCBslow( kdf(), kds())\n"
  "        	CB_ca_ca[i] = 0.8*ssCBca( kdf(), kds())\n"
  "\n"
  "        	iCB[i] = 0.2*ssCB( kdf(), kds())\n"
  "        	iCB_f_ca[i] = 0.2*ssCBfast( kdf(), kds())\n"
  "        	iCB_ca_s[i] = 0.2*ssCBslow( kdf(), kds())\n"
  "        	iCB_ca_ca[i] = 0.2*ssCBca(kdf(), kds())\n"
  "\n"
  "        	PV[i] = ssPV( kdc(), kdm())\n"
  "        	PV_ca[i] = ssPVca(kdc(), kdm())\n"
  "        	PV_mg[i] = ssPVmg(kdc(), kdm())\n"
  "\n"
  "		\n"
  "	}\n"
  "  	parea = PI*diam\n"
  "	ica = 0\n"
  "	ica_pmp = 0\n"
  ":	ica_pmp_last = 0\n"
  "	pump = TotalPump\n"
  "	pumpca = 0\n"
  "}\n"
  "\n"
  "LOCAL frat[Nannuli]  : scales the rate constants for model geometry\n"
  "\n"
  "PROCEDURE factors() {\n"
  "	LOCAL r, dr2\n"
  "	r = 1/2                : starts at edge (half diam)\n"
  "	dr2 = r/(Nannuli-1)/2  : full thickness of outermost annulus,\n"
  "                         : half thickness of all other annuli\n"
  "	vrat[0] = 0\n"
  "	frat[0] = 2*r\n"
  "	FROM i=0 TO Nannuli-2 {\n"
  "		vrat[i] = vrat[i] + PI*(r-dr2/2)*2*dr2  : interior half\n"
  "		r = r - dr2\n"
  "		frat[i+1] = 2*PI*r/(2*dr2)  : outer radius of annulus\n"
  "                                : div by distance between centers\n"
  "		r = r - dr2\n"
  "    		vrat[i+1] = PI*(r+dr2/2)*2*dr2  : outer half of annulus\n"
  "  	}\n"
  "}\n"
  "\n"
  "LOCAL dsq, dsqvol  : can't define local variable in KINETIC block\n"
  "                   :   or use in COMPARTMENT statement\n"
  "\n"
  "KINETIC state {\n"
  "  COMPARTMENT i, diam*diam*vrat[i] {ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg}\n"
  "  COMPARTMENT (1e10)*parea {pump pumpca}\n"
  "	:pump\n"
  ":	~ ca[0] + pump <-> pumpca  (kpmp1*parea*(1e10), kpmp2*parea*(1e10))\n"
  ":	~ pumpca <-> pump   (kpmp3*parea*(1e10), 0)\n"
  ":  	CONSERVE pump + pumpca = TotalPump * parea * (1e10)\n"
  "\n"
  ":	ica_pmp = 2*FARADAY*(f_flux - b_flux)/parea\n"
  "\n"
  "	: all currents except pump\n"
  "	: ica is Ca efflux\n"
  "	~ ca[0] << (-ica*PI*diam/(2*FARADAY))\n"
  "\n"
  "	:RADIAL DIFFUSION OF ca, mg and mobile buffers\n"
  "\n"
  "    FROM i=0 TO Nannuli-1 {\n"
  "    ~ ca[i] << (-beta*vmax*vrat[i]*ca[i] / (ca[i] + kpmp2/kpmp1))\n"
  "\n"
  "    }\n"
  "    \n"
  "	FROM i=0 TO Nannuli-2 {\n"
  "		~ ca[i] <-> ca[i+1]	(DCa*frat[i+1], DCa*frat[i+1])\n"
  "		~ mg[i] <-> mg[i+1]	(DCa*frat[i+1], DCa*frat[i+1])\n"
  "		~ CB[i] <-> CB[i+1]	(Dcbd1*frat[i+1], Dcbd1*frat[i+1])\n"
  "		~ CB_f_ca[i] <-> CB_f_ca[i+1]	(Dcbd1*frat[i+1], Dcbd1*frat[i+1])\n"
  "		~ CB_ca_s[i] <-> CB_ca_s[i+1]	(Dcbd1*frat[i+1], Dcbd1*frat[i+1])\n"
  "		~ CB_ca_ca[i] <-> CB_ca_ca[i+1]	(Dcbd1*frat[i+1], Dcbd1*frat[i+1])\n"
  "		~ PV[i] <-> PV[i+1]	(Dpar*frat[i+1], Dpar*frat[i+1])\n"
  "		~ PV_ca[i] <-> PV_ca[i+1]	(Dpar*frat[i+1], Dpar*frat[i+1])\n"
  "		~ PV_mg[i] <-> PV_mg[i+1] 	(Dpar*frat[i+1], Dpar*frat[i+1])\n"
  "	}\n"
  "	dsq = diam*diam\n"
  "	FROM i=0 TO Nannuli-1 {\n"
  "		dsqvol = dsq*vrat[i]\n"
  "		:Calbindin	\n"
  "		~ ca[i] + CB[i] <-> CB_ca_s[i] (nf1*dsqvol, nf2*dsqvol)\n"
  "	       	~ ca[i] + CB[i] <-> CB_f_ca[i] (ns1*dsqvol, ns2*dsqvol)\n"
  "        	~ ca[i] + CB_f_ca[i] <-> CB_ca_ca[i] (nf1*dsqvol, nf2*dsqvol)\n"
  "        	~ ca[i] + CB_ca_s[i] <-> CB_ca_ca[i] (ns1*dsqvol, ns2*dsqvol)\n"
  "\n"
  "        	~ ca[i] + iCB[i] <-> iCB_ca_s[i] (nf1*dsqvol, nf2*dsqvol)\n"
  "        	~ ca[i] + iCB[i] <-> iCB_f_ca[i] (ns1*dsqvol, ns2*dsqvol)\n"
  "        	~ ca[i] + iCB_f_ca[i] <-> iCB_ca_ca[i] (nf1*dsqvol, nf2*dsqvol)\n"
  "        	~ ca[i] + iCB_ca_s[i] <-> iCB_ca_ca[i] (ns1*dsqvol, ns2*dsqvol)\n"
  "\n"
  "\n"
  "		:Paravalbumin\n"
  "        	~ ca[i] + PV[i] <-> PV_ca[i] (m1*dsqvol, m2*dsqvol)\n"
  "        	~ mg[i] + PV[i] <-> PV_mg[i] (p1*dsqvol, p2*dsqvol)\n"
  "	}\n"
  "\n"
  "\n"
  "\n"
  "  	cai = ca[0]\n"
  "  	ca1 = ca[1]\n"
  "  	ca2 = ca[2]\n"
  "  	ca3 = ca[3]\n"
  "  	ca4 = ca[4]\n"
  "  	ca5 = ca[5]\n"
  "  	ca9 = ca[9]\n"
  ":  	if (ca[0]<cainull){: keep minimum\n"
  ":	   cai=cainull }\n"
  "	mgi = mg[0]\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION ssCB( kdf(), kds()) (mM) {\n"
  "	ssCB = CBnull/(1+kdf()+kds()+(kdf()*kds()))\n"
  "}\n"
  "FUNCTION ssCBfast( kdf(), kds()) (mM) {\n"
  "	ssCBfast = (CBnull*kds())/(1+kdf()+kds()+(kdf()*kds()))\n"
  "}\n"
  "FUNCTION ssCBslow( kdf(), kds()) (mM) {\n"
  "	ssCBslow = (CBnull*kdf())/(1+kdf()+kds()+(kdf()*kds()))\n"
  "}\n"
  "FUNCTION ssCBca(kdf(), kds()) (mM) {\n"
  "	ssCBca = (CBnull*kdf()*kds())/(1+kdf()+kds()+(kdf()*kds()))\n"
  "}\n"
  "FUNCTION kdf() (1) {\n"
  "	kdf = (cainull*nf1)/nf2\n"
  "}\n"
  "FUNCTION kds() (1) {\n"
  "	kds = (cainull*ns1)/ns2\n"
  "}\n"
  "FUNCTION kdc() (1) {\n"
  "	kdc = (cainull*m1)/m2\n"
  "}\n"
  "FUNCTION kdm() (1) {\n"
  "	kdm = (mginull*p1)/p2\n"
  "}\n"
  "FUNCTION ssPV( kdc(), kdm()) (mM) {\n"
  "	ssPV = PVnull/(1+kdc()+kdm())\n"
  "}\n"
  "FUNCTION ssPVca( kdc(), kdm()) (mM) {\n"
  "	ssPVca = (PVnull*kdc)/(1+kdc+kdm)\n"
  "}\n"
  "FUNCTION ssPVmg( kdc(), kdm()) (mM) {\n"
  "	ssPVmg = (PVnull*kdm())/(1+kdc()+kdm())\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION u (x, th) {\n"
  "  	if (x<th) {\n"
  "    		u = 1\n"
  "  	} else {\n"
  "    		u = 0\n"
  "  	}\n"
  "}\n"
  ;
#endif
