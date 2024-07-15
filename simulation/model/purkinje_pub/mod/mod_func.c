#include <stdio.h>
#include "hocdec.h"
#define IMPORT extern __declspec(dllimport)
IMPORT int nrnmpi_myid, nrn_nobanner_;

extern void _BK_Slow_reg();
extern void _CaP_reg();
extern void _CaT_reg();
extern void _Kv1_reg();
extern void _SK2_reg();
extern void _capmax_reg();
extern void _cdp_AIS_reg();
extern void _cdp_smooth_reg();
extern void _cdp_soma_reg();
extern void _cdp_spiny_reg();
extern void _distr_reg();
extern void _ih_reg();
extern void _kv3_reg();
extern void _kv4f_reg();
extern void _kv4s_reg();
extern void _mslo_reg();
extern void _nap_reg();
extern void _narsg_reg();
extern void _peak_reg();
extern void _pkjlk_reg();
extern void _syn2_reg();

void modl_reg(){
	//nrn_mswindll_stdio(stdin, stdout, stderr);
    if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
	fprintf(stderr, "Additional mechanisms from files\n");

fprintf(stderr," BK_Slow.mod");
fprintf(stderr," CaP.mod");
fprintf(stderr," CaT.mod");
fprintf(stderr," Kv1.mod");
fprintf(stderr," SK2.mod");
fprintf(stderr," capmax.mod");
fprintf(stderr," cdp_AIS.mod");
fprintf(stderr," cdp_smooth.mod");
fprintf(stderr," cdp_soma.mod");
fprintf(stderr," cdp_spiny.mod");
fprintf(stderr," distr.mod");
fprintf(stderr," ih.mod");
fprintf(stderr," kv3.mod");
fprintf(stderr," kv4f.mod");
fprintf(stderr," kv4s.mod");
fprintf(stderr," mslo.mod");
fprintf(stderr," nap.mod");
fprintf(stderr," narsg.mod");
fprintf(stderr," peak.mod");
fprintf(stderr," pkjlk.mod");
fprintf(stderr," syn2.mod");
fprintf(stderr, "\n");
    }
_BK_Slow_reg();
_CaP_reg();
_CaT_reg();
_Kv1_reg();
_SK2_reg();
_capmax_reg();
_cdp_AIS_reg();
_cdp_smooth_reg();
_cdp_soma_reg();
_cdp_spiny_reg();
_distr_reg();
_ih_reg();
_kv3_reg();
_kv4f_reg();
_kv4s_reg();
_mslo_reg();
_nap_reg();
_narsg_reg();
_peak_reg();
_pkjlk_reg();
_syn2_reg();
}
