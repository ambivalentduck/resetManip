/*
 * BasicModelTarget.h
 *
 * Real-Time Workshop code generation for Simulink model "BasicModelTarget.mdl".
 *
 * Model version              : 1.972
 * Real-Time Workshop version : 7.5  (R2010a)  25-Jan-2010
 * C source code generated on : Wed Feb 16 12:11:02 2011
 *
 * Target selection: xpctarget.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */
#ifndef RTW_HEADER_BasicModelTarget_h_
#define RTW_HEADER_BasicModelTarget_h_
#include "rtw_modelmap.h"
#ifndef BasicModelTarget_COMMON_INCLUDES_
# define BasicModelTarget_COMMON_INCLUDES_
#include <xpcimports.h>
#include <xpcdatatypes.h>
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
#include "rt_zcfcn.h"
#include "rt_nonfinite.h"
#include "rtGetInf.h"
#include "rtGetNaN.h"
#include "rt_SATURATE.h"
#include "rt_mod_snf.h"
#include "rt_pow_snf.h"
#endif                                 /* BasicModelTarget_COMMON_INCLUDES_ */

#include "BasicModelTarget_types.h"

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
# define rtmGetDataMapInfo(rtm)        ((rtm)->DataMapInfo)
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ((rtm)->DataMapInfo = (val))
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
# define rtmGetIntgData(rtm)           ((rtm)->ModelData.intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->ModelData.intgData = (val))
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
# define rtmGetOdeF(rtm)               ((rtm)->ModelData.odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->ModelData.odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ((rtm)->ModelData.odeY)
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ((rtm)->ModelData.odeY = (val))
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
# define rtmGetPerTaskSampleHits(rtm)  ((rtm)->Timing.RateInteraction)
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ((rtm)->Timing.RateInteraction = (val))
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
# define rtmGetTaskCounters(rtm)       ((rtm)->Timing.TaskCounters)
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ((rtm)->Timing.TaskCounters = (val))
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
# define rtmIsContinuousTask(rtm, tid) ((tid) <= 1)
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
# define rtmIsSampleHit(rtm, sti, tid) (((rtm)->Timing.sampleTimeTaskIDPtr[sti] == (tid)))
#endif

#ifndef rtmStepTask
# define rtmStepTask(rtm, idx)         ((rtm)->Timing.TaskCounters.TID[(idx)] == 0)
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

#ifndef rtmTaskCounter
# define rtmTaskCounter(rtm, idx)      ((rtm)->Timing.TaskCounters.TID[(idx)])
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
#define BasicModelTarget_rtModel       rtModel_BasicModelTarget

/* user code (top of export header file) */
#include "xpcdatatypes.h"

