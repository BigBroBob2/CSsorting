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
 
#define nrn_init _nrn_init__cdp20N_FD2
#define _nrn_initial _nrn_initial__cdp20N_FD2
#define nrn_cur _nrn_cur__cdp20N_FD2
#define _nrn_current _nrn_current__cdp20N_FD2
#define nrn_jacob _nrn_jacob__cdp20N_FD2
#define nrn_state _nrn_state__cdp20N_FD2
#define _net_receive _net_receive__cdp20N_FD2 
#define factors factors__cdp20N_FD2 
#define state state__cdp20N_FD2 
 
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
#define ca (_p + 1)
#define ca_columnindex 1
#define mg (_p + 21)
#define mg_columnindex 21
#define CB (_p + 41)
#define CB_columnindex 41
#define CB_f_ca (_p + 61)
#define CB_f_ca_columnindex 61
#define CB_ca_s (_p + 81)
#define CB_ca_s_columnindex 81
#define CB_ca_ca (_p + 101)
#define CB_ca_ca_columnindex 101
#define iCB (_p + 121)
#define iCB_columnindex 121
#define iCB_f_ca (_p + 141)
#define iCB_f_ca_columnindex 141
#define iCB_ca_s (_p + 161)
#define iCB_ca_s_columnindex 161
#define iCB_ca_ca (_p + 181)
#define iCB_ca_ca_columnindex 181
#define PV (_p + 201)
#define PV_columnindex 201
#define PV_ca (_p + 221)
#define PV_ca_columnindex 221
#define PV_mg (_p + 241)
#define PV_mg_columnindex 241
#define pump _p[261]
#define pump_columnindex 261
#define pumpca _p[262]
#define pumpca_columnindex 262
#define ica _p[263]
#define ica_columnindex 263
#define parea _p[264]
#define parea_columnindex 264
#define cai _p[265]
#define cai_columnindex 265
#define cao _p[266]
#define cao_columnindex 266
#define mgi _p[267]
#define mgi_columnindex 267
#define Dca (_p + 268)
#define Dca_columnindex 268
#define Dmg (_p + 288)
#define Dmg_columnindex 288
#define DCB (_p + 308)
#define DCB_columnindex 308
#define DCB_f_ca (_p + 328)
#define DCB_f_ca_columnindex 328
#define DCB_ca_s (_p + 348)
#define DCB_ca_s_columnindex 348
#define DCB_ca_ca (_p + 368)
#define DCB_ca_ca_columnindex 368
#define DiCB (_p + 388)
#define DiCB_columnindex 388
#define DiCB_f_ca (_p + 408)
#define DiCB_f_ca_columnindex 408
#define DiCB_ca_s (_p + 428)
#define DiCB_ca_s_columnindex 428
#define DiCB_ca_ca (_p + 448)
#define DiCB_ca_ca_columnindex 448
#define DPV (_p + 468)
#define DPV_columnindex 468
#define DPV_ca (_p + 488)
#define DPV_ca_columnindex 488
#define DPV_mg (_p + 508)
#define DPV_mg_columnindex 508
#define Dpump _p[528]
#define Dpump_columnindex 528
#define Dpumpca _p[529]
#define Dpumpca_columnindex 529
#define _g _p[530]
#define _g_columnindex 530
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
 "setdata_cdp20N_FD2", _hoc_setdata,
 "factors_cdp20N_FD2", _hoc_factors,
 "kdm_cdp20N_FD2", _hoc_kdm,
 "kdc_cdp20N_FD2", _hoc_kdc,
 "kds_cdp20N_FD2", _hoc_kds,
 "kdf_cdp20N_FD2", _hoc_kdf,
 "ssPVmg_cdp20N_FD2", _hoc_ssPVmg,
 "ssPVca_cdp20N_FD2", _hoc_ssPVca,
 "ssPV_cdp20N_FD2", _hoc_ssPV,
 "ssCBca_cdp20N_FD2", _hoc_ssCBca,
 "ssCBslow_cdp20N_FD2", _hoc_ssCBslow,
 "ssCBfast_cdp20N_FD2", _hoc_ssCBfast,
 "ssCB_cdp20N_FD2", _hoc_ssCB,
 0, 0
};
#define kdm kdm_cdp20N_FD2
#define kdc kdc_cdp20N_FD2
#define kds kds_cdp20N_FD2
#define kdf kdf_cdp20N_FD2
#define ssPVmg ssPVmg_cdp20N_FD2
#define ssPVca ssPVca_cdp20N_FD2
#define ssPV ssPV_cdp20N_FD2
#define ssCBca ssCBca_cdp20N_FD2
#define ssCBslow ssCBslow_cdp20N_FD2
#define ssCBfast ssCBfast_cdp20N_FD2
#define ssCB ssCB_cdp20N_FD2
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
 /* declare global and static user variables */
#define BTCnull BTCnull_cdp20N_FD2
 double BTCnull = 0;
#define CBnull CBnull_cdp20N_FD2
 double CBnull = 0.08;
#define DMNPEnull DMNPEnull_cdp20N_FD2
 double DMNPEnull = 0;
#define Dpar Dpar_cdp20N_FD2
 double Dpar = 0.043;
#define Dcbd2 Dcbd2_cdp20N_FD2
 double Dcbd2 = 0;
#define Dcbd1 Dcbd1_cdp20N_FD2
 double Dcbd1 = 0.028;
#define Ddmnpe Ddmnpe_cdp20N_FD2
 double Ddmnpe = 0.08;
#define Dbtc Dbtc_cdp20N_FD2
 double Dbtc = 0.007;
#define DCa DCa_cdp20N_FD2
 double DCa = 0.233;
#define Kp Kp_cdp20N_FD2
 double Kp = 0.0027;
#define PVnull PVnull_cdp20N_FD2
 double PVnull = 0.04;
#define TotalPump TotalPump_cdp20N_FD2
 double TotalPump = 1e-15;
#define beta beta_cdp20N_FD2
 double beta = 1;
