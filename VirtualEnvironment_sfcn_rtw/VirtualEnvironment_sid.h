/*
 * VirtualEnvironment_sid.h
 *
 * Code generation for model "VirtualEnvironment_sf.mdl".
 *
 * Model version              : 1.43
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Fri Jun  2 18:30:40 2017
 *
 * Target selection: rtwsfcn.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Emulation hardware selection:
 *    Differs from embedded hardware (MATLAB Host)
 * Code generation objectives: Unspecified
 * Validation result: Not run
 *
 * SOURCES: VirtualEnvironment_sf.c
 */

/* statically allocated instance data for model: VirtualEnvironment */
{
  {
    /* Local SimStruct for the generated S-Function */
    static LocalS slS;
    LocalS *lS = &slS;
    ssSetUserData(rts, lS);

    /* block I/O */
    {
      static BlockIO_VirtualEnvironment sfcnB;
      void *b = (real_T *) &sfcnB;
      ssSetLocalBlockIO(rts, b);
      (void) memset(b, 0,
                    sizeof(BlockIO_VirtualEnvironment));
    }

    /* model checksums */
    ssSetChecksumVal(rts, 0, 525635063U);
    ssSetChecksumVal(rts, 1, 895810233U);
    ssSetChecksumVal(rts, 2, 247251920U);
    ssSetChecksumVal(rts, 3, 3203112525U);
  }
}
