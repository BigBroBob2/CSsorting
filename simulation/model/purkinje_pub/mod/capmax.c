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
 
#define nrn_init _nrn_init__capmax
#define _nrn_initial _nrn_initial__capmax
#define nrn_cur _nrn_cur__capmax
#define _nrn_current _nrn_current__capmax
#define nrn_jacob _nrn_jacob__capmax
#define nrn_state _nrn_state__capmax
#define _net_receive _net_receive__capmax 
#define absmx absmx__capmax 
#define mxpos mxpos__capmax 
#define mx mx__capmax 
 
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
#define debug _p[0]
#define debug_columnindex 0
#define i _p[1]
#define i_columnindex 1
#define tp _p[2]
#define tp_columnindex 2
#define i1 _p[3]
#define i1_columnindex 3
#define i2 _p[4]
#define i2_columnindex 4
#define i3 _p[5]
#define i3_columnindex 5
#define up _p[6]
#define up_columnindex 6
#define lockit _p[7]
#define lockit_columnindex 7
#define Dup _p[8]
#define Dup_columnindex 8
#define Dlockit _p[9]
#define Dlockit_columnindex 9
#define _g _p[10]
#define _g_columnindex 10
#define icap	*_ppvar[0]._pval
#define _p_icap	_ppvar[0]._pval
 
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
 static int hoc_nrnpointerindex =  0;
 /* external NEURON variables */
 /* declaration of user functions */
 static void _hoc_absmx(void);
 static void _hoc_mxpos(void);
 static void _hoc_mx(void);
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
 "setdata_capmax", _hoc_setdata,
 "absmx_capmax", _hoc_absmx,
 "mxpos_capmax", _hoc_mxpos,
 "mx_capmax", _hoc_mx,
 0, 0
};
 /* declare global and static user variables */
 /* some parameters have upper and lower limits */
 static HocParmLimits _hoc_parm_limits[] = {
 0,0,0
};
 static HocParmUnits _hoc_parm_units[] = {
 "i_capmax", "milliamp/cm2",
 "tp_capmax", "ms",
 "icap_capmax", "milliamp/cm2",
 0,0
};
 static double delta_t = 0.01;
 static double lockit0 = 0;
 static double up0 = 0;
 static double v = 0;
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
"capmax",
 "debug_capmax",
 0,
 "i_capmax",
 "tp_capmax",
 "i1_capmax",
 "i2_capmax",
 "i3_capmax",
 0,
 "up_capmax",
 "lockit_capmax",
 0,
 "icap_capmax",
 0};
 
extern Prop* need_memb(Symbol*);

static void nrn_alloc(Prop* _prop) {
	Prop *prop_ion;
	double *_p; Datum *_ppvar;
 	_p = nrn_prop_data_alloc(_mechtype, 11, _prop);
 	/*initialize range parameters*/
 	debug = 0;
 	_prop->param = _p;
 	_prop->param_size = 11;
 	_ppvar = nrn_prop_datum_alloc(_mechtype, 1, _prop);
 	_prop->dparam = _ppvar;
 	/*connect ionic variables to this model*/
 
}
 static void _initlists();
 extern Symbol* hoc_lookup(const char*);
extern void _nrn_thread_reg(int, int, void(*)(Datum*));
extern void _nrn_thread_table_reg(int, void(*)(double*, Datum*, Datum*, NrnThread*, int));
extern void hoc_register_tolerance(int, HocStateTolerance*, Symbol***);
extern void _cvode_abstol( Symbol**, double*, int);

 void _capmax_reg() {
	int _vectorized = 0;
  _initlists();
 	register_mech(_mechanism, nrn_alloc,nrn_cur, nrn_jacob, nrn_state, nrn_init, hoc_nrnpointerindex, 0);
 _mechtype = nrn_get_mechtype(_mechanism[1]);
     _nrn_setdata_reg(_mechtype, _setdata);
 #if NMODL_TEXT
  hoc_reg_nmodl_text(_mechtype, nmodl_file_text);
  hoc_reg_nmodl_filename(_mechtype, nmodl_filename);
#endif
  hoc_register_prop_size(_mechtype, 11, 1);
  hoc_register_dparam_semantics(_mechtype, 0, "pointer");
 	hoc_register_cvode(_mechtype, _ode_count, 0, 0, 0);
 	hoc_register_var(hoc_scdoub, hoc_vdoub, hoc_intfunc);
 	ivoc_help("help ?1 capmax capmax.mod\n");
 hoc_register_limits(_mechtype, _hoc_parm_limits);
 hoc_register_units(_mechtype, _hoc_parm_units);
 }
static int _reset;
static char *modelname = "";

static int error;
static int _ninits = 0;
static int _match_recurse=1;
static void _modl_cleanup(){ _match_recurse=1;}
static int absmx();
static int mxpos();
static int mx();
 
static int  absmx (  ) {
   if ( fabs ( icap ) > i ) {
     i = fabs ( icap ) ;
     tp = t ;
     }
    return 0; }
 
static void _hoc_absmx(void) {
  double _r;
   _r = 1.;
 absmx (  );
 hoc_retpushx(_r);
}
 
static int  mxpos (  ) {
   if ( icap > i ) {
     i = icap ;
     tp = t ;
     }
    return 0; }
 