#define b2 b2_cdp20N_FD2
 double b2 = 0.08;
#define b1 b1_cdp20N_FD2
 double b1 = 5.33;
#define c2 c2_cdp20N_FD2
 double c2 = 0.000107;
#define c1 c1_cdp20N_FD2
 double c1 = 5.63;
#define cainull cainull_cdp20N_FD2
 double cainull = 4.5e-05;
#define kpmp3 kpmp3_cdp20N_FD2
 double kpmp3 = 72.55;
#define kpmp2 kpmp2_cdp20N_FD2
 double kpmp2 = 17.5;
#define kpmp1 kpmp1_cdp20N_FD2
 double kpmp1 = 3000;
#define m2 m2_cdp20N_FD2
 double m2 = 0.00095;
#define m1 m1_cdp20N_FD2
 double m1 = 107;
#define mginull mginull_cdp20N_FD2
 double mginull = 0.59;
#define ns2 ns2_cdp20N_FD2
 double ns2 = 0.0026;
#define ns1 ns1_cdp20N_FD2
 double ns1 = 5.5;
#define nf2 nf2_cdp20N_FD2
 double nf2 = 0.0358;
#define nf1 nf1_cdp20N_FD2
 double nf1 = 43.5;
#define p2 p2_cdp20N_FD2
 double p2 = 0.025;
#define p1 p1_cdp20N_FD2
 double p1 = 0.8;
#define vmax vmax_cdp20N_FD2
 double vmax = 0.1;
