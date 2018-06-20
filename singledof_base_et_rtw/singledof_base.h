/*
 * singledof_base.h
 *
 * Code generation for model "singledof_base.mdl".
 *
 * Model version              : 1.264
 * Simulink Coder version : 8.1 (R2011b) 08-Jul-2011
 * C source code generated on : Tue Jun 19 15:46:07 2018
 *
 * Target selection: ectarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_singledof_base_h_
#define RTW_HEADER_singledof_base_h_
#ifndef singledof_base_COMMON_INCLUDES_
# define singledof_base_COMMON_INCLUDES_
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
#include "rt_sfcn_helper.h"
#endif                                 /* singledof_base_COMMON_INCLUDES_ */

#include "singledof_base_types.h"

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
#define singledof_base_rtModel         RT_MODEL_singledof_base

/* Block signals for system '<S18>/lowpass' */
typedef struct {
  real_T out;                          /* '<S18>/lowpass' */
} rtB_lowpass_singledof_base;

/* Block states (auto storage) for system '<S18>/lowpass' */
typedef struct {
  real_T out_prev;                     /* '<S18>/lowpass' */
  int32_T sfEvent;                     /* '<S18>/lowpass' */
  uint8_T is_active_c13_singledof_base;/* '<S18>/lowpass' */
  boolean_T isStable;                  /* '<S18>/lowpass' */
  boolean_T doneDoubleBufferReInit;    /* '<S18>/lowpass' */
  boolean_T out_prev_not_empty;        /* '<S18>/lowpass' */
} rtDW_lowpass_singledof_base;

/* Block signals for system '<S19>/lowpass' */
typedef struct {
  real_T out;                          /* '<S19>/lowpass' */
} rtB_lowpass_singledof_base_i;

/* Block states (auto storage) for system '<S19>/lowpass' */
typedef struct {
  real_T out_prev;                     /* '<S19>/lowpass' */
  int32_T sfEvent;                     /* '<S19>/lowpass' */
  uint8_T is_active_c2_singledof_base; /* '<S19>/lowpass' */
  boolean_T isStable;                  /* '<S19>/lowpass' */
  boolean_T doneDoubleBufferReInit;    /* '<S19>/lowpass' */
  boolean_T out_prev_not_empty;        /* '<S19>/lowpass' */
} rtDW_lowpass_singledof_base_e;

/* Block signals for system '<S86>/lowpass' */
typedef struct {
  real_T out;                          /* '<S86>/lowpass' */
} rtB_lowpass_singledof_base_b;

