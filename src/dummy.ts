import { LogiLed } from './models';

/*
 * dummy fallback implementation for unsupported operating systems.
 * behaves like Logitech Gaming Software isn't running.
 */

const dummyBooleanSdkFunction: any = function () { return false; }
const dummyVoidSdkFunction: any = function () { };

export const dummy: LogiLed = {

    init: dummyBooleanSdkFunction,

    getSdkVersion: dummyBooleanSdkFunction,
    getConfigOptionNumber: dummyBooleanSdkFunction,
    getConfigOptionBool: dummyBooleanSdkFunction,
    getConfigOptionColor: dummyBooleanSdkFunction,
    //getConfigOptionKeyInput: dummyBooleanSdkFunction,
    setConfigOptionLabel: dummyBooleanSdkFunction,

    setTargetDevice: dummyBooleanSdkFunction,
    setLightingForTargetZone: dummyBooleanSdkFunction,
    saveCurrentLighting: dummyBooleanSdkFunction,
    setLighting: dummyBooleanSdkFunction,
    restoreLighting: dummyBooleanSdkFunction,
    flashLighting: dummyBooleanSdkFunction,
    pulseLighting: dummyBooleanSdkFunction,
    stopEffects: dummyBooleanSdkFunction,

    setLightingFromBitmap: dummyBooleanSdkFunction,
    setLightingForKeyWithScanCode: dummyBooleanSdkFunction,
    setLightingForKeyWithHidCode: dummyBooleanSdkFunction,
    setLightingForKeyWithQuartzCode: dummyBooleanSdkFunction,
    setLightingForKeyWithKeyName: dummyBooleanSdkFunction,
    saveLightingForKey: dummyBooleanSdkFunction,
    restoreLightingForKey: dummyBooleanSdkFunction,
    excludeKeysFromBitmap: dummyBooleanSdkFunction,

    flashSingleKey: dummyBooleanSdkFunction,
    pulseSingleKey: dummyBooleanSdkFunction,
    stopEffectsOnKey: dummyBooleanSdkFunction,

    shutdown: dummyVoidSdkFunction
};
