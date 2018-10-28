import { KeyName } from './keyname';
import { Constants } from './constants';

export enum TargetDevice {
    Monochrome = 1 << 0,
    RGB = 1 << 1,
    PerKeyRGB = 1 << 2,
    All = Monochrome | RGB | PerKeyRGB
}

export enum DeviceType {
    Keyboard = 0x0,
    Mouse = 0x3,
    Mousemat = 0x4,
    Headset = 0x8,
    Speaker = 0xe
}

export interface SdkVersion {
    majorNum?: number;
    minorNum?: number;
    buildNum?: number;
}

export interface TargetDeviceSetting {
    targetDevice: TargetDevice;
}

export interface ColorSetting {
    redPercentage: number;
    greenPercentage: number;
    bluePercentage: number;
}

export interface DeviceTypeSetting {
    deviceType: DeviceType;
}

export interface EffectTimingSetting {
    milliSecondsDuration: number;
    milliSecondsInterval: number;
}

export interface KeyNameSetting {
    keyName: KeyName;
}

export interface KeyCodeSetting {
    keyCode: number;
}

export interface KeyListSetting {
    keyList: Array<KeyName>;
}

export interface BitmapSetting {
    bitmap: Uint8Array;
}

interface ConfigSetting<T> {
    configPath: string;
    defaultValue: T;
    value?: T
}

export type ConfigNumberSetting = ConfigSetting<number>;
export type ConfigBooleanSetting = ConfigSetting<boolean>;

export interface ConfigLabelSetting {
    configPath: string;
    label: string;
}

export interface ConfigColorSetting {
    configPath: string;
    defaultRed: number;
    defaultGreen: number;
    defaultBlue: number;
    red?: number;
    green?: number;
    blue?: number;
}

export interface PulseKeySetting {
    startRedPercentage: number;
    startGreenPercentage: number;
    startBluePercentage: number;
    finishRedPercentage: number;
    finishGreenPercentage: number;
    finishBluePercentage: number;
    milliSecondsDuration: number;
    isInfinite: boolean;
}

export interface LogiLed {

    /**
     * Makes sure there isn’t already another instance running and then makes necessary initializations. It saves the current lighting for all connected and supported devices.This function will also stop any effect currently going on the connected devices.
     * @returns If the function succeeds, it returns true. Otherwise false. If it returns false, means that the connection with Logitech Gaming Software is broken, make sure that it is running.
     */
    init(): boolean;

    /**
     * Retrieves the version of the SDK version installed on the user’s system.
     * @param versionOut The function will fill this object with the build numbers of the SDK.
     * @returns If the function succeeds, it returns true. Otherwise false. If it returns false, meansthat there is no SDK installed on the user system, or the sdk version could not be retrieved.
     */
    getSdkVersion(versionOut: SdkVersion): boolean;

    /**
     * Retrieves the user's setting as a number.
     * @param options Path and default value to use for the config number. The `value` property will be populated with the user's setting.
     */
    getConfigOptionNumber(options: ConfigNumberSetting): boolean;

    /**
     * Retrieves the user's setting as a boolean.
     * @param options Path and default value to use for the config boolean. The `value` property will be populated with the user's setting.
     */
    getConfigOptionBool(options: ConfigBooleanSetting): boolean;

    /**
     * Retrieves the user's setting as a color.
     * @param options Path and default values to use for the config color. The `red`, `green`, and `blue` properties will be populated with the user's setting.
     */
    getConfigOptionColor(options: ConfigColorSetting): boolean;

    //getConfigOptionKeyInput(): boolean;

    /**
     * Sets a display name for the given label in the Logitech Gaming Software.
     * @param options Options to set the config display name.
     */
    setConfigOptionLabel(options: ConfigLabelSetting): boolean;

    /**
     * Sets the target device type for future calls.The default target device is TargetDevice.All, therefore, if no call is made to LogiLedSetTargetDevice the SDK will apply any function to all the connected devices.
     * @param options The target device.
     */
    setTargetDevice(options: TargetDeviceSetting): boolean;

    /**
     * Saves the current lighting so that it can be restored after a temporary effect is finished.
     */
    saveCurrentLighting(): boolean;

    /**
     * Sets the lighting on connected and supported devices
     * @param options Amount of each RGB color, each ranging from 0 to 100.
     *  
     * Do notcall this function immediately after LogiLedInit(). Instead leave a little bit of time after LogiLedInit().
     * 
     * For devices that only support a single color, the highest percentage value given of the three colors will define the intensity. For monochrome backlighting device, Logitech Gaming Softwarewill reduce proportionally the value of the highest color, according to the user hardware brightness setting.
     */
    setLighting(options: ColorSetting): boolean;

