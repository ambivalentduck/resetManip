/*
 * rt_mod_snf.c
 *
 * Real-Time Workshop code generation for Simulink model "modelinference_target.mdl".
 *
 * Model version              : 1.900
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed Jul 21 13:13:36 2010
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 */

#include "rt_mod_snf.h"
#include "rt_nonfinite.h"
#include <float.h>
#include <math.h>

/*
 * Calls double-precision version of MOD, with guard against domain error
 * and guards against non-finites
 */
real_T rt_mod_snf(const real_T xr, const real_T yr)
{
  real_T zr, yrf, tr, trf, wr;
  if (yr == 0.0) {
    zr = xr;
  } else if (rtIsInf(xr) || rtIsInf(yr) || rtIsNaN(xr) || rtIsNaN(yr)) {
    zr = (rtNaN);
  } else {
    yrf = floor(yr);
    tr = xr/yr;
    if (yr == yrf) {
      /* Integer denominator.  Use conventional formula.*/
      trf = floor(tr);
      zr = xr - trf*yr;
    } else {
      /* Noninteger denominator. Check for nearly integer quotient.*/
      if (fabs(tr) < 4.5035996273704960E+015) {
        wr = ((tr < 0.0) ? -floor((fabs(tr) + 0.5)) : floor((fabs(tr) + 0.5)));
      } else {
        wr = tr;
      }

      if (fabs(tr - wr) <= ((DBL_EPSILON)*fabs(tr))) {
        zr = 0.0;
      } else {
        trf = floor(tr);
        zr = (tr - trf)*yr;
      }
    }
  }

  return zr;
}                                      /* end rt_mod_snf */