/* Block signals (auto storage) */
typedef struct {
  real_T Clock;                        /* '<Root>/Clock' */
  real_T OffsetinRadians;              /* '<S16>/Offset in Radians' */
  real_T UnitDelay[17];                /* '<S16>/Unit Delay' */
  real_T DotProduct;                   /* '<S16>/Dot Product' */
  real_T Product1;                     /* '<S16>/Product1' */
  real_T Sum;                          /* '<S16>/Sum' */
  real_T J10;                          /* '<S15>/J10' */
  real_T OffsetinRadians_h;            /* '<S14>/Offset in Radians' */
  real_T UnitDelay_i[17];              /* '<S14>/Unit Delay' */
  real_T EncoderDecimal;               /* '<S14>/Encoder Decimal' */
  real_T EncoderRadians;               /* '<S14>/Encoder Radians' */
  real_T Sum_j;                        /* '<S14>/Sum' */
  real_T J11;                          /* '<S15>/J11' */
  real_T Sum_h;                        /* '<S15>/Sum' */
  real_T J00;                          /* '<S15>/J00' */
  real_T J01;                          /* '<S15>/J01' */
  real_T Sum1;                         /* '<S15>/Sum1' */
  real_T TransferFcn8;                 /* '<S4>/Transfer Fcn8' */
  real_T Derivative1;                  /* '<S4>/Derivative1' */
  real_T InputParam;                   /* '<Root>/Input Param' */
  real_T InputParam1;                  /* '<Root>/Input Param1' */
  real_T InputParam2;                  /* '<Root>/Input Param2' */
  real_T InputParam3;                  /* '<Root>/InputParam3' */
  real_T Function1justdirecttransmissiio;/* '<S7>/Function1: just direct transmissiion for now' */
  real_T TransferFcn9;                 /* '<S4>/Transfer Fcn9' */
  real_T Derivative3;                  /* '<S4>/Derivative3' */
  real_T Function1justdirecttransmissi_j;/* '<S8>/Function1: just direct transmissiion for now' */
  real_T AveX;                         /* '<S2>/Ave X' */
  real_T Gain1;                        /* '<S2>/Gain1' */
  real_T AveY;                         /* '<S2>/Ave Y' */
  real_T Gain2;                        /* '<S2>/Gain2' */
  real_T RadialVec[2];                 /* '<S2>/Radial Vec' */
  real_T Fcn3;                         /* '<S2>/Fcn3' */
  real_T Fcn1;                         /* '<S2>/Fcn1' */
  real_T AveX1;                        /* '<S2>/Ave X1' */
  real_T Unpack_o1;                    /* '<S1>/Unpack' */
  real_T Unpack_o2;                    /* '<S1>/Unpack' */
  real_T Unpack_o3;                    /* '<S1>/Unpack' */
  real_T Unpack_o4;                    /* '<S1>/Unpack' */
  real_T Unpack_o5;                    /* '<S1>/Unpack' */
  real_T Unpack_o6;                    /* '<S1>/Unpack' */
  real_T Product5;                     /* '<S1>/Product5' */
  real_T Product2;                     /* '<S1>/Product2' */
  real_T Product3;                     /* '<S1>/Product3' */
  real_T Sum_n;                        /* '<S1>/Sum' */
  real_T Sum1_a[2];                    /* '<S1>/Sum1' */
  real_T Fcn3_n;                       /* '<S1>/Fcn3' */
  real_T Divide[2];                    /* '<S1>/Divide' */
  real_T Product1_h[2];                /* '<S1>/Product1' */
  real_T SumofForcesX;                 /* '<S1>/Sum of Forces - X' */
  real_T Product4;                     /* '<S2>/Product4' */
  real_T Fcn4;                         /* '<S2>/Fcn4' */
  real_T Divide_m[2];                  /* '<S2>/Divide' */
  real_T DotProduct_a;                 /* '<S2>/Dot Product' */
  real_T Saturation1;                  /* '<S2>/Saturation1' */
  real_T Product5_o;                   /* '<S2>/Product5' */
  real_T Product6;                     /* '<S2>/Product6' */
  real_T Gain3;                        /* '<S2>/Gain3' */
  real_T Product2_l[2];                /* '<S2>/Product2' */
  real_T AveX2;                        /* '<S2>/Ave X2' */
  real_T Product7;                     /* '<S2>/Product7' */
  real_T Product1_k[2];                /* '<S2>/Product1' */
  real_T AveX3[2];                     /* '<S2>/Ave X3' */
  real_T Product3_k[2];                /* '<S2>/Product3' */
  real_T SumofForcesX_d;               /* '<S2>/Sum of Forces - X' */
  real_T Gain;                         /* '<S1>/Gain' */
  real_T Product9;                     /* '<S1>/Product9' */
  real_T Product7_p;                   /* '<S1>/Product7' */
  real_T Product8;                     /* '<S1>/Product8' */
  real_T Sum2;                         /* '<S1>/Sum2' */
  real_T SumofForcesY;                 /* '<S1>/Sum of Forces - Y' */
  real_T Product8_m;                   /* '<S2>/Product8' */
  real_T SumofForcesY_n;               /* '<S2>/Sum of Forces - Y' */
  real_T Fxsinth2;                     /* '<S3>/Fxsin(th2)' */
  real_T Fxsinth21;                    /* '<S3>/Fxsin(th2)1' */
  real_T Sum_g;                        /* '<S3>/Sum' */
  real_T Fxsinth22;                    /* '<S3>/Fxsin(th2)2' */
  real_T Fxsinth23;                    /* '<S3>/Fxsin(th2)3' */
  real_T Sum1_j;                       /* '<S3>/Sum1' */
  real_T RateTransition1;              /* '<Root>/Rate Transition1' */
  real_T RateTransition2;              /* '<Root>/Rate Transition2' */
  real_T Derivative2;                  /* '<S4>/Derivative2' */
  real_T Derivative6;                  /* '<S4>/Derivative6' */
  real_T RateTransition1_e;            /* '<S6>/Rate Transition1' */
  real_T sin_th2;                      /* '<S6>/sin_th2' */
  real_T Fxsinth2_g;                   /* '<S6>/Fxsin(th2)' */
  real_T RateTransition;               /* '<S6>/Rate Transition' */
  real_T cos_th1;                      /* '<S6>/cos_th1' */
  real_T Fycosth2;                     /* '<S6>/Fycos(th2)' */
  real_T Sum_gb;                       /* '<S6>/Sum' */
  real_T Fxcosth2;                     /* '<S6>/Fxcos(th2)' */
  real_T Fysinth2;                     /* '<S6>/Fysin(th2)' */
  real_T Sum1_k;                       /* '<S6>/Sum1' */
  real_T Receive_o2;                   /* '<S1>/Receive' */
  real_T Subtract1;                    /* '<S1>/Subtract1' */
  real_T RectField;                    /* '<S2>/Rect Field' */
  real_T InputParam3_a;                /* '<Root>/Input Param3' */
  real_T Product;                      /* '<Root>/Product' */
  real_T Product1_n;                   /* '<Root>/Product1' */
  real_T Sum2_a;                       /* '<Root>/Sum2' */
  real_T Divide_i;                     /* '<Root>/Divide' */
  real_T Gain_o[4];                    /* '<S12>/Gain' */
  real_T th1th2pi;                     /* '<S5>/th1-th2-pi' */
  real_T Gain1_c[4];                   /* '<S12>/Gain1' */
  real_T Gain2_c[4];                   /* '<S12>/Gain2' */
  real_T Gain3_b[4];                   /* '<S12>/Gain3' */
  real_T Add[4];                       /* '<S12>/Add' */
  real_T TransferFcn1;                 /* '<S4>/Transfer Fcn1' */
  real_T Derivative5;                  /* '<S4>/Derivative5' */
  real_T Derivative4;                  /* '<S4>/Derivative4' */
  real_T TransferFcn2;                 /* '<S4>/Transfer Fcn2' */
  real_T Derivative7;                  /* '<S4>/Derivative7' */
  real_T Derivative8;                  /* '<S4>/Derivative8' */
  real_T TmpSignalConversionAtMatrixMult[2];
  real_T MatrixMultiply[2];            /* '<S5>/Matrix Multiply' */
  real_T Gain_i[4];                    /* '<S13>/Gain' */
  real_T th1th2pi1;                    /* '<S5>/th1-th2-pi1' */
  real_T Gain1_i[4];                   /* '<S13>/Gain1' */
  real_T Gain_p;                       /* '<S5>/Gain' */
  real_T Gain2_e[4];                   /* '<S13>/Gain2' */
  real_T Gain3_g[4];                   /* '<S13>/Gain3' */
  real_T Add_b[4];                     /* '<S13>/Add' */
  real_T squared1;                     /* '<S5>/squared1' */
  real_T squared;                      /* '<S5>/squared' */
  real_T TmpSignalConversionAtMatrixMu_k[2];
  real_T MatrixMultiply1[2];           /* '<S5>/Matrix Multiply1' */
  real_T Sum_a[2];                     /* '<S5>/Sum' */
  real_T Saturation2;                  /* '<Root>/Saturation2' */
  real_T Product2_o;                   /* '<Root>/Product2' */
  real_T Sum1_m;                       /* '<Root>/Sum1' */
  real_T ZeroOrderHold;                /* '<Root>/Zero-Order Hold' */
  real_T EGain;                        /* '<Root>/E Gain' */
  real_T Product3_a;                   /* '<Root>/Product3' */
  real_T RESET;                        /* '<Root>/RESET' */
  real_T Sum_o;                        /* '<Root>/Sum' */
  real_T ZeroOrderHold1;               /* '<Root>/Zero-Order Hold1' */
  real_T SGain;                        /* '<Root>/S Gain' */
  real_T Integrator;                   /* '<S7>/Integrator' */
  real_T Saturation1_p;                /* '<Root>/Saturation1' */
  real_T SGain3;                       /* '<Root>/S Gain3' */
  real_T Integrator_g;                 /* '<S8>/Integrator' */
  real_T Saturation;                   /* '<Root>/Saturation' */
  real_T SGain4;                       /* '<Root>/S Gain4' */
  real_T Bit1_o1;                      /* '<S14>/Bit1' */
  real_T Bit1_o2;                      /* '<S14>/Bit1' */
  real_T Bits181_o1;                   /* '<S14>/Bits1-8 1' */
  real_T Bits181_o2;                   /* '<S14>/Bits1-8 1' */
  real_T Bits181_o3;                   /* '<S14>/Bits1-8 1' */
  real_T Bits181_o4;                   /* '<S14>/Bits1-8 1' */
  real_T Bits181_o5;                   /* '<S14>/Bits1-8 1' */
  real_T Bits181_o6;                   /* '<S14>/Bits1-8 1' */
  real_T Bits181_o7;                   /* '<S14>/Bits1-8 1' */
  real_T Bits181_o8;                   /* '<S14>/Bits1-8 1' */
  real_T Bits91_o1;                    /* '<S14>/Bits9-1' */
  real_T Bits91_o2;                    /* '<S14>/Bits9-1' */
  real_T Bits91_o3;                    /* '<S14>/Bits9-1' */
  real_T Bits91_o4;                    /* '<S14>/Bits9-1' */
  real_T Bits91_o5;                    /* '<S14>/Bits9-1' */
  real_T Bits91_o6;                    /* '<S14>/Bits9-1' */
  real_T Bits91_o7;                    /* '<S14>/Bits9-1' */
  real_T Bits91_o8;                    /* '<S14>/Bits9-1' */
  real_T Sum_ga;                       /* '<S17>/Sum' */
  real_T MathFunction;                 /* '<S17>/Math Function' */
  real_T PulseGenerator1;              /* '<S14>/Pulse Generator1' */
  real_T PCI6031EAD_o1;                /* '<S6>/PCI-6031E AD' */
  real_T PCI6031EAD_o2;                /* '<S6>/PCI-6031E AD' */
  real_T PCI6031EAD_o3;                /* '<S6>/PCI-6031E AD' */
  real_T PCI6031EAD_o4;                /* '<S6>/PCI-6031E AD' */
  real_T PCI6031EAD_o5;                /* '<S6>/PCI-6031E AD' */
  real_T PCI6031EAD_o6;                /* '<S6>/PCI-6031E AD' */
  real_T Bit17_o1;                     /* '<S16>/Bit17' */
  real_T Bit17_o2;                     /* '<S16>/Bit17' */
  real_T Bits18_o1;                    /* '<S16>/Bits1-8 ' */
  real_T Bits18_o2;                    /* '<S16>/Bits1-8 ' */
  real_T Bits18_o3;                    /* '<S16>/Bits1-8 ' */
  real_T Bits18_o4;                    /* '<S16>/Bits1-8 ' */
  real_T Bits18_o5;                    /* '<S16>/Bits1-8 ' */
  real_T Bits18_o6;                    /* '<S16>/Bits1-8 ' */
  real_T Bits18_o7;                    /* '<S16>/Bits1-8 ' */
  real_T Bits18_o8;                    /* '<S16>/Bits1-8 ' */
  real_T Bits916_o1;                   /* '<S16>/Bits9-16' */
  real_T Bits916_o2;                   /* '<S16>/Bits9-16' */
  real_T Bits916_o3;                   /* '<S16>/Bits9-16' */
  real_T Bits916_o4;                   /* '<S16>/Bits9-16' */
  real_T Bits916_o5;                   /* '<S16>/Bits9-16' */
  real_T Bits916_o6;                   /* '<S16>/Bits9-16' */
  real_T Bits916_o7;                   /* '<S16>/Bits9-16' */
  real_T Bits916_o8;                   /* '<S16>/Bits9-16' */
  real_T Sum_d;                        /* '<S18>/Sum' */
  real_T MathFunction_p;               /* '<S18>/Math Function' */
  real_T PulseGenerator;               /* '<S16>/Pulse Generator' */
  real_T Xy;                           /* '<S6>/Xy' */
  real_T Xy2;                          /* '<S6>/Xy2' */
  real_T f;                            /* '<S6>/f' */
  real_T f1;                           /* '<S6>/f1' */
  real_T Function2Canbeafunctionofstates;/* '<S7>/Function2: Can be a function of states and parameters' */
  real_T Function2Canbeafunctionofstat_n;/* '<S8>/Function2: Can be a function of states and parameters' */
  real_T FilterCutoffFreq;             /* '<Root>/FilterCutoffFreq' */
  real_T FilterZeta;                   /* '<Root>/FilterZeta' */
  uint8_T RateTransition3[48];         /* '<S1>/Rate Transition3' */
  uint8_T Pack1[72];                   /* '<Root>/Pack1' */
  uint8_T RateTransition_i[72];        /* '<Root>/Rate Transition' */
  uint8_T Receive_o1[48];              /* '<S1>/Receive' */
} BlockIO_BasicModelTarget;