#define vrat vrat_cdp20N_FD2
 double vrat[20];
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "cainull_cdp20N_FD2", "mM",
 "mginull_cdp20N_FD2", "mM",
 "DCa_cdp20N_FD2", "um2/ms",
 "Dbtc_cdp20N_FD2", "um2/ms",
 "Ddmnpe_cdp20N_FD2", "um2/ms",
 "Dcbd1_cdp20N_FD2", "um2/ms",
 "Dcbd2_cdp20N_FD2", "um2/ms",
 "Dpar_cdp20N_FD2", "um2/ms",
 "BTCnull_cdp20N_FD2", "mM",
 "b1_cdp20N_FD2", "/ms",
 "b2_cdp20N_FD2", "/ms",
 "DMNPEnull_cdp20N_FD2", "mM",
 "c1_cdp20N_FD2", "/ms",
 "c2_cdp20N_FD2", "/ms",
 "nf1_cdp20N_FD2", "/ms",
 "nf2_cdp20N_FD2", "/ms",
 "ns1_cdp20N_FD2", "/ms",
 "ns2_cdp20N_FD2", "/ms",
 "PVnull_cdp20N_FD2", "mM",
 "m1_cdp20N_FD2", "/ms",
 "m2_cdp20N_FD2", "/ms",
 "p1_cdp20N_FD2", "/ms",
 "p2_cdp20N_FD2", "/ms",
 "kpmp1_cdp20N_FD2", "/mM-ms",
 "kpmp2_cdp20N_FD2", "/ms",
 "kpmp3_cdp20N_FD2", "/ms",
 "beta_cdp20N_FD2", "1",
 "Kp_cdp20N_FD2", "mM",
 "vrat_cdp20N_FD2", "um2",
 "ca_cdp20N_FD2", "mM",
 "mg_cdp20N_FD2", "mM",
 "CB_cdp20N_FD2", "mM",
 "CB_f_ca_cdp20N_FD2", "mM",
 "CB_ca_s_cdp20N_FD2", "mM",
 "CB_ca_ca_cdp20N_FD2", "mM",
 "iCB_cdp20N_FD2", "mM",
 "iCB_f_ca_cdp20N_FD2", "mM",
 "iCB_ca_s_cdp20N_FD2", "mM",
 "iCB_ca_ca_cdp20N_FD2", "mM",
 "PV_cdp20N_FD2", "mM",
 "PV_ca_cdp20N_FD2", "mM",
 "PV_mg_cdp20N_FD2", "mM",
 "pump_cdp20N_FD2", "mol/cm2",
 "pumpca_cdp20N_FD2", "mol/cm2",
 "ica_pmp_cdp20N_FD2", "mA/cm2",
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
 "cainull_cdp20N_FD2", &cainull_cdp20N_FD2,
 "mginull_cdp20N_FD2", &mginull_cdp20N_FD2,
 "DCa_cdp20N_FD2", &DCa_cdp20N_FD2,
 "Dbtc_cdp20N_FD2", &Dbtc_cdp20N_FD2,
 "Ddmnpe_cdp20N_FD2", &Ddmnpe_cdp20N_FD2,
 "Dcbd1_cdp20N_FD2", &Dcbd1_cdp20N_FD2,
 "Dcbd2_cdp20N_FD2", &Dcbd2_cdp20N_FD2,
 "Dpar_cdp20N_FD2", &Dpar_cdp20N_FD2,
 "BTCnull_cdp20N_FD2", &BTCnull_cdp20N_FD2,
 "b1_cdp20N_FD2", &b1_cdp20N_FD2,
 "b2_cdp20N_FD2", &b2_cdp20N_FD2,
 "DMNPEnull_cdp20N_FD2", &DMNPEnull_cdp20N_FD2,
 "c1_cdp20N_FD2", &c1_cdp20N_FD2,
 "c2_cdp20N_FD2", &c2_cdp20N_FD2,
 "CBnull_cdp20N_FD2", &CBnull_cdp20N_FD2,
 "nf1_cdp20N_FD2", &nf1_cdp20N_FD2,
 "nf2_cdp20N_FD2", &nf2_cdp20N_FD2,
 "ns1_cdp20N_FD2", &ns1_cdp20N_FD2,
 "ns2_cdp20N_FD2", &ns2_cdp20N_FD2,
 "PVnull_cdp20N_FD2", &PVnull_cdp20N_FD2,
 "m1_cdp20N_FD2", &m1_cdp20N_FD2,
 "m2_cdp20N_FD2", &m2_cdp20N_FD2,
 "p1_cdp20N_FD2", &p1_cdp20N_FD2,
 "p2_cdp20N_FD2", &p2_cdp20N_FD2,
 "kpmp1_cdp20N_FD2", &kpmp1_cdp20N_FD2,
 "kpmp2_cdp20N_FD2", &kpmp2_cdp20N_FD2,
 "kpmp3_cdp20N_FD2", &kpmp3_cdp20N_FD2,
 "TotalPump_cdp20N_FD2", &TotalPump_cdp20N_FD2,
 "beta_cdp20N_FD2", &beta_cdp20N_FD2,
 "vmax_cdp20N_FD2", &vmax_cdp20N_FD2,
 "Kp_cdp20N_FD2", &Kp_cdp20N_FD2,
 0,0
};
 static DoubVec hoc_vdoub[] = {
 "vrat_cdp20N_FD2", vrat_cdp20N_FD2, 20,
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
"cdp20N_FD2",
 0,
 "ica_pmp_cdp20N_FD2",
 0,
 "ca_cdp20N_FD2[20]",
 "mg_cdp20N_FD2[20]",
 "CB_cdp20N_FD2[20]",
 "CB_f_ca_cdp20N_FD2[20]",
 "CB_ca_s_cdp20N_FD2[20]",
 "CB_ca_ca_cdp20N_FD2[20]",
 "iCB_cdp20N_FD2[20]",
 "iCB_f_ca_cdp20N_FD2[20]",
 "iCB_ca_s_cdp20N_FD2[20]",
 "iCB_ca_ca_cdp20N_FD2[20]",
 "PV_cdp20N_FD2[20]",
 "PV_ca_cdp20N_FD2[20]",
 "PV_mg_cdp20N_FD2[20]",
 "pump_cdp20N_FD2",
 "pumpca_cdp20N_FD2",
 0,
 0};
 static Symbol* _morphology_sym;
 static Symbol* _ca_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 531, _prop);
 	/*initialize range parameters*/
 	_prop->param = _p;
 	_prop->param_size = 531;
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
 "mg_cdp20N_FD2", 1e-07,
 "pump_cdp20N_FD2", 1e-15,
 "pumpca_cdp20N_FD2", 1e-15,
 0,0
};
 static void _update_ion_pointer(Datum*);
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _cdp_soma_reg() {
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
  hoc_register_prop_size(_mechtype, 531, 6);
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
 	ivoc_help("help ?1 cdp20N_FD2 cdp_soma.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 
#define FARADAY _nrnunit_FARADAY[_nrnunit_use_legacy_]
static double _nrnunit_FARADAY[2] = {0x1.34c0c8b92a9b7p+3, 9.64853}; /* 9.64853321233100125 */
 
#define PI _nrnunit_PI[_nrnunit_use_legacy_]
static double _nrnunit_PI[2] = {0x1.921fb54442d18p+1, 3.14159}; /* 3.14159265358979312 */
 static double _zfactors_done ;
 static double _zradii [ 20 ] ;
 static double _zfrat [ 20 ] ;
 static double _zdsqvol ;
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
 static int _slist1[260], _dlist1[260]; static double *_temp1;
 static int state();
 
static int  factors (  ) {
   double _lr , _ldr2 , _ldr3 ;
 _lr = diam / 2.0 ;
   _ldr2 = 0.0368 ;
   _ldr3 = ( _lr - _ldr2 ) / ( 20.0 - 1.0 ) ;
   _zradii [ 0 ] = _lr ;
   _zradii [ 1 ] = _lr - _ldr2 ;
   {int  _li ;for ( _li = 2 ; _li <= 20 - 1 ; _li ++ ) {
     _zradii [ _li ] = _zradii [ _li - 1 ] - _ldr3 ;
     printf ( "%f\n" , _zradii [ _li ] ) ;
     } }
   vrat [ 0 ] = 0.0 ;
   _zfrat [ 0 ] = 2.0 * _lr ;
   {int  _li ;for ( _li = 0 ; _li <= 20 - 2 ; _li ++ ) {
     vrat [ _li ] = PI * ( ( _zradii [ _li ] * _zradii [ _li ] ) - ( _zradii [ _li + 1 ] * _zradii [ _li + 1 ] ) ) ;
     } }
   vrat [ 20 - 1 ] = PI * _zradii [ 20 - 1 ] * _zradii [ 20 - 1 ] ;
   {int  _li ;for ( _li = 1 ; _li <= 20 - 1 ; _li ++ ) {
     if ( ((double) _li )  == 1.0 ) {
       _zfrat [ _li ] = 2.0 * PI * _zradii [ _li ] / ( _ldr2 + ( _ldr3 / 2.0 ) ) ;
       }
     else if ( ((double) _li ) > 1.0  && ((double) _li ) < ( 20.0 - 1.0 ) ) {
       _zfrat [ _li ] = 2.0 * PI * _zradii [ _li ] / _ldr3 ;
       }
     else if ( ((double) _li )  == ( 20.0 - 1.0 ) ) {
       _zfrat [ _li ] = 2.0 * PI * _zradii [ _li ] / ( ( _ldr3 / 2.0 ) + _zradii [ _li ] ) ;
       }
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
for(_i=0;_i<260;_i++){
  	_RHS1(_i) = -_dt1*(_p[_slist1[_i]] - _p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 0) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 0, _i + 0) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 20) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 20, _i + 20) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 40) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 40, _i + 40) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 60) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 60, _i + 60) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 80) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 80, _i + 80) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 100) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 100, _i + 100) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 120) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 120, _i + 120) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 140) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 140, _i + 140) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 160) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 160, _i + 160) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 180) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 180, _i + 180) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 200) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 200, _i + 200) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 220) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 220, _i + 220) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 240) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 240, _i + 240) *= ( vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , vrat [ ((int) _i ) ] {
     ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg }
   */
 /* COMPARTMENT ( 1e10 ) * parea {
     pump pumpca }
   */
 /* ~ ca [ 0 ] < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 140 +  0) += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
     /* ~ ca [ _li ] < < ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) )*/
 f_flux = b_flux = 0.;
 _RHS1( 140 +  _li) += (b_flux =   ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) ) );
 /*FLUX*/
  } }
   {int  _li ;for ( _li = 0 ; _li <= 20 - 2 ; _li ++ ) {
     /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * ca [ _li + 1] ;
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li + 1) += (f_flux - b_flux);
 
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li + 1 ,140 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 140 +  _li ,140 +  _li + 1)  -= _term;
 _MATELM1( 140 +  _li + 1 ,140 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] <-> mg [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 f_flux =  DCa * _zfrat [ _li + 1 ] * mg [ _li] ;
 b_flux =  DCa * _zfrat [ _li + 1 ] * mg [ _li + 1] ;
 _RHS1( 240 +  _li) -= (f_flux - b_flux);
 _RHS1( 240 +  _li + 1) += (f_flux - b_flux);
 
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 240 +  _li ,240 +  _li)  += _term;
 _MATELM1( 240 +  _li + 1 ,240 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 240 +  _li ,240 +  _li + 1)  -= _term;
 _MATELM1( 240 +  _li + 1 ,240 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB [ _li ] <-> CB [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB [ _li + 1] ;
 _RHS1( 60 +  _li) -= (f_flux - b_flux);
 _RHS1( 60 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li + 1)  -= _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_f_ca [ _li ] <-> CB_f_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_f_ca [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_f_ca [ _li + 1] ;
 _RHS1( 40 +  _li) -= (f_flux - b_flux);
 _RHS1( 40 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li + 1)  -= _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_ca_s [ _li ] <-> CB_ca_s [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 f_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_s [ _li] ;
 b_flux =  Dcbd1 * _zfrat [ _li + 1 ] * CB_ca_s [ _li + 1] ;
 _RHS1( 20 +  _li) -= (f_flux - b_flux);
 _RHS1( 20 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li + 1)  -= _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li + 1)  += _term;
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
 _RHS1( 120 +  _li) -= (f_flux - b_flux);
 _RHS1( 120 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 120 +  _li ,120 +  _li + 1)  -= _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_ca [ _li ] <-> PV_ca [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV_ca [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV_ca [ _li + 1] ;
 _RHS1( 100 +  _li) -= (f_flux - b_flux);
 _RHS1( 100 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 _MATELM1( 100 +  _li + 1 ,100 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 100 +  _li ,100 +  _li + 1)  -= _term;
 _MATELM1( 100 +  _li + 1 ,100 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_mg [ _li ] <-> PV_mg [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 f_flux =  Dpar * _zfrat [ _li + 1 ] * PV_mg [ _li] ;
 b_flux =  Dpar * _zfrat [ _li + 1 ] * PV_mg [ _li + 1] ;
 _RHS1( 80 +  _li) -= (f_flux - b_flux);
 _RHS1( 80 +  _li + 1) += (f_flux - b_flux);
 
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 _MATELM1( 80 +  _li + 1 ,80 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 80 +  _li ,80 +  _li + 1)  -= _term;
 _MATELM1( 80 +  _li + 1 ,80 +  _li + 1)  += _term;
 /*REACTION*/
  } }
   {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
     _zdsqvol = vrat [ _li ] ;
     /* ~ ca [ _li ] + CB [ _li ] <-> CB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * CB [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * CB_ca_s [ _li] ;
 _RHS1( 60 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 20 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 140 +  _li ,60 +  _li)  += _term;
 _MATELM1( 20 +  _li ,60 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 60 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 20 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB [ _li ] <-> CB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * CB [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * CB_f_ca [ _li] ;
 _RHS1( 60 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 40 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 140 +  _li ,60 +  _li)  += _term;
 _MATELM1( 40 +  _li ,60 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 60 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 40 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_f_ca [ _li ] <-> CB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * CB_f_ca [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * CB_ca_ca [ _li] ;
 _RHS1( 40 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 0 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 _MATELM1( 140 +  _li ,40 +  _li)  += _term;
 _MATELM1( 0 +  _li ,40 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB_f_ca [ _li] ;
 _MATELM1( 40 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 0 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 40 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_ca_s [ _li ] <-> CB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * CB_ca_s [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * CB_ca_ca [ _li] ;
 _RHS1( 20 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 0 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 140 +  _li ,20 +  _li)  += _term;
 _MATELM1( 0 +  _li ,20 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB_ca_s [ _li] ;
 _MATELM1( 20 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 0 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 20 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * iCB [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * iCB_ca_s [ _li] ;
 _RHS1( 220 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 180 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 220 +  _li ,220 +  _li)  += _term;
 _MATELM1( 140 +  _li ,220 +  _li)  += _term;
 _MATELM1( 180 +  _li ,220 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 220 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 180 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 220 +  _li ,180 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,180 +  _li)  -= _term;
 _MATELM1( 180 +  _li ,180 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * iCB [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * iCB_f_ca [ _li] ;
 _RHS1( 220 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 200 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 220 +  _li ,220 +  _li)  += _term;
 _MATELM1( 140 +  _li ,220 +  _li)  += _term;
 _MATELM1( 200 +  _li ,220 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 220 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 200 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 220 +  _li ,200 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,200 +  _li)  -= _term;
 _MATELM1( 200 +  _li ,200 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_f_ca [ _li ] <-> iCB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 f_flux =  nf1 * _zdsqvol * iCB_f_ca [ _li] * ca [ _li] ;
 b_flux =  nf2 * _zdsqvol * iCB_ca_ca [ _li] ;
 _RHS1( 200 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 160 +  _li) += (f_flux - b_flux);
 
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 200 +  _li ,200 +  _li)  += _term;
 _MATELM1( 140 +  _li ,200 +  _li)  += _term;
 _MATELM1( 160 +  _li ,200 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB_f_ca [ _li] ;
 _MATELM1( 200 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 160 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 200 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 160 +  _li ,160 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_ca_s [ _li ] <-> iCB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 f_flux =  ns1 * _zdsqvol * iCB_ca_s [ _li] * ca [ _li] ;
 b_flux =  ns2 * _zdsqvol * iCB_ca_ca [ _li] ;
 _RHS1( 180 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 160 +  _li) += (f_flux - b_flux);
 
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 180 +  _li ,180 +  _li)  += _term;
 _MATELM1( 140 +  _li ,180 +  _li)  += _term;
 _MATELM1( 160 +  _li ,180 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB_ca_s [ _li] ;
 _MATELM1( 180 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 160 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 180 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 160 +  _li ,160 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + PV [ _li ] <-> PV_ca [ _li ] ( m1 * _zdsqvol , m2 * _zdsqvol )*/
 f_flux =  m1 * _zdsqvol * PV [ _li] * ca [ _li] ;
 b_flux =  m2 * _zdsqvol * PV_ca [ _li] ;
 _RHS1( 120 +  _li) -= (f_flux - b_flux);
 _RHS1( 140 +  _li) -= (f_flux - b_flux);
 _RHS1( 100 +  _li) += (f_flux - b_flux);
 
 _term =  m1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 140 +  _li ,120 +  _li)  += _term;
 _MATELM1( 100 +  _li ,120 +  _li)  -= _term;
 _term =  m1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 120 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 100 +  _li ,140 +  _li)  -= _term;
 _term =  m2 * _zdsqvol ;
 _MATELM1( 120 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] + PV [ _li ] <-> PV_mg [ _li ] ( p1 * _zdsqvol , p2 * _zdsqvol )*/
 f_flux =  p1 * _zdsqvol * PV [ _li] * mg [ _li] ;
 b_flux =  p2 * _zdsqvol * PV_mg [ _li] ;
 _RHS1( 120 +  _li) -= (f_flux - b_flux);
 _RHS1( 240 +  _li) -= (f_flux - b_flux);
 _RHS1( 80 +  _li) += (f_flux - b_flux);
 
 _term =  p1 * _zdsqvol * mg [ _li] ;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 240 +  _li ,120 +  _li)  += _term;
 _MATELM1( 80 +  _li ,120 +  _li)  -= _term;
 _term =  p1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 120 +  _li ,240 +  _li)  += _term;
 _MATELM1( 240 +  _li ,240 +  _li)  += _term;
 _MATELM1( 80 +  _li ,240 +  _li)  -= _term;
 _term =  p2 * _zdsqvol ;
 _MATELM1( 120 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 240 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 /*REACTION*/
  } }
   cai = ca [ 0 ] ;
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
 
/*CVODE ode begin*/
 static int _ode_spec1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
 {int _i; for(_i=0;_i<260;_i++) _p[_dlist1[_i]] = 0.0;}
 /* COMPARTMENT _li , vrat [ ((int) _i ) ] {
   ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
   pump pumpca }
 */
 /* ~ ca [ 0 ] < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 f_flux = b_flux = 0.;
 Dca [ 0] += (b_flux =   ( - ica * PI * diam / ( 2.0 * FARADAY ) ) );
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
   /* ~ ca [ _li ] < < ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) )*/
 f_flux = b_flux = 0.;
 Dca [ _li] += (b_flux =   ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) ) );
 /*FLUX*/
  } }
 {int  _li ;for ( _li = 0 ; _li <= 20 - 2 ; _li ++ ) {
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
 {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
   _zdsqvol = vrat [ _li ] ;
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
 mgi = mg [ 0 ] ;
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 0]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 20]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 40]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 60]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 80]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 100]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 120]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 140]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 160]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 180]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 200]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 220]] /= ( vrat [ ((int) _i ) ]);}
 for (_i=0; _i < 20; _i++) { _p[_dlist1[_i + 240]] /= ( vrat [ ((int) _i ) ]);}
   } return _reset;
 }
 
