/* Created by Language version: 7.7.0 */
/* VECTORIZED */
#define NRN_VECTORIZED 1
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
 
#define nrn_init _nrn_init__Kv4s
#define _nrn_initial _nrn_initial__Kv4s
#define nrn_cur _nrn_cur__Kv4s
#define _nrn_current _nrn_current__Kv4s
#define nrn_jacob _nrn_jacob__Kv4s
#define nrn_state _nrn_state__Kv4s
#define _net_receive _net_receive__Kv4s 
#define rates rates__Kv4s 
#define states states__Kv4s 
 
#define _threadargscomma_ _p, _ppvar, _thread, _nt,
#define _threadargsprotocomma_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt,
#define _threadargs_ _p, _ppvar, _thread, _nt
#define _threadargsproto_ double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt
 	/*SUPPRESS 761*/
	/*SUPPRESS 762*/
	/*SUPPRESS 763*/
	/*SUPPRESS 765*/
	 extern double *getarg();
 /* Thread safe. No static _p or _ppvar. */
 
#define t _nt->_t
#define dt _nt->_dt
#define vshift _p[0]
#define vshift_columnindex 0
#define gbar _p[1]
#define gbar_columnindex 1
#define ik _p[2]
#define ik_columnindex 2
#define gk _p[3]
#define gk_columnindex 3
#define n _p[4]
#define n_columnindex 4
#define h _p[5]
#define h_columnindex 5
#define ek _p[6]
#define ek_columnindex 6
#define g _p[7]
#define g_columnindex 7
#define T _p[8]
#define T_columnindex 8
#define qt _p[9]
#define qt_columnindex 9
#define E _p[10]
#define E_columnindex 10
#define zeta _p[11]
#define zeta_columnindex 11
#define ninf _p[12]
#define ninf_columnindex 12
#define taun _p[13]
#define taun_columnindex 13
#define alphan _p[14]
#define alphan_columnindex 14
#define betan _p[15]
#define betan_columnindex 15
#define alphah _p[16]
#define alphah_columnindex 16
#define betah _p[17]
#define betah_columnindex 17
#define hinf _p[18]
#define hinf_columnindex 18
#define tauh _p[19]
#define tauh_columnindex 19
#define Dn _p[20]
#define Dn_columnindex 20
#define Dh _p[21]
#define Dh_columnindex 21
#define v _p[22]
#define v_columnindex 22
#define _g _p[23]
#define _g_columnindex 23
#define _ion_ek	*_ppvar[0]._pval
#define _ion_ik	*_ppvar[1]._pval
#define _ion_dikdv	*_ppvar[2]._pval
 
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
 static Datum* _extcall_thread;
 static Prop* _extcall_prop;
 /* external NEURON variables */
 extern double celsius;
 /* declaration of user functions */
 static void _hoc_alphahfkt(void);
 static void _hoc_alphanfkt(void);
 static void _hoc_betahfkt(void);
 static void _hoc_betanfkt(void);
 static void _hoc_ghk(void);
 static void _hoc_kelvinfkt(void);
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
 _extcall_prop = _prop;
 }
 static void _hoc_setdata() {
 Prop *_prop, *hoc_getdata_range(int);
 _prop = hoc_getdata_range(_mechtype);
   _setdata(_prop);
 hoc_retpushx(1.);
}
 /* connect user functions to hoc names */
 static VoidFunc hoc_intfunc[] = {
 "setdata_Kv4s", _hoc_setdata,
 "alphahfkt_Kv4s", _hoc_alphahfkt,
 "alphanfkt_Kv4s", _hoc_alphanfkt,
 "betahfkt_Kv4s", _hoc_betahfkt,
 "betanfkt_Kv4s", _hoc_betanfkt,
 "ghk_Kv4s", _hoc_ghk,
 "kelvinfkt_Kv4s", _hoc_kelvinfkt,
 "rates_Kv4s", _hoc_rates,
 0, 0
};
#define alphahfkt alphahfkt_Kv4s
#define alphanfkt alphanfkt_Kv4s
#define betahfkt betahfkt_Kv4s
#define betanfkt betanfkt_Kv4s
#define ghk ghk_Kv4s
#define kelvinfkt kelvinfkt_Kv4s
 extern double alphahfkt( _threadargsprotocomma_ double );
 extern double alphanfkt( _threadargsprotocomma_ double );
 extern double betahfkt( _threadargsprotocomma_ double );
 extern double betanfkt( _threadargsprotocomma_ double );
 extern double ghk( _threadargsprotocomma_ double , double , double , double );
 extern double kelvinfkt( _threadargsprotocomma_ double );
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 "gbar_Kv4s", 0, 1e+09,
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "gbar_Kv4s", "mho/cm2",
 "ik_Kv4s", "mA/cm2",
 "gk_Kv4s", "mho/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double h0 = 0;
 static double n0 = 0;
 /* connect global user variables to hoc */
 static DoubScal hoc_scdoub[] = {
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
"Kv4s",
 "vshift_Kv4s",
 "gbar_Kv4s",
 0,
 "ik_Kv4s",
 "gk_Kv4s",
 0,
 "n_Kv4s",
 "h_Kv4s",
 0,
 0};
 static Symbol* _k_sym;
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 24, _prop);
 	/*initialize range parameters*/
 	vshift = 0;
 	gbar = 0.0039;
 	_prop->param = _p;
 	_prop->param_size = 24;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 4, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 prop_ion = need_memb(_k_sym);
 nrn_promote(prop_ion, 0, 1);
 	_ppvar[0]._pval = &prop_ion->param[0]; /* ek */
 	_ppvar[1]._pval = &prop_ion->param[3]; /* ik */
 	_ppvar[2]._pval = &prop_ion->param[4]; /* _ion_dikdv */
 
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

 void _kv4s_reg() {
	int _vectorized = 1;
  _initlists();
 	ion_reg("k", -10000.);
 	_k_sym = hoc_lookup("k_ion");
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
     _nrn_thread_reg(_mechtype, 2, _update_ion_pointer);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 24, 4);
  hoc_register_dparam_semantics(_mechtype, 0, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 1, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 2, "k_ion");
  hoc_register_dparam_semantics(_mechtype, 3, "cvodeieq");
 	hoc_register_cvode(_mechtype, _ode_count, _ode_map, _ode_spec, _ode_matsol);
 	hoc_register_tolerance(_mechtype, _hoc_state_tol, &_atollist);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 Kv4s kv4s.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
 static double q10 = 3;
 static double F = 9.6485e4;
 static double R = 8.3145;
 static double can = 0.15743;
 static double cvan = 57;
 static double ckan = -32.19976;
 static double cbn = 0.15743;
 static double cvbn = 57;
 static double ckbn = 37.51346;
 static double cah = 0.01342;
 static double cvah = 60;
 static double ckah = -7.86476;
 static double cbh = 0.04477;
 static double cvbh = 54;
 static double ckbh = 11.3615;
 static double vh = -75.30348;
 static double kh = -6.06329;
 static double ki = 150;
 static double ko = 2.5;