/* Block states (auto storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE[17];         /* '<S16>/Unit Delay' */
  real_T UnitDelay_DSTATE_o[17];       /* '<S14>/Unit Delay' */
  real_T RateTransition1_Buffer0;      /* '<Root>/Rate Transition1' */
  real_T RateTransition2_Buffer0;      /* '<Root>/Rate Transition2' */
  real_T RateTransition1_Buffer0_g;    /* '<S6>/Rate Transition1' */
  real_T RateTransition_Buffer0;       /* '<S6>/Rate Transition' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative1_RWORK;                 /* '<S4>/Derivative1' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative3_RWORK;                 /* '<S4>/Derivative3' */

  real_T PCI6031EDA_RWORK[6];          /* '<Root>/PCI-6031E DA' */
  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative2_RWORK;                 /* '<S4>/Derivative2' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative6_RWORK;                 /* '<S4>/Derivative6' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative5_RWORK;                 /* '<S4>/Derivative5' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative4_RWORK;                 /* '<S4>/Derivative4' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative7_RWORK;                 /* '<S4>/Derivative7' */

  struct {
    real_T TimeStampA;
    real_T LastUAtTimeA;
    real_T TimeStampB;
    real_T LastUAtTimeB;
  } Derivative8_RWORK;                 /* '<S4>/Derivative8' */

  real_T PCI6031EAD_RWORK[64];         /* '<S6>/PCI-6031E AD' */
  void *Send_PWORK;                    /* '<Root>/Send' */
  void *Receive_PWORK;                 /* '<S1>/Receive' */
  int32_T clockTickCounter;            /* '<S14>/Pulse Generator1' */
  int32_T clockTickCounter_i;          /* '<S16>/Pulse Generator' */
  int_T PCI6031EDA_IWORK[2];           /* '<Root>/PCI-6031E DA' */
  int_T Send_IWORK[2];                 /* '<Root>/Send' */
  struct {
    int_T AcquireOK;
  } SFunction_IWORK;                   /* '<S9>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_i;                 /* '<S10>/S-Function' */

  struct {
    int_T AcquireOK;
  } SFunction_IWORK_l;                 /* '<S11>/S-Function' */

  int_T Receive_IWORK[2];              /* '<S1>/Receive' */
  int_T Bit1_IWORK[2];                 /* '<S14>/Bit1' */
  int_T Bits181_IWORK[2];              /* '<S14>/Bits1-8 1' */
  int_T Bits91_IWORK[2];               /* '<S14>/Bits9-1' */
  int_T PCIDIO961_IWORK[2];            /* '<S14>/PCI-DIO-96 1' */
  int_T PCI6031EAD_IWORK[66];          /* '<S6>/PCI-6031E AD' */
  int_T Bit17_IWORK[2];                /* '<S16>/Bit17' */
  int_T Bits18_IWORK[2];               /* '<S16>/Bits1-8 ' */
  int_T Bits916_IWORK[2];              /* '<S16>/Bits9-16' */
  int_T IntOE_IWORK[2];                /* '<S16>/Int & OE' */
  uint8_T RateTransition3_Buffer0[48]; /* '<S1>/Rate Transition3' */
} D_Work_BasicModelTarget;

