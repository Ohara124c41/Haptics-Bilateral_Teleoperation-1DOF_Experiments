/*
 * singledof_demo.h
 *
 * Code generation for model "singledof_demo.mdl".
 *
 * Model version              : 1.201
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Mon Jun 18 09:37:41 2018
 *
 * Target selection: ectarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_singledof_demo_h_
#define RTW_HEADER_singledof_demo_h_
#ifndef singledof_demo_COMMON_INCLUDES_
# define singledof_demo_COMMON_INCLUDES_
#include <stddef.h>
#include <float.h>
#include <math.h>
#include <string.h>
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#include "dt_info.h"
#include "ext_work.h"
#include "rt_defines.h"
#include "rt_nonfinite.h"
#endif                                 /* singledof_demo_COMMON_INCLUDES_ */

#include "singledof_demo_types.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlkStateChangeFlag
# define rtmGetBlkStateChangeFlag(rtm) ((rtm)->ModelData.blkStateChange)
#endif

#ifndef rtmSetBlkStateChangeFlag
# define rtmSetBlkStateChangeFlag(rtm, val) ((rtm)->ModelData.blkStateChange = (val))
#endif

#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->ModelData.blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->ModelData.blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->ModelData.constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->ModelData.constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->ModelData.contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->ModelData.contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->ModelData.contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->ModelData.contStates = (val))
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->ModelData.defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->ModelData.defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->ModelData.derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->ModelData.derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ()
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ()
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ()
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ()
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ((rtm)->NonInlinedSFcns)
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ((rtm)->NonInlinedSFcns = (val))
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ()
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ()
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->ModelData.prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->ModelData.prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->Work.dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->Work.dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->ModelData.inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->ModelData.inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->ModelData.outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->ModelData.outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->ModelData.zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->ModelData.zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->ModelData.zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->ModelData.zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->ModelData.derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->ModelData.derivs = (val))
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->Work.dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->Work.dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTime
# define rtmGetVarNextHitTime(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTime
# define rtmSetVarNextHitTime(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define singledof_demo_rtModel         RT_MODEL_singledof_demo

/* Block signals for system '<S15>/lowpass' */
typedef struct {
  real_T out;                          /* '<S15>/lowpass' */
} rtB_lowpass_singledof_demo;

/* Block states (auto storage) for system '<S15>/lowpass' */
typedef struct {
  real_T out_prev;                     /* '<S15>/lowpass' */
  int32_T sfEvent;                     /* '<S15>/lowpass' */
  uint8_T is_active_c21_singledof_demo;/* '<S15>/lowpass' */
  boolean_T isStable;                  /* '<S15>/lowpass' */
  boolean_T doneDoubleBufferReInit;    /* '<S15>/lowpass' */
  boolean_T out_prev_not_empty;        /* '<S15>/lowpass' */
} rtDW_lowpass_singledof_demo;

/* Block signals for system '<S23>/lowpass' */
typedef struct {
  real_T out;                          /* '<S23>/lowpass' */
} rtB_lowpass_singledof_demo_g;

/* Block states (auto storage) for system '<S23>/lowpass' */
typedef struct {
  real_T out_prev;                     /* '<S23>/lowpass' */
  int32_T sfEvent;                     /* '<S23>/lowpass' */
  uint8_T is_active_c13_singledof_demo;/* '<S23>/lowpass' */
  boolean_T isStable;                  /* '<S23>/lowpass' */
  boolean_T doneDoubleBufferReInit;    /* '<S23>/lowpass' */
  boolean_T out_prev_not_empty;        /* '<S23>/lowpass' */
} rtDW_lowpass_singledof_demo_i;

/* Block signals for system '<S24>/lowpass' */
typedef struct {
  real_T out;                          /* '<S24>/lowpass' */
} rtB_lowpass_singledof_demo_c;