static int _reset;
static char *modelname = "Voltage-gated potassium channel from Kv4 subunits";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int rates(_threadargsprotocomma_ double);
 
static int _ode_spec1(_threadargsproto_);
/*static int _ode_matsol1(_threadargsproto_);*/
 static int _slist1[2], _dlist1[2];
 static int states(_threadargsproto_);
 
/*CVODE*/
 static int _ode_spec1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {int _reset = 0; {
   rates ( _threadargscomma_ v ) ;
   Dn = ( ninf - n ) / taun ;
   Dh = ( hinf - h ) / tauh ;
   }
 return _reset;
}
 static int _ode_matsol1 (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
 rates ( _threadargscomma_ v ) ;
 Dn = Dn  / (1. - dt*( ( ( ( - 1.0 ) ) ) / taun )) ;
 Dh = Dh  / (1. - dt*( ( ( ( - 1.0 ) ) ) / tauh )) ;
  return 0;
}
 /*END CVODE*/
 static int states (double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) { {
   rates ( _threadargscomma_ v ) ;
    n = n + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / taun)))*(- ( ( ( ninf ) ) / taun ) / ( ( ( ( - 1.0 ) ) ) / taun ) - n) ;
    h = h + (1. - exp(dt*(( ( ( - 1.0 ) ) ) / tauh)))*(- ( ( ( hinf ) ) / tauh ) / ( ( ( ( - 1.0 ) ) ) / tauh ) - h) ;
   }
  return 0;
}
 
static int  rates ( _threadargsprotocomma_ double _lv ) {
   alphan = alphanfkt ( _threadargscomma_ _lv ) ;
   betan = betanfkt ( _threadargscomma_ _lv ) ;
   ninf = 1.0 / ( 1.0 + exp ( ( - 49.0 - _lv ) / 12.5 ) ) ;
   taun = 1.0 / ( ( alphan + betan ) * qt ) ;
   alphah = alphahfkt ( _threadargscomma_ _lv ) ;
   betah = betahfkt ( _threadargscomma_ _lv ) ;
   hinf = 1.0 / ( 1.0 + exp ( ( _lv - ( vh - vshift ) ) / - kh ) ) ;
   tauh = 100.0 / qt ;
   g = ghk ( _threadargscomma_ _lv , ki , ko , 1.0 ) ;
    return 0; }
 