/* Continuous states (auto storage) */
typedef struct {
  real_T TransferFcn8_CSTATE[3];       /* '<S4>/Transfer Fcn8' */
  real_T TransferFcn9_CSTATE[3];       /* '<S4>/Transfer Fcn9' */
  real_T TransferFcn1_CSTATE[3];       /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[3];       /* '<S4>/Transfer Fcn2' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S8>/Integrator' */
} ContinuousStates_BasicModelTarget;

/* State derivatives (auto storage) */
typedef struct {
  real_T TransferFcn8_CSTATE[3];       /* '<S4>/Transfer Fcn8' */
  real_T TransferFcn9_CSTATE[3];       /* '<S4>/Transfer Fcn9' */
  real_T TransferFcn1_CSTATE[3];       /* '<S4>/Transfer Fcn1' */
  real_T TransferFcn2_CSTATE[3];       /* '<S4>/Transfer Fcn2' */
  real_T Integrator_CSTATE;            /* '<S7>/Integrator' */
  real_T Integrator_CSTATE_l;          /* '<S8>/Integrator' */
} StateDerivatives_BasicModelTarget;

/* State disabled  */
typedef struct {
  boolean_T TransferFcn8_CSTATE[3];    /* '<S4>/Transfer Fcn8' */
  boolean_T TransferFcn9_CSTATE[3];    /* '<S4>/Transfer Fcn9' */
  boolean_T TransferFcn1_CSTATE[3];    /* '<S4>/Transfer Fcn1' */
  boolean_T TransferFcn2_CSTATE[3];    /* '<S4>/Transfer Fcn2' */
  boolean_T Integrator_CSTATE;         /* '<S7>/Integrator' */
  boolean_T Integrator_CSTATE_l;       /* '<S8>/Integrator' */
} StateDisabled_BasicModelTarget;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Integrator_Reset_ZCE;     /* '<S7>/Integrator' */
  ZCSigState Integrator_Reset_ZCE_k;   /* '<S8>/Integrator' */
} PrevZCSigStates_BasicModelTarget;

#ifndef ODE5_INTG
#define ODE5_INTG

/* ODE5 Integration Data */
typedef struct {
  real_T *y;                           /* output */
  real_T *f[6];                        /* derivatives */
} ODE5_IntgData;

#endif

/* External outputs (root outports fed by signals with auto storage) */
typedef struct {
  real_T Time_Out1s;                   /* '<Root>/Time_Out1   [s]' */
  real_T Displayedxm;                  /* '<Root>/Displayed x [m]' */
  real_T DisplayedYm;                  /* '<Root>/Displayed Y [m]' */
  real_T X_Handlem;                    /* '<Root>/X_Handle  [m]' */
  real_T Y_Handlem;                    /* '<Root>/Y_Handle   [m]' */
  real_T ForceX;                       /* '<Root>/ForceX' */
  real_T ForceY;                       /* '<Root>/ForceY' */
  real_T Trget_Flag_Out1;              /* '<Root>/Trget_Flag_Out1' */
  real_T Trget_Flag_Out3;              /* '<Root>/Trget_Flag_Out3' */
} ExternalOutputs_BasicModelTarget;

/* Backward compatible GRT Identifiers */
#define rtB                            BasicModelTarget_B
#define BlockIO                        BlockIO_BasicModelTarget
#define rtX                            BasicModelTarget_X
#define ContinuousStates               ContinuousStates_BasicModelTarget
#define rtY                            BasicModelTarget_Y
#define ExternalOutputs                ExternalOutputs_BasicModelTarget
#define rtP                            BasicModelTarget_P
#define Parameters                     Parameters_BasicModelTarget
#define rtDWork                        BasicModelTarget_DWork
#define D_Work                         D_Work_BasicModelTarget
#define rtPrevZCSigState               BasicModelTarget_PrevZCSigState
#define PrevZCSigStates                PrevZCSigStates_BasicModelTarget