/* Block states (auto storage) for system '<S24>/lowpass' */
typedef struct {
  real_T out_prev;                     /* '<S24>/lowpass' */
  int32_T sfEvent;                     /* '<S24>/lowpass' */
  uint8_T is_active_c2_singledof_demo; /* '<S24>/lowpass' */
  boolean_T isStable;                  /* '<S24>/lowpass' */
  boolean_T doneDoubleBufferReInit;    /* '<S24>/lowpass' */
  boolean_T out_prev_not_empty;        /* '<S24>/lowpass' */
} rtDW_lowpass_singledof_demo_g;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T MultiportSwitch1;             /* '<S4>/Multiport Switch1' */
  real_T SwitchControl;                /* '<S65>/SwitchControl' */
  real_T ec_EL5101_enc;                /* '<S44>/ec_EL5101_enc' */
  real_T ec_EL5101_enc_l;              /* '<S46>/ec_EL5101_enc' */
  real_T SwitchControl_g[2];           /* '<S30>/SwitchControl' */
  real_T motorrevolutionsmaster[2];    /* '<S2>/Gain' */
  real_T positionofleverrad[2];        /* '<S2>/Gain6' */
  real_T IntegerDelay;                 /* '<S67>/Integer Delay' */
  real_T IntegerDelay1;                /* '<S67>/Integer Delay1' */
  real_T MultiportSwitch1_k;           /* '<S67>/Multiport Switch1' */
  real_T WeightedSampleTimeMath1;      /* '<S75>/Weighted Sample Time Math1' */
  real_T IntegerDelay2;                /* '<S68>/Integer Delay2' */
  real_T IntegerDelay1_i;              /* '<S68>/Integer Delay1' */
  real_T MultiportSwitch1_f;           /* '<S68>/Multiport Switch1' */
  real_T WeightedSampleTimeMath1_j;    /* '<S85>/Weighted Sample Time Math1' */
  real_T WeightedSampleTimeMath1_b;    /* '<S15>/Weighted Sample Time Math1' */
  real_T Derivative;                   /* '<S2>/Derivative' */
  real_T P1;                           /* '<S12>/P1' */
  real_T TSamp;                        /* '<S14>/TSamp' */
  real_T Diff;                         /* '<S14>/Diff' */
  real_T WeightedSampleTimeMath1_c;    /* '<S18>/Weighted Sample Time Math1' */
  real_T Derivative2;                  /* '<S2>/Derivative2' */
  real_T P1_g;                         /* '<S13>/P1' */
  real_T TSamp_d;                      /* '<S17>/TSamp' */
  real_T Diff_m;                       /* '<S17>/Diff' */
  real_T ec_EL3102_adc[2];             /* '<S21>/ec_EL3102_adc' */
  real_T chachb;                       /* '<S2>/Add4' */
  real_T ec_EL3102_adc_n[2];           /* '<S22>/ec_EL3102_adc' */
  real_T chachb_o;                     /* '<S2>/Add5' */
  real_T SwitchControl_b;              /* '<S28>/SwitchControl' */
  real_T V;                            /* '<S2>/Add1' */
  real_T Divide4;                      /* '<S2>/Divide4' */
  real_T forcalibration;               /* '<S2>/Divide5' */
  real_T SwitchControl_h;              /* '<S27>/SwitchControl' */
  real_T V_d;                          /* '<S2>/Add2' */
  real_T Divide;                       /* '<S2>/Divide' */
  real_T Divide2;                      /* '<S2>/Divide2' */
  real_T WeightedSampleTimeMath1_o;    /* '<S24>/Weighted Sample Time Math1' */
  real_T TimeDelay1;                   /* '<S32>/TimeDelay1' */
  real_T ShuntDynPredicterPart1;       /* '<S32>/ShuntDynPredicter Part 1' */
  real_T TimeDelay2;                   /* '<S32>/TimeDelay2' */
  real_T DiscreteTransferFcn;          /* '<S32>/Discrete Transfer Fcn' */
  real_T Correctionfactor;             /* '<S32>/Correction factor' */
  real_T Add5;                         /* '<S32>/Add5' */
  real_T WeightedSampleTimeMath1_of;   /* '<S26>/Weighted Sample Time Math1' */
  real_T TimeDelay1_c;                 /* '<S33>/TimeDelay1' */
  real_T TimeDelay2_d;                 /* '<S33>/TimeDelay2' */
  real_T DiscreteTransferFcn_d;        /* '<S33>/Discrete Transfer Fcn' */
  real_T Filtered;                     /* '<S33>/Add5' */
  real_T IntegerDelay_o;               /* '<S36>/Integer Delay' */
  real_T xi1;                          /* '<S48>/Integer Delay2' */
  real_T Add1;                         /* '<S48>/Add1' */
  real_T i;                            /* '<S48>/Multiport Switch2' */
  real_T xi;                           /* '<S48>/Product1' */
  real_T MultiportSwitch2;             /* '<S36>/Multiport Switch2' */
  real_T IntegerDelay_h;               /* '<S37>/Integer Delay' */
  real_T xi1_i;                        /* '<S49>/Integer Delay1' */
  real_T Add1_p;                       /* '<S49>/Add1' */
  real_T i_f;                          /* '<S49>/Multiport Switch2' */
  real_T xi_k;                         /* '<S49>/Product1' */
  real_T MultiportSwitch2_c;           /* '<S37>/Multiport Switch2' */
  real_T WeightedSampleTimeMath1_h;    /* '<S25>/Weighted Sample Time Math1' */
  real_T WeightedSampleTimeMath1_d;    /* '<S23>/Weighted Sample Time Math1' */
  real_T ec_EL5101_enc_i;              /* '<S45>/ec_EL5101_enc' */
  real_T Add1_j;                       /* '<S34>/Add1' */
  real_T ec_EL5101_enc_b;              /* '<S47>/ec_EL5101_enc' */
  real_T Add1_a;                       /* '<S35>/Add1' */
  real_T DiscreteTimeIntegrator;       /* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S2>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2;      /* '<S2>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator3;      /* '<S2>/Discrete-Time Integrator3' */
  real_T ec_EL1008_di[8];              /* '<S20>/ec_EL1008_di' */
  real_T Gain;                         /* '<S3>/Gain' */
  real_T Abs1[4];                      /* '<S53>/Abs1' */
  real_T Gain_n;                       /* '<S53>/Gain' */
  real_T MultiportSwitch2_j;           /* '<S10>/Multiport Switch2' */
  real_T WeightedSampleTimeMath1_i;    /* '<S101>/Weighted Sample Time Math1' */
  real_T DiscreteTimeIntegrator_o;     /* '<S96>/Discrete-Time Integrator' */
  real_T P2;                           /* '<S96>/P2' */
  real_T TSamp_p;                      /* '<S100>/TSamp' */
  real_T Diff_c;                       /* '<S100>/Diff' */
  real_T uMotorV;                      /* '<S3>/Add1' */
  real_T Gain1;                        /* '<S3>/Gain1' */
  real_T Abs1_l[4];                    /* '<S54>/Abs1' */
  real_T Gain_o;                       /* '<S54>/Gain' */
  real_T WeightedSampleTimeMath1_e;    /* '<S105>/Weighted Sample Time Math1' */
  real_T DiscreteTimeIntegrator_o5;    /* '<S97>/Discrete-Time Integrator' */
  real_T P2_k;                         /* '<S97>/P2' */
  real_T TSamp_o;                      /* '<S104>/TSamp' */
  real_T Diff_h;                       /* '<S104>/Diff' */
  real_T WeightedSampleTimeMath1_m;    /* '<S93>/Weighted Sample Time Math1' */
  real_T DiscreteTimeIntegrator_i;     /* '<S89>/Discrete-Time Integrator' */
  real_T P2_e;                         /* '<S89>/P2' */
  real_T TSamp_i;                      /* '<S92>/TSamp' */
  real_T Diff_j;                       /* '<S92>/Diff' */
  real_T Product1;                     /* '<S11>/Product1' */
  real_T uMotorV_k;                    /* '<S3>/Add2' */
  real_T SwitchControl_e[4];           /* '<S56>/SwitchControl' */
  real_T MultiportSwitch;              /* '<S94>/Multiport Switch' */
  real_T UnitDelay1;                   /* '<S90>/Unit Delay1' */
  real_T MultiportSwitch4;             /* '<S90>/Multiport Switch4' */
  real_T UnitDelay1_e;                 /* '<S91>/Unit Delay1' */
  real_T MultiportSwitch4_n;           /* '<S91>/Multiport Switch4' */
  real_T MultiportSwitch_h;            /* '<S102>/Multiport Switch' */
  real_T MultiportSwitch_j;            /* '<S106>/Multiport Switch' */
  real_T UnitDelay1_o;                 /* '<S98>/Unit Delay1' */
  real_T MultiportSwitch4_c;           /* '<S98>/Multiport Switch4' */
  real_T UnitDelay1_p;                 /* '<S99>/Unit Delay1' */
  real_T MultiportSwitch4_e;           /* '<S99>/Multiport Switch4' */
  real_T Gain3;                        /* '<S9>/Gain3' */
  real_T Gain2;                        /* '<S9>/Gain2' */
  boolean_T DataTypeConversion1;       /* '<S8>/Data Type Conversion1' */
  boolean_T Logic[2];                  /* '<S108>/Logic' */
  boolean_T LogicalOperator1;          /* '<S10>/Logical Operator1' */
  boolean_T LogicalOperator3;          /* '<S10>/Logical Operator3' */
  boolean_T DataTypeConversion;        /* '<S31>/Data Type Conversion' */
  boolean_T IntegerDelay2_k;           /* '<S2>/Integer Delay2' */
  boolean_T IntegerDelay_j;            /* '<S2>/Integer Delay' */
  boolean_T LogicalOperator;           /* '<S2>/Logical Operator' */
  boolean_T DataTypeConversion1_f;     /* '<S31>/Data Type Conversion1' */
  boolean_T Memory;                    /* '<S43>/Memory' */
  boolean_T Logic_m[2];                /* '<S43>/Logic' */
  boolean_T LogicalOperator5;          /* '<S38>/Logical Operator5' */
  boolean_T LogicalOperator_g;         /* '<S57>/Logical Operator' */
  rtB_lowpass_singledof_demo_c sf_lowpass_m;/* '<S105>/lowpass' */
  rtB_lowpass_singledof_demo_c sf_lowpass_h;/* '<S101>/lowpass' */
  rtB_lowpass_singledof_demo_c sf_lowpass_b;/* '<S93>/lowpass' */
  rtB_lowpass_singledof_demo_c sf_lowpass_k;/* '<S85>/lowpass' */
  rtB_lowpass_singledof_demo_c sf_lowpass;/* '<S75>/lowpass' */
  rtB_lowpass_singledof_demo_g sf_lowpass_n2;/* '<S26>/lowpass' */
  rtB_lowpass_singledof_demo_g sf_lowpass_i;/* '<S25>/lowpass' */
  rtB_lowpass_singledof_demo_c sf_lowpass_kz;/* '<S24>/lowpass' */
  rtB_lowpass_singledof_demo_g sf_lowpass_au;/* '<S23>/lowpass' */
  rtB_lowpass_singledof_demo sf_lowpass_n;/* '<S18>/lowpass' */
  rtB_lowpass_singledof_demo sf_lowpass_a;/* '<S15>/lowpass' */
} BlockIO_singledof_demo;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S67>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S68>/Discrete-Time Integrator' */
  real_T FixPtUnitDelay1_DSTATE;       /* '<S66>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S4>/Unit Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S4>/Discrete-Time Integrator' */
  real_T IntegerDelay_DSTATE;          /* '<S67>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S67>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S68>/Integer Delay2' */
  real_T IntegerDelay1_DSTATE_j;       /* '<S68>/Integer Delay1' */
  real_T UD_DSTATE;                    /* '<S14>/UD' */
  real_T UD_DSTATE_h;                  /* '<S17>/UD' */
  real_T IntegerDelay1_DSTATE_o;       /* '<S37>/Integer Delay1' */
  real_T IntegerDelay1_DSTATE_k;       /* '<S36>/Integer Delay1' */
  real_T ShuntDynPredicterPart1_DSTATE[7];/* '<S32>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_DSTATE;   /* '<S32>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_DSTATE[7];/* '<S32>/ShuntDynPredicter Part 2' */
  real_T ShuntDynPredicterPart1_DSTATE_e[7];/* '<S33>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_DSTATE_o; /* '<S33>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_DSTATE_c[7];/* '<S33>/ShuntDynPredicter Part 2' */
  real_T IntegerDelay_DSTATE_p;        /* '<S36>/Integer Delay' */
  real_T IntegerDelay2_DSTATE_e;       /* '<S48>/Integer Delay2' */
  real_T IntegerDelay_DSTATE_n;        /* '<S48>/Integer Delay' */
  real_T IntegerDelay_DSTATE_i;        /* '<S37>/Integer Delay' */
  real_T IntegerDelay1_DSTATE_m;       /* '<S49>/Integer Delay1' */
  real_T IntegerDelay_DSTATE_f;        /* '<S49>/Integer Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_h;/* '<S2>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S2>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S2>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S2>/Discrete-Time Integrator3' */
  real_T DiscreteTimeIntegrator_DSTATE_p;/* '<S96>/Discrete-Time Integrator' */
  real_T UD_DSTATE_g;                  /* '<S100>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_m;/* '<S97>/Discrete-Time Integrator' */
  real_T UD_DSTATE_i;                  /* '<S104>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_k;/* '<S89>/Discrete-Time Integrator' */
  real_T UD_DSTATE_k;                  /* '<S92>/UD' */
  real_T UnitDelay1_DSTATE;            /* '<S90>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_m;          /* '<S91>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_b;          /* '<S98>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_i;          /* '<S99>/Unit Delay1' */
  real_T ShuntDynPredicterPart1_tmp;   /* '<S32>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_tmp;      /* '<S32>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_tmp;   /* '<S32>/ShuntDynPredicter Part 2' */
  real_T ShuntDynPredicterPart1_tmp_j; /* '<S33>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_tmp_k;    /* '<S33>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_tmp_e; /* '<S33>/ShuntDynPredicter Part 2' */
  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay2_RWORK;                  /* '<S1>/TimeDelay2' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay3_RWORK;                  /* '<S1>/TimeDelay3' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK;                  /* '<S1>/TimeDelay1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S2>/Derivative' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay4_RWORK;                  /* '<S1>/TimeDelay4' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative2_RWORK;                 /* '<S2>/Derivative2' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_g;                /* '<S32>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay2_RWORK_m;                /* '<S32>/TimeDelay2' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_i;                /* '<S33>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay2_RWORK_g;                /* '<S33>/TimeDelay2' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_c;                /* '<S99>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_h;                /* '<S91>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_it;               /* '<S98>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_e;                /* '<S90>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay2_PWORK;                  /* '<S1>/TimeDelay2' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay3_PWORK;                  /* '<S1>/TimeDelay3' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK;                  /* '<S1>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay4_PWORK;                  /* '<S1>/TimeDelay4' */

  struct {
    void *LoggedData;
  } ADC_master_PWORK;                  /* '<S2>/ADC_master' */

  struct {
    void *LoggedData;
  } ADC_slave_PWORK;                   /* '<S2>/ADC_slave' */

  struct {
    void *LoggedData;
  } forces_PWORK;                      /* '<S2>/forces' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_n;                /* '<S32>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay2_PWORK_p;                /* '<S32>/TimeDelay2' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_p;                /* '<S33>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay2_PWORK_o;                /* '<S33>/TimeDelay2' */

  struct {
    void *LoggedData;
  } ForceSensor_actuatorTorque_comp;   /* '<S32>/ForceSensor_actuatorTorque_comparison' */

  struct {
    void *LoggedData;
  } veloc_PWORK;                       /* '<S2>/veloc' */

  struct {
    void *LoggedData;
  } Din_PWORK;                         /* '<S2>/Din' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_j;                /* '<S99>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_k;                /* '<S91>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_m;                /* '<S98>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_jj;               /* '<S90>/TimeDelay1' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S9>/Scope' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay2_IWORK;                  /* '<S1>/TimeDelay2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay3_IWORK;                  /* '<S1>/TimeDelay3' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK;                  /* '<S1>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay4_IWORK;                  /* '<S1>/TimeDelay4' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_b;                /* '<S32>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay2_IWORK_g;                /* '<S32>/TimeDelay2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_c;                /* '<S33>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay2_IWORK_h;                /* '<S33>/TimeDelay2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_f;                /* '<S99>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_h;                /* '<S91>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_cu;               /* '<S98>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_g;                /* '<S90>/TimeDelay1' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S66>/FixPt Unit Delay2' */
  boolean_T IntegerDelay1_DSTATE_mx[10];/* '<S8>/Integer Delay1' */
  boolean_T IntegerDelay1_DSTATE_kf[10];/* '<S31>/Integer Delay1' */
  boolean_T IntegerDelay2_DSTATE_f[2]; /* '<S2>/Integer Delay2' */
  boolean_T IntegerDelay_DSTATE_o;     /* '<S2>/Integer Delay' */
  boolean_T IntegerDelay1_DSTATE_h[10];/* '<S38>/Integer Delay1' */
  boolean_T Memory_PreviousInput;      /* '<S108>/Memory' */
  boolean_T Memory_PreviousInput_i;    /* '<S43>/Memory' */
  rtDW_lowpass_singledof_demo_g sf_lowpass_m;/* '<S105>/lowpass' */
  rtDW_lowpass_singledof_demo_g sf_lowpass_h;/* '<S101>/lowpass' */
  rtDW_lowpass_singledof_demo_g sf_lowpass_b;/* '<S93>/lowpass' */
  rtDW_lowpass_singledof_demo_g sf_lowpass_k;/* '<S85>/lowpass' */
  rtDW_lowpass_singledof_demo_g sf_lowpass;/* '<S75>/lowpass' */
  rtDW_lowpass_singledof_demo_i sf_lowpass_n2;/* '<S26>/lowpass' */
  rtDW_lowpass_singledof_demo_i sf_lowpass_i;/* '<S25>/lowpass' */
  rtDW_lowpass_singledof_demo_g sf_lowpass_kz;/* '<S24>/lowpass' */
  rtDW_lowpass_singledof_demo_i sf_lowpass_au;/* '<S23>/lowpass' */
  rtDW_lowpass_singledof_demo sf_lowpass_n;/* '<S18>/lowpass' */
  rtDW_lowpass_singledof_demo sf_lowpass_a;/* '<S15>/lowpass' */
} D_Work_singledof_demo;