static void _hoc_rates(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 rates ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double ghk ( _threadargsprotocomma_ double _lv , double _lki , double _lko , double _lz ) {
   double _lghk;
 E = ( 1e-3 ) * _lv ;
   zeta = ( _lz * F * E ) / ( R * T ) ;
   if ( fabs ( 1.0 - exp ( - zeta ) ) < 1e-6 ) {
     _lghk = ( 1e-6 ) * ( _lz * F ) * ( _lki - _lko * exp ( - zeta ) ) * ( 1.0 + zeta / 2.0 ) ;
     }
   else {
     _lghk = ( 1e-6 ) * ( _lz * zeta * F ) * ( _lki - _lko * exp ( - zeta ) ) / ( 1.0 - exp ( - zeta ) ) ;
     }
   
return _lghk;
 }
 
static void _hoc_ghk(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  ghk ( _p, _ppvar, _thread, _nt, *getarg(1) , *getarg(2) , *getarg(3) , *getarg(4) );
 hoc_retpushx(_r);
}
 
double alphanfkt ( _threadargsprotocomma_ double _lv ) {
   double _lalphanfkt;
 _lalphanfkt = can * exp ( - ( _lv + cvan ) / ckan ) ;
   
return _lalphanfkt;
 }
 
static void _hoc_alphanfkt(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphanfkt ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betanfkt ( _threadargsprotocomma_ double _lv ) {
   double _lbetanfkt;
 _lbetanfkt = cbn * exp ( - ( _lv + cvbn ) / ckbn ) ;
   
return _lbetanfkt;
 }
 
static void _hoc_betanfkt(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betanfkt ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double kelvinfkt ( _threadargsprotocomma_ double _lt ) {
   double _lkelvinfkt;
 _lkelvinfkt = 273.19 + _lt ;
   
return _lkelvinfkt;
 }
 
static void _hoc_kelvinfkt(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  kelvinfkt ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double alphahfkt ( _threadargsprotocomma_ double _lv ) {
   double _lalphahfkt;
 _lalphahfkt = cah / ( 1.0 + exp ( - ( _lv + cvah ) / ckah ) ) ;
   
return _lalphahfkt;
 }
 
static void _hoc_alphahfkt(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  alphahfkt ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
double betahfkt ( _threadargsprotocomma_ double _lv ) {
   double _lbetahfkt;
 _lbetahfkt = cbh / ( 1.0 + exp ( - ( _lv + cvbh ) / ckbh ) ) ;
   
return _lbetahfkt;
 }
 
static void _hoc_betahfkt(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r =  betahfkt ( _p, _ppvar, _thread, _nt, *getarg(1) );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ return 2;}
 
static void _ode_spec(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
     _ode_spec1 (_p, _ppvar, _thread, _nt);
  }}
 
static void _ode_map(int _ieq, double** _pv, double** _pvdot, double* _pp, Datum* _ppd, double* _atol, int _type) { 
	double* _p; Datum* _ppvar;
 	int _i; _p = _pp; _ppvar = _ppd;
	_cvode_ieq = _ieq;
	for (_i=0; _i < 2; ++_i) {
		_pv[_i] = _pp + _slist1[_i];  _pvdot[_i] = _pp + _dlist1[_i];
		_cvode_abstol(_atollist, _atol, _i);
	}
 }
 
static void _ode_matsol_instance1(_threadargsproto_) {
 _ode_matsol1 (_p, _ppvar, _thread, _nt);
 }
 
static void _ode_matsol(NrnThread* _nt, _Memb_list* _ml, int _type) {
   double* _p; Datum* _ppvar; Datum* _thread;
   Node* _nd; double _v; int _iml, _cntml;
  _cntml = _ml->_nodecount;
  _thread = _ml->_thread;
  for (_iml = 0; _iml < _cntml; ++_iml) {
    _p = _ml->_data[_iml]; _ppvar = _ml->_pdata[_iml];
    _nd = _ml->_nodelist[_iml];
    v = NODEV(_nd);
  ek = _ion_ek;
 _ode_matsol_instance1(_threadargs_);
 }}
 extern void nrn_update_ion_pointer(Symbol*, Datum*, int, int);
 static void _update_ion_pointer(Datum* _ppvar) {
   nrn_update_ion_pointer(_k_sym, _ppvar, 0, 0);
   nrn_update_ion_pointer(_k_sym, _ppvar, 1, 3);
   nrn_update_ion_pointer(_k_sym, _ppvar, 2, 4);
 }

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
  h = h0;
  n = n0;
 {
   T = kelvinfkt ( _threadargscomma_ celsius ) ;
   qt = pow( q10 , ( ( celsius - 23.0 ) / 10.0 ) ) ;
   rates ( _threadargscomma_ v ) ;
   n = ninf ;
   h = hinf ;
   }
 
}
}

static void nrn_init(NrnThread* _nt, _Memb_list* _ml, int _type){
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ek = _ion_ek;
 initmodel(_p, _ppvar, _thread, _nt);
 }
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{ {
   gk = gbar * n * n * n * n * h ;
   ik = gk * ( v - ek ) ;
   }
 _current += ik;

} return _current;
}

static void nrn_cur(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; double _rhs, _v; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ek = _ion_ek;
 _g = _nrn_current(_p, _ppvar, _thread, _nt, _v + .001);
 	{ double _dik;
  _dik = ik;
 _rhs = _nrn_current(_p, _ppvar, _thread, _nt, _v);
  _ion_dikdv += (_dik - ik)/.001 ;
 	}
 _g = (_g - _rhs)/.001;
  _ion_ik += ik ;
#if CACHEVEC
  if (use_cachevec) {
	VEC_RHS(_ni[_iml]) -= _rhs;
  }else
#endif
  {
	NODERHS(_nd) -= _rhs;
  }
 
}
 
}