/* Parameters (auto storage) */
struct Parameters_BasicModelTarget_ {
  real_T OffsetShoulderOFFSETSH_Value; /* Expression: 59430
                                        * Referenced by: '<S16>/Offset Shoulder (OFFSETSH) '
                                        */
  real_T BitsRadianTRIG_SCALE_Value;   /* Expression: 0.0000479368996214262884295
                                        * Referenced by: '<S16>/Bits//Radian (TRIG_SCALE)'
                                        */
  real_T Vector217_Value[17];          /* Expression: [1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536]
                                        * Referenced by: '<S16>/Vector 2^17'
                                        */
  real_T UnitDelay_X0;                 /* Expression: 0
                                        * Referenced by: '<S16>/Unit Delay'
                                        */
  real_T OffsetElbowOFFSETEL_Value;    /* Expression: 75060
                                        * Referenced by: '<S14>/Offset Elbow (OFFSETEL) '
                                        */
  real_T BitsRadianTRIG_SCALE_Value_p; /* Expression: 0.0000479368996214262884295
                                        * Referenced by: '<S14>/Bits//Radian (TRIG_SCALE)'
                                        */
  real_T Const_Value;                  /* Expression: pi/2
                                        * Referenced by: '<S14>/Const'
                                        */
  real_T Constant2_Value[17];          /* Expression: [1 2 4 8 16 32 64 128 256 512 1024 2048 4096 8192 16384 32768 65536]
                                        * Referenced by: '<S14>/Constant2'
                                        */
  real_T UnitDelay_X0_o;               /* Expression: 0
                                        * Referenced by: '<S14>/Unit Delay'
                                        */
  real_T ALPHA_Value;                  /* Expression: 0.11783577990381
                                        * Referenced by: '<S14>/(ALPHA)'
                                        */
  real_T TransferFcn8_A[3];            /* Computed Parameter: TransferFcn8_A
                                        * Referenced by: '<S4>/Transfer Fcn8'
                                        */
  real_T TransferFcn8_C[3];            /* Computed Parameter: TransferFcn8_C
                                        * Referenced by: '<S4>/Transfer Fcn8'
                                        */
  real_T InputParam_Value;             /* Expression: 0
                                        * Referenced by: '<Root>/Input Param'
                                        */
  real_T InputParam1_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Input Param1'
                                        */
  real_T InputParam2_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/Input Param2'
                                        */
  real_T InputParam3_Value;            /* Expression: 0
                                        * Referenced by: '<Root>/InputParam3'
                                        */
  real_T TransferFcn9_A[3];            /* Computed Parameter: TransferFcn9_A
                                        * Referenced by: '<S4>/Transfer Fcn9'
                                        */
  real_T TransferFcn9_C[3];            /* Computed Parameter: TransferFcn9_C
                                        * Referenced by: '<S4>/Transfer Fcn9'
                                        */
  real_T xwm_Value;                    /* Expression: .282
                                        * Referenced by: '<S2>/xwm'
                                        */
  real_T xwp_Value;                    /* Expression: -.32
                                        * Referenced by: '<S2>/xwp'
                                        */
  real_T Gain1_Gain;                   /* Expression: .5
                                        * Referenced by: '<S2>/Gain1'
                                        */
  real_T ywm_Value;                    /* Expression: .66
                                        * Referenced by: '<S2>/ywm'
                                        */
  real_T ywp_Value;                    /* Expression: .36
                                        * Referenced by: '<S2>/ywp'
                                        */
  real_T Gain2_Gain;                   /* Expression: .5
                                        * Referenced by: '<S2>/Gain2'
                                        */
  real_T r_Value;                      /* Expression: .2
                                        * Referenced by: '<S2>/r'
                                        */
  real_T One_Value;                    /* Expression: 1
                                        * Referenced by: '<S2>/One'
                                        */
  real_T Saturation1_UpperSat;         /* Expression: inf
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Saturation1_LowerSat;         /* Expression: 0
                                        * Referenced by: '<S2>/Saturation1'
                                        */
  real_T Bwall_Value;                  /* Expression: 200
                                        * Referenced by: '<S2>/Bwall'
                                        */
  real_T Gain3_Gain;                   /* Expression: -1
                                        * Referenced by: '<S2>/Gain3'
                                        */
  real_T Kwall_Value;                  /* Expression: 60
                                        * Referenced by: '<S2>/Kwall'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S1>/Gain'
                                        */
  real_T RateTransition1_X0;           /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition1'
                                        */
  real_T RateTransition2_X0;           /* Expression: 0
                                        * Referenced by: '<Root>/Rate Transition2'
                                        */
  real_T PCI6031EDA_P1_Size[2];        /* Computed Parameter: PCI6031EDA_P1_Size
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P1[2];             /* Expression: channel
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P2_Size[2];        /* Computed Parameter: PCI6031EDA_P2_Size
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P2[2];             /* Expression: range
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P3_Size[2];        /* Computed Parameter: PCI6031EDA_P3_Size
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P3[2];             /* Expression: reset
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P4_Size[2];        /* Computed Parameter: PCI6031EDA_P4_Size
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P4[2];             /* Expression: initValue
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P5_Size[2];        /* Computed Parameter: PCI6031EDA_P5_Size
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P5;                /* Expression: sampletime
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P6_Size[2];        /* Computed Parameter: PCI6031EDA_P6_Size
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P6;                /* Expression: slot
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P7_Size[2];        /* Computed Parameter: PCI6031EDA_P7_Size
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T PCI6031EDA_P7;                /* Expression: boardType
                                        * Referenced by: '<Root>/PCI-6031E DA'
                                        */
  real_T RateTransition1_X0_n;         /* Expression: 0
                                        * Referenced by: '<S6>/Rate Transition1'
                                        */
  real_T RateTransition_X0;            /* Expression: 0
                                        * Referenced by: '<S6>/Rate Transition'
                                        */
  real_T Send_P1_Size[2];              /* Computed Parameter: Send_P1_Size
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P1[11];                  /* Computed Parameter: Send_P1
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P2_Size[2];              /* Computed Parameter: Send_P2_Size
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P2;                      /* Expression: ipPort
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P3_Size[2];              /* Computed Parameter: Send_P3_Size
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P3;                      /* Expression: localPort
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P4_Size[2];              /* Computed Parameter: Send_P4_Size
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P4;                      /* Expression: sampletime
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P5_Size[2];              /* Computed Parameter: Send_P5_Size
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Send_P5;                      /* Expression: vblLen
                                        * Referenced by: '<Root>/Send'
                                        */
  real_T Receive_P1_Size[2];           /* Computed Parameter: Receive_P1_Size
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P1[7];                /* Computed Parameter: Receive_P1
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P2_Size[2];           /* Computed Parameter: Receive_P2_Size
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P2;                   /* Expression: ipPort
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P3_Size[2];           /* Computed Parameter: Receive_P3_Size
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P3;                   /* Expression: width
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P4_Size[2];           /* Computed Parameter: Receive_P4_Size
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P4;                   /* Expression: sampletime
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P5_Size[2];           /* Computed Parameter: Receive_P5_Size
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T Receive_P5;                   /* Expression: vblLen
                                        * Referenced by: '<S1>/Receive'
                                        */
  real_T RectField_Value;              /* Expression: 0
                                        * Referenced by: '<S2>/Rect Field'
                                        */
  real_T InputParam3_Value_g;          /* Expression: .45
                                        * Referenced by: '<Root>/Input Param3'
                                        */
  real_T A_Value;                      /* Expression: .23277
                                        * Referenced by: '<S5>/A'
                                        */
  real_T Gain_Gain_p[4];               /* Expression: [1, 0; 0, 0]
                                        * Referenced by: '<S12>/Gain'
                                        */
  real_T B_Value;                      /* Expression: .046586
                                        * Referenced by: '<S5>/B'
                                        */
  real_T Gain1_Gain_g[4];              /* Expression: [0, 1; 0, 0]
                                        * Referenced by: '<S12>/Gain1'
                                        */
  real_T Gain2_Gain_e[4];              /* Expression: [0, 0; 1, 0]
                                        * Referenced by: '<S12>/Gain2'
                                        */
  real_T C_Value;                      /* Expression: .041126
                                        * Referenced by: '<S5>/C '
                                        */
  real_T Gain3_Gain_j[4];              /* Expression: [0, 0; 0, 1]
                                        * Referenced by: '<S12>/Gain3'
                                        */
  real_T TransferFcn1_A[3];            /* Computed Parameter: TransferFcn1_A
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn1_C[3];            /* Computed Parameter: TransferFcn1_C
                                        * Referenced by: '<S4>/Transfer Fcn1'
                                        */
  real_T TransferFcn2_A[3];            /* Computed Parameter: TransferFcn2_A
                                        * Referenced by: '<S4>/Transfer Fcn2'
                                        */
  real_T TransferFcn2_C[3];            /* Computed Parameter: TransferFcn2_C
                                        * Referenced by: '<S4>/Transfer Fcn2'
                                        */
  real_T C1_Value;                     /* Expression: 0
                                        * Referenced by: '<S5>/C 1'
                                        */
  real_T Gain_Gain_g[4];               /* Expression: [1, 0; 0, 0]
                                        * Referenced by: '<S13>/Gain'
                                        */
  real_T Gain1_Gain_gy[4];             /* Expression: [0, 1; 0, 0]
                                        * Referenced by: '<S13>/Gain1'
                                        */
  real_T Gain_Gain_c;                  /* Expression: -1
                                        * Referenced by: '<S5>/Gain'
                                        */
  real_T Gain2_Gain_f[4];              /* Expression: [0, 0; 1, 0]
                                        * Referenced by: '<S13>/Gain2'
                                        */
  real_T C2_Value;                     /* Expression: 0
                                        * Referenced by: '<S5>/C 2'
                                        */
  real_T Gain3_Gain_a[4];              /* Expression: [0, 0; 0, 1]
                                        * Referenced by: '<S13>/Gain3'
                                        */
  real_T Saturation2_UpperSat;         /* Expression: .4
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T Saturation2_LowerSat;         /* Expression: 0
                                        * Referenced by: '<Root>/Saturation2'
                                        */
  real_T EGain_Gain;                   /* Expression: 1.1421  % from PCIO.H: [Nm] per Volt for the motor
                                        * Referenced by: '<Root>/E Gain'
                                        */
  real_T RESET_Value;                  /* Expression: 1
                                        * Referenced by: '<Root>/RESET'
                                        */
  real_T SGain_Gain;                   /* Expression: -1.1421  % from PCIO.H: [Nm] per Volt for the motor
                                        * Referenced by: '<Root>/S Gain'
                                        */
  real_T Integrator_IC;                /* Expression: 0
                                        * Referenced by: '<S7>/Integrator'
                                        */
  real_T Saturation1_UpperSat_j;       /* Expression: 20
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T Saturation1_LowerSat_n;       /* Expression: -20
                                        * Referenced by: '<Root>/Saturation1'
                                        */
  real_T SGain3_Gain;                  /* Expression: 0
                                        * Referenced by: '<Root>/S Gain3'
                                        */
  real_T Integrator_IC_k;              /* Expression: 0
                                        * Referenced by: '<S8>/Integrator'
                                        */
  real_T Saturation_UpperSat;          /* Expression: 20
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T Saturation_LowerSat;          /* Expression: -20
                                        * Referenced by: '<Root>/Saturation'
                                        */
  real_T SGain4_Gain;                  /* Expression: 0
                                        * Referenced by: '<Root>/S Gain4'
                                        */
  real_T Bit1_P1_Size[2];              /* Computed Parameter: Bit1_P1_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P1[2];                   /* Expression: channel
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P2_Size[2];              /* Computed Parameter: Bit1_P2_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P2;                      /* Expression: port
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P3_Size[2];              /* Computed Parameter: Bit1_P3_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P3[3];                   /* Expression: ival
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P4_Size[2];              /* Computed Parameter: Bit1_P4_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P4;                      /* Expression: chip
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P5_Size[2];              /* Computed Parameter: Bit1_P5_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P5;                      /* Expression: sampletime
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P6_Size[2];              /* Computed Parameter: Bit1_P6_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P6;                      /* Expression: slot
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P7_Size[2];              /* Computed Parameter: Bit1_P7_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P7;                      /* Expression: control
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P8_Size[2];              /* Computed Parameter: Bit1_P8_Size
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bit1_P8;                      /* Expression: boardType
                                        * Referenced by: '<S14>/Bit1'
                                        */
  real_T Bits181_P1_Size[2];           /* Computed Parameter: Bits181_P1_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P1[8];                /* Expression: channel
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P2_Size[2];           /* Computed Parameter: Bits181_P2_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P2;                   /* Expression: port
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P3_Size[2];           /* Computed Parameter: Bits181_P3_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P3[3];                /* Expression: ival
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P4_Size[2];           /* Computed Parameter: Bits181_P4_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P4;                   /* Expression: chip
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P5_Size[2];           /* Computed Parameter: Bits181_P5_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P5;                   /* Expression: sampletime
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P6_Size[2];           /* Computed Parameter: Bits181_P6_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P6;                   /* Expression: slot
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P7_Size[2];           /* Computed Parameter: Bits181_P7_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P7;                   /* Expression: control
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P8_Size[2];           /* Computed Parameter: Bits181_P8_Size
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits181_P8;                   /* Expression: boardType
                                        * Referenced by: '<S14>/Bits1-8 1'
                                        */
  real_T Bits91_P1_Size[2];            /* Computed Parameter: Bits91_P1_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P1[8];                 /* Expression: channel
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P2_Size[2];            /* Computed Parameter: Bits91_P2_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P2;                    /* Expression: port
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P3_Size[2];            /* Computed Parameter: Bits91_P3_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P3[3];                 /* Expression: ival
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P4_Size[2];            /* Computed Parameter: Bits91_P4_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P4;                    /* Expression: chip
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P5_Size[2];            /* Computed Parameter: Bits91_P5_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P5;                    /* Expression: sampletime
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P6_Size[2];            /* Computed Parameter: Bits91_P6_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P6;                    /* Expression: slot
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P7_Size[2];            /* Computed Parameter: Bits91_P7_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P7;                    /* Expression: control
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P8_Size[2];            /* Computed Parameter: Bits91_P8_Size
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Bits91_P8;                    /* Expression: boardType
                                        * Referenced by: '<S14>/Bits9-1'
                                        */
  real_T Constant_Value;               /* Expression: 2
                                        * Referenced by: '<S17>/Constant'
                                        */
  real_T PulseGenerator1_Amp;          /* Expression: 1
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Period;       /* Expression: 2
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_Duty;         /* Expression: 1
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  real_T PulseGenerator1_PhaseDelay;   /* Expression: 0
                                        * Referenced by: '<S14>/Pulse Generator1'
                                        */
  real_T Constant3_Value;              /* Expression: 0
                                        * Referenced by: '<S14>/Constant3'
                                        */
  real_T PCIDIO961_P1_Size[2];         /* Computed Parameter: PCIDIO961_P1_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P1[2];              /* Expression: channel
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P2_Size[2];         /* Computed Parameter: PCIDIO961_P2_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P2;                 /* Expression: port
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P3_Size[2];         /* Computed Parameter: PCIDIO961_P3_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P3[2];              /* Expression: reset
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P4_Size[2];         /* Computed Parameter: PCIDIO961_P4_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P4[2];              /* Expression: initValue
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P5_Size[2];         /* Computed Parameter: PCIDIO961_P5_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P5[3];              /* Expression: ival
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P6_Size[2];         /* Computed Parameter: PCIDIO961_P6_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P6;                 /* Expression: chip
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P7_Size[2];         /* Computed Parameter: PCIDIO961_P7_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P7;                 /* Expression: sampletime
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P8_Size[2];         /* Computed Parameter: PCIDIO961_P8_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P8;                 /* Expression: slot
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P9_Size[2];         /* Computed Parameter: PCIDIO961_P9_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P9;                 /* Expression: control
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P10_Size[2];        /* Computed Parameter: PCIDIO961_P10_Size
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCIDIO961_P10;                /* Expression: boardType
                                        * Referenced by: '<S14>/PCI-DIO-96 1'
                                        */
  real_T PCI6031EAD_P1_Size[2];        /* Computed Parameter: PCI6031EAD_P1_Size
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P1[6];             /* Expression: channel
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P2_Size[2];        /* Computed Parameter: PCI6031EAD_P2_Size
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P2[6];             /* Expression: range
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P3_Size[2];        /* Computed Parameter: PCI6031EAD_P3_Size
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P3[6];             /* Expression: coupling
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P4_Size[2];        /* Computed Parameter: PCI6031EAD_P4_Size
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P4;                /* Expression: sampletime
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P5_Size[2];        /* Computed Parameter: PCI6031EAD_P5_Size
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P5;                /* Expression: slot
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P6_Size[2];        /* Computed Parameter: PCI6031EAD_P6_Size
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T PCI6031EAD_P6;                /* Expression: boardType
                                        * Referenced by: '<S6>/PCI-6031E AD'
                                        */
  real_T Bit17_P1_Size[2];             /* Computed Parameter: Bit17_P1_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P1[2];                  /* Expression: channel
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P2_Size[2];             /* Computed Parameter: Bit17_P2_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P2;                     /* Expression: port
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P3_Size[2];             /* Computed Parameter: Bit17_P3_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P3[3];                  /* Expression: ival
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P4_Size[2];             /* Computed Parameter: Bit17_P4_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P4;                     /* Expression: chip
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P5_Size[2];             /* Computed Parameter: Bit17_P5_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P5;                     /* Expression: sampletime
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P6_Size[2];             /* Computed Parameter: Bit17_P6_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P6;                     /* Expression: slot
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P7_Size[2];             /* Computed Parameter: Bit17_P7_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P7;                     /* Expression: control
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P8_Size[2];             /* Computed Parameter: Bit17_P8_Size
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bit17_P8;                     /* Expression: boardType
                                        * Referenced by: '<S16>/Bit17'
                                        */
  real_T Bits18_P1_Size[2];            /* Computed Parameter: Bits18_P1_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P1[8];                 /* Expression: channel
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P2_Size[2];            /* Computed Parameter: Bits18_P2_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P2;                    /* Expression: port
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P3_Size[2];            /* Computed Parameter: Bits18_P3_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P3[3];                 /* Expression: ival
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P4_Size[2];            /* Computed Parameter: Bits18_P4_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P4;                    /* Expression: chip
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P5_Size[2];            /* Computed Parameter: Bits18_P5_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P5;                    /* Expression: sampletime
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P6_Size[2];            /* Computed Parameter: Bits18_P6_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P6;                    /* Expression: slot
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P7_Size[2];            /* Computed Parameter: Bits18_P7_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P7;                    /* Expression: control
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P8_Size[2];            /* Computed Parameter: Bits18_P8_Size
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits18_P8;                    /* Expression: boardType
                                        * Referenced by: '<S16>/Bits1-8 '
                                        */
  real_T Bits916_P1_Size[2];           /* Computed Parameter: Bits916_P1_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P1[8];                /* Expression: channel
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P2_Size[2];           /* Computed Parameter: Bits916_P2_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P2;                   /* Expression: port
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P3_Size[2];           /* Computed Parameter: Bits916_P3_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P3[3];                /* Expression: ival
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P4_Size[2];           /* Computed Parameter: Bits916_P4_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P4;                   /* Expression: chip
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P5_Size[2];           /* Computed Parameter: Bits916_P5_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P5;                   /* Expression: sampletime
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P6_Size[2];           /* Computed Parameter: Bits916_P6_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P6;                   /* Expression: slot
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P7_Size[2];           /* Computed Parameter: Bits916_P7_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P7;                   /* Expression: control
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P8_Size[2];           /* Computed Parameter: Bits916_P8_Size
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Bits916_P8;                   /* Expression: boardType
                                        * Referenced by: '<S16>/Bits9-16'
                                        */
  real_T Constant_Value_p;             /* Expression: 2
                                        * Referenced by: '<S18>/Constant'
                                        */
  real_T PulseGenerator_Amp;           /* Expression: 1
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  real_T PulseGenerator_Period;        /* Expression: 2
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  real_T PulseGenerator_Duty;          /* Expression: 1
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  real_T PulseGenerator_PhaseDelay;    /* Expression: 0
                                        * Referenced by: '<S16>/Pulse Generator'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S16>/Constant1'
                                        */
  real_T IntOE_P1_Size[2];             /* Computed Parameter: IntOE_P1_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P1[2];                  /* Expression: channel
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P2_Size[2];             /* Computed Parameter: IntOE_P2_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P2;                     /* Expression: port
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P3_Size[2];             /* Computed Parameter: IntOE_P3_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P3[2];                  /* Expression: reset
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P4_Size[2];             /* Computed Parameter: IntOE_P4_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P4[2];                  /* Expression: initValue
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P5_Size[2];             /* Computed Parameter: IntOE_P5_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P5[3];                  /* Expression: ival
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P6_Size[2];             /* Computed Parameter: IntOE_P6_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P6;                     /* Expression: chip
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P7_Size[2];             /* Computed Parameter: IntOE_P7_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P7;                     /* Expression: sampletime
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P8_Size[2];             /* Computed Parameter: IntOE_P8_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P8;                     /* Expression: slot
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P9_Size[2];             /* Computed Parameter: IntOE_P9_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P9;                     /* Expression: control
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P10_Size[2];            /* Computed Parameter: IntOE_P10_Size
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T IntOE_P10;                    /* Expression: boardType
                                        * Referenced by: '<S16>/Int & OE'
                                        */
  real_T Xy_Gain;                      /* Expression: 13.3447
                                        * Referenced by: '<S6>/Xy'
                                        */
  real_T Xy2_Gain;                     /* Expression: 2.2597
                                        * Referenced by: '<S6>/Xy2'
                                        */
  real_T f_Gain;                       /* Expression: 13.3447
                                        * Referenced by: '<S6>/f'
                                        */
  real_T f1_Gain;                      /* Expression: 2.2597
                                        * Referenced by: '<S6>/f1'
                                        */
  real_T FilterCutoffFreq_Value;       /* Expression: 100
                                        * Referenced by: '<Root>/FilterCutoffFreq'
                                        */
  real_T FilterZeta_Value;             /* Expression: .9
                                        * Referenced by: '<Root>/FilterZeta'
                                        */
  uint8_T RateTransition3_X0;          /* Computed Parameter: RateTransition3_X0
                                        * Referenced by: '<S1>/Rate Transition3'
                                        */
};