    /**
     * Restores the last saved lighting. It should be called after a temporary effect is finished.
     */
    restoreLighting(): boolean;

    /**
     * Saves the current lighting, plays the flashingeffect on the targeted devices and, finally, restores the saved lighting.
     * @param options Color and timing options for the flashing effect.
     */
    flashLighting(options: ColorSetting & EffectTimingSetting): boolean;

    /**
     * Saves the current lighting, plays the pulsing effect on the targeted devicesand, finally, restores the saved lighting.
     * @param options Color and timing options for the pulsing effect.
     */
    pulseLighting(options: ColorSetting & EffectTimingSetting): boolean;

    /**
     * Stops any of the presets effects (started from flashLighting or pulseLighting).
     */
    stopEffects(): boolean;

    /**
     * Sets the array of bytes passed as parameter as colors to per-key backlighting featured connected devices.
     * @param options An unsigned chararray containing the colors to assign to each key on the per-lighting device connected. The size required for this bitmap is defined by LOGI_LED_BITMAP_SIZE.
     */
    setLightingFromBitmap(options: BitmapSetting): boolean;

    /**
     * Sets the key identified by the scancode passed as parameter to the desired color.This function only affects per-key backlighting featured connected devices.
     * @param options The keyCode and color settings to be applied.
     */
    setLightingForKeyWithScanCode(options: KeyCodeSetting & ColorSetting): boolean;

    /**
     * Sets the key identified by the hid code passed as parameter to the desired color. This function only affects per-key backlighting featured connected devices.
     * @param options The keyCode and color settings to be applied.
     */
    setLightingForKeyWithHidCode(options: KeyCodeSetting & ColorSetting): boolean;

    /**
     * Sets the key identified by the quartz code passed as parameter to the desired color. This function only affects per-key backlighting featured connected devices.
     * @param options The keyCode and color settings to be applied.
     */
    setLightingForKeyWithQuartzCode(options: KeyCodeSetting & ColorSetting): boolean;

    /**
     * Sets the key identified by the code passed as parameter to the desired color. This function only affects per-key backlighting featured connected devices.
     * @param options The keyCode and color settings to be applied.
     */
    setLightingForKeyWithKeyName(options: KeyNameSetting & ColorSetting): boolean;

    /**
     * Saves the current color on the keycode passed as argument. Use this function with the `restoreLightingForKey` to preserve the state of a key before applying any effect. This function only affects per-key backlighting featured connected devices.
     * @param options The key to save the color of.
     */
    saveLightingForKey(options: KeyNameSetting): boolean;

    /**
     * Restores the saved color on the keycode passed as argument. Use this function with the LogiLedSaveLightingForKey to preserve the state of a key before applying any effect. This function only affects per-key backlighting featured connected devices.
     * @param options The key to restore the color on.
     */
    restoreLightingForKey(options: KeyNameSetting): boolean;

    /**
     * Sets a list of keys, defined by keynames to be ignored when calling the function LogiLedSetLightingFromBitmap. This is useful when creating effects on the bitmap during gameplay loop, but still wanting to set some keys on top of that using the LogiLedSetLightingFromKeyName.
     * @param options A preallocated array of KeyName to be excluded.
     */
    excludeKeysFromBitmap(options: KeyListSetting): boolean;

    /**
     * Starts a flashing effect on the key passed as parameter. This function only affects per-key backlighting featured connected devices.
     * @param options Key, color and timing options for the flashing effect.
     */
    flashSingleKey(options: KeyNameSetting & ColorSetting & EffectTimingSetting): boolean;
    
    /**
     * Starts a pulsing effect on the key passed as parameter.
     * @param options Key, color and timing options for the pulsing effect.
     */
    pulseSingleKey(options: KeyNameSetting & PulseKeySetting): boolean;
    
    /**
     * Stops any ongoing effect on the key passed in as parameter. This function only affects per-key backlighting featured connected devices.
     * @param options The key to stop the effects on.
     */
    stopEffectsOnKey(options: KeyNameSetting): boolean;

    /**
     * Restores the last saved lighting and frees memory used by the SDK.
     */
    shutdown(): void;
}

export type LogiLedStatic = LogiLed & typeof Constants & {
    KeyName: typeof KeyName;
    DeviceType: typeof DeviceType;
    TargetDevice: typeof TargetDevice;
}