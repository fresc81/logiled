
/*
 * dummy fallback implementation for unsupported operating systems.
 * behaves like Logitech Gaming Software isn't running.
 */

function dummySDKFunction (): boolean {
    return false;
}

function dummyVoidSDKFunction (): void {
}

module dummy {

    export let init = dummySDKFunction;
    export let getSdkVersion = dummySDKFunction;
    export let getConfigOptionNumber = dummySDKFunction;
    export let getConfigOptionBool = dummySDKFunction;
    export let setTargetDevice = dummySDKFunction;
    export let saveCurrentLighting = dummySDKFunction;
    export let setLighting = dummySDKFunction;
    export let restoreLighting = dummySDKFunction;
    export let flashLighting = dummySDKFunction;
    export let pulseLighting = dummySDKFunction;
    export let stopEffects = dummySDKFunction;
    export let setLightingForKeyWithKeyName = dummySDKFunction;
    export let saveLightingForKey = dummySDKFunction;
    export let flashSingleKey = dummySDKFunction;
    export let pulseSingleKey = dummySDKFunction;
    export let restoreLightingForKey = dummySDKFunction;
    export let stopEffectsOnKey = dummySDKFunction;
    export let shutdown = dummyVoidSDKFunction;

}

export = dummy;