/* Backward compatible GRT Identifiers */
#define rtB                            singledof_demo_B
#define BlockIO                        BlockIO_singledof_demo
#define rtXdot                         singledof_demo_Xdot
#define StateDerivatives               StateDerivatives_singledof_demo
#define tXdis                          singledof_demo_Xdis
#define StateDisabled                  StateDisabled_singledof_demo
#define rtP                            singledof_demo_P
#define Parameters                     Parameters_singledof_demo
#define rtDWork                        singledof_demo_DWork
#define D_Work                         D_Work_singledof_demo

/* Parameters (auto storage) */
struct Parameters_singledof_demo_ {
  real_T Constant2_Value;              /* Expression: -0.86
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1.042
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant5_Value[2];           /* Expression: [-8E3 -17E3]
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T Constant4_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Gain2_Gain;                   /* Expression: .5
                                        * Referenced by: '<S53>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: .5
                                        * Referenced by: '<S53>/Gain1'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: .5
                                        * Referenced by: '<S54>/Gain2'
                                        */
  real_T Gain1_Gain_i;                 /* Expression: .5
                                        * Referenced by: '<S54>/Gain1'
                                        */
  real_T Constant15_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant15'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant16'
                                        */
  real_T Constant17_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant17'
                                        */
  real_T Constant18_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant18'
                                        */
  real_T yes_Value;                    /* Expression: 1
                                        * Referenced by: '<S4>/yes'
                                        */
  real_T yes1_Value;                   /* Expression: 1
                                        * Referenced by: '<S4>/yes1'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T P1_Gain;                      /* Expression: Is
                                        * Referenced by: '<S89>/P1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T P1_Gain_b;                    /* Expression: Im
                                        * Referenced by: '<S96>/P1'
                                        */
  real_T P1_Gain_o;                    /* Expression: Is
                                        * Referenced by: '<S97>/P1'
                                        */
  real_T setting_Value;                /* Expression: mode
                                        * Referenced by: '<S10>/setting'
                                        */
  real_T setting4_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/setting4'
                                        */
  real_T P3_Gain;                      /* Expression: B_m
                                        * Referenced by: '<S12>/P3'
                                        */
  real_T P2_Gain;                      /* Expression: K_m
                                        * Referenced by: '<S12>/P2'
                                        */
  real_T Gain1_Gain_n;                 /* Expression: 1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Saturation_UpperSat;          /* Expression: maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T P3_Gain_k;                    /* Expression: B_s
                                        * Referenced by: '<S13>/P3'
                                        */
  real_T P2_Gain_l;                    /* Expression: K_s
                                        * Referenced by: '<S13>/P2'
                                        */
  real_T P1_Gain_g;                    /* Expression: -1
                                        * Referenced by: '<S1>/P1'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S1>/Saturation1'
                                        */
  real_T on2_Value;                    /* Expression: 0
                                        * Referenced by: '<S8>/on2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S67>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S67>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S70>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_g;/* Computed Parameter: DiscreteTimeIntegrator_gainva_g
                                          * Referenced by: '<S68>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: 0
                                        * Referenced by: '<S68>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_c;             /* Expression: const
                                        * Referenced by: '<S80>/Constant'
                                        */
  real_T ShutdownSim_Value;            /* Expression: 226
                                        * Referenced by: '<S4>/ShutdownSim'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S66>/FixPt Unit Delay1'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S4>/Unit Delay2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_e;/* Computed Parameter: DiscreteTimeIntegrator_gainva_e
                                          * Referenced by: '<S4>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_a;  /* Expression: 0
                                        * Referenced by: '<S4>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T ec_EL5101_enc_P1_Size[2];     /* Computed Parameter: ec_EL5101_enc_P1_Size
                                        * Referenced by: '<S44>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1;             /* Expression: link_id
                                        * Referenced by: '<S44>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_Size_o[2];   /* Computed Parameter: ec_EL5101_enc_P1_Size_o
                                        * Referenced by: '<S46>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_m;           /* Expression: link_id
                                        * Referenced by: '<S46>/ec_EL5101_enc'
                                        */
  real_T Gain1_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1/(7500*4)
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/10*2*pi
                                        * Referenced by: '<S2>/Gain6'
                                        */
  real_T IntegerDelay_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S67>/Integer Delay'
                                        */
  real_T Constant_Value_g;             /* Expression: const
                                        * Referenced by: '<S69>/Constant'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S67>/Constant1'
                                        */
  real_T Constant4_Value_d;            /* Expression: .01
                                        * Referenced by: '<S67>/Constant4'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S67>/Integer Delay1'
                                         */
  real_T Constant_Value_n;             /* Expression: -.3
                                        * Referenced by: '<S67>/Constant'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S72>/Slider Gain'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S75>/Constant1'
                                        */
  real_T CutofffreqHz_Value;           /* Expression: cf
                                        * Referenced by: '<S75>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt; /* Computed Parameter: WeightedSampleTimeMath1_WtEt
                                        * Referenced by: '<S75>/Weighted Sample Time Math1'
                                        */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S68>/Integer Delay2'
                                         */
  real_T Constant_Value_j;             /* Expression: const
                                        * Referenced by: '<S79>/Constant'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S68>/Constant1'
                                        */
  real_T Constant4_Value_a;            /* Expression: .01
                                        * Referenced by: '<S68>/Constant4'
                                        */
  real_T IntegerDelay1_InitialConditio_e;/* Expression: 0.0
                                          * Referenced by: '<S68>/Integer Delay1'
                                          */
  real_T Constant_Value_ng;            /* Expression: -.3
                                        * Referenced by: '<S68>/Constant'
                                        */
  real_T SliderGain_Gain_b;            /* Expression: gain
                                        * Referenced by: '<S82>/Slider Gain'
                                        */
  real_T Constant1_Value_a;            /* Expression: 1
                                        * Referenced by: '<S85>/Constant1'
                                        */
  real_T CutofffreqHz_Value_f;         /* Expression: cf
                                        * Referenced by: '<S85>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_f;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_f
                                         * Referenced by: '<S85>/Weighted Sample Time Math1'
                                         */
  real_T setting18_Value;              /* Expression: comm_delay
                                        * Referenced by: '<S10>/setting18'
                                        */
  real_T TimeDelay2_MaxDelay;          /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay2'
                                        */
  real_T TimeDelay2_InitOutput;        /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay2'
                                        */
  real_T TimeDelay3_MaxDelay;          /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay3'
                                        */
  real_T TimeDelay3_InitOutput;        /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay3'
                                        */
  real_T TimeDelay1_MaxDelay;          /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput;        /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay1'
                                        */
  real_T CutofffreqHz_Value_j;         /* Expression: cf
                                        * Referenced by: '<S15>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S15>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_fn;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_fn
                                          * Referenced by: '<S15>/Weighted Sample Time Math1'
                                          */
  real_T P1_Gain_d;                    /* Expression: K_dm
                                        * Referenced by: '<S12>/P1'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S14>/TSamp'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S14>/UD'
                                        */
  real_T TimeDelay4_MaxDelay;          /* Expression: 1
                                        * Referenced by: '<S1>/TimeDelay4'
                                        */
  real_T TimeDelay4_InitOutput;        /* Expression: 0
                                        * Referenced by: '<S1>/TimeDelay4'
                                        */
  real_T CutofffreqHz_Value_f0;        /* Expression: cf
                                        * Referenced by: '<S18>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_hw;           /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_f1;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_f1
                                          * Referenced by: '<S18>/Weighted Sample Time Math1'
                                          */
  real_T P1_Gain_h;                    /* Expression: K_ds
                                        * Referenced by: '<S13>/P1'
                                        */
  real_T TSamp_WtEt_f;                 /* Computed Parameter: TSamp_WtEt_f
                                        * Referenced by: '<S17>/TSamp'
                                        */
  real_T UD_X0_e;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S17>/UD'
                                        */
  real_T ec_EL3102_adc_P1_Size[2];     /* Computed Parameter: ec_EL3102_adc_P1_Size
                                        * Referenced by: '<S21>/ec_EL3102_adc'
                                        */
  real_T ec_EL3102_adc_P1;             /* Expression: link_id
                                        * Referenced by: '<S21>/ec_EL3102_adc'
                                        */
  real_T ec_EL3102_adc_P1_Size_e[2];   /* Computed Parameter: ec_EL3102_adc_P1_Size_e
                                        * Referenced by: '<S22>/ec_EL3102_adc'
                                        */
  real_T ec_EL3102_adc_P1_l;           /* Expression: link_id
                                        * Referenced by: '<S22>/ec_EL3102_adc'
                                        */
  real_T Constant11_Value;             /* Expression: 6.5
                                        * Referenced by: '<S2>/Constant11'
                                        */
  real_T IntegerDelay1_InitialConditio_l;/* Expression: 0.0
                                          * Referenced by: '<S37>/Integer Delay1'
                                          */
  real_T Constant10_Value;             /* Expression: L_arm
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant12_Value;             /* Expression: 0.5
                                        * Referenced by: '<S2>/Constant12'
                                        */
  real_T IntegerDelay1_InitialConditio_a;/* Expression: 0.0
                                          * Referenced by: '<S36>/Integer Delay1'
                                          */
  real_T Constant7_Value;              /* Expression: 16.6
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T Constant3_Value;              /* Expression: L_arm
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: .5
                                        * Referenced by: '<S2>/Constant8'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S24>/Constant1'
                                        */
  real_T CutofffreqHz_Value_m;         /* Expression: cf
                                        * Referenced by: '<S24>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_n;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_n
                                         * Referenced by: '<S24>/Weighted Sample Time Math1'
                                         */
  real_T setting6_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/setting6'
                                        */
  real_T Constant2_Value_l;            /* Expression: 0
                                        * Referenced by: '<S32>/Constant2'
                                        */
  real_T TimeDelay1_MaxDelay_o;        /* Expression: 1
                                        * Referenced by: '<S32>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_d;      /* Expression: 0
                                        * Referenced by: '<S32>/TimeDelay1'
                                        */
  real_T ShuntDynPredicterPart1_InitialS;/* Expression: 0
                                          * Referenced by: '<S32>/ShuntDynPredicter Part 1'
                                          */
  real_T ShuntDynPredicterPart1_Numerato[8];/* Expression: shuntDynPredict_part1_tfd_foh.num{1}
                                             * Referenced by: '<S32>/ShuntDynPredicter Part 1'
                                             */
  real_T ShuntDynPredicterPart1_Denomina[8];/* Expression: shuntDynPredict_part1_tfd_foh.den{1}
                                             * Referenced by: '<S32>/ShuntDynPredicter Part 1'
                                             */
  real_T Constant1_Value_n;            /* Expression: 1/2000*3
                                        * Referenced by: '<S32>/Constant1'
                                        */
  real_T TimeDelay2_MaxDelay_g;        /* Expression: 1
                                        * Referenced by: '<S32>/TimeDelay2'
                                        */
  real_T TimeDelay2_InitOutput_c;      /* Expression: 0
                                        * Referenced by: '<S32>/TimeDelay2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S32>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_Numerator[2];/* Expression: lowOrder_tfd_foh.num{1}
                                           * Referenced by: '<S32>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_Denominator[2];/* Expression: lowOrder_tfd_foh.den{1}
                                             * Referenced by: '<S32>/Discrete Transfer Fcn'
                                             */
  real_T ShuntDynPredicterPart2_InitialS;/* Expression: 0
                                          * Referenced by: '<S32>/ShuntDynPredicter Part 2'
                                          */
  real_T ShuntDynPredicterPart2_Numerato[8];/* Expression: shuntDynPredict_part2_tfd_foh.num{1}
                                             * Referenced by: '<S32>/ShuntDynPredicter Part 2'
                                             */
  real_T ShuntDynPredicterPart2_Denomina[8];/* Expression: shuntDynPredict_part2_tfd_foh.den{1}
                                             * Referenced by: '<S32>/ShuntDynPredicter Part 2'
                                             */
  real_T Correctionfactor_Gain;        /* Expression: 1.05
                                        * Referenced by: '<S32>/Correction factor'
                                        */
  real_T Constant1_Value_c;            /* Expression: 1
                                        * Referenced by: '<S26>/Constant1'
                                        */
  real_T CutofffreqHz_Value_e;         /* Expression: cf
                                        * Referenced by: '<S26>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_k;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_k
                                         * Referenced by: '<S26>/Weighted Sample Time Math1'
                                         */
  real_T setting16_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/setting16'
                                        */
  real_T Constant2_Value_k;            /* Expression: 0
                                        * Referenced by: '<S33>/Constant2'
                                        */
  real_T TimeDelay1_MaxDelay_c;        /* Expression: 1
                                        * Referenced by: '<S33>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_i;      /* Expression: 0
                                        * Referenced by: '<S33>/TimeDelay1'
                                        */
  real_T ShuntDynPredicterPart1_Initia_k;/* Expression: 0
                                          * Referenced by: '<S33>/ShuntDynPredicter Part 1'
                                          */
  real_T ShuntDynPredicterPart1_Numera_f[8];/* Expression: shuntDynPredict_part1_tfd_foh.num{1}
                                             * Referenced by: '<S33>/ShuntDynPredicter Part 1'
                                             */
  real_T ShuntDynPredicterPart1_Denomi_f[8];/* Expression: shuntDynPredict_part1_tfd_foh.den{1}
                                             * Referenced by: '<S33>/ShuntDynPredicter Part 1'
                                             */
  real_T Constant1_Value_l;            /* Expression: 1/2000*3
                                        * Referenced by: '<S33>/Constant1'
                                        */
  real_T TimeDelay2_MaxDelay_m;        /* Expression: 1
                                        * Referenced by: '<S33>/TimeDelay2'
                                        */
  real_T TimeDelay2_InitOutput_l;      /* Expression: 0
                                        * Referenced by: '<S33>/TimeDelay2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_o;/* Expression: 0
                                          * Referenced by: '<S33>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_Numerator_d[2];/* Expression: lowOrder_tfd_foh.num{1}
                                             * Referenced by: '<S33>/Discrete Transfer Fcn'
                                             */
  real_T DiscreteTransferFcn_Denominat_j[2];/* Expression: lowOrder_tfd_foh.den{1}
                                             * Referenced by: '<S33>/Discrete Transfer Fcn'
                                             */
  real_T ShuntDynPredicterPart2_Initia_n;/* Expression: 0
                                          * Referenced by: '<S33>/ShuntDynPredicter Part 2'
                                          */
  real_T ShuntDynPredicterPart2_Numera_c[8];/* Expression: shuntDynPredict_part2_tfd_foh.num{1}
                                             * Referenced by: '<S33>/ShuntDynPredicter Part 2'
                                             */
  real_T ShuntDynPredicterPart2_Denomi_h[8];/* Expression: shuntDynPredict_part2_tfd_foh.den{1}
                                             * Referenced by: '<S33>/ShuntDynPredicter Part 2'
                                             */
  real_T Correctionfactor_Gain_c;      /* Expression: 1.05
                                        * Referenced by: '<S33>/Correction factor'
                                        */
  real_T IntegerDelay_InitialCondition_e;/* Expression: 0.0
                                          * Referenced by: '<S36>/Integer Delay'
                                          */
  real_T min_val_Value;                /* Expression: .2
                                        * Referenced by: '<S36>/min_val'
                                        */
  real_T max_val_Value;                /* Expression: 0.5
                                        * Referenced by: '<S36>/max_val'
                                        */
  real_T IntegerDelay2_InitialConditio_b;/* Expression: 0.0
                                          * Referenced by: '<S48>/Integer Delay2'
                                          */
  real_T constant_Value;               /* Expression: 1
                                        * Referenced by: '<S48>/constant'
                                        */
  real_T constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S48>/constant1'
                                        */
  real_T IntegerDelay_InitialCondition_a;/* Expression: 0.0
                                          * Referenced by: '<S48>/Integer Delay'
                                          */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S48>/constant2'
                                        */
  real_T IntegerDelay_InitialCondition_h;/* Expression: 0.0
                                          * Referenced by: '<S37>/Integer Delay'
                                          */
  real_T min_val_Value_p;              /* Expression: .2
                                        * Referenced by: '<S37>/min_val'
                                        */
  real_T max_val_Value_p;              /* Expression: 0.5
                                        * Referenced by: '<S37>/max_val'
                                        */
  real_T IntegerDelay1_InitialConditi_l5;/* Expression: 0.0
                                          * Referenced by: '<S49>/Integer Delay1'
                                          */
  real_T constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S49>/constant'
                                        */
  real_T constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S49>/constant1'
                                        */
  real_T IntegerDelay_InitialCondition_k;/* Expression: 0.0
                                          * Referenced by: '<S49>/Integer Delay'
                                          */
  real_T constant2_Value_b;            /* Expression: 1
                                        * Referenced by: '<S49>/constant2'
                                        */
  real_T CutofffreqHz_Value_d;         /* Expression: cf
                                        * Referenced by: '<S25>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_ns;           /* Expression: 1
                                        * Referenced by: '<S25>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_kb;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_kb
                                          * Referenced by: '<S25>/Weighted Sample Time Math1'
                                          */
  real_T CutofffreqHz_Value_eg;        /* Expression: cf
                                        * Referenced by: '<S23>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_ds;           /* Expression: 1
                                        * Referenced by: '<S23>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_n1;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_n1
                                          * Referenced by: '<S23>/Weighted Sample Time Math1'
                                          */
  real_T ec_EL5101_enc_P1_Size_d[2];   /* Computed Parameter: ec_EL5101_enc_P1_Size_d
                                        * Referenced by: '<S45>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_p;           /* Expression: link_id
                                        * Referenced by: '<S45>/ec_EL5101_enc'
                                        */
  real_T Gain1_Gain_n1;                /* Expression: -1
                                        * Referenced by: '<S34>/Gain1'
                                        */
  real_T Gain_Gain_e;                  /* Expression: 1/(7500*4)
                                        * Referenced by: '<S34>/Gain'
                                        */
  real_T Gain6_Gain_m;                 /* Expression: 1/10*360
                                        * Referenced by: '<S34>/Gain6'
                                        */
  real_T Constant4_Value_aa;           /* Expression: 18
                                        * Referenced by: '<S34>/Constant4'
                                        */
  real_T ec_EL5101_enc_P1_Size_f[2];   /* Computed Parameter: ec_EL5101_enc_P1_Size_f
                                        * Referenced by: '<S47>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_d;           /* Expression: link_id
                                        * Referenced by: '<S47>/ec_EL5101_enc'
                                        */
  real_T Gain1_Gain_f;                 /* Expression: 1
                                        * Referenced by: '<S35>/Gain1'
                                        */
  real_T Gain_Gain_en;                 /* Expression: 1/(7500*4)
                                        * Referenced by: '<S35>/Gain'
                                        */
  real_T Gain6_Gain_d;                 /* Expression: 1/10*360
                                        * Referenced by: '<S35>/Gain6'
                                        */
  real_T Constant4_Value_e;            /* Expression: -19
                                        * Referenced by: '<S35>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainva_d;/* Computed Parameter: DiscreteTimeIntegrator_gainva_d
                                          * Referenced by: '<S2>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_m;  /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S2>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<S2>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator2'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;/* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                          * Referenced by: '<S2>/Discrete-Time Integrator3'
                                          */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<S2>/Discrete-Time Integrator3'
                                        */
  real_T ec_EL1008_di_P1_Size[2];      /* Computed Parameter: ec_EL1008_di_P1_Size
                                        * Referenced by: '<S20>/ec_EL1008_di'
                                        */
  real_T ec_EL1008_di_P1;              /* Expression: link_id
                                        * Referenced by: '<S20>/ec_EL1008_di'
                                        */
  real_T on2_Value_p;                  /* Expression: 0
                                        * Referenced by: '<S31>/on2'
                                        */
  real_T Constant6_Value_h;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T on_Value;                     /* Expression: .01
                                        * Referenced by: '<S2>/on'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T on1_Value;                    /* Expression: 7
                                        * Referenced by: '<S38>/on1'
                                        */
  real_T on3_Value;                    /* Expression: 0.1
                                        * Referenced by: '<S38>/on3'
                                        */
  real_T setting3_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/setting3'
                                        */
  real_T Gain_Gain_l;                  /* Expression: 0.01
                                        * Referenced by: '<S3>/Gain'
                                        */
  real_T Constant_Value_ja;            /* Expression: const
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant2_Value_kt[4];        /* Expression: [0.04907     0.00274     0.05296     0.00325]
                                        * Referenced by: '<S53>/Constant2'
                                        */
  real_T Constant_Value_g3;            /* Expression: const
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T Constant1_Value_hz;           /* Expression: 1
                                        * Referenced by: '<S53>/Constant1'
                                        */
  real_T Gain_Gain_f;                  /* Expression: -1
                                        * Referenced by: '<S53>/Gain'
                                        */
  real_T TimeDelay1_MaxDelay_d;        /* Expression: 1
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_h;      /* Expression: 0
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  real_T setting19_Value;              /* Expression: mu
                                        * Referenced by: '<S10>/setting19'
                                        */
  real_T setting2_Value;               /* Expression: lambda
                                        * Referenced by: '<S10>/setting2'
                                        */
  real_T CutofffreqHz_Value_a;         /* Expression: cf
                                        * Referenced by: '<S101>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_g;            /* Expression: 1
                                        * Referenced by: '<S101>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_g;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_g
                                         * Referenced by: '<S101>/Weighted Sample Time Math1'
                                         */
  real_T P_Gain;                       /* Expression: Pm
                                        * Referenced by: '<S96>/P'
                                        */
  real_T DiscreteTimeIntegrator_gainva_k;/* Computed Parameter: DiscreteTimeIntegrator_gainva_k
                                          * Referenced by: '<S96>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_i;  /* Expression: 0
                                        * Referenced by: '<S96>/Discrete-Time Integrator'
                                        */
  real_T P2_Gain_i;                    /* Expression: Dm
                                        * Referenced by: '<S96>/P2'
                                        */
  real_T TSamp_WtEt_h;                 /* Computed Parameter: TSamp_WtEt_h
                                        * Referenced by: '<S100>/TSamp'
                                        */
  real_T UD_X0_n;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S100>/UD'
                                        */
  real_T TimeDelay1_MaxDelay_n;        /* Expression: 1
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_l;      /* Expression: 0
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  real_T Constant3_Value_g;            /* Expression: torque_constant
                                        * Referenced by: '<S3>/Constant3'
                                        */
  real_T Constant6_Value_p;            /* Expression: .01
                                        * Referenced by: '<S3>/Constant6'
                                        */
  real_T setting5_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/setting5'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: 0.01
                                        * Referenced by: '<S3>/Gain1'
                                        */
  real_T Constant_Value_cb;            /* Expression: const
                                        * Referenced by: '<S60>/Constant'
                                        */
  real_T Constant_Value_o;             /* Expression: 1
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant3_Value_p[4];         /* Expression: [0.04555     0.00229     0.03561     0.00305]
                                        * Referenced by: '<S54>/Constant3'
                                        */
  real_T Constant_Value_e;             /* Expression: const
                                        * Referenced by: '<S61>/Constant'
                                        */
  real_T Constant1_Value_m;            /* Expression: 1
                                        * Referenced by: '<S54>/Constant1'
                                        */
  real_T Gain_Gain_fe;                 /* Expression: -1
                                        * Referenced by: '<S54>/Gain'
                                        */
  real_T TimeDelay1_MaxDelay_j;        /* Expression: 1
                                        * Referenced by: '<S98>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_n;      /* Expression: 0
                                        * Referenced by: '<S98>/TimeDelay1'
                                        */
  real_T CutofffreqHz_Value_g;         /* Expression: cf
                                        * Referenced by: '<S105>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_ig;           /* Expression: 1
                                        * Referenced by: '<S105>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_c;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_c
                                         * Referenced by: '<S105>/Weighted Sample Time Math1'
                                         */
  real_T P_Gain_d;                     /* Expression: Ps
                                        * Referenced by: '<S97>/P'
                                        */
  real_T DiscreteTimeIntegrator_gainva_h;/* Computed Parameter: DiscreteTimeIntegrator_gainva_h
                                          * Referenced by: '<S97>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S97>/Discrete-Time Integrator'
                                        */
  real_T P2_Gain_j;                    /* Expression: Ds
                                        * Referenced by: '<S97>/P2'
                                        */
  real_T TSamp_WtEt_p;                 /* Computed Parameter: TSamp_WtEt_p
                                        * Referenced by: '<S104>/TSamp'
                                        */
  real_T UD_X0_h;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S104>/UD'
                                        */
  real_T TimeDelay1_MaxDelay_oo;       /* Expression: 1
                                        * Referenced by: '<S90>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_g;      /* Expression: 0
                                        * Referenced by: '<S90>/TimeDelay1'
                                        */
  real_T CutofffreqHz_Value_ae;        /* Expression: cf
                                        * Referenced by: '<S93>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_li;           /* Expression: 1
                                        * Referenced by: '<S93>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_a;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_a
                                         * Referenced by: '<S93>/Weighted Sample Time Math1'
                                         */
  real_T P_Gain_e;                     /* Expression: Ps
                                        * Referenced by: '<S89>/P'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                          * Referenced by: '<S89>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_b;  /* Expression: 0
                                        * Referenced by: '<S89>/Discrete-Time Integrator'
                                        */
  real_T P2_Gain_io;                   /* Expression: Ds
                                        * Referenced by: '<S89>/P2'
                                        */
  real_T TSamp_WtEt_o;                 /* Computed Parameter: TSamp_WtEt_o
                                        * Referenced by: '<S92>/TSamp'
                                        */
  real_T UD_X0_f;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S92>/UD'
                                        */
  real_T Constant8_Value_n;            /* Expression: torque_constant
                                        * Referenced by: '<S3>/Constant8'
                                        */
  real_T Constant7_Value_c;            /* Expression: -.01
                                        * Referenced by: '<S3>/Constant7'
                                        */
  real_T ec_EL4038_dac_P1_Size[2];     /* Computed Parameter: ec_EL4038_dac_P1_Size
                                        * Referenced by: '<S52>/ec_EL4038_dac'
                                        */
  real_T ec_EL4038_dac_P1;             /* Expression: link_id
                                        * Referenced by: '<S52>/ec_EL4038_dac'
                                        */
  real_T Constant_Value_p;             /* Expression: const
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T Constant_Value_i;             /* Expression: const
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T Constant10_Value_m;           /* Expression: 0
                                        * Referenced by: '<S3>/Constant10'
                                        */
  real_T Constant11_Value_a;           /* Expression: 0
                                        * Referenced by: '<S3>/Constant11'
                                        */
  real_T Constant12_Value_b;           /* Expression: 0
                                        * Referenced by: '<S3>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0
                                        * Referenced by: '<S3>/Constant14'
                                        */
  real_T Constant9_Value_i;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant9'
                                        */
  real_T ec_EL2008_do_P1_Size[2];      /* Computed Parameter: ec_EL2008_do_P1_Size
                                        * Referenced by: '<S51>/ec_EL2008_do'
                                        */
  real_T ec_EL2008_do_P1;              /* Expression: link_id
                                        * Referenced by: '<S51>/ec_EL2008_do'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant1'
                                        */
  real_T Constant2_Value_h;            /* Expression: 1
                                        * Referenced by: '<S3>/Constant2'
                                        */
  real_T Constant4_Value_n;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant4'
                                        */
  real_T Constant5_Value_d;            /* Expression: 0
                                        * Referenced by: '<S3>/Constant5'
                                        */
  real_T setting17_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/setting17'
                                        */
  real_T UnitDelay1_X0;                /* Expression: 0
                                        * Referenced by: '<S90>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_k;              /* Expression: 0
                                        * Referenced by: '<S91>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_kh;             /* Expression: 0
                                        * Referenced by: '<S98>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_i;              /* Expression: 0
                                        * Referenced by: '<S99>/Unit Delay1'
                                        */
  real_T Gain3_Gain_a;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T Gain2_Gain_g;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain2'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S8>/Integer Delay1'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S67>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_l;/* Computed Parameter: IntegerDelay1_DelayLength_l
                                        * Referenced by: '<S67>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S68>/Integer Delay2'
                                        */
  uint32_T IntegerDelay1_DelayLength_l5;/* Computed Parameter: IntegerDelay1_DelayLength_l5
                                         * Referenced by: '<S68>/Integer Delay1'
                                         */
  uint32_T IntegerDelay1_DelayLength_f;/* Computed Parameter: IntegerDelay1_DelayLength_f
                                        * Referenced by: '<S37>/Integer Delay1'
                                        */
  uint32_T IntegerDelay1_DelayLength_g;/* Computed Parameter: IntegerDelay1_DelayLength_g
                                        * Referenced by: '<S36>/Integer Delay1'
                                        */
  uint32_T IntegerDelay_DelayLength_k; /* Computed Parameter: IntegerDelay_DelayLength_k
                                        * Referenced by: '<S36>/Integer Delay'
                                        */
  uint32_T IntegerDelay2_DelayLength_c;/* Computed Parameter: IntegerDelay2_DelayLength_c
                                        * Referenced by: '<S48>/Integer Delay2'
                                        */
  uint32_T IntegerDelay_DelayLength_e; /* Computed Parameter: IntegerDelay_DelayLength_e
                                        * Referenced by: '<S48>/Integer Delay'
                                        */
  uint32_T IntegerDelay_DelayLength_f; /* Computed Parameter: IntegerDelay_DelayLength_f
                                        * Referenced by: '<S37>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_d;/* Computed Parameter: IntegerDelay1_DelayLength_d
                                        * Referenced by: '<S49>/Integer Delay1'
                                        */
  uint32_T IntegerDelay_DelayLength_kj;/* Computed Parameter: IntegerDelay_DelayLength_kj
                                        * Referenced by: '<S49>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_db;/* Computed Parameter: IntegerDelay1_DelayLength_db
                                         * Referenced by: '<S31>/Integer Delay1'
                                         */
  uint32_T IntegerDelay2_DelayLength_a;/* Computed Parameter: IntegerDelay2_DelayLength_a
                                        * Referenced by: '<S2>/Integer Delay2'
                                        */
  uint32_T IntegerDelay_DelayLength_ki;/* Computed Parameter: IntegerDelay_DelayLength_ki
                                        * Referenced by: '<S2>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_j;/* Computed Parameter: IntegerDelay1_DelayLength_j
                                        * Referenced by: '<S38>/Integer Delay1'
                                        */
  uint8_T Constant_Value_h;            /* Expression: uint8(1)
                                        * Referenced by: '<S5>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S5>/SwitchControl'
                                        */
  uint8_T Constant_Value_d;            /* Expression: uint8(1)
                                        * Referenced by: '<S65>/Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S66>/FixPt Unit Delay2'
                                        */
  uint8_T SwitchControl_Threshold_c;   /* Expression: uint8(0)
                                        * Referenced by: '<S65>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S66>/FixPt Constant'
                                        */
  uint8_T Constant_Value_hr;           /* Expression: uint8(1)
                                        * Referenced by: '<S30>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_b;   /* Expression: uint8(0)
                                        * Referenced by: '<S30>/SwitchControl'
                                        */
  uint8_T Constant_Value_a;            /* Expression: uint8(1)
                                        * Referenced by: '<S28>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_l;   /* Expression: uint8(1)
                                        * Referenced by: '<S28>/SwitchControl'
                                        */
  uint8_T Constant_Value_oj;           /* Expression: uint8(1)
                                        * Referenced by: '<S27>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_k;   /* Expression: uint8(1)
                                        * Referenced by: '<S27>/SwitchControl'
                                        */
  uint8_T Constant_Value_da;           /* Expression: uint8(1)
                                        * Referenced by: '<S29>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_o;   /* Expression: uint8(0)
                                        * Referenced by: '<S29>/SwitchControl'
                                        */
  uint8_T Constant_Value_k;            /* Expression: uint8(1)
                                        * Referenced by: '<S56>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_p;   /* Expression: uint8(1)
                                        * Referenced by: '<S56>/SwitchControl'
                                        */
  boolean_T IntegerDelay1_InitialConditio_i;/* Computed Parameter: IntegerDelay1_InitialConditio_i
                                             * Referenced by: '<S8>/Integer Delay1'
                                             */
  boolean_T Memory_X0;                 /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S108>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S108>/Logic'
                                        */
  boolean_T IntegerDelay1_InitialConditi_lf;/* Computed Parameter: IntegerDelay1_InitialConditi_lf
                                             * Referenced by: '<S31>/Integer Delay1'
                                             */
  boolean_T IntegerDelay2_InitialConditio_m;/* Computed Parameter: IntegerDelay2_InitialConditio_m
                                             * Referenced by: '<S2>/Integer Delay2'
                                             */
  boolean_T IntegerDelay_InitialCondition_b;/* Computed Parameter: IntegerDelay_InitialCondition_b
                                             * Referenced by: '<S2>/Integer Delay'
                                             */
  boolean_T Memory_X0_a;               /* Computed Parameter: Memory_X0_a
                                        * Referenced by: '<S43>/Memory'
                                        */
  boolean_T Logic_table_g[16];         /* Computed Parameter: Logic_table_g
                                        * Referenced by: '<S43>/Logic'
                                        */
  boolean_T IntegerDelay1_InitialConditio_k;/* Computed Parameter: IntegerDelay1_InitialConditio_k
                                             * Referenced by: '<S38>/Integer Delay1'
                                             */
};