static void nrn_jacob(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
 
}
 
}

static void nrn_state(NrnThread* _nt, _Memb_list* _ml, int _type) {
double* _p; Datum* _ppvar; Datum* _thread;
Node *_nd; double _v = 0.0; int* _ni; int _iml, _cntml;
#if CACHEVEC
    _ni = _ml->_nodeindices;
#endif
_cntml = _ml->_nodecount;
_thread = _ml->_thread;
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
  ek = _ion_ek;
 {   states(_p, _ppvar, _thread, _nt);
  } }}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
 _slist1[0] = n_columnindex;  _dlist1[0] = Dn_columnindex;
 _slist1[1] = h_columnindex;  _dlist1[1] = Dh_columnindex;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "kv4s.mod";
static const char* nmodl_file_text = 
  "TITLE Voltage-gated potassium channel from Kv4 subunits\n"
  "\n"
  "COMMENT\n"
  "\n"
  "NEURON implementation of a potassium channel from Kv4 subunits\n"
  "Kv4 activation from Sacco inactivation from SD\n"
  "Yunliang Zang April 16th 2015\n"
  "\n"
  "ENDCOMMENT\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX Kv4s\n"
  "	USEION k READ ek WRITE ik\n"
  "	RANGE gk, gbar, ik,vshift\n"
  ":   GLOBAL ninf, taun, hinf, tauh\n"
  ":    THREADSAFE\n"
  "}\n"
  "\n"
  "UNITS {\n"
  "	(mV) = (millivolt)\n"
  "	(mA) = (milliamp)\n"
  "	(nA) = (nanoamp)\n"
  "	(pA) = (picoamp)\n"
  "	(S)  = (siemens)\n"
  "	(nS) = (nanosiemens)\n"
  "	(pS) = (picosiemens)\n"
  "	(um) = (micron)\n"
  "	(molar) = (1/liter)\n"
  "	(mM) = (millimolar)		\n"
  "}\n"
  "\n"
  "CONSTANT {\n"
  "	q10 = 3\n"
  "	F = 9.6485e4 (coulombs)\n"
  "	R = 8.3145 (joule/kelvin)\n"
  "	can = 0.15743 (1/ms)\n"
  "	cvan = 57 (mV)\n"
  "	ckan = -32.19976 (mV)\n"
  "	cbn = 0.15743 (1/ms)\n"
  "	cvbn = 57 (mV)\n"
  "	ckbn = 37.51346 (mV)\n"
  "\n"
  "	\n"
  "	cah = 0.01342 (1/ms)\n"
  "	cvah = 60 (mV)\n"
  "	ckah = -7.86476 (mV)\n"
  "	cbh = 0.04477 (1/ms)\n"
  "	cvbh = 54 (mV)\n"
  "	ckbh = 11.3615 (mV)\n"
  "	\n"
  "	vh = -75.30348 (mV)\n"
  "	kh = -6.06329 (mV)\n"
  "	ki = 150 (mM)			:from Stephane\n"
  "	ko = 2.5 (mM)   \n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	v (mV)\n"
  "	celsius (degC)\n"
  "	vshift = 0\n"
  "	gbar = 0.0039 (mho/cm2)   <0,1e9>\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	ik (mA/cm2) \n"
  "	ek (mV)\n"
  "	gk (mho/cm2)\n"
  "	g (coulombs/cm3)\n"
  "	\n"
  "	T (kelvin)\n"
  "	qt\n"
  "	E (volt)\n"
  "	zeta\n"
  "\n"
  "	ninf\n"
  "	taun (ms)\n"
  "	alphan (1/ms)\n"
  "	betan (1/ms)\n"
  "	alphah (1/ms)\n"
  "	betah (1/ms)	\n"
  "\n"
  "	hinf\n"
  ":	h1inf\n"
  ":	h2inf\n"
  "	tauh (ms)\n"
  ":	tauh2 (ms)    \n"
  "}\n"
  "\n"
  "STATE { n h }\n"
  "\n"
  "INITIAL {\n"
  "	T = kelvinfkt (celsius)\n"
  "	qt = q10^((celsius-23 (degC))/10 (degC))\n"
  "	rates(v)\n"
  "	n = ninf\n"
  "	h = hinf\n"
  "}\n"
  "\n"
  "BREAKPOINT {\n"
  "	SOLVE states METHOD cnexp\n"
  "    gk = gbar * n*n*n*n*h\n"
  "	ik = gk * (v - ek)\n"
  "}\n"
  "\n"
  "DERIVATIVE states {\n"
  "	rates(v)\n"
  "	n' = (ninf-n)/taun\n"
  "	h' = (hinf-h)/tauh\n"
  "\n"
  "}\n"
  "\n"
  "PROCEDURE rates(v (mV)) {\n"
  "	alphan = alphanfkt(v)\n"
  "	betan = betanfkt(v)\n"
  ":	ninf = alphan / (alphan+betan) \n"
  ":	ninf = (1/(1+exp(-(v+27)/8.8)))^(1/4)\n"
  "	ninf = 1.0 / (1.0 + exp((-49 - v)/12.5))\n"
  "\n"
  "	taun = 1/((alphan+betan)*qt)\n"
  "	alphah = alphahfkt(v)\n"
  "	betah = betahfkt(v)\n"
  ":	h1inf = alphah / (alphah + betah)\n"
  ":	h2inf = alphah / (alphah + betah)\n"
  "	hinf = 1/(1+exp((v-(vh-vshift))/-kh))\n"
  ":	h2inf =1/(1+exp((v-(vh-vshift))/-kh))\n"
  ":	tauh1 = (1.96+2*1.59/(exp((-92-v)/13.8)+exp((v+92)/13.8)))/qt\n"
  "	tauh =100/qt\n"
  "	g = ghk(v, ki, ko, 1)\n"
  "}\n"
  "\n"
  "FUNCTION ghk( v (mV), ki (mM), ko (mM), z )  (coulombs/cm3) {\n"
  "    E = (1e-3) * v\n"
  "      zeta = (z*F*E)/(R*T)\n"
  "\n"
  "\n"
  "    if ( fabs(1-exp(-zeta)) < 1e-6 ) {\n"
  "        ghk = (1e-6) * (z*F) * (ki - ko*exp(-zeta)) * (1 + zeta/2)\n"
  "    } else {\n"
  "        ghk = (1e-6) * (z*zeta*F) * (ki - ko*exp(-zeta)) / (1-exp(-zeta))\n"
  "    }\n"
  "}\n"
  "\n"
  "\n"
  "FUNCTION alphanfkt(v (mV)) (1/ms) {\n"
  "	alphanfkt = can * exp(-(v+cvan)/ckan) \n"
  "}\n"
  "\n"
  "FUNCTION betanfkt(v (mV)) (1/ms) {\n"
  "	betanfkt = cbn * exp(-(v+cvbn)/ckbn)\n"
  "}\n"
  "\n"
  "FUNCTION kelvinfkt( t (degC) )  (kelvin) {\n"
  "    kelvinfkt = 273.19 + t\n"
  "}\n"
  "FUNCTION alphahfkt(v (mV))  (1/ms) {\n"
  "	alphahfkt = cah / (1+exp(-(v+cvah)/ckah))\n"
  "}\n"
  "\n"
  "FUNCTION betahfkt(v (mV))  (1/ms)  {\n"
  "	betahfkt = cbh / (1+exp(-(v+cvbh)/ckbh))\n"
  "}\n"
  ;
#endif