/*CVODE matsol*/
 static int _ode_matsol1() {_reset=0;{
 double b_flux, f_flux, _term; int _i;
   b_flux = f_flux = 0.;
 {int _i; double _dt1 = 1.0/dt;
for(_i=0;_i<260;_i++){
  	_RHS1(_i) = _dt1*(_p[_dlist1[_i]]);
	_MATELM1(_i, _i) = _dt1;
      
} 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 0) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 0, _i + 0) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 20) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 20, _i + 20) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 40) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 40, _i + 40) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 60) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 60, _i + 60) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 80) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 80, _i + 80) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 100) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 100, _i + 100) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 120) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 120, _i + 120) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 140) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 140, _i + 140) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 160) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 160, _i + 160) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 180) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 180, _i + 180) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 200) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 200, _i + 200) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 220) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 220, _i + 220) *= ( vrat [ ((int) _i ) ]);  } 
for (_i=0; _i < 20; _i++) {
  	_RHS1(_i + 240) *= ( vrat [ ((int) _i ) ]) ;
_MATELM1(_i + 240, _i + 240) *= ( vrat [ ((int) _i ) ]);  } }
 /* COMPARTMENT _li , vrat [ ((int) _i ) ] {
 ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg }
 */
 /* COMPARTMENT ( 1e10 ) * parea {
 pump pumpca }
 */
 /* ~ ca [ 0 ] < < ( - ica * PI * diam / ( 2.0 * FARADAY ) )*/
 /*FLUX*/
  {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
 /* ~ ca [ _li ] < < ( - beta * vmax * vrat [ _li ] * ca [ _li ] / ( ca [ _li ] + kpmp2 / kpmp1 ) )*/
 /*FLUX*/
  } }
 {int  _li ;for ( _li = 0 ; _li <= 20 - 2 ; _li ++ ) {
 /* ~ ca [ _li ] <-> ca [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li + 1 ,140 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 140 +  _li ,140 +  _li + 1)  -= _term;
 _MATELM1( 140 +  _li + 1 ,140 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] <-> mg [ _li + 1 ] ( DCa * _zfrat [ _li + 1 ] , DCa * _zfrat [ _li + 1 ] )*/
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 240 +  _li ,240 +  _li)  += _term;
 _MATELM1( 240 +  _li + 1 ,240 +  _li)  -= _term;
 _term =  DCa * _zfrat [ _li + 1 ] ;
 _MATELM1( 240 +  _li ,240 +  _li + 1)  -= _term;
 _MATELM1( 240 +  _li + 1 ,240 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB [ _li ] <-> CB [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 60 +  _li ,60 +  _li + 1)  -= _term;
 _MATELM1( 60 +  _li + 1 ,60 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_f_ca [ _li ] <-> CB_f_ca [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 40 +  _li ,40 +  _li + 1)  -= _term;
 _MATELM1( 40 +  _li + 1 ,40 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ CB_ca_s [ _li ] <-> CB_ca_s [ _li + 1 ] ( Dcbd1 * _zfrat [ _li + 1 ] , Dcbd1 * _zfrat [ _li + 1 ] )*/
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li)  -= _term;
 _term =  Dcbd1 * _zfrat [ _li + 1 ] ;
 _MATELM1( 20 +  _li ,20 +  _li + 1)  -= _term;
 _MATELM1( 20 +  _li + 1 ,20 +  _li + 1)  += _term;
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
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 120 +  _li ,120 +  _li + 1)  -= _term;
 _MATELM1( 120 +  _li + 1 ,120 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_ca [ _li ] <-> PV_ca [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 _MATELM1( 100 +  _li + 1 ,100 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 100 +  _li ,100 +  _li + 1)  -= _term;
 _MATELM1( 100 +  _li + 1 ,100 +  _li + 1)  += _term;
 /*REACTION*/
  /* ~ PV_mg [ _li ] <-> PV_mg [ _li + 1 ] ( Dpar * _zfrat [ _li + 1 ] , Dpar * _zfrat [ _li + 1 ] )*/
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 _MATELM1( 80 +  _li + 1 ,80 +  _li)  -= _term;
 _term =  Dpar * _zfrat [ _li + 1 ] ;
 _MATELM1( 80 +  _li ,80 +  _li + 1)  -= _term;
 _MATELM1( 80 +  _li + 1 ,80 +  _li + 1)  += _term;
 /*REACTION*/
  } }
 {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
 _zdsqvol = vrat [ _li ] ;
 /* ~ ca [ _li ] + CB [ _li ] <-> CB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 140 +  _li ,60 +  _li)  += _term;
 _MATELM1( 20 +  _li ,60 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 60 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 20 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,20 +  _li)  -= _term;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB [ _li ] <-> CB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 60 +  _li ,60 +  _li)  += _term;
 _MATELM1( 140 +  _li ,60 +  _li)  += _term;
 _MATELM1( 40 +  _li ,60 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB [ _li] ;
 _MATELM1( 60 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 40 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 60 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,40 +  _li)  -= _term;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_f_ca [ _li ] <-> CB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 40 +  _li ,40 +  _li)  += _term;
 _MATELM1( 140 +  _li ,40 +  _li)  += _term;
 _MATELM1( 0 +  _li ,40 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * CB_f_ca [ _li] ;
 _MATELM1( 40 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 0 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 40 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + CB_ca_s [ _li ] <-> CB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 20 +  _li ,20 +  _li)  += _term;
 _MATELM1( 140 +  _li ,20 +  _li)  += _term;
 _MATELM1( 0 +  _li ,20 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * CB_ca_s [ _li] ;
 _MATELM1( 20 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 0 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 20 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,0 +  _li)  -= _term;
 _MATELM1( 0 +  _li ,0 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_ca_s [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 220 +  _li ,220 +  _li)  += _term;
 _MATELM1( 140 +  _li ,220 +  _li)  += _term;
 _MATELM1( 180 +  _li ,220 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 220 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 180 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 220 +  _li ,180 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,180 +  _li)  -= _term;
 _MATELM1( 180 +  _li ,180 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB [ _li ] <-> iCB_f_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 220 +  _li ,220 +  _li)  += _term;
 _MATELM1( 140 +  _li ,220 +  _li)  += _term;
 _MATELM1( 200 +  _li ,220 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB [ _li] ;
 _MATELM1( 220 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 200 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 220 +  _li ,200 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,200 +  _li)  -= _term;
 _MATELM1( 200 +  _li ,200 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_f_ca [ _li ] <-> iCB_ca_ca [ _li ] ( nf1 * _zdsqvol , nf2 * _zdsqvol )*/
 _term =  nf1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 200 +  _li ,200 +  _li)  += _term;
 _MATELM1( 140 +  _li ,200 +  _li)  += _term;
 _MATELM1( 160 +  _li ,200 +  _li)  -= _term;
 _term =  nf1 * _zdsqvol * iCB_f_ca [ _li] ;
 _MATELM1( 200 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 160 +  _li ,140 +  _li)  -= _term;
 _term =  nf2 * _zdsqvol ;
 _MATELM1( 200 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 160 +  _li ,160 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + iCB_ca_s [ _li ] <-> iCB_ca_ca [ _li ] ( ns1 * _zdsqvol , ns2 * _zdsqvol )*/
 _term =  ns1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 180 +  _li ,180 +  _li)  += _term;
 _MATELM1( 140 +  _li ,180 +  _li)  += _term;
 _MATELM1( 160 +  _li ,180 +  _li)  -= _term;
 _term =  ns1 * _zdsqvol * iCB_ca_s [ _li] ;
 _MATELM1( 180 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 160 +  _li ,140 +  _li)  -= _term;
 _term =  ns2 * _zdsqvol ;
 _MATELM1( 180 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,160 +  _li)  -= _term;
 _MATELM1( 160 +  _li ,160 +  _li)  += _term;
 /*REACTION*/
  /* ~ ca [ _li ] + PV [ _li ] <-> PV_ca [ _li ] ( m1 * _zdsqvol , m2 * _zdsqvol )*/
 _term =  m1 * _zdsqvol * ca [ _li] ;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 140 +  _li ,120 +  _li)  += _term;
 _MATELM1( 100 +  _li ,120 +  _li)  -= _term;
 _term =  m1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 120 +  _li ,140 +  _li)  += _term;
 _MATELM1( 140 +  _li ,140 +  _li)  += _term;
 _MATELM1( 100 +  _li ,140 +  _li)  -= _term;
 _term =  m2 * _zdsqvol ;
 _MATELM1( 120 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 140 +  _li ,100 +  _li)  -= _term;
 _MATELM1( 100 +  _li ,100 +  _li)  += _term;
 /*REACTION*/
  /* ~ mg [ _li ] + PV [ _li ] <-> PV_mg [ _li ] ( p1 * _zdsqvol , p2 * _zdsqvol )*/
 _term =  p1 * _zdsqvol * mg [ _li] ;
 _MATELM1( 120 +  _li ,120 +  _li)  += _term;
 _MATELM1( 240 +  _li ,120 +  _li)  += _term;
 _MATELM1( 80 +  _li ,120 +  _li)  -= _term;
 _term =  p1 * _zdsqvol * PV [ _li] ;
 _MATELM1( 120 +  _li ,240 +  _li)  += _term;
 _MATELM1( 240 +  _li ,240 +  _li)  += _term;
 _MATELM1( 80 +  _li ,240 +  _li)  -= _term;
 _term =  p2 * _zdsqvol ;
 _MATELM1( 120 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 240 +  _li ,80 +  _li)  -= _term;
 _MATELM1( 80 +  _li ,80 +  _li)  += _term;
 /*REACTION*/
  } }
 cai = ca [ 0 ] ;
 mgi = mg [ 0 ] ;
   } return _reset;
 }
 