/* Block states (auto storage) for system '<S86>/lowpass' */
typedef struct {
  real_T out_prev;                     /* '<S86>/lowpass' */
  int32_T sfEvent;                     /* '<S86>/lowpass' */
  uint8_T is_active_c21_singledof_base;/* '<S86>/lowpass' */
  boolean_T isStable;                  /* '<S86>/lowpass' */
  boolean_T doneDoubleBufferReInit;    /* '<S86>/lowpass' */
  boolean_T out_prev_not_empty;        /* '<S86>/lowpass' */
} rtDW_lowpass_singledof_base_c;

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T MultiportSwitch1;             /* '<S3>/Multiport Switch1' */
  real_T SwitchControl;                /* '<S60>/SwitchControl' */
  real_T ec_EL5101_enc;                /* '<S39>/ec_EL5101_enc' */
  real_T ec_EL5101_enc_h;              /* '<S41>/ec_EL5101_enc' */
  real_T SwitchControl_n[2];           /* '<S25>/SwitchControl' */
  real_T motorrevolutionsmaster[2];    /* '<S1>/Gain' */
  real_T positionofleverrad[2];        /* '<S1>/Gain6' */
  real_T IntegerDelay;                 /* '<S62>/Integer Delay' */
  real_T IntegerDelay1;                /* '<S62>/Integer Delay1' */
  real_T MultiportSwitch1_k;           /* '<S62>/Multiport Switch1' */
  real_T WeightedSampleTimeMath1;      /* '<S70>/Weighted Sample Time Math1' */
  real_T IntegerDelay2;                /* '<S63>/Integer Delay2' */
  real_T IntegerDelay1_h;              /* '<S63>/Integer Delay1' */
  real_T MultiportSwitch1_h;           /* '<S63>/Multiport Switch1' */
  real_T WeightedSampleTimeMath1_i;    /* '<S80>/Weighted Sample Time Math1' */
  real_T Derivative2;                  /* '<S1>/Derivative2' */
  real_T MultiportSwitch2;             /* '<S10>/Multiport Switch2' */
  real_T VirtualEnvironment_o2;        /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_o3;        /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_o4;        /* '<S11>/Virtual Environment' */
  real_T ec_EL1008_di[8];              /* '<S15>/ec_EL1008_di' */
  real_T WeightedSampleTimeMath1_a;    /* '<S106>/Weighted Sample Time Math1' */
  real_T DiscreteTimeIntegrator;       /* '<S98>/Discrete-Time Integrator' */
  real_T P2;                           /* '<S98>/P2' */
  real_T TSamp;                        /* '<S105>/TSamp' */
  real_T Diff;                         /* '<S105>/Diff' */
  real_T WeightedSampleTimeMath1_l;    /* '<S94>/Weighted Sample Time Math1' */
  real_T DiscreteTimeIntegrator_k;     /* '<S90>/Discrete-Time Integrator' */
  real_T P2_b;                         /* '<S90>/P2' */
  real_T TSamp_o;                      /* '<S93>/TSamp' */
  real_T Diff_o;                       /* '<S93>/Diff' */
  real_T WeightedSampleTimeMath1_h;    /* '<S88>/Weighted Sample Time Math1' */
  real_T Derivative;                   /* '<S1>/Derivative' */
  real_T Setpoint;                     /* '<S13>/Setpoint' */
  real_T WeightedSampleTimeMath1_p;    /* '<S102>/Weighted Sample Time Math1' */
  real_T DiscreteTimeIntegrator_ke;    /* '<S97>/Discrete-Time Integrator' */
  real_T P2_m;                         /* '<S97>/P2' */
  real_T TSamp_e;                      /* '<S101>/TSamp' */
  real_T Diff_b;                       /* '<S101>/Diff' */
  real_T WeightedSampleTimeMath1_c;    /* '<S86>/Weighted Sample Time Math1' */
  real_T P1;                           /* '<S84>/P1' */
  real_T Setpoint_a;                   /* '<S12>/Setpoint' */
  real_T Product1;                     /* '<S14>/Product1' */
  real_T ec_EL3102_adc[2];             /* '<S16>/ec_EL3102_adc' */
  real_T chachb;                       /* '<S1>/Add4' */
  real_T ec_EL3102_adc_d[2];           /* '<S17>/ec_EL3102_adc' */
  real_T chachb_n;                     /* '<S1>/Add5' */
  real_T SwitchControl_o;              /* '<S23>/SwitchControl' */
  real_T V;                            /* '<S1>/Add1' */
  real_T Divide4;                      /* '<S1>/Divide4' */
  real_T forcalibration;               /* '<S1>/Divide5' */
  real_T SwitchControl_f;              /* '<S22>/SwitchControl' */
  real_T V_m;                          /* '<S1>/Add2' */
  real_T Divide;                       /* '<S1>/Divide' */
  real_T Divide2;                      /* '<S1>/Divide2' */
  real_T WeightedSampleTimeMath1_j;    /* '<S19>/Weighted Sample Time Math1' */
  real_T TimeDelay1;                   /* '<S27>/TimeDelay1' */
  real_T ShuntDynPredicterPart1;       /* '<S27>/ShuntDynPredicter Part 1' */
  real_T TimeDelay2;                   /* '<S27>/TimeDelay2' */
  real_T DiscreteTransferFcn;          /* '<S27>/Discrete Transfer Fcn' */
  real_T Correctionfactor;             /* '<S27>/Correction factor' */
  real_T Add5;                         /* '<S27>/Add5' */
  real_T WeightedSampleTimeMath1_pt;   /* '<S21>/Weighted Sample Time Math1' */
  real_T TimeDelay1_n;                 /* '<S28>/TimeDelay1' */
  real_T TimeDelay2_a;                 /* '<S28>/TimeDelay2' */
  real_T DiscreteTransferFcn_i;        /* '<S28>/Discrete Transfer Fcn' */
  real_T Filtered;                     /* '<S28>/Add5' */
  real_T IntegerDelay_o;               /* '<S31>/Integer Delay' */
  real_T xi1;                          /* '<S43>/Integer Delay2' */
  real_T Add1;                         /* '<S43>/Add1' */
  real_T i;                            /* '<S43>/Multiport Switch2' */
  real_T xi;                           /* '<S43>/Product1' */
  real_T MultiportSwitch2_c;           /* '<S31>/Multiport Switch2' */
  real_T IntegerDelay_f;               /* '<S32>/Integer Delay' */
  real_T xi1_l;                        /* '<S44>/Integer Delay1' */
  real_T Add1_c;                       /* '<S44>/Add1' */
  real_T i_p;                          /* '<S44>/Multiport Switch2' */
  real_T xi_d;                         /* '<S44>/Product1' */
  real_T MultiportSwitch2_f;           /* '<S32>/Multiport Switch2' */
  real_T WeightedSampleTimeMath1_f;    /* '<S20>/Weighted Sample Time Math1' */
  real_T WeightedSampleTimeMath1_fi;   /* '<S18>/Weighted Sample Time Math1' */
  real_T ec_EL5101_enc_p;              /* '<S40>/ec_EL5101_enc' */
  real_T Add1_i;                       /* '<S29>/Add1' */
  real_T ec_EL5101_enc_d;              /* '<S42>/ec_EL5101_enc' */
  real_T Add1_a;                       /* '<S30>/Add1' */
  real_T DiscreteTimeIntegrator_d;     /* '<S1>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1;      /* '<S1>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2;      /* '<S1>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator3;      /* '<S1>/Discrete-Time Integrator3' */
  real_T Gain;                         /* '<S2>/Gain' */
  real_T Abs1[4];                      /* '<S48>/Abs1' */
  real_T Gain_m;                       /* '<S48>/Gain' */
  real_T uMotorV;                      /* '<S2>/Add1' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  real_T Abs1_l[4];                    /* '<S49>/Abs1' */
  real_T Gain_h;                       /* '<S49>/Gain' */
  real_T uMotorV_k;                    /* '<S2>/Add2' */
  real_T SwitchControl_c[4];           /* '<S51>/SwitchControl' */
  real_T MultiportSwitch;              /* '<S95>/Multiport Switch' */
  real_T UnitDelay1;                   /* '<S91>/Unit Delay1' */
  real_T MultiportSwitch4;             /* '<S91>/Multiport Switch4' */
  real_T UnitDelay1_p;                 /* '<S92>/Unit Delay1' */
  real_T MultiportSwitch4_j;           /* '<S92>/Multiport Switch4' */
  real_T MultiportSwitch_d;            /* '<S103>/Multiport Switch' */
  real_T MultiportSwitch_l;            /* '<S107>/Multiport Switch' */
  real_T UnitDelay1_j;                 /* '<S99>/Unit Delay1' */
  real_T MultiportSwitch4_b;           /* '<S99>/Multiport Switch4' */
  real_T UnitDelay1_m;                 /* '<S100>/Unit Delay1' */
  real_T MultiportSwitch4_jo;          /* '<S100>/Multiport Switch4' */
  real_T Gain3;                        /* '<S9>/Gain3' */
  real_T Gain2;                        /* '<S9>/Gain2' */
  real_T VirtualEnvironment_o1;        /* '<S11>/Virtual Environment' */
  boolean_T DataTypeConversion1;       /* '<S8>/Data Type Conversion1' */
  boolean_T Logic[2];                  /* '<S109>/Logic' */
  boolean_T IntegerDelay2_a;           /* '<S1>/Integer Delay2' */
  boolean_T IntegerDelay_d;            /* '<S1>/Integer Delay' */
  boolean_T LogicalOperator;           /* '<S1>/Logical Operator' */
  boolean_T DataTypeConversion1_b;     /* '<S26>/Data Type Conversion1' */
  boolean_T DataTypeConversion;        /* '<S26>/Data Type Conversion' */
  boolean_T Memory;                    /* '<S38>/Memory' */
  boolean_T Logic_k[2];                /* '<S38>/Logic' */
  boolean_T LogicalOperator1;          /* '<S10>/Logical Operator1' */
  boolean_T LogicalOperator3;          /* '<S10>/Logical Operator3' */
  boolean_T LogicalOperator5;          /* '<S33>/Logical Operator5' */
  boolean_T LogicalOperator_a;         /* '<S52>/Logical Operator' */
  rtB_lowpass_singledof_base_i sf_lowpass_m;/* '<S106>/lowpass' */
  rtB_lowpass_singledof_base_i sf_lowpass_bv;/* '<S102>/lowpass' */
  rtB_lowpass_singledof_base_i sf_lowpass_lk;/* '<S94>/lowpass' */
  rtB_lowpass_singledof_base_b sf_lowpass_b;/* '<S88>/lowpass' */
  rtB_lowpass_singledof_base_b sf_lowpass_g;/* '<S86>/lowpass' */
  rtB_lowpass_singledof_base_i sf_lowpass_l;/* '<S80>/lowpass' */
  rtB_lowpass_singledof_base_i sf_lowpass;/* '<S70>/lowpass' */
  rtB_lowpass_singledof_base sf_lowpass_k;/* '<S21>/lowpass' */
  rtB_lowpass_singledof_base sf_lowpass_h;/* '<S20>/lowpass' */
  rtB_lowpass_singledof_base_i sf_lowpass_o;/* '<S19>/lowpass' */
  rtB_lowpass_singledof_base sf_lowpass_c;/* '<S18>/lowpass' */
} BlockIO_singledof_base;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T DiscreteTimeIntegrator_DSTATE;/* '<S62>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator_DSTATE_g;/* '<S63>/Discrete-Time Integrator' */
  real_T FixPtUnitDelay1_DSTATE;       /* '<S61>/FixPt Unit Delay1' */
  real_T UnitDelay2_DSTATE;            /* '<S3>/Unit Delay2' */
  real_T DiscreteTimeIntegrator_DSTATE_b;/* '<S3>/Discrete-Time Integrator' */
  real_T IntegerDelay_DSTATE;          /* '<S62>/Integer Delay' */
  real_T IntegerDelay1_DSTATE;         /* '<S62>/Integer Delay1' */
  real_T IntegerDelay2_DSTATE;         /* '<S63>/Integer Delay2' */
  real_T IntegerDelay1_DSTATE_h;       /* '<S63>/Integer Delay1' */
  real_T DiscreteTimeIntegrator_DSTAT_bo;/* '<S98>/Discrete-Time Integrator' */
  real_T UD_DSTATE;                    /* '<S105>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_e;/* '<S90>/Discrete-Time Integrator' */
  real_T UD_DSTATE_c;                  /* '<S93>/UD' */
  real_T DiscreteTimeIntegrator_DSTATE_d;/* '<S97>/Discrete-Time Integrator' */
  real_T UD_DSTATE_a;                  /* '<S101>/UD' */
  real_T IntegerDelay1_DSTATE_p;       /* '<S32>/Integer Delay1' */
  real_T IntegerDelay1_DSTATE_e;       /* '<S31>/Integer Delay1' */
  real_T ShuntDynPredicterPart1_DSTATE[7];/* '<S27>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_DSTATE;   /* '<S27>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_DSTATE[7];/* '<S27>/ShuntDynPredicter Part 2' */
  real_T ShuntDynPredicterPart1_DSTATE_m[7];/* '<S28>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_DSTATE_l; /* '<S28>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_DSTATE_e[7];/* '<S28>/ShuntDynPredicter Part 2' */
  real_T IntegerDelay_DSTATE_h;        /* '<S31>/Integer Delay' */
  real_T IntegerDelay2_DSTATE_m;       /* '<S43>/Integer Delay2' */
  real_T IntegerDelay_DSTATE_g;        /* '<S43>/Integer Delay' */
  real_T IntegerDelay_DSTATE_m;        /* '<S32>/Integer Delay' */
  real_T IntegerDelay1_DSTATE_l;       /* '<S44>/Integer Delay1' */
  real_T IntegerDelay_DSTATE_hp;       /* '<S44>/Integer Delay' */
  real_T DiscreteTimeIntegrator_DSTATE_f;/* '<S1>/Discrete-Time Integrator' */
  real_T DiscreteTimeIntegrator1_DSTATE;/* '<S1>/Discrete-Time Integrator1' */
  real_T DiscreteTimeIntegrator2_DSTATE;/* '<S1>/Discrete-Time Integrator2' */
  real_T DiscreteTimeIntegrator3_DSTATE;/* '<S1>/Discrete-Time Integrator3' */
  real_T UnitDelay1_DSTATE;            /* '<S91>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_d;          /* '<S92>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_p;          /* '<S99>/Unit Delay1' */
  real_T UnitDelay1_DSTATE_p5;         /* '<S100>/Unit Delay1' */
  real_T VirtualEnvironment_DWORK0;    /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_DWORK1;    /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_DWORK2;    /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_DWORK3;    /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_DWORK4;    /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_DWORK5;    /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_DWORK6[5]; /* '<S11>/Virtual Environment' */
  real_T VirtualEnvironment_DWORK7[5]; /* '<S11>/Virtual Environment' */
  real_T ShuntDynPredicterPart1_tmp;   /* '<S27>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_tmp;      /* '<S27>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_tmp;   /* '<S27>/ShuntDynPredicter Part 2' */
  real_T ShuntDynPredicterPart1_tmp_b; /* '<S28>/ShuntDynPredicter Part 1' */
  real_T DiscreteTransferFcn_tmp_m;    /* '<S28>/Discrete Transfer Fcn' */
  real_T ShuntDynPredicterPart2_tmp_e; /* '<S28>/ShuntDynPredicter Part 2' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative2_RWORK;                 /* '<S1>/Derivative2' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK;                  /* '<S99>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_k;                /* '<S91>/TimeDelay1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative_RWORK;                  /* '<S1>/Derivative' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_m;                /* '<S100>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_p;                /* '<S92>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_c;                /* '<S27>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay2_RWORK;                  /* '<S27>/TimeDelay2' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay1_RWORK_a;                /* '<S28>/TimeDelay1' */

  struct {
    real_T modelTStart;
    real_T TUbufferArea[4000];
  } TimeDelay2_RWORK_n;                /* '<S28>/TimeDelay2' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK;                  /* '<S99>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_j;                /* '<S91>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_p;                /* '<S100>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_e;                /* '<S92>/TimeDelay1' */

  struct {
    void *LoggedData;
  } ADC_master_PWORK;                  /* '<S1>/ADC_master' */

  struct {
    void *LoggedData;
  } ADC_slave_PWORK;                   /* '<S1>/ADC_slave' */

  struct {
    void *LoggedData;
  } forces_PWORK;                      /* '<S1>/forces' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_jg;               /* '<S27>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay2_PWORK;                  /* '<S27>/TimeDelay2' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay1_PWORK_f;                /* '<S28>/TimeDelay1' */

  struct {
    void *TUbufferPtrs[2];
  } TimeDelay2_PWORK_k;                /* '<S28>/TimeDelay2' */

  struct {
    void *LoggedData;
  } ForceSensor_actuatorTorque_comp;   /* '<S27>/ForceSensor_actuatorTorque_comparison' */

  struct {
    void *LoggedData;
  } veloc_PWORK;                       /* '<S1>/veloc' */

  struct {
    void *LoggedData;
  } Din_PWORK;                         /* '<S1>/Din' */

  struct {
    void *LoggedData;
  } Scope_PWORK;                       /* '<S9>/Scope' */

  uint32_T VirtualEnvironment_DWORK8;  /* '<S11>/Virtual Environment' */
  uint32_T VirtualEnvironment_DWORK9[625];/* '<S11>/Virtual Environment' */
  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK;                  /* '<S99>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_a;                /* '<S91>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_f;                /* '<S100>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_o;                /* '<S92>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_p;                /* '<S27>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay2_IWORK;                  /* '<S27>/TimeDelay2' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay1_IWORK_c;                /* '<S28>/TimeDelay1' */

  struct {
    int_T Tail;
    int_T Head;
    int_T Last;
    int_T CircularBufSize;
  } TimeDelay2_IWORK_j;                /* '<S28>/TimeDelay2' */

  uint8_T FixPtUnitDelay2_DSTATE;      /* '<S61>/FixPt Unit Delay2' */
  boolean_T IntegerDelay1_DSTATE_a[10];/* '<S8>/Integer Delay1' */
  boolean_T IntegerDelay2_DSTATE_a[2]; /* '<S1>/Integer Delay2' */
  boolean_T IntegerDelay_DSTATE_f;     /* '<S1>/Integer Delay' */
  boolean_T IntegerDelay1_DSTATE_i[10];/* '<S26>/Integer Delay1' */
  boolean_T IntegerDelay1_DSTATE_b[10];/* '<S33>/Integer Delay1' */
  uint8_T VirtualEnvironment_DWORK10;  /* '<S11>/Virtual Environment' */
  boolean_T Memory_PreviousInput;      /* '<S109>/Memory' */
  boolean_T VirtualEnvironment_DWORK11;/* '<S11>/Virtual Environment' */
  boolean_T VirtualEnvironment_DWORK12;/* '<S11>/Virtual Environment' */
  boolean_T VirtualEnvironment_DWORK13;/* '<S11>/Virtual Environment' */
  boolean_T Memory_PreviousInput_c;    /* '<S38>/Memory' */
  rtDW_lowpass_singledof_base_e sf_lowpass_m;/* '<S106>/lowpass' */
  rtDW_lowpass_singledof_base_e sf_lowpass_bv;/* '<S102>/lowpass' */
  rtDW_lowpass_singledof_base_e sf_lowpass_lk;/* '<S94>/lowpass' */
  rtDW_lowpass_singledof_base_c sf_lowpass_b;/* '<S88>/lowpass' */
  rtDW_lowpass_singledof_base_c sf_lowpass_g;/* '<S86>/lowpass' */
  rtDW_lowpass_singledof_base_e sf_lowpass_l;/* '<S80>/lowpass' */
  rtDW_lowpass_singledof_base_e sf_lowpass;/* '<S70>/lowpass' */
  rtDW_lowpass_singledof_base sf_lowpass_k;/* '<S21>/lowpass' */
  rtDW_lowpass_singledof_base sf_lowpass_h;/* '<S20>/lowpass' */
  rtDW_lowpass_singledof_base_e sf_lowpass_o;/* '<S19>/lowpass' */
  rtDW_lowpass_singledof_base sf_lowpass_c;/* '<S18>/lowpass' */
} D_Work_singledof_base;

