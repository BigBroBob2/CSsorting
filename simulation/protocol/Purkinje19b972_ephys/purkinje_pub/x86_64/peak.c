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
 
#define nrn_init _nrn_init__pk
#define _nrn_initial _nrn_initial__pk
#define nrn_cur _nrn_cur__pk
#define _nrn_current _nrn_current__pk
#define nrn_jacob _nrn_jacob__pk
#define nrn_state _nrn_state__pk
#define _net_receive _net_receive__pk 
#define check check__pk 
 
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
#define vhalf _p[0]
#define vhalf_columnindex 0
#define tpeak _p[1]
#define tpeak_columnindex 1
#define tpeakdvdt _p[2]
#define tpeakdvdt_columnindex 2
#define vpeak _p[3]
#define vpeak_columnindex 3
#define vpeakm _p[4]
#define vpeakm_columnindex 4
#define dvdt _p[5]
#define dvdt_columnindex 5
#define dvdt2 _p[6]
#define dvdt2_columnindex 6
#define dvdt2peak _p[7]
#define dvdt2peak_columnindex 7
#define dvdtpeak _p[8]
#define dvdtpeak_columnindex 8
#define onset_ref _p[9]
#define onset_ref_columnindex 9
#define onset _p[10]
#define onset_columnindex 10
#define vonset _p[11]
#define vonset_columnindex 11
#define halfwidth _p[12]
#define halfwidth_columnindex 12
#define dvdr _p[13]
#define dvdr_columnindex 13
#define vrest _p[14]
#define vrest_columnindex 14
#define Rmismatch _p[15]
#define Rmismatch_columnindex 15
#define Zmismatch _p[16]
#define Zmismatch_columnindex 16
#define Rback _p[17]
#define Rback_columnindex 17
#define Zback _p[18]
#define Zback_columnindex 18
#define Rfwd _p[19]
#define Rfwd_columnindex 19
#define Zfwd _p[20]
#define Zfwd_columnindex 20
#define R _p[21]
#define R_columnindex 21
#define Z _p[22]
#define Z_columnindex 22
#define aRmismatch _p[23]
#define aRmismatch_columnindex 23
#define aZmismatch _p[24]
#define aZmismatch_columnindex 24
#define aRback _p[25]
#define aRback_columnindex 25
#define aZback _p[26]
#define aZback_columnindex 26
#define aRfwd _p[27]
#define aRfwd_columnindex 27
#define aZfwd _p[28]
#define aZfwd_columnindex 28
#define aR _p[29]
#define aR_columnindex 29
#define aZ _p[30]
#define aZ_columnindex 30
#define f _p[31]
#define f_columnindex 31
#define Xo _p[32]
#define Xo_columnindex 32
#define Xlen _p[33]
#define Xlen_columnindex 33
#define Xsec _p[34]
#define Xsec_columnindex 34
#define Xfrc _p[35]
#define Xfrc_columnindex 35
#define sign _p[36]
#define sign_columnindex 36
#define thresh _p[37]
#define thresh_columnindex 37
#define v1 _p[38]
#define v1_columnindex 38
#define v2 _p[39]
#define v2_columnindex 39
#define v3 _p[40]
#define v3_columnindex 40
#define below _p[41]
#define below_columnindex 41
#define below_old _p[42]
#define below_old_columnindex 42
#define upstroke _p[43]
#define upstroke_columnindex 43
#define downstroke _p[44]
#define downstroke_columnindex 44
#define v _p[45]
#define v_columnindex 45
#define _g _p[46]
#define _g_columnindex 46
 
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
 /* declaration of user functions */
 static void _hoc_check(void);
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
 "setdata_pk", _hoc_setdata,
 "check_pk", _hoc_check,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "vhalf_pk", "mV",
 "tpeak_pk", "ms",
 "tpeakdvdt_pk", "ms",
 "vpeak_pk", "mV",
 "vpeakm_pk", "mV",
 "dvdt_pk", "ms",
 "dvdt2_pk", "mV/ms*ms",
 "dvdt2peak_pk", "mV/ms*ms",
 "dvdtpeak_pk", "mV/ms",
 "onset_ref_pk", "mV/ms",
 "onset_pk", "ms",
 "vonset_pk", "mV",
 "halfwidth_pk", "ms",
 "dvdr_pk", "mv/micron",
 "vrest_pk", "mV",
 "Rmismatch_pk", "1",
 "Zmismatch_pk", "1",
 "Rback_pk", "Mohm",
 "Zback_pk", "Mohm",
 "Rfwd_pk", "Mohm",
 "Zfwd_pk", "Mohm",
 "R_pk", "Mohm",
 "Z_pk", "Mohm",
 "aRmismatch_pk", "1",
 "aZmismatch_pk", "1",
 "aRback_pk", "Mohm",
 "aZback_pk", "Mohm",
 "aRfwd_pk", "Mohm",
 "aZfwd_pk", "Mohm",
 "aR_pk", "Mohm",
 "aZ_pk", "Mohm",
 "Xo_pk", "1",
 "Xlen_pk", "1",
 "Xsec_pk", "1",
 "Xfrc_pk", "1",
 "sign_pk", "1",
 "thresh_pk", "nA",
 0,0
};
 static double delta_t = 1;
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
 /* connect range variables in _p that hoc is supposed to know about */
 static const char *_mechanism[] = {
 "7.7.0",
"pk",
 "vhalf_pk",
 0,
 "tpeak_pk",
 "tpeakdvdt_pk",
 "vpeak_pk",
 "vpeakm_pk",
 "dvdt_pk",
 "dvdt2_pk",
 "dvdt2peak_pk",
 "dvdtpeak_pk",
 "onset_ref_pk",
 "onset_pk",
 "vonset_pk",
 "halfwidth_pk",
 "dvdr_pk",
 "vrest_pk",
 "Rmismatch_pk",
 "Zmismatch_pk",
 "Rback_pk",
 "Zback_pk",
 "Rfwd_pk",
 "Zfwd_pk",
 "R_pk",
 "Z_pk",
 "aRmismatch_pk",
 "aZmismatch_pk",
 "aRback_pk",
 "aZback_pk",
 "aRfwd_pk",
 "aZfwd_pk",
 "aR_pk",
 "aZ_pk",
 "f_pk",
 "Xo_pk",
 "Xlen_pk",
 "Xsec_pk",
 "Xfrc_pk",
 "sign_pk",
 "thresh_pk",
 0,
 0,
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 47, _prop);
 	/*initialize range parameters*/
 	vhalf = 0;
 	_prop->param = _p;
 	_prop->param_size = 47;
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _peak_reg() {
	int _vectorized = 1;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 1);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 47, 0);
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 pk /home/cbao/Purkinje19b972_ephys/purkinje_pub/peak.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "peak.mod";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int check(_threadargsproto_);
 
