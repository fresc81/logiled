#ifndef NATIVE_EXTENSION_GRAB_H
#define NATIVE_EXTENSION_GRAB_H

#include <nan.h>

NAN_METHOD(Init);

NAN_METHOD(GetSdkVersion);
NAN_METHOD(GetConfigOptionNumber);
NAN_METHOD(GetConfigOptionBool);
NAN_METHOD(GetConfigOptionColor);
NAN_METHOD(GetConfigOptionKeyInput);
NAN_METHOD(SetConfigOptionLabel);

NAN_METHOD(SetTargetDevice);
NAN_METHOD(SetLightingForTargetZone);
NAN_METHOD(SaveCurrentLighting);
NAN_METHOD(SetLighting);
NAN_METHOD(RestoreLighting);
NAN_METHOD(FlashLighting);
NAN_METHOD(PulseLighting);
NAN_METHOD(StopEffects);

NAN_METHOD(SetLightingFromBitmap);
NAN_METHOD(SetLightingForKeyWithScanCode);
NAN_METHOD(SetLightingForKeyWithHidCode);
NAN_METHOD(SetLightingForKeyWithQuartzCode);
NAN_METHOD(SetLightingForKeyWithKeyName);
NAN_METHOD(SaveLightingForKey);
NAN_METHOD(RestoreLightingForKey);
NAN_METHOD(ExcludeKeysFromBitmap);

NAN_METHOD(FlashSingleKey);
NAN_METHOD(PulseSingleKey);
NAN_METHOD(StopEffectsOnKey);

NAN_METHOD(Shutdown);

#endif