/* Backward compatible GRT Identifiers */
#define rtB                            singledof_base_B
#define BlockIO                        BlockIO_singledof_base
#define rtXdot                         singledof_base_Xdot
#define StateDerivatives               StateDerivatives_singledof_base
#define tXdis                          singledof_base_Xdis
#define StateDisabled                  StateDisabled_singledof_base
#define rtP                            singledof_base_P
#define Parameters                     Parameters_singledof_base
#define rtDWork                        singledof_base_DWork
#define D_Work                         D_Work_singledof_base

/* Parameters (auto storage) */
struct Parameters_singledof_base_ {
  real_T Constant2_Value;              /* Expression: -0.86
                                        * Referenced by: '<S1>/Constant2'
                                        */
  real_T Constant1_Value;              /* Expression: 1.042
                                        * Referenced by: '<S1>/Constant1'
                                        */
  real_T Constant5_Value[2];           /* Expression: [-8E3 -17E3]
                                        * Referenced by: '<S1>/Constant5'
                                        */
  real_T Constant4_Value[2];           /* Expression: [0 0]
                                        * Referenced by: '<S1>/Constant4'
                                        */
  real_T Gain2_Gain;                   /* Expression: .5
                                        * Referenced by: '<S48>/Gain2'
                                        */
  real_T Gain1_Gain;                   /* Expression: .5
                                        * Referenced by: '<S48>/Gain1'
                                        */
  real_T Gain2_Gain_c;                 /* Expression: .5
                                        * Referenced by: '<S49>/Gain2'
                                        */
  real_T Gain1_Gain_h;                 /* Expression: .5
                                        * Referenced by: '<S49>/Gain1'
                                        */
  real_T Constant15_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant15'
                                        */
  real_T Constant16_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant16'
                                        */
  real_T Constant17_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant17'
                                        */
  real_T Constant18_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant18'
                                        */
  real_T yes_Value;                    /* Expression: 1
                                        * Referenced by: '<S3>/yes'
                                        */
  real_T yes1_Value;                   /* Expression: 1
                                        * Referenced by: '<S3>/yes1'
                                        */
  real_T Constant1_Value_f;            /* Expression: 1
                                        * Referenced by: '<Root>/Constant1'
                                        */
  real_T Constant6_Value;              /* Expression: 0
                                        * Referenced by: '<Root>/Constant6'
                                        */
  real_T P1_Gain;                      /* Expression: Is
                                        * Referenced by: '<S90>/P1'
                                        */
  real_T Gain1_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S6>/Gain1'
                                        */
  real_T P1_Gain_h;                    /* Expression: Im
                                        * Referenced by: '<S97>/P1'
                                        */
  real_T P1_Gain_c;                    /* Expression: Is
                                        * Referenced by: '<S98>/P1'
                                        */
  real_T setting_Value;                /* Expression: mode
                                        * Referenced by: '<S10>/setting'
                                        */
  real_T setting4_Value;               /* Expression: 1
                                        * Referenced by: '<S10>/setting4'
                                        */
  real_T P2_Gain;                      /* Expression: 20
                                        * Referenced by: '<S84>/P2'
                                        */
  real_T Saturation_UpperSat;          /* Expression: maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation'
                                        */
  real_T Gain3_Gain;                   /* Expression: 0
                                        * Referenced by: '<S6>/Gain3'
                                        */
  real_T P1_Gain_hq;                   /* Expression: 0.25
                                        * Referenced by: '<S85>/P1'
                                        */
  real_T P2_Gain_a;                    /* Expression: 5
                                        * Referenced by: '<S85>/P2'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: -maxTorque_allowed
                                        * Referenced by: '<S5>/Saturation1'
                                        */
  real_T on2_Value;                    /* Expression: 0
                                        * Referenced by: '<S8>/on2'
                                        */
  real_T DiscreteTimeIntegrator_gainval;/* Computed Parameter: DiscreteTimeIntegrator_gainval
                                         * Referenced by: '<S62>/Discrete-Time Integrator'
                                         */
  real_T DiscreteTimeIntegrator_IC;    /* Expression: 0
                                        * Referenced by: '<S62>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value;               /* Expression: const
                                        * Referenced by: '<S65>/Constant'
                                        */
  real_T DiscreteTimeIntegrator_gainva_f;/* Computed Parameter: DiscreteTimeIntegrator_gainva_f
                                          * Referenced by: '<S63>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_h;  /* Expression: 0
                                        * Referenced by: '<S63>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_k;             /* Expression: const
                                        * Referenced by: '<S75>/Constant'
                                        */
  real_T ShutdownSim_Value;            /* Expression: 224
                                        * Referenced by: '<S3>/ShutdownSim'
                                        */
  real_T FixPtUnitDelay1_X0;           /* Expression: 0.0
                                        * Referenced by: '<S61>/FixPt Unit Delay1'
                                        */
  real_T UnitDelay2_X0;                /* Expression: 0
                                        * Referenced by: '<S3>/Unit Delay2'
                                        */
  real_T DiscreteTimeIntegrator_gainva_a;/* Computed Parameter: DiscreteTimeIntegrator_gainva_a
                                          * Referenced by: '<S3>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_e;  /* Expression: 0
                                        * Referenced by: '<S3>/Discrete-Time Integrator'
                                        */
  real_T Constant_Value_f;             /* Expression: const
                                        * Referenced by: '<S59>/Constant'
                                        */
  real_T ec_EL5101_enc_P1_Size[2];     /* Computed Parameter: ec_EL5101_enc_P1_Size
                                        * Referenced by: '<S39>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1;             /* Expression: link_id
                                        * Referenced by: '<S39>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_Size_i[2];   /* Computed Parameter: ec_EL5101_enc_P1_Size_i
                                        * Referenced by: '<S41>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_c;           /* Expression: link_id
                                        * Referenced by: '<S41>/ec_EL5101_enc'
                                        */
  real_T Gain1_Gain_o;                 /* Expression: -1
                                        * Referenced by: '<S1>/Gain1'
                                        */
  real_T Gain_Gain;                    /* Expression: 1/(7500*4)
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T Gain6_Gain;                   /* Expression: 1/10*2*pi
                                        * Referenced by: '<S1>/Gain6'
                                        */
  real_T IntegerDelay_InitialCondition;/* Expression: 0.0
                                        * Referenced by: '<S62>/Integer Delay'
                                        */
  real_T Constant_Value_g;             /* Expression: const
                                        * Referenced by: '<S64>/Constant'
                                        */
  real_T Constant1_Value_l;            /* Expression: 1
                                        * Referenced by: '<S62>/Constant1'
                                        */
  real_T Constant4_Value_d;            /* Expression: .01
                                        * Referenced by: '<S62>/Constant4'
                                        */
  real_T IntegerDelay1_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S62>/Integer Delay1'
                                         */
  real_T Constant_Value_j;             /* Expression: -.3
                                        * Referenced by: '<S62>/Constant'
                                        */
  real_T SliderGain_Gain;              /* Expression: gain
                                        * Referenced by: '<S67>/Slider Gain'
                                        */
  real_T Constant1_Value_p;            /* Expression: 1
                                        * Referenced by: '<S70>/Constant1'
                                        */
  real_T CutofffreqHz_Value;           /* Expression: cf
                                        * Referenced by: '<S70>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt; /* Computed Parameter: WeightedSampleTimeMath1_WtEt
                                        * Referenced by: '<S70>/Weighted Sample Time Math1'
                                        */
  real_T IntegerDelay2_InitialCondition;/* Expression: 0.0
                                         * Referenced by: '<S63>/Integer Delay2'
                                         */
  real_T Constant_Value_jo;            /* Expression: const
                                        * Referenced by: '<S74>/Constant'
                                        */
  real_T Constant1_Value_h;            /* Expression: 1
                                        * Referenced by: '<S63>/Constant1'
                                        */
  real_T Constant4_Value_f;            /* Expression: .01
                                        * Referenced by: '<S63>/Constant4'
                                        */
  real_T IntegerDelay1_InitialConditio_j;/* Expression: 0.0
                                          * Referenced by: '<S63>/Integer Delay1'
                                          */
  real_T Constant_Value_n;             /* Expression: -.3
                                        * Referenced by: '<S63>/Constant'
                                        */
  real_T SliderGain_Gain_n;            /* Expression: gain
                                        * Referenced by: '<S77>/Slider Gain'
                                        */
  real_T Constant1_Value_e;            /* Expression: 1
                                        * Referenced by: '<S80>/Constant1'
                                        */
  real_T CutofffreqHz_Value_j;         /* Expression: cf
                                        * Referenced by: '<S80>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_e;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_e
                                         * Referenced by: '<S80>/Weighted Sample Time Math1'
                                         */
  real_T Constant6_Value_p;            /* Expression: 0
                                        * Referenced by: '<S1>/Constant6'
                                        */
  real_T on_Value;                     /* Expression: .01
                                        * Referenced by: '<S1>/on'
                                        */
  real_T Constant9_Value;              /* Expression: 0
                                        * Referenced by: '<S1>/Constant9'
                                        */
  real_T ec_EL1008_di_P1_Size[2];      /* Computed Parameter: ec_EL1008_di_P1_Size
                                        * Referenced by: '<S15>/ec_EL1008_di'
                                        */
  real_T ec_EL1008_di_P1;              /* Expression: link_id
                                        * Referenced by: '<S15>/ec_EL1008_di'
                                        */
  real_T on2_Value_j;                  /* Expression: 0
                                        * Referenced by: '<S26>/on2'
                                        */
  real_T max_val_Value;                /* Expression: 0.5
                                        * Referenced by: '<S32>/max_val'
                                        */
  real_T max_val_Value_c;              /* Expression: 0.5
                                        * Referenced by: '<S31>/max_val'
                                        */
  real_T setting18_Value;              /* Expression: comm_delay
                                        * Referenced by: '<S10>/setting18'
                                        */
  real_T TimeDelay1_MaxDelay;          /* Expression: 1
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput;        /* Expression: 0
                                        * Referenced by: '<S99>/TimeDelay1'
                                        */
  real_T CutofffreqHz_Value_k;         /* Expression: cf
                                        * Referenced by: '<S106>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_k;            /* Expression: 1
                                        * Referenced by: '<S106>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_eg;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_eg
                                          * Referenced by: '<S106>/Weighted Sample Time Math1'
                                          */
  real_T P_Gain;                       /* Expression: Ps
                                        * Referenced by: '<S98>/P'
                                        */
  real_T DiscreteTimeIntegrator_gainva_i;/* Computed Parameter: DiscreteTimeIntegrator_gainva_i
                                          * Referenced by: '<S98>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_n;  /* Expression: 0
                                        * Referenced by: '<S98>/Discrete-Time Integrator'
                                        */
  real_T P2_Gain_g;                    /* Expression: Ds
                                        * Referenced by: '<S98>/P2'
                                        */
  real_T TSamp_WtEt;                   /* Computed Parameter: TSamp_WtEt
                                        * Referenced by: '<S105>/TSamp'
                                        */
  real_T UD_X0;                        /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S105>/UD'
                                        */
  real_T TimeDelay1_MaxDelay_m;        /* Expression: 1
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_g;      /* Expression: 0
                                        * Referenced by: '<S91>/TimeDelay1'
                                        */
  real_T CutofffreqHz_Value_e;         /* Expression: cf
                                        * Referenced by: '<S94>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_d;            /* Expression: 1
                                        * Referenced by: '<S94>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_k;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_k
                                         * Referenced by: '<S94>/Weighted Sample Time Math1'
                                         */
  real_T P_Gain_m;                     /* Expression: Ps
                                        * Referenced by: '<S90>/P'
                                        */
  real_T DiscreteTimeIntegrator_gainva_b;/* Computed Parameter: DiscreteTimeIntegrator_gainva_b
                                          * Referenced by: '<S90>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_k;  /* Expression: 0
                                        * Referenced by: '<S90>/Discrete-Time Integrator'
                                        */
  real_T P2_Gain_g2;                   /* Expression: Ds
                                        * Referenced by: '<S90>/P2'
                                        */
  real_T TSamp_WtEt_b;                 /* Computed Parameter: TSamp_WtEt_b
                                        * Referenced by: '<S93>/TSamp'
                                        */
  real_T UD_X0_d;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S93>/UD'
                                        */
  real_T CutofffreqHz_Value_h;         /* Expression: cf
                                        * Referenced by: '<S88>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_o;            /* Expression: 1
                                        * Referenced by: '<S88>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_m;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_m
                                         * Referenced by: '<S88>/Weighted Sample Time Math1'
                                         */
  real_T constant_Value;               /* Expression: 1
                                        * Referenced by: '<S13>/constant'
                                        */
  real_T Setpoint_Gain;                /* Expression: gain
                                        * Referenced by: '<S13>/Setpoint'
                                        */
  real_T TimeDelay1_MaxDelay_g;        /* Expression: 1
                                        * Referenced by: '<S100>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_n;      /* Expression: 0
                                        * Referenced by: '<S100>/TimeDelay1'
                                        */
  real_T setting19_Value;              /* Expression: mu
                                        * Referenced by: '<S10>/setting19'
                                        */
  real_T setting2_Value;               /* Expression: lambda
                                        * Referenced by: '<S10>/setting2'
                                        */
  real_T CutofffreqHz_Value_l;         /* Expression: cf
                                        * Referenced by: '<S102>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_i;            /* Expression: 1
                                        * Referenced by: '<S102>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_b;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_b
                                         * Referenced by: '<S102>/Weighted Sample Time Math1'
                                         */
  real_T P_Gain_c;                     /* Expression: Pm
                                        * Referenced by: '<S97>/P'
                                        */
  real_T DiscreteTimeIntegrator_gainva_p;/* Computed Parameter: DiscreteTimeIntegrator_gainva_p
                                          * Referenced by: '<S97>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_j;  /* Expression: 0
                                        * Referenced by: '<S97>/Discrete-Time Integrator'
                                        */
  real_T P2_Gain_ga;                   /* Expression: Dm
                                        * Referenced by: '<S97>/P2'
                                        */
  real_T TSamp_WtEt_d;                 /* Computed Parameter: TSamp_WtEt_d
                                        * Referenced by: '<S101>/TSamp'
                                        */
  real_T UD_X0_p;                      /* Expression: ICPrevScaledInput
                                        * Referenced by: '<S101>/UD'
                                        */
  real_T TimeDelay1_MaxDelay_c;        /* Expression: 1
                                        * Referenced by: '<S92>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_f;      /* Expression: 0
                                        * Referenced by: '<S92>/TimeDelay1'
                                        */
  real_T CutofffreqHz_Value_d;         /* Expression: cf
                                        * Referenced by: '<S86>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_iu;           /* Expression: 1
                                        * Referenced by: '<S86>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_c;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_c
                                         * Referenced by: '<S86>/Weighted Sample Time Math1'
                                         */
  real_T P1_Gain_m;                    /* Expression: -0.075
                                        * Referenced by: '<S84>/P1'
                                        */
  real_T constant_Value_i;             /* Expression: 1
                                        * Referenced by: '<S12>/constant'
                                        */
  real_T Setpoint_Gain_h;              /* Expression: gain
                                        * Referenced by: '<S12>/Setpoint'
                                        */
  real_T ec_EL3102_adc_P1_Size[2];     /* Computed Parameter: ec_EL3102_adc_P1_Size
                                        * Referenced by: '<S16>/ec_EL3102_adc'
                                        */
  real_T ec_EL3102_adc_P1;             /* Expression: link_id
                                        * Referenced by: '<S16>/ec_EL3102_adc'
                                        */
  real_T ec_EL3102_adc_P1_Size_g[2];   /* Computed Parameter: ec_EL3102_adc_P1_Size_g
                                        * Referenced by: '<S17>/ec_EL3102_adc'
                                        */
  real_T ec_EL3102_adc_P1_n;           /* Expression: link_id
                                        * Referenced by: '<S17>/ec_EL3102_adc'
                                        */
  real_T Constant11_Value;             /* Expression: 3.15
                                        * Referenced by: '<S1>/Constant11'
                                        */
  real_T IntegerDelay1_InitialConditio_k;/* Expression: 0.0
                                          * Referenced by: '<S32>/Integer Delay1'
                                          */
  real_T Constant10_Value;             /* Expression: L_arm
                                        * Referenced by: '<S1>/Constant10'
                                        */
  real_T Constant12_Value;             /* Expression: 0.5
                                        * Referenced by: '<S1>/Constant12'
                                        */
  real_T IntegerDelay1_InitialConditio_c;/* Expression: 0.0
                                          * Referenced by: '<S31>/Integer Delay1'
                                          */
  real_T Constant7_Value;              /* Expression: 26.7
                                        * Referenced by: '<S1>/Constant7'
                                        */
  real_T Constant3_Value;              /* Expression: L_arm
                                        * Referenced by: '<S1>/Constant3'
                                        */
  real_T Constant8_Value;              /* Expression: .5
                                        * Referenced by: '<S1>/Constant8'
                                        */
  real_T Constant1_Value_j;            /* Expression: 1
                                        * Referenced by: '<S19>/Constant1'
                                        */
  real_T CutofffreqHz_Value_b;         /* Expression: cf
                                        * Referenced by: '<S19>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_j;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_j
                                         * Referenced by: '<S19>/Weighted Sample Time Math1'
                                         */
  real_T setting6_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/setting6'
                                        */
  real_T Constant2_Value_o;            /* Expression: 0
                                        * Referenced by: '<S27>/Constant2'
                                        */
  real_T TimeDelay1_MaxDelay_m2;       /* Expression: 1
                                        * Referenced by: '<S27>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_c;      /* Expression: 0
                                        * Referenced by: '<S27>/TimeDelay1'
                                        */
  real_T ShuntDynPredicterPart1_InitialS;/* Expression: 0
                                          * Referenced by: '<S27>/ShuntDynPredicter Part 1'
                                          */
  real_T ShuntDynPredicterPart1_Numerato[8];/* Expression: shuntDynPredict_part1_tfd_foh.num{1}
                                             * Referenced by: '<S27>/ShuntDynPredicter Part 1'
                                             */
  real_T ShuntDynPredicterPart1_Denomina[8];/* Expression: shuntDynPredict_part1_tfd_foh.den{1}
                                             * Referenced by: '<S27>/ShuntDynPredicter Part 1'
                                             */
  real_T Constant1_Value_b;            /* Expression: 1/2000*3
                                        * Referenced by: '<S27>/Constant1'
                                        */
  real_T TimeDelay2_MaxDelay;          /* Expression: 1
                                        * Referenced by: '<S27>/TimeDelay2'
                                        */
  real_T TimeDelay2_InitOutput;        /* Expression: 0
                                        * Referenced by: '<S27>/TimeDelay2'
                                        */
  real_T DiscreteTransferFcn_InitialStat;/* Expression: 0
                                          * Referenced by: '<S27>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_Numerator[2];/* Expression: lowOrder_tfd_foh.num{1}
                                           * Referenced by: '<S27>/Discrete Transfer Fcn'
                                           */
  real_T DiscreteTransferFcn_Denominator[2];/* Expression: lowOrder_tfd_foh.den{1}
                                             * Referenced by: '<S27>/Discrete Transfer Fcn'
                                             */
  real_T ShuntDynPredicterPart2_InitialS;/* Expression: 0
                                          * Referenced by: '<S27>/ShuntDynPredicter Part 2'
                                          */
  real_T ShuntDynPredicterPart2_Numerato[8];/* Expression: shuntDynPredict_part2_tfd_foh.num{1}
                                             * Referenced by: '<S27>/ShuntDynPredicter Part 2'
                                             */
  real_T ShuntDynPredicterPart2_Denomina[8];/* Expression: shuntDynPredict_part2_tfd_foh.den{1}
                                             * Referenced by: '<S27>/ShuntDynPredicter Part 2'
                                             */
  real_T Correctionfactor_Gain;        /* Expression: 1.05
                                        * Referenced by: '<S27>/Correction factor'
                                        */
  real_T Constant1_Value_dg;           /* Expression: 1
                                        * Referenced by: '<S21>/Constant1'
                                        */
  real_T CutofffreqHz_Value_j3;        /* Expression: cf
                                        * Referenced by: '<S21>/Cut-off freq (Hz)'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_n;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_n
                                         * Referenced by: '<S21>/Weighted Sample Time Math1'
                                         */
  real_T setting16_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/setting16'
                                        */
  real_T Constant2_Value_e;            /* Expression: 0
                                        * Referenced by: '<S28>/Constant2'
                                        */
  real_T TimeDelay1_MaxDelay_n;        /* Expression: 1
                                        * Referenced by: '<S28>/TimeDelay1'
                                        */
  real_T TimeDelay1_InitOutput_j;      /* Expression: 0
                                        * Referenced by: '<S28>/TimeDelay1'
                                        */
  real_T ShuntDynPredicterPart1_Initia_g;/* Expression: 0
                                          * Referenced by: '<S28>/ShuntDynPredicter Part 1'
                                          */
  real_T ShuntDynPredicterPart1_Numera_g[8];/* Expression: shuntDynPredict_part1_tfd_foh.num{1}
                                             * Referenced by: '<S28>/ShuntDynPredicter Part 1'
                                             */
  real_T ShuntDynPredicterPart1_Denomi_i[8];/* Expression: shuntDynPredict_part1_tfd_foh.den{1}
                                             * Referenced by: '<S28>/ShuntDynPredicter Part 1'
                                             */
  real_T Constant1_Value_g;            /* Expression: 1/2000*3
                                        * Referenced by: '<S28>/Constant1'
                                        */
  real_T TimeDelay2_MaxDelay_n;        /* Expression: 1
                                        * Referenced by: '<S28>/TimeDelay2'
                                        */
  real_T TimeDelay2_InitOutput_h;      /* Expression: 0
                                        * Referenced by: '<S28>/TimeDelay2'
                                        */
  real_T DiscreteTransferFcn_InitialSt_n;/* Expression: 0
                                          * Referenced by: '<S28>/Discrete Transfer Fcn'
                                          */
  real_T DiscreteTransferFcn_Numerator_c[2];/* Expression: lowOrder_tfd_foh.num{1}
                                             * Referenced by: '<S28>/Discrete Transfer Fcn'
                                             */
  real_T DiscreteTransferFcn_Denominat_l[2];/* Expression: lowOrder_tfd_foh.den{1}
                                             * Referenced by: '<S28>/Discrete Transfer Fcn'
                                             */
  real_T ShuntDynPredicterPart2_Initia_i;/* Expression: 0
                                          * Referenced by: '<S28>/ShuntDynPredicter Part 2'
                                          */
  real_T ShuntDynPredicterPart2_Numera_c[8];/* Expression: shuntDynPredict_part2_tfd_foh.num{1}
                                             * Referenced by: '<S28>/ShuntDynPredicter Part 2'
                                             */
  real_T ShuntDynPredicterPart2_Denomi_h[8];/* Expression: shuntDynPredict_part2_tfd_foh.den{1}
                                             * Referenced by: '<S28>/ShuntDynPredicter Part 2'
                                             */
  real_T Correctionfactor_Gain_h;      /* Expression: 1.05
                                        * Referenced by: '<S28>/Correction factor'
                                        */
  real_T IntegerDelay_InitialCondition_a;/* Expression: 0.0
                                          * Referenced by: '<S31>/Integer Delay'
                                          */
  real_T min_val_Value;                /* Expression: .2
                                        * Referenced by: '<S31>/min_val'
                                        */
  real_T IntegerDelay2_InitialConditio_b;/* Expression: 0.0
                                          * Referenced by: '<S43>/Integer Delay2'
                                          */
  real_T constant_Value_j;             /* Expression: 1
                                        * Referenced by: '<S43>/constant'
                                        */
  real_T constant1_Value;              /* Expression: 1
                                        * Referenced by: '<S43>/constant1'
                                        */
  real_T IntegerDelay_InitialCondition_h;/* Expression: 0.0
                                          * Referenced by: '<S43>/Integer Delay'
                                          */
  real_T constant2_Value;              /* Expression: 1
                                        * Referenced by: '<S43>/constant2'
                                        */
  real_T IntegerDelay_InitialCondition_i;/* Expression: 0.0
                                          * Referenced by: '<S32>/Integer Delay'
                                          */
  real_T min_val_Value_j;              /* Expression: .2
                                        * Referenced by: '<S32>/min_val'
                                        */
  real_T IntegerDelay1_InitialConditio_d;/* Expression: 0.0
                                          * Referenced by: '<S44>/Integer Delay1'
                                          */
  real_T constant_Value_c;             /* Expression: 1
                                        * Referenced by: '<S44>/constant'
                                        */
  real_T constant1_Value_c;            /* Expression: 1
                                        * Referenced by: '<S44>/constant1'
                                        */
  real_T IntegerDelay_InitialCondition_m;/* Expression: 0.0
                                          * Referenced by: '<S44>/Integer Delay'
                                          */
  real_T constant2_Value_g;            /* Expression: 1
                                        * Referenced by: '<S44>/constant2'
                                        */
  real_T CutofffreqHz_Value_d2;        /* Expression: cf
                                        * Referenced by: '<S20>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_ou;           /* Expression: 1
                                        * Referenced by: '<S20>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_f;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_f
                                         * Referenced by: '<S20>/Weighted Sample Time Math1'
                                         */
  real_T CutofffreqHz_Value_kp;        /* Expression: cf
                                        * Referenced by: '<S18>/Cut-off freq (Hz)'
                                        */
  real_T Constant1_Value_ej;           /* Expression: 1
                                        * Referenced by: '<S18>/Constant1'
                                        */
  real_T WeightedSampleTimeMath1_WtEt_d;/* Computed Parameter: WeightedSampleTimeMath1_WtEt_d
                                         * Referenced by: '<S18>/Weighted Sample Time Math1'
                                         */
  real_T ec_EL5101_enc_P1_Size_b[2];   /* Computed Parameter: ec_EL5101_enc_P1_Size_b
                                        * Referenced by: '<S40>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_i;           /* Expression: link_id
                                        * Referenced by: '<S40>/ec_EL5101_enc'
                                        */
  real_T Gain1_Gain_o0;                /* Expression: -1
                                        * Referenced by: '<S29>/Gain1'
                                        */
  real_T Gain_Gain_i;                  /* Expression: 1/(7500*4)
                                        * Referenced by: '<S29>/Gain'
                                        */
  real_T Gain6_Gain_h;                 /* Expression: 1/10*360
                                        * Referenced by: '<S29>/Gain6'
                                        */
  real_T Constant4_Value_o;            /* Expression: 18
                                        * Referenced by: '<S29>/Constant4'
                                        */
  real_T ec_EL5101_enc_P1_Size_a[2];   /* Computed Parameter: ec_EL5101_enc_P1_Size_a
                                        * Referenced by: '<S42>/ec_EL5101_enc'
                                        */
  real_T ec_EL5101_enc_P1_d;           /* Expression: link_id
                                        * Referenced by: '<S42>/ec_EL5101_enc'
                                        */
  real_T Gain1_Gain_k;                 /* Expression: 1
                                        * Referenced by: '<S30>/Gain1'
                                        */
  real_T Gain_Gain_g;                  /* Expression: 1/(7500*4)
                                        * Referenced by: '<S30>/Gain'
                                        */
  real_T Gain6_Gain_k;                 /* Expression: 1/10*360
                                        * Referenced by: '<S30>/Gain6'
                                        */
  real_T Constant4_Value_n;            /* Expression: -19
                                        * Referenced by: '<S30>/Constant4'
                                        */
  real_T DiscreteTimeIntegrator_gainv_ad;/* Computed Parameter: DiscreteTimeIntegrator_gainv_ad
                                          * Referenced by: '<S1>/Discrete-Time Integrator'
                                          */
  real_T DiscreteTimeIntegrator_IC_d;  /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator'
                                        */
  real_T DiscreteTimeIntegrator1_gainval;/* Computed Parameter: DiscreteTimeIntegrator1_gainval
                                          * Referenced by: '<S1>/Discrete-Time Integrator1'
                                          */
  real_T DiscreteTimeIntegrator1_IC;   /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator1'
                                        */
  real_T DiscreteTimeIntegrator2_gainval;/* Computed Parameter: DiscreteTimeIntegrator2_gainval
                                          * Referenced by: '<S1>/Discrete-Time Integrator2'
                                          */
  real_T DiscreteTimeIntegrator2_IC;   /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator2'
                                        */
  real_T DiscreteTimeIntegrator3_gainval;/* Computed Parameter: DiscreteTimeIntegrator3_gainval
                                          * Referenced by: '<S1>/Discrete-Time Integrator3'
                                          */
  real_T DiscreteTimeIntegrator3_IC;   /* Expression: 0
                                        * Referenced by: '<S1>/Discrete-Time Integrator3'
                                        */
  real_T on1_Value;                    /* Expression: 7
                                        * Referenced by: '<S33>/on1'
                                        */
  real_T on3_Value;                    /* Expression: 0.1
                                        * Referenced by: '<S33>/on3'
                                        */
  real_T setting3_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/setting3'
                                        */
  real_T Gain_Gain_n;                  /* Expression: 0.01
                                        * Referenced by: '<S2>/Gain'
                                        */
  real_T Constant_Value_m;             /* Expression: const
                                        * Referenced by: '<S53>/Constant'
                                        */
  real_T Constant_Value_l;             /* Expression: 1
                                        * Referenced by: '<S48>/Constant'
                                        */
  real_T Constant2_Value_m[4];         /* Expression: [0.04907     0.00274     0.05296     0.00325]
                                        * Referenced by: '<S48>/Constant2'
                                        */
  real_T Constant_Value_fm;            /* Expression: const
                                        * Referenced by: '<S54>/Constant'
                                        */
  real_T Constant1_Value_pz;           /* Expression: 1
                                        * Referenced by: '<S48>/Constant1'
                                        */
  real_T Gain_Gain_gm;                 /* Expression: -1
                                        * Referenced by: '<S48>/Gain'
                                        */
  real_T Constant3_Value_m;            /* Expression: torque_constant
                                        * Referenced by: '<S2>/Constant3'
                                        */
  real_T Constant6_Value_m;            /* Expression: .01
                                        * Referenced by: '<S2>/Constant6'
                                        */
  real_T setting5_Value;               /* Expression: 0
                                        * Referenced by: '<S10>/setting5'
                                        */
  real_T Gain1_Gain_j;                 /* Expression: 0.01
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T Constant_Value_d;             /* Expression: const
                                        * Referenced by: '<S55>/Constant'
                                        */
  real_T Constant_Value_h;             /* Expression: 1
                                        * Referenced by: '<S49>/Constant'
                                        */
  real_T Constant3_Value_p[4];         /* Expression: [0.04555     0.00229     0.03561     0.00305]
                                        * Referenced by: '<S49>/Constant3'
                                        */
  real_T Constant_Value_lh;            /* Expression: const
                                        * Referenced by: '<S56>/Constant'
                                        */
  real_T Constant1_Value_oe;           /* Expression: 1
                                        * Referenced by: '<S49>/Constant1'
                                        */
  real_T Gain_Gain_ni;                 /* Expression: -1
                                        * Referenced by: '<S49>/Gain'
                                        */
  real_T Constant8_Value_d;            /* Expression: torque_constant
                                        * Referenced by: '<S2>/Constant8'
                                        */
  real_T Constant7_Value_n;            /* Expression: -.01
                                        * Referenced by: '<S2>/Constant7'
                                        */
  real_T ec_EL4038_dac_P1_Size[2];     /* Computed Parameter: ec_EL4038_dac_P1_Size
                                        * Referenced by: '<S47>/ec_EL4038_dac'
                                        */
  real_T ec_EL4038_dac_P1;             /* Expression: link_id
                                        * Referenced by: '<S47>/ec_EL4038_dac'
                                        */
  real_T Constant_Value_p;             /* Expression: const
                                        * Referenced by: '<S57>/Constant'
                                        */
  real_T Constant_Value_nk;            /* Expression: const
                                        * Referenced by: '<S58>/Constant'
                                        */
  real_T Constant10_Value_j;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant10'
                                        */
  real_T Constant11_Value_i;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant11'
                                        */
  real_T Constant12_Value_h;           /* Expression: 0
                                        * Referenced by: '<S2>/Constant12'
                                        */
  real_T Constant13_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant13'
                                        */
  real_T Constant14_Value;             /* Expression: 0
                                        * Referenced by: '<S2>/Constant14'
                                        */
  real_T Constant9_Value_n;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant9'
                                        */
  real_T ec_EL2008_do_P1_Size[2];      /* Computed Parameter: ec_EL2008_do_P1_Size
                                        * Referenced by: '<S46>/ec_EL2008_do'
                                        */
  real_T ec_EL2008_do_P1;              /* Expression: link_id
                                        * Referenced by: '<S46>/ec_EL2008_do'
                                        */
  real_T Constant1_Value_e3;           /* Expression: 1
                                        * Referenced by: '<S2>/Constant1'
                                        */
  real_T Constant2_Value_a;            /* Expression: 1
                                        * Referenced by: '<S2>/Constant2'
                                        */
  real_T Constant4_Value_b;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant4'
                                        */
  real_T Constant5_Value_i;            /* Expression: 0
                                        * Referenced by: '<S2>/Constant5'
                                        */
  real_T setting17_Value;              /* Expression: 0
                                        * Referenced by: '<S10>/setting17'
                                        */
  real_T UnitDelay1_X0;                /* Expression: 0
                                        * Referenced by: '<S91>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_h;              /* Expression: 0
                                        * Referenced by: '<S92>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_b;              /* Expression: 0
                                        * Referenced by: '<S99>/Unit Delay1'
                                        */
  real_T UnitDelay1_X0_c;              /* Expression: 0
                                        * Referenced by: '<S100>/Unit Delay1'
                                        */
  real_T Gain3_Gain_c;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain3'
                                        */
  real_T Gain2_Gain_d;                 /* Expression: -1
                                        * Referenced by: '<S9>/Gain2'
                                        */
  uint32_T IntegerDelay1_DelayLength;  /* Computed Parameter: IntegerDelay1_DelayLength
                                        * Referenced by: '<S8>/Integer Delay1'
                                        */
  uint32_T IntegerDelay_DelayLength;   /* Computed Parameter: IntegerDelay_DelayLength
                                        * Referenced by: '<S62>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_m;/* Computed Parameter: IntegerDelay1_DelayLength_m
                                        * Referenced by: '<S62>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength;  /* Computed Parameter: IntegerDelay2_DelayLength
                                        * Referenced by: '<S63>/Integer Delay2'
                                        */
  uint32_T IntegerDelay1_DelayLength_p;/* Computed Parameter: IntegerDelay1_DelayLength_p
                                        * Referenced by: '<S63>/Integer Delay1'
                                        */
  uint32_T IntegerDelay2_DelayLength_c;/* Computed Parameter: IntegerDelay2_DelayLength_c
                                        * Referenced by: '<S1>/Integer Delay2'
                                        */
  uint32_T IntegerDelay_DelayLength_a; /* Computed Parameter: IntegerDelay_DelayLength_a
                                        * Referenced by: '<S1>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_d;/* Computed Parameter: IntegerDelay1_DelayLength_d
                                        * Referenced by: '<S32>/Integer Delay1'
                                        */
  uint32_T IntegerDelay1_DelayLength_a;/* Computed Parameter: IntegerDelay1_DelayLength_a
                                        * Referenced by: '<S31>/Integer Delay1'
                                        */
  uint32_T IntegerDelay_DelayLength_m; /* Computed Parameter: IntegerDelay_DelayLength_m
                                        * Referenced by: '<S31>/Integer Delay'
                                        */
  uint32_T IntegerDelay2_DelayLength_l;/* Computed Parameter: IntegerDelay2_DelayLength_l
                                        * Referenced by: '<S43>/Integer Delay2'
                                        */
  uint32_T IntegerDelay_DelayLength_d; /* Computed Parameter: IntegerDelay_DelayLength_d
                                        * Referenced by: '<S43>/Integer Delay'
                                        */
  uint32_T IntegerDelay_DelayLength_h; /* Computed Parameter: IntegerDelay_DelayLength_h
                                        * Referenced by: '<S32>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_n;/* Computed Parameter: IntegerDelay1_DelayLength_n
                                        * Referenced by: '<S44>/Integer Delay1'
                                        */
  uint32_T IntegerDelay_DelayLength_p; /* Computed Parameter: IntegerDelay_DelayLength_p
                                        * Referenced by: '<S44>/Integer Delay'
                                        */
  uint32_T IntegerDelay1_DelayLength_f;/* Computed Parameter: IntegerDelay1_DelayLength_f
                                        * Referenced by: '<S26>/Integer Delay1'
                                        */
  uint32_T IntegerDelay1_DelayLength_g;/* Computed Parameter: IntegerDelay1_DelayLength_g
                                        * Referenced by: '<S33>/Integer Delay1'
                                        */
  uint8_T Constant_Value_dm;           /* Expression: uint8(1)
                                        * Referenced by: '<S4>/Constant'
                                        */
  uint8_T SwitchControl_Threshold;     /* Expression: uint8(0)
                                        * Referenced by: '<S4>/SwitchControl'
                                        */
  uint8_T Constant_Value_po;           /* Expression: uint8(1)
                                        * Referenced by: '<S60>/Constant'
                                        */
  uint8_T FixPtUnitDelay2_X0;          /* Computed Parameter: FixPtUnitDelay2_X0
                                        * Referenced by: '<S61>/FixPt Unit Delay2'
                                        */
  uint8_T SwitchControl_Threshold_k;   /* Expression: uint8(0)
                                        * Referenced by: '<S60>/SwitchControl'
                                        */
  uint8_T FixPtConstant_Value;         /* Computed Parameter: FixPtConstant_Value
                                        * Referenced by: '<S61>/FixPt Constant'
                                        */
  uint8_T Constant_Value_ja;           /* Expression: uint8(1)
                                        * Referenced by: '<S25>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_n;   /* Expression: uint8(0)
                                        * Referenced by: '<S25>/SwitchControl'
                                        */
  uint8_T Constant_Value_e;            /* Expression: uint8(1)
                                        * Referenced by: '<S24>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_a;   /* Expression: uint8(0)
                                        * Referenced by: '<S24>/SwitchControl'
                                        */
  uint8_T Constant_Value_b;            /* Expression: uint8(1)
                                        * Referenced by: '<S23>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_l;   /* Expression: uint8(1)
                                        * Referenced by: '<S23>/SwitchControl'
                                        */
  uint8_T Constant_Value_bn;           /* Expression: uint8(1)
                                        * Referenced by: '<S22>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_m;   /* Expression: uint8(1)
                                        * Referenced by: '<S22>/SwitchControl'
                                        */
  uint8_T Constant_Value_kr;           /* Expression: uint8(1)
                                        * Referenced by: '<S51>/Constant'
                                        */
  uint8_T SwitchControl_Threshold_g;   /* Expression: uint8(1)
                                        * Referenced by: '<S51>/SwitchControl'
                                        */
  boolean_T IntegerDelay1_InitialConditio_e;/* Computed Parameter: IntegerDelay1_InitialConditio_e
                                             * Referenced by: '<S8>/Integer Delay1'
                                             */
  boolean_T Memory_X0;                 /* Computed Parameter: Memory_X0
                                        * Referenced by: '<S109>/Memory'
                                        */
  boolean_T Logic_table[16];           /* Computed Parameter: Logic_table
                                        * Referenced by: '<S109>/Logic'
                                        */
  boolean_T IntegerDelay2_InitialConditio_h;/* Computed Parameter: IntegerDelay2_InitialConditio_h
                                             * Referenced by: '<S1>/Integer Delay2'
                                             */
  boolean_T IntegerDelay_InitialConditio_hn;/* Computed Parameter: IntegerDelay_InitialConditio_hn
                                             * Referenced by: '<S1>/Integer Delay'
                                             */
  boolean_T Memory_X0_p;               /* Computed Parameter: Memory_X0_p
                                        * Referenced by: '<S38>/Memory'
                                        */
  boolean_T Logic_table_g[16];         /* Computed Parameter: Logic_table_g
                                        * Referenced by: '<S38>/Logic'
                                        */
  boolean_T IntegerDelay1_InitialConditi_dg;/* Computed Parameter: IntegerDelay1_InitialConditi_dg
                                             * Referenced by: '<S26>/Integer Delay1'
                                             */
  boolean_T IntegerDelay1_InitialConditi_ca;/* Computed Parameter: IntegerDelay1_InitialConditi_ca
                                             * Referenced by: '<S33>/Integer Delay1'
                                             */
};