static int  check ( _threadargsproto_ ) {
   if ( v > vpeak  && vpeakm  == - 100.0 ) {
     tpeak = t ;
     vpeak = v ;
     }
   if ( v + 4.0 < vpeak ) {
     vpeakm = 1.0 ;
     }
   v1 = v2 ;
   v2 = v3 ;
   v3 = v ;
   dvdt = ( v3 - v2 ) / ( dt ) ;
   dvdt2 = ( v3 - 2.0 * v2 + v1 ) / ( dt * dt ) ;
   if ( t < 1.0 ) {
     dvdt2 = 0.0 ;
     }
   if ( dvdt > dvdtpeak ) {
     dvdtpeak = dvdt ;
     tpeakdvdt = t ;
     }
   if ( dvdt2 > dvdt2peak ) {
     dvdt2peak = dvdt2 ;
     }
   if ( dvdt > onset_ref  && onset  == 0.0  && t > 1.0 ) {
     onset = t - dt ;
     vonset = v2 ;
     }
   below = 0.0 ;
   if ( vhalf > v ) {
     below = 1.0 ;
     }
   if ( below  == 0.0  && below_old  == 1.0  && upstroke  == 0.0 ) {
     upstroke = t ;
     }
   if ( below  == 1.0  && below_old  == 0.0  && downstroke  == 0.0 ) {
     downstroke = t ;
     }
   halfwidth = downstroke - upstroke ;
   below_old = below ;
    return 0; }
 