/* Real-time Model Data Structure */
struct rtModel_BasicModelTarget {
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
    SimStruct childSFunctions[12];
    SimStruct *childSFunctionPtrs[12];
    struct _ssBlkInfo2 blkInfo2[12];
    struct _ssSFcnModelMethods2 methods2[12];
    struct _ssSFcnModelMethods3 methods3[12];
    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[7];
      mxArray *params[7];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn0;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[1];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn1;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[5];
      mxArray *params[5];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn2;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn3;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn4;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn5;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn6;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[6];
      uint_T attribs[6];
      mxArray *params[6];
      struct _ssDWorkRecord dWork[2];
      struct _ssDWorkAuxRecord dWorkAux[2];
    } Sfcn7;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[2];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn8;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn9;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortOutputs outputPortInfo[8];
      uint_T attribs[8];
      mxArray *params[8];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn10;

    struct {
      time_T sfcnPeriod[1];
      time_T sfcnOffset[1];
      int_T sfcnTsMap[1];
      struct _ssPortInputs inputPortInfo[2];
      real_T const *UPtrs0[1];
      real_T const *UPtrs1[1];
      uint_T attribs[10];
      mxArray *params[10];
      struct _ssDWorkRecord dWork[1];
      struct _ssDWorkAuxRecord dWorkAux[1];
    } Sfcn11;
  } NonInlinedSFcns;

  /*
   * DataMapInfo:
   * The following substructure contains information regarding
   * structures generated in the model's C API.
   */
  struct {
    rtwCAPI_ModelMappingInfo mmi;
  } DataMapInfo;

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
    real_T odeY[14];
    real_T odeF[6][14];
    ODE5_IntgData intgData;
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
    uint32_T clockTick2;
    uint32_T clockTickH2;
    time_T stepSize2;
    uint32_T clockTick3;
    uint32_T clockTickH3;
    time_T stepSize3;
    uint32_T clockTick4;
    uint32_T clockTickH4;
    time_T stepSize4;
    struct {
      uint8_T TID[5];
    } TaskCounters;

    struct {
      boolean_T TID0_3;
      boolean_T TID1_2;
      boolean_T TID1_4;
      boolean_T TID2_3;
    } RateInteraction;

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
    time_T sampleTimesArray[5];
    time_T offsetTimesArray[5];
    int_T sampleTimeTaskIDArray[5];
    int_T sampleHitArray[5];
    int_T perTaskSampleHitsArray[25];
    time_T tArray[5];
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
extern Parameters_BasicModelTarget BasicModelTarget_P;