/* Real-time Model Data Structure */
struct RT_MODEL_singledof_base {
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
    SimStruct childSFunctions[10];
    SimStruct *childSFunctionPtrs[10];
    struct _ssBlkInfo2 blkInfo2[10];
    struct _ssSFcnModelMethods2 methods2[10];
    struct _ssSFcnModelMethods3 methods3[10];
    struct _ssStatesInfo2 statesInfo2[10];
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
      struct _ssPortInputs inputPortInfo[3];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      real_T const *UPtrs2[1];
      struct _ssPortOutputs outputPortInfo[4];
      struct _ssDWorkRecord dWork[14];
      struct _ssDWorkAuxRecord dWorkAux[14];
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
      struct _ssPortOutputs outputPortInfo[1];
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

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      real_T const *UPtrs0[8];
      uint_T attribs[1];
      mxArray *params[1];
    } Sfcn9;
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
extern Parameters_singledof_base singledof_base_P;

/* Block signals (auto storage) */
extern BlockIO_singledof_base singledof_base_B;

/* Block states (auto storage) */
extern D_Work_singledof_base singledof_base_DWork;

/* Model entry point functions */
extern void singledof_base_initialize(boolean_T firstTime);
extern void singledof_base_output(int_T tid);
extern void singledof_base_update(int_T tid);
extern void singledof_base_terminate(void);