/*CVODE end*/
 
static int _ode_count(int _type){ return 260;}
 
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
	for (_i=0; _i < 260; ++_i) {
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
 _cvode_sparse(&_cvsparseobj1, 260, _dlist1, _p, _ode_matsol1, &_coef1);
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
 for (_i=0; _i<20; _i++) CB_ca_ca[_i] = CB_ca_ca0;
 for (_i=0; _i<20; _i++) CB_ca_s[_i] = CB_ca_s0;
 for (_i=0; _i<20; _i++) CB_f_ca[_i] = CB_f_ca0;
 for (_i=0; _i<20; _i++) CB[_i] = CB0;
 for (_i=0; _i<20; _i++) PV_mg[_i] = PV_mg0;
 for (_i=0; _i<20; _i++) PV_ca[_i] = PV_ca0;
 for (_i=0; _i<20; _i++) PV[_i] = PV0;
 for (_i=0; _i<20; _i++) ca[_i] = ca0;
 for (_i=0; _i<20; _i++) iCB_ca_ca[_i] = iCB_ca_ca0;
 for (_i=0; _i<20; _i++) iCB_ca_s[_i] = iCB_ca_s0;
 for (_i=0; _i<20; _i++) iCB_f_ca[_i] = iCB_f_ca0;
 for (_i=0; _i<20; _i++) iCB[_i] = iCB0;
 for (_i=0; _i<20; _i++) mg[_i] = mg0;
  pumpca = pumpca0;
  pump = pump0;
 {
   if ( _zfactors_done  == 0.0 ) {
     _zfactors_done = 1.0 ;
     factors ( _threadargs_ ) ;
     }
   {int  _li ;for ( _li = 0 ; _li <= 20 - 1 ; _li ++ ) {
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
 { error = sparse(&_sparseobj1, 260, _slist1, _dlist1, _p, &t, dt, state,&_coef1, _linmat1);
 if(error){fprintf(stderr,"at line 125 in file cdp_soma.mod:\n:	ica = ica_pmp\n"); nrn_complain(_p); abort_run(error);}
    if (secondorder) {
    int _i;
    for (_i = 0; _i < 260; ++_i) {
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
 for(_i=0;_i<20;_i++){_slist1[0+_i] = CB_ca_ca_columnindex + _i;  _dlist1[0+_i] = DCB_ca_ca_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[20+_i] = CB_ca_s_columnindex + _i;  _dlist1[20+_i] = DCB_ca_s_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[40+_i] = CB_f_ca_columnindex + _i;  _dlist1[40+_i] = DCB_f_ca_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[60+_i] = CB_columnindex + _i;  _dlist1[60+_i] = DCB_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[80+_i] = PV_mg_columnindex + _i;  _dlist1[80+_i] = DPV_mg_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[100+_i] = PV_ca_columnindex + _i;  _dlist1[100+_i] = DPV_ca_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[120+_i] = PV_columnindex + _i;  _dlist1[120+_i] = DPV_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[140+_i] = ca_columnindex + _i;  _dlist1[140+_i] = Dca_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[160+_i] = iCB_ca_ca_columnindex + _i;  _dlist1[160+_i] = DiCB_ca_ca_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[180+_i] = iCB_ca_s_columnindex + _i;  _dlist1[180+_i] = DiCB_ca_s_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[200+_i] = iCB_f_ca_columnindex + _i;  _dlist1[200+_i] = DiCB_f_ca_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[220+_i] = iCB_columnindex + _i;  _dlist1[220+_i] = DiCB_columnindex + _i;}
 for(_i=0;_i<20;_i++){_slist1[240+_i] = mg_columnindex + _i;  _dlist1[240+_i] = Dmg_columnindex + _i;}
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "cdp_soma.mod";
static const char* nmodl_file_text = 
  ": Calcium ion accumulation with radial and longitudinal diffusion and pump\n"
  "\n"
  "NEURON {\n"
  "  SUFFIX cdp20N_FD2\n"
  "  USEION ca READ cao, cai, ica WRITE cai\n"
  "  RANGE ica_pmp\n"
  ":RANGE pump_0\n"
  "GLOBAL vrat, TotalPump\n"
  "    : vrat must be GLOBAL--see INITIAL block\n"
  "    : however TotalBuffer and TotalPump may be RANGE\n"
  ":    THREADSAFE\n"
  "}\n"
  "\n"
  "DEFINE Nannuli 20\n"
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
  "	BTCnull = 0	(mM)\n"
  "	b1 = 5.33	(/ms mM)\n"
  "	b2 = 0.08	(/ms)\n"
  "\n"
  ":	values for caged compound DMNPE-4\n"
  "	DMNPEnull = 0	(mM)\n"
  "	c1 = 5.63	(/ms mM)\n"
  "	c2 = 0.107e-3	(/ms)\n"
  "\n"
  ":       values for Calbindin (2 high and 2 low affinity binding sites)\n"
  "\n"
  ":        CBnull=	.16             (mM)\n"
  " 		CBnull=	.08       \n"
  "        nf1   =43.5           (/ms mM)\n"
  "        nf2   =3.58e-2        (/ms)\n"
  "        ns1   =5.5            (/ms mM)\n"
  "        ns2   =0.26e-2        (/ms)\n"
  "\n"
  ":       values for Parvalbumin\n"
  "\n"
  ":        PVnull  = .08           (mM)\n"
  "         PVnull  = .04           (mM)\n"
  "        m1    = 1.07e2        (/ms mM)\n"
  "        m2    = 9.5e-4                (/ms)\n"
  "        p1    = 0.8           (/ms mM)\n"
  "        p2    = 2.5e-2                (/ms)\n"
  "\n"
  "  	kpmp1    = 3e3       (/mM-ms)\n"
  "  	kpmp2    = 1.75e1   (/ms)\n"
  "  	kpmp3    = 7.255e1  (/ms)\n"
  "  : to eliminate pump, set TotalPump to 0 in hoc\n"
  "	TotalPump = 1e-15	\n"
  "	\n"
  "	beta  = 1(1)           :introducing beta to take care of other ER mechanisms(SERCA and leak channel density)\n"
  "    vmax =0.1\n"
  "    Kp = 2.7e-3 (mM)	\n"
  "	\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	diam      (um)\n"
  "	ica       (mA/cm2)\n"
  "	ica_pmp   (mA/cm2)\n"
  ":	ica_pmp_last   (mA/cm2)\n"
  "	parea     (um)     : pump area per unit length\n"
  "	cai       (mM)\n"
  "	cao       (mM)\n"
  "	mgi	(mM)	\n"
  "	vrat[Nannuli]  (um2) : dimensionless\n"
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
  "LOCAL radii[Nannuli]\n"
  "LOCAL frat[Nannuli]  : scales the rate constants for model geometry\n"
  "\n"
  "PROCEDURE factors() {\n"
  "	LOCAL r, dr2, dr3\n"
  " 	\n"
  "	r = diam/2                : starts at edge (half diam)\n"
  ":	dr2 = 0.1  : full thickness of outermost annulus,\n"
  "                         : half thickness of all other annuli\n"
  "	dr2 = 0.0368  : full thickness of outermost annulus,\n"
  "	dr3 = (r-dr2)/(Nannuli-1)	:other shells thickness\n"
  "        radii[0] = r\n"
  "	radii[1] = r - dr2\n"
  "        FROM i=2 TO Nannuli-1 {\n"
  "		radii[i] = radii[i-1]- dr3\n"
  "	printf(\"%f\\n\",radii[i])\n"
  "	}\n"
  "\n"
  "	vrat[0] = 0\n"
  "	frat[0] = 2*r\n"
  "	FROM i=0 TO Nannuli-2 {\n"
  "		vrat[i] = PI*((radii[i]*radii[i])-(radii[i+1]*radii[i+1]))\n"
  "  	}\n"
  "	vrat[Nannuli-1] = PI*radii[Nannuli-1]*radii[Nannuli-1]\n"
  "	FROM i=1 TO Nannuli-1 {\n"
  "		if (i==1) {\n"
  "			frat[i] = 2*PI*radii[i]/(dr2+(dr3/2))\n"
  "		} else if (i>1&&i<(Nannuli-1)) { \n"
  "			frat[i] = 2*PI*radii[i]/dr3\n"
  "		} else if (i==(Nannuli-1)) {\n"
  "			frat[i] = 2*PI*radii[i]/((dr3/2)+radii[i])\n"
  "		}\n"
  "	}\n"
  "}\n"
  " \n"
  "LOCAL dsqvol  : can't define local variable in KINETIC block\n"
  "                   :   or use in COMPARTMENT statement\n"
  "\n"
  "KINETIC state {\n"
  "  COMPARTMENT i, vrat[i] {ca mg CB CB_f_ca CB_ca_s CB_ca_ca iCB iCB_f_ca iCB_ca_s iCB_ca_ca PV PV_ca PV_mg}\n"
  "  COMPARTMENT (1e10)*parea {pump pumpca}\n"
  "	:pump\n"
  ":	~ ca[0] + pump <-> pumpca  (kpmp1*parea*(1e10), kpmp2*parea*(1e10))\n"
  ":	~ pumpca <-> pump   (kpmp3*parea*(1e10), 0)\n"
  ":  	CONSERVE pump + pumpca = TotalPump * parea * (1e10)\n"
  "\n"
  ":	ica_pmp = 2*FARADAY*(f_flux - b_flux)/parea	\n"
  "	: all currents except pump\n"
  "	: ica is Ca efflux\n"
  "	~ ca[0] << (-ica*PI*diam/(2*FARADAY))\n"
  "\n"
  "    FROM i=0 TO Nannuli-1 {\n"
  "     ~ ca[i] << (-beta*vmax*vrat[i]*ca[i] / (ca[i] + kpmp2/kpmp1))\n"
  "   }\n"
  "\n"
  "	:RADIAL DIFFUSION OF ca, mg and mobile buffers\n"
  "\n"
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
  "	FROM i=0 TO Nannuli-1 {\n"
  "		dsqvol = vrat[i]\n"
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
  "\n"
  "	}\n"
  "\n"
  "  	cai = ca[0]\n"
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
  ;
#endif
