#include <stdio.h>
#include "hocdec.h"
extern int nrnmpi_myid;
extern int nrn_nobanner_;
#if defined(__cplusplus)
extern "C" {
#endif

extern void _BK_Slow_reg(void);
extern void _CaP_reg(void);
extern void _CaT_reg(void);
extern void _Kv1_reg(void);
extern void _SK2_reg(void);
extern void _capmax_reg(void);
extern void _cdp_AIS_reg(void);
extern void _cdp_smooth_reg(void);
extern void _cdp_soma_reg(void);
extern void _cdp_spiny_reg(void);
extern void _distr_reg(void);
extern void _ih_reg(void);
extern void _kv3_reg(void);
extern void _kv4f_reg(void);
extern void _kv4s_reg(void);
extern void _mslo_reg(void);
extern void _nap_reg(void);
extern void _narsg_reg(void);
extern void _peak_reg(void);
extern void _pkjlk_reg(void);
extern void _syn2_reg(void);

void modl_reg() {
  if (!nrn_nobanner_) if (nrnmpi_myid < 1) {
    fprintf(stderr, "Additional mechanisms from files\n");
    fprintf(stderr, " \"BK_Slow.mod\"");
    fprintf(stderr, " \"CaP.mod\"");
    fprintf(stderr, " \"CaT.mod\"");
    fprintf(stderr, " \"Kv1.mod\"");
    fprintf(stderr, " \"SK2.mod\"");
    fprintf(stderr, " \"capmax.mod\"");
    fprintf(stderr, " \"cdp_AIS.mod\"");
    fprintf(stderr, " \"cdp_smooth.mod\"");
    fprintf(stderr, " \"cdp_soma.mod\"");
    fprintf(stderr, " \"cdp_spiny.mod\"");
    fprintf(stderr, " \"distr.mod\"");
    fprintf(stderr, " \"ih.mod\"");
    fprintf(stderr, " \"kv3.mod\"");
    fprintf(stderr, " \"kv4f.mod\"");
    fprintf(stderr, " \"kv4s.mod\"");
    fprintf(stderr, " \"mslo.mod\"");
    fprintf(stderr, " \"nap.mod\"");
    fprintf(stderr, " \"narsg.mod\"");
    fprintf(stderr, " \"peak.mod\"");
    fprintf(stderr, " \"pkjlk.mod\"");
    fprintf(stderr, " \"syn2.mod\"");
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

#if defined(__cplusplus)
}
#endif