/* Real-time Model object */
extern struct RT_MODEL_singledof_base *const singledof_base_M;

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
 * '<Root>' : 'singledof_base'
 * '<S1>'   : 'singledof_base/AI DI'
 * '<S2>'   : 'singledof_base/AO DO'
 * '<S3>'   : 'singledof_base/Initialize'
 * '<S4>'   : 'singledof_base/Manual Switch3'
 * '<S5>'   : 'singledof_base/Own controller'
 * '<S6>'   : 'singledof_base/Pos-force'
 * '<S7>'   : 'singledof_base/Pos-pos'
 * '<S8>'   : 'singledof_base/STOP'
 * '<S9>'   : 'singledof_base/Scopes'
 * '<S10>'  : 'singledof_base/Settings'
 * '<S11>'  : 'singledof_base/Virtual Environment'
 * '<S12>'  : 'singledof_base/overrule tau_dm'
 * '<S13>'  : 'singledof_base/overrule tau_ds'
 * '<S14>'  : 'singledof_base/selectOutput'
 * '<S15>'  : 'singledof_base/AI DI/EL1008 Din'
 * '<S16>'  : 'singledof_base/AI DI/EL3102master ADC'
 * '<S17>'  : 'singledof_base/AI DI/EL3102slave ADC'
 * '<S18>'  : 'singledof_base/AI DI/Lowpass1'
 * '<S19>'  : 'singledof_base/AI DI/Lowpass2'
 * '<S20>'  : 'singledof_base/AI DI/Lowpass3'
 * '<S21>'  : 'singledof_base/AI DI/Lowpass4'
 * '<S22>'  : 'singledof_base/AI DI/Manual Switch1'
 * '<S23>'  : 'singledof_base/AI DI/Manual Switch2'
 * '<S24>'  : 'singledof_base/AI DI/Manual Switch3'
 * '<S25>'  : 'singledof_base/AI DI/Manual Switch5'
 * '<S26>'  : 'singledof_base/AI DI/STOP'
 * '<S27>'  : 'singledof_base/AI DI/compensateShunt_m'
 * '<S28>'  : 'singledof_base/AI DI/compensateShunt_s'
 * '<S29>'  : 'singledof_base/AI DI/enc_master'
 * '<S30>'  : 'singledof_base/AI DI/enc_slave'
 * '<S31>'  : 'singledof_base/AI DI/find_zero_during_init_m'
 * '<S32>'  : 'singledof_base/AI DI/find_zero_during_init_s'
 * '<S33>'  : 'singledof_base/AI DI/safety block'
 * '<S34>'  : 'singledof_base/AI DI/Lowpass1/lowpass'
 * '<S35>'  : 'singledof_base/AI DI/Lowpass2/lowpass'
 * '<S36>'  : 'singledof_base/AI DI/Lowpass3/lowpass'
 * '<S37>'  : 'singledof_base/AI DI/Lowpass4/lowpass'
 * '<S38>'  : 'singledof_base/AI DI/STOP/S-R Flip-Flop'
 * '<S39>'  : 'singledof_base/AI DI/enc_master/EL5101 Encoder'
 * '<S40>'  : 'singledof_base/AI DI/enc_master/EL5101 Latch'
 * '<S41>'  : 'singledof_base/AI DI/enc_slave/EL5101 Encoder'
 * '<S42>'  : 'singledof_base/AI DI/enc_slave/EL5101 Latch'
 * '<S43>'  : 'singledof_base/AI DI/find_zero_during_init_m/moving avg'
 * '<S44>'  : 'singledof_base/AI DI/find_zero_during_init_s/moving avg'
 * '<S45>'  : 'singledof_base/AI DI/safety block/S-R Flip-Flop'
 * '<S46>'  : 'singledof_base/AO DO/EL2008 DigitalOut'
 * '<S47>'  : 'singledof_base/AO DO/EL4038 AnalogOut'
 * '<S48>'  : 'singledof_base/AO DO/FricComp_m'
 * '<S49>'  : 'singledof_base/AO DO/FricComp_s'
 * '<S50>'  : 'singledof_base/AO DO/LED'
 * '<S51>'  : 'singledof_base/AO DO/Manual Switch1'
 * '<S52>'  : 'singledof_base/AO DO/extraSafety'
 * '<S53>'  : 'singledof_base/AO DO/FricComp_m/Compare To Constant'
 * '<S54>'  : 'singledof_base/AO DO/FricComp_m/Compare To Constant1'
 * '<S55>'  : 'singledof_base/AO DO/FricComp_s/Compare To Constant'
 * '<S56>'  : 'singledof_base/AO DO/FricComp_s/Compare To Constant1'
 * '<S57>'  : 'singledof_base/AO DO/extraSafety/Compare To Constant'
 * '<S58>'  : 'singledof_base/AO DO/extraSafety/Compare To Constant1'
 * '<S59>'  : 'singledof_base/Initialize/Compare To Constant'
 * '<S60>'  : 'singledof_base/Initialize/Manual Switch'
 * '<S61>'  : 'singledof_base/Initialize/Unit Delay External IC'
 * '<S62>'  : 'singledof_base/Initialize/initialize_um'
 * '<S63>'  : 'singledof_base/Initialize/initialize_us'
 * '<S64>'  : 'singledof_base/Initialize/initialize_um/Compare To Constant'
 * '<S65>'  : 'singledof_base/Initialize/initialize_um/Compare To Constant1'
 * '<S66>'  : 'singledof_base/Initialize/initialize_um/contr_m_init'
 * '<S67>'  : 'singledof_base/Initialize/initialize_um/contr_m_init/D'
 * '<S68>'  : 'singledof_base/Initialize/initialize_um/contr_m_init/Discrete Derivative'
 * '<S69>'  : 'singledof_base/Initialize/initialize_um/contr_m_init/I'
 * '<S70>'  : 'singledof_base/Initialize/initialize_um/contr_m_init/Lowpass3'
 * '<S71>'  : 'singledof_base/Initialize/initialize_um/contr_m_init/P'
 * '<S72>'  : 'singledof_base/Initialize/initialize_um/contr_m_init/anti windup'
 * '<S73>'  : 'singledof_base/Initialize/initialize_um/contr_m_init/Lowpass3/lowpass'
 * '<S74>'  : 'singledof_base/Initialize/initialize_us/Compare To Constant'
 * '<S75>'  : 'singledof_base/Initialize/initialize_us/Compare To Constant1'
 * '<S76>'  : 'singledof_base/Initialize/initialize_us/contr_s_init'
 * '<S77>'  : 'singledof_base/Initialize/initialize_us/contr_s_init/D'
 * '<S78>'  : 'singledof_base/Initialize/initialize_us/contr_s_init/Discrete Derivative'
 * '<S79>'  : 'singledof_base/Initialize/initialize_us/contr_s_init/I'
 * '<S80>'  : 'singledof_base/Initialize/initialize_us/contr_s_init/Lowpass3'
 * '<S81>'  : 'singledof_base/Initialize/initialize_us/contr_s_init/P'
 * '<S82>'  : 'singledof_base/Initialize/initialize_us/contr_s_init/anti windup'
 * '<S83>'  : 'singledof_base/Initialize/initialize_us/contr_s_init/Lowpass3/lowpass'
 * '<S84>'  : 'singledof_base/Own controller/Controller master'
 * '<S85>'  : 'singledof_base/Own controller/Controller slave'
 * '<S86>'  : 'singledof_base/Own controller/Controller master/Lowpass1'
 * '<S87>'  : 'singledof_base/Own controller/Controller master/Lowpass1/lowpass'
 * '<S88>'  : 'singledof_base/Own controller/Controller slave/Lowpass1'
 * '<S89>'  : 'singledof_base/Own controller/Controller slave/Lowpass1/lowpass'
 * '<S90>'  : 'singledof_base/Pos-force/contr_s'
 * '<S91>'  : 'singledof_base/Pos-force/master to slave'
 * '<S92>'  : 'singledof_base/Pos-force/slave to master'
 * '<S93>'  : 'singledof_base/Pos-force/contr_s/Discrete Derivative'
 * '<S94>'  : 'singledof_base/Pos-force/contr_s/Lowpass1'
 * '<S95>'  : 'singledof_base/Pos-force/contr_s/anti windup'
 * '<S96>'  : 'singledof_base/Pos-force/contr_s/Lowpass1/lowpass'
 * '<S97>'  : 'singledof_base/Pos-pos/contr_m'
 * '<S98>'  : 'singledof_base/Pos-pos/contr_s'
 * '<S99>'  : 'singledof_base/Pos-pos/master to slave'
 * '<S100>' : 'singledof_base/Pos-pos/slave to master'
 * '<S101>' : 'singledof_base/Pos-pos/contr_m/Discrete Derivative'
 * '<S102>' : 'singledof_base/Pos-pos/contr_m/Lowpass1'
 * '<S103>' : 'singledof_base/Pos-pos/contr_m/anti windup'
 * '<S104>' : 'singledof_base/Pos-pos/contr_m/Lowpass1/lowpass'
 * '<S105>' : 'singledof_base/Pos-pos/contr_s/Discrete Derivative'
 * '<S106>' : 'singledof_base/Pos-pos/contr_s/Lowpass1'
 * '<S107>' : 'singledof_base/Pos-pos/contr_s/anti windup'
 * '<S108>' : 'singledof_base/Pos-pos/contr_s/Lowpass1/lowpass'
 * '<S109>' : 'singledof_base/STOP/S-R Flip-Flop'
 */
#endif                                 /* RTW_HEADER_singledof_base_h_ */