static void _hoc_check(void) {
  double _r;
   double* _p; Datum* _ppvar; Datum* _thread; NrnThread* _nt;
   if (_extcall_prop) {_p = _extcall_prop->param; _ppvar = _extcall_prop->dparam;}else{ _p = (double*)0; _ppvar = (Datum*)0; }
  _thread = _extcall_thread;
  _nt = nrn_threads;
 _r = 1.;
 check ( _p, _ppvar, _thread, _nt );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("pk", "cannot be used with CVODE"); return 0;}

static void initmodel(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt) {
  int _i; double _save;{
 {
   tpeak = 0.0 ;
   tpeakdvdt = 0.0 ;
   vpeak = - 100.0 ;
   vpeakm = - 100.0 ;
   onset = 0.0 ;
   dvdtpeak = 0.0 ;
   dvdt2peak = 0.0 ;
   downstroke = 0.0 ;
   upstroke = 0.0 ;
   vrest = v ;
   check ( _threadargs_ ) ;
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
 initmodel(_p, _ppvar, _thread, _nt);
}
}

static double _nrn_current(double* _p, Datum* _ppvar, Datum* _thread, NrnThread* _nt, double _v){double _current=0.;v=_v;{
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
 {  { check(_p, _ppvar, _thread, _nt); }
  } {
   }
}}

}

static void terminal(){}

static void _initlists(){
 double _x; double* _p = &_x;
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if defined(__cplusplus)
} /* extern "C" */
#endif

#if NMODL_TEXT
static const char* nmodl_filename = "/home/cbao/Purkinje19b972_ephys/purkinje_pub/peak.mod";
static const char* nmodl_file_text = 
  "TITLE peak.mod\n"
  "\n"
  "COMMENT \n"
  "pk: record peak time and peak value of membrane potential\n"
  "Michael Hausser & Arnd Roth                     25.9.1997\n"
  "Philipp Vetter	modified last			30.12.1998\n"
  "Mickey 	London	modified last			30.12.1998\n"
  "\n"
  "vpeak/tpeak are locked to first peak\n"
  "dvdt2 is for time t - 2*dt\n"
  "AP measurements		dvdtmax, dvdtmaxII, onset, vonset, halfwidth, vhalf, vrest, dVdr\n"
  "electrotonic lengths	X, Xsec\n"
  "impedance mismatch	Zmismatch, Rmismatch, aZmismatch, aRmismatch, f\n"
  "\n"
  "Copyright (C) 2001  Philipp Vetter, Arnd Roth and Michael Hausser\n"
  "\n"
  "This program is free software; you can redistribute it and/or\n"
  "modify it under the terms of the GNU General Public License\n"
  "as published by the Free Software Foundation; either version 2\n"
  "of the License, or (at your option) any later version.\n"
  "\n"
  "This program is distributed in the hope that it will be useful,\n"
  "but WITHOUT ANY WARRANTY; without even the implied warranty of\n"
  "MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the\n"
  "GNU General Public License for more details.\n"
  "\n"
  "You should have received a copy of the GNU General Public License\n"
  "along with this program; if not, write to the Free Software\n"
  "Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.\n"
  "ENDCOMMENT\n"
  "\n"
  "UNITS {\n"
  "	(mV) = (millivolt)\n"
  "	(Mohms) = (megohms)\n"
  "}\n"
  "\n"
  "INDEPENDENT {t FROM 0 TO 1 WITH 1 (ms)}\n"
  "\n"
  "NEURON {\n"
  "	SUFFIX pk\n"
  "	RANGE tpeak, vpeak, vpeakm,tpeakdvdt\n"
  "	RANGE dvdtpeak, dvdt2peak, onset_ref, onset, vonset, halfwidth, vhalf, vrest, dvdr\n"
  "	RANGE Zmismatch, Rmismatch, aZmismatch, aRmismatch, f\n"
  "	RANGE Zback, Rback, aZback, aRback\n"
  "	RANGE Zfwd, Rfwd, aZfwd, aRfwd\n"
  "	RANGE Z, R, aZ, aR\n"
  "	RANGE Xsec, Xfrc, Xlen, Xo, sign\n"
  "	RANGE dvdt2,dvdt\n"
  "	RANGE thresh\n"
  "}\n"
  "\n"
  "PARAMETER {\n"
  "	vhalf (mV)\n"
  "	v (mV)\n"
  "	dt (ms)\n"
  "}\n"
  "\n"
  "ASSIGNED {\n"
  "	tpeak (ms)\n"
  "	tpeakdvdt (ms)\n"
  "	vpeak (mV)\n"
  "	vpeakm (mV)\n"
  "	dvdt (ms)\n"
  "	dvdt2 (mV/ms*ms)\n"
  "	dvdt2peak (mV/ms*ms)\n"
  "	dvdtpeak (mV/ms)\n"
  "	onset_ref (mV/ms)\n"
  "	onset (ms)\n"
  "	v1 (mV)\n"
  "	v2 (mV)\n"
  "	v3 (mV)\n"
  "	vonset (mV)\n"
  "	halfwidth (ms)\n"
  "	below\n"
  "	below_old\n"
  "	upstroke (ms)\n"
  "	downstroke (ms)\n"
  "	dvdr     (mv/micron)\n"
  "	vrest (mV)\n"
  "	Rmismatch     (1)\n"
  "	Zmismatch     (1)\n"
  "	Rback   (Mohm)\n"
  "	Zback   (Mohm)\n"
  "	Rfwd    (Mohm)\n"
  "	Zfwd    (Mohm)\n"
  "	R     	(Mohm)\n"
  "	Z     	(Mohm)\n"
  "\n"
  "\n"
  "	aRmismatch  (1)\n"
  "	aZmismatch  (1)\n"
  "	aRback  (Mohm)\n"
  "	aZback  (Mohm)\n"
  "	aRfwd   (Mohm)\n"
  "	aZfwd   (Mohm)\n"
  "	aR     	(Mohm)\n"
  "	aZ     	(Mohm)\n"
  "\n"
  "\n"
  "\n"
  "\n"
  "	f     (0.001/ms)\n"
  "	Xo 	(1)\n"
  "	Xlen    (1)\n"
  "	Xsec	(1)\n"
  "	Xfrc	(1)\n"
  "	sign	(1)\n"
  "	thresh (nA)\n"
  "}\n"
  "\n"
  "INITIAL {\n"
  "	tpeak = 0 (ms)\n"
  "	tpeakdvdt = 0 (ms)\n"
  "	vpeak = -100 (mV)\n"
  "	vpeakm = -100 (mV)\n"
  "	onset = 0    (ms)\n"
  "	dvdtpeak  = 0 (mV/ms)\n"
  "	dvdt2peak  = 0 (mV/ms)\n"
  "	downstroke = 0 (ms)\n"
  "	upstroke   = 0 (ms)\n"
  "	vrest = v\n"
  "	check()\n"
  "}\n"
  "\n"
  "BREAKPOINT {	SOLVE check  }\n"
  "\n"
  "\n"
  "PROCEDURE check() {\n"
  "			if (v > vpeak && vpeakm==-100) { tpeak = t\n"
  "					 		 vpeak = v }\n"
  "\n"
  "			if (v+4 < vpeak) { vpeakm = 1 }\n"
  "\n"
  "			v1        = v2\n"
  "			v2        = v3\n"
  "			v3        = v\n"
  "		        dvdt	  = (v3 - v2)/(dt)\n"
  "			dvdt2	  = (v3 - 2*v2 +v1)/(dt*dt)\n"
  "			if (t < 1)  {\n"
  "			dvdt2 =0\n"
  "			}\n"
  "			\n"
  "\n"
  "			if (dvdt > dvdtpeak) 			      	{ \n"
  "			   	   					  dvdtpeak = dvdt \n"
  "			   	   					  tpeakdvdt = t	     	  \n"
  "									}\n"
  "			if (dvdt2 > dvdt2peak) 			      	{ dvdt2peak = dvdt2 }\n"
  "\n"
  "			if (dvdt > onset_ref && onset == 0 && t > 1) 	{ onset  = t-dt\n"
  "							                  vonset = v2 }\n"
  "			below     = 0	\n"
  "			if (vhalf > v) {below = 1}\n"
  "			if (below == 0 && below_old == 1 && upstroke == 0)   {upstroke = t}\n"
  "			if (below == 1 && below_old == 0 && downstroke == 0) {downstroke = t}\n"
  "\n"
  "			halfwidth = downstroke - upstroke\n"
  "			below_old = below\n"
  "}\n"
  ;
#endif