static void _hoc_mxpos(void) {
  double _r;
   _r = 1.;
 mxpos (  );
 hoc_retpushx(_r);
}
 
static int  mx (  ) {
   if ( up  == 1.0 ) {
     if ( lockit < 0.0 ) {
       if ( icap > i ) {
         i = icap ;
         tp = t ;
         }
       if ( debug  == 1.0 ) {
         
/*VERBATIM*/
  	 
	               fprintf(stdout,"Lockit %f\tup: %f\tt: %f\ti: %f\n",lockit,up,t,i);
 }
       }
     }
   if ( ( t > 10.0 )  && ( icap > i3 )  && ( i3 > i2 )  && ( i2 > i1 ) ) {
     up = 1.0 ;
     }
   else {
     up = 0.0 ;
     }
   if ( ( icap > 0.0 )  && ( icap < i * 0.75 )  && ( ( t - tp ) < 2.0 ) ) {
     lockit = 1.0 ;
     }
   i1 = i2 ;
   i2 = i3 ;
   i3 = icap ;
    return 0; }
 
static void _hoc_mx(void) {
  double _r;
   _r = 1.;
 mx (  );
 hoc_retpushx(_r);
}
 
static int _ode_count(int _type){ hoc_execerror("capmax", "cannot be used with CVODE"); return 0;}

static void initmodel() {
  int _i; double _save;_ninits++;
 _save = t;
 t = 0.0;
{
  lockit = lockit0;
  up = up0;
 {
   i = 0.0 ;
   tp = 0.0 ;
   lockit = - 1.0 ;
   up = 0.0 ;
   i1 = 0.0 ;
   i2 = 0.0 ;
   i3 = 0.0 ;
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
 initmodel();
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
 { error =  mx();
 if(error){fprintf(stderr,"at line 37 in file capmax.mod:\n	   SOLVE mx \n"); nrn_complain(_p); abort_run(error);}
 } {
   }
}}

}

static void terminal(){}

static void _initlists() {
 int _i; static int _first = 1;
  if (!_first) return;
_first = 0;
}

#if NMODL_TEXT
static const char* nmodl_filename = "capmax.mod";
static const char* nmodl_file_text = 
  ": Recrd the time at which icap has a peak.\n"
  ": By Michael Hines 09-2004\n"
  "\n"
  "NEURON {\n"
  " SUFFIX capmax  \n"
  " POINTER icap \n"
  " RANGE i,tp,debug,i1,i2,i3,lockit,i1,i2,i3,up\n"
  "}\n"
  "\n"
  "PARAMETER { \n"
  "	 debug = 0\n"
  "}\n"
  "\n"
  "ASSIGNED { \n"
  "	 i (milliamp/cm2)  \n"
  "	 tp  (ms)\n"
  "	 icap (milliamp/cm2) \n"
  "	 i1 \n"
  "	 i2\n"
  "	 i3\n"
  "}\n"
  "STATE {\n"
  "      up\n"
  "      lockit\n"
  "}\n"
  "\n"
  "INITIAL { i = 0\n"
  "	  tp =0\n"
  "	  lockit = -1\n"
  "	  up = 0\n"
  "	  i1= 0\n"
  "	  i2 = 0\n"
  "	  i3 = 0\n"
  "	 }\n"
  "\n"
  "BREAKPOINT { \n"
  "	   SOLVE mx \n"
  "}\n"
  " \n"
  "PROCEDURE absmx() {\n"
  "	   if (fabs(icap) > i) { \n"
  "	      i = fabs(icap) \n"
  "	      tp  = t\n"
  "	   }\n"
  "}\n"
  "\n"
  "PROCEDURE mxpos() {\n"
  "	   if (icap > i) { \n"
  "	      i = icap \n"
  "	      tp  = t\n"
  "	   }\n"
  "}\n"
  "\n"
  "\n"
  "PROCEDURE mx() {\n"
  "	  if (up == 1 ) { \n"
  "	    if (lockit < 0) { \n"
  "	   	   if (icap > i) {	\n"
  "	      	      i = icap \n"
  "	      	      tp  =  t\n"
  "	   	   }\n"
  "	   	   if (debug == 1 ) {  \n"
  "	             VERBATIM   	 \n"
  "	               fprintf(stdout,\"Lockit %f\\tup: %f\\tt: %f\\ti: %f\\n\",lockit,up,t,i);\n"
  "	             ENDVERBATIM\n"
  "	          }\n"
  "            }\n"
  "\n"
  "          } \n"
  "	  if ( (t>10) && (icap>i3) && (i3>i2) && (i2>i1) ) { \n"
  "	      up = 1\n"
  "	  } else { \n"
  "	     up =0 \n"
  "	  }	     	      \n"
  "	   \n"
  "\n"
  "	  if ( (icap > 0 ) && ( icap < i*0.75) && ( (t-tp) < 2) ) {  \n"
  "	       lockit = 1\n"
  "	  }	       \n"
  "	  i1 = i2\n"
  "	  i2 = i3\n"
  "	  i3 = icap\n"
  "}\n"
  "\n"
  "\n"
  "\n"
  "\n"
  ;
#endif