/* Block signals (auto storage) */
extern BlockIO_BasicModelTarget BasicModelTarget_B;

/* Continuous states (auto storage) */
extern ContinuousStates_BasicModelTarget BasicModelTarget_X;

/* Block states (auto storage) */
extern D_Work_BasicModelTarget BasicModelTarget_DWork;

/* External outputs (root outports fed by signals with auto storage) */
extern ExternalOutputs_BasicModelTarget BasicModelTarget_Y;

/* External function called from main */
extern time_T rt_SimUpdateDiscreteEvents(
  int_T rtmNumSampTimes, void *rtmTimingData, int_T *rtmSampleHitPtr, int_T
  *rtmPerTaskSampleHits )
  ;

/* External data declarations for dependent source files */

/* Zero-crossing (trigger) state */
extern PrevZCSigStates_BasicModelTarget BasicModelTarget_PrevZCSigState;

/* Model entry point functions */
extern void BasicModelTarget_SetEventsForThisBaseStep(boolean_T *eventFlags);
extern void BasicModelTarget_initialize(boolean_T firstTime);
extern void BasicModelTarget_output(int_T tid);
extern void BasicModelTarget_update(int_T tid);
extern void BasicModelTarget_terminate(void);

/* Real-time Model object */
extern struct rtModel_BasicModelTarget *BasicModelTarget_rtM;

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
 * '<Root>' : BasicModelTarget
 * '<S1>'   : BasicModelTarget/ Calculate Additional Forces from UDP input
 * '<S2>'   : BasicModelTarget/ Pillow Subsystem]
 * '<S3>'   : BasicModelTarget/Endpoint Forces to Motor Torques
 * '<S4>'   : BasicModelTarget/Filtered  Velocity Calculations
 * '<S5>'   : BasicModelTarget/Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs
 * '<S6>'   : BasicModelTarget/Subsystem
 * '<S7>'   : BasicModelTarget/X Direction  Virtual DOF + Endpoint Force Calculation
 * '<S8>'   : BasicModelTarget/Y Direction  Virtual DOF + Endpoint Force Calculation
 * '<S9>'   : BasicModelTarget/ Calculate Additional Forces from UDP input/Scope (xPC)
 * '<S10>'  : BasicModelTarget/ Calculate Additional Forces from UDP input/Scope (xPC) 1
 * '<S11>'  : BasicModelTarget/ Calculate Additional Forces from UDP input/Scope (xPC) 2
 * '<S12>'  : BasicModelTarget/Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make
 * '<S13>'  : BasicModelTarget/Manipulandum  Dynamic Compensation: will function poorly with unfiltered inputs/2x2Make1
 * '<S14>'  : BasicModelTarget/Subsystem/Elbow Angle
 * '<S15>'  : BasicModelTarget/Subsystem/Jacobian-Cartesian Transformation
 * '<S16>'  : BasicModelTarget/Subsystem/Shoulder Angle
 * '<S17>'  : BasicModelTarget/Subsystem/Elbow Angle/Parity
 * '<S18>'  : BasicModelTarget/Subsystem/Shoulder Angle/Parity
 */
#endif                                 /* RTW_HEADER_BasicModelTarget_h_ */