/* Real-time Model Data Structure */
struct RT_MODEL_singledof_demo {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;

  /*
   * NonInlinedSFcns:
   * The following substructure contains information regarding
   * non-inlined s-functions used in the model.
   */
  struct {
    RTWSfcnInfo sfcnInfo;
    time_T *taskTimePtrs[2];
    SimStruct childSFunctions[9];
    SimStruct *childSFunctionPtrs[9];
    struct _ssBlkInfo2 blkInfo2[9];
    struct _ssSFcnModelMethods2 methods2[9];
    struct _ssSFcnModelMethods3 methods3[9];
    struct _ssStatesInfo2 statesInfo2[9];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[1];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn8;
  } NonInlinedSFcns;

  /*
   * ModelData:
   * The following substructure contains information regarding
   * the data used in the model.
   */
  struct {
    void *blockIO;
    const void *constBlockIO;
    real_T *defaultParam;
    ZCSigState *prevZCSigState;
    real_T *contStates;
    real_T *derivs;
    real_T *zcSignalValues;
    void *inputs;
    void *outputs;
    boolean_T *contStateDisabled;
    boolean_T zCCacheNeedsReset;
    boolean_T derivCacheNeedsReset;
    boolean_T blkStateChange;
  } ModelData;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;

  /*
   * Work:
   * The following substructure contains information regarding
   * the work vectors in the model.
   */
  struct {
    void *dwork;
  } Work;
};

/* Block parameters (auto storage) */
extern Parameters_singledof_demo singledof_demo_P;

/* Block signals (auto storage) */
extern BlockIO_singledof_demo singledof_demo_B;

/* Block states (auto storage) */
extern D_Work_singledof_demo singledof_demo_DWork;

/* Model entry point functions */
extern void singledof_demo_initialize(boolean_T firstTime);
extern void singledof_demo_output(int_T tid);
extern void singledof_demo_update(int_T tid);
extern void singledof_demo_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_singledof_demo *const singledof_demo_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'singledof_demo'
 * '<S1>'   : 'singledof_demo/4channel (direct) OK'
 * '<S2>'   : 'singledof_demo/AI DI'
 * '<S3>'   : 'singledof_demo/AO DO'
 * '<S4>'   : 'singledof_demo/Initialize'
 * '<S5>'   : 'singledof_demo/Manual Switch3'
 * '<S6>'   : 'singledof_demo/Pos-force'
 * '<S7>'   : 'singledof_demo/Pos-pos'
 * '<S8>'   : 'singledof_demo/STOP'
 * '<S9>'   : 'singledof_demo/Scopes'
 * '<S10>'  : 'singledof_demo/Settings'
 * '<S11>'  : 'singledof_demo/selectOutput'
 * '<S12>'  : 'singledof_demo/4channel (direct) OK/PD controller master'
 * '<S13>'  : 'singledof_demo/4channel (direct) OK/PD controller slave'
 * '<S14>'  : 'singledof_demo/4channel (direct) OK/PD controller master/Discrete Derivative'
 * '<S15>'  : 'singledof_demo/4channel (direct) OK/PD controller master/Lowpass1'
 * '<S16>'  : 'singledof_demo/4channel (direct) OK/PD controller master/Lowpass1/lowpass'
 * '<S17>'  : 'singledof_demo/4channel (direct) OK/PD controller slave/Discrete Derivative'
 * '<S18>'  : 'singledof_demo/4channel (direct) OK/PD controller slave/Lowpass1'
 * '<S19>'  : 'singledof_demo/4channel (direct) OK/PD controller slave/Lowpass1/lowpass'
 * '<S20>'  : 'singledof_demo/AI DI/EL1008 Din'
 * '<S21>'  : 'singledof_demo/AI DI/EL3102master ADC'
 * '<S22>'  : 'singledof_demo/AI DI/EL3102slave ADC'
 * '<S23>'  : 'singledof_demo/AI DI/Lowpass1'
 * '<S24>'  : 'singledof_demo/AI DI/Lowpass2'
 * '<S25>'  : 'singledof_demo/AI DI/Lowpass3'
 * '<S26>'  : 'singledof_demo/AI DI/Lowpass4'
 * '<S27>'  : 'singledof_demo/AI DI/Manual Switch1'
 * '<S28>'  : 'singledof_demo/AI DI/Manual Switch2'
 * '<S29>'  : 'singledof_demo/AI DI/Manual Switch3'
 * '<S30>'  : 'singledof_demo/AI DI/Manual Switch5'
 * '<S31>'  : 'singledof_demo/AI DI/STOP'
 * '<S32>'  : 'singledof_demo/AI DI/compensateShunt_m'
 * '<S33>'  : 'singledof_demo/AI DI/compensateShunt_s'
 * '<S34>'  : 'singledof_demo/AI DI/enc_master'
 * '<S35>'  : 'singledof_demo/AI DI/enc_slave'
 * '<S36>'  : 'singledof_demo/AI DI/find_zero_during_init_m'
 * '<S37>'  : 'singledof_demo/AI DI/find_zero_during_init_s'
 * '<S38>'  : 'singledof_demo/AI DI/safety block'
 * '<S39>'  : 'singledof_demo/AI DI/Lowpass1/lowpass'
 * '<S40>'  : 'singledof_demo/AI DI/Lowpass2/lowpass'
 * '<S41>'  : 'singledof_demo/AI DI/Lowpass3/lowpass'
 * '<S42>'  : 'singledof_demo/AI DI/Lowpass4/lowpass'
 * '<S43>'  : 'singledof_demo/AI DI/STOP/S-R Flip-Flop'
 * '<S44>'  : 'singledof_demo/AI DI/enc_master/EL5101 Encoder'
 * '<S45>'  : 'singledof_demo/AI DI/enc_master/EL5101 Latch'
 * '<S46>'  : 'singledof_demo/AI DI/enc_slave/EL5101 Encoder'
 * '<S47>'  : 'singledof_demo/AI DI/enc_slave/EL5101 Latch'
 * '<S48>'  : 'singledof_demo/AI DI/find_zero_during_init_m/moving avg'
 * '<S49>'  : 'singledof_demo/AI DI/find_zero_during_init_s/moving avg'
 * '<S50>'  : 'singledof_demo/AI DI/safety block/S-R Flip-Flop'
 * '<S51>'  : 'singledof_demo/AO DO/EL2008 DigitalOut'
 * '<S52>'  : 'singledof_demo/AO DO/EL4038 AnalogOut'
 * '<S53>'  : 'singledof_demo/AO DO/FricComp_m'
 * '<S54>'  : 'singledof_demo/AO DO/FricComp_s'
 * '<S55>'  : 'singledof_demo/AO DO/LED'
 * '<S56>'  : 'singledof_demo/AO DO/Manual Switch1'
 * '<S57>'  : 'singledof_demo/AO DO/extraSafety'
 * '<S58>'  : 'singledof_demo/AO DO/FricComp_m/Compare To Constant'
 * '<S59>'  : 'singledof_demo/AO DO/FricComp_m/Compare To Constant1'
 * '<S60>'  : 'singledof_demo/AO DO/FricComp_s/Compare To Constant'
 * '<S61>'  : 'singledof_demo/AO DO/FricComp_s/Compare To Constant1'
 * '<S62>'  : 'singledof_demo/AO DO/extraSafety/Compare To Constant'
 * '<S63>'  : 'singledof_demo/AO DO/extraSafety/Compare To Constant1'
 * '<S64>'  : 'singledof_demo/Initialize/Compare To Constant'
 * '<S65>'  : 'singledof_demo/Initialize/Manual Switch'
 * '<S66>'  : 'singledof_demo/Initialize/Unit Delay External IC'
 * '<S67>'  : 'singledof_demo/Initialize/initialize_um'
 * '<S68>'  : 'singledof_demo/Initialize/initialize_us'
 * '<S69>'  : 'singledof_demo/Initialize/initialize_um/Compare To Constant'
 * '<S70>'  : 'singledof_demo/Initialize/initialize_um/Compare To Constant1'
 * '<S71>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init'
 * '<S72>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init/D'
 * '<S73>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init/Discrete Derivative'
 * '<S74>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init/I'
 * '<S75>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init/Lowpass3'
 * '<S76>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init/P'
 * '<S77>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init/anti windup'
 * '<S78>'  : 'singledof_demo/Initialize/initialize_um/contr_m_init/Lowpass3/lowpass'
 * '<S79>'  : 'singledof_demo/Initialize/initialize_us/Compare To Constant'
 * '<S80>'  : 'singledof_demo/Initialize/initialize_us/Compare To Constant1'
 * '<S81>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init'
 * '<S82>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init/D'
 * '<S83>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init/Discrete Derivative'
 * '<S84>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init/I'
 * '<S85>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init/Lowpass3'
 * '<S86>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init/P'
 * '<S87>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init/anti windup'
 * '<S88>'  : 'singledof_demo/Initialize/initialize_us/contr_s_init/Lowpass3/lowpass'
 * '<S89>'  : 'singledof_demo/Pos-force/contr_s'
 * '<S90>'  : 'singledof_demo/Pos-force/master to slave'
 * '<S91>'  : 'singledof_demo/Pos-force/slave to master'
 * '<S92>'  : 'singledof_demo/Pos-force/contr_s/Discrete Derivative'
 * '<S93>'  : 'singledof_demo/Pos-force/contr_s/Lowpass1'
 * '<S94>'  : 'singledof_demo/Pos-force/contr_s/anti windup'
 * '<S95>'  : 'singledof_demo/Pos-force/contr_s/Lowpass1/lowpass'
 * '<S96>'  : 'singledof_demo/Pos-pos/contr_m'
 * '<S97>'  : 'singledof_demo/Pos-pos/contr_s'
 * '<S98>'  : 'singledof_demo/Pos-pos/master to slave'
 * '<S99>'  : 'singledof_demo/Pos-pos/slave to master'
 * '<S100>' : 'singledof_demo/Pos-pos/contr_m/Discrete Derivative'
 * '<S101>' : 'singledof_demo/Pos-pos/contr_m/Lowpass1'
 * '<S102>' : 'singledof_demo/Pos-pos/contr_m/anti windup'
 * '<S103>' : 'singledof_demo/Pos-pos/contr_m/Lowpass1/lowpass'
 * '<S104>' : 'singledof_demo/Pos-pos/contr_s/Discrete Derivative'
 * '<S105>' : 'singledof_demo/Pos-pos/contr_s/Lowpass1'
 * '<S106>' : 'singledof_demo/Pos-pos/contr_s/anti windup'
 * '<S107>' : 'singledof_demo/Pos-pos/contr_s/Lowpass1/lowpass'
 * '<S108>' : 'singledof_demo/STOP/S-R Flip-Flop'
 */
#endif                                 /* RTW_HEADER_singledof_demo_h_ */
