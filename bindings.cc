#include "functions.h"

using v8::FunctionTemplate;

// NativeExtension.cc represents the top level of the module.
// C++ constructs that are exposed to javascript are exported here

NAN_MODULE_INIT(InitAll) {

  Nan::Set(target, Nan::New("init").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(Init)).ToLocalChecked());
  Nan::Set(target, Nan::New("getSdkVersion").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetSdkVersion)).ToLocalChecked());

  Nan::Set(target, Nan::New("getConfigOptionNumber").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetConfigOptionNumber)).ToLocalChecked());
  Nan::Set(target, Nan::New("getConfigOptionBool").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetConfigOptionBool)).ToLocalChecked());
  Nan::Set(target, Nan::New("getConfigOptionColor").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(GetConfigOptionColor)).ToLocalChecked());
  Nan::Set(target, Nan::New("setConfigOptionLabel").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetConfigOptionLabel)).ToLocalChecked());

  Nan::Set(target, Nan::New("setTargetDevice").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetTargetDevice)).ToLocalChecked());
  Nan::Set(target, Nan::New("setLightingForTargetZone").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetLightingForTargetZone)).ToLocalChecked());
  Nan::Set(target, Nan::New("saveCurrentLighting").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SaveCurrentLighting)).ToLocalChecked());
  Nan::Set(target, Nan::New("setLighting").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetLighting)).ToLocalChecked());
  Nan::Set(target, Nan::New("restoreLighting").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(RestoreLighting)).ToLocalChecked());
  Nan::Set(target, Nan::New("flashLighting").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(FlashLighting)).ToLocalChecked());
  Nan::Set(target, Nan::New("pulseLighting").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(PulseLighting)).ToLocalChecked());
  Nan::Set(target, Nan::New("stopEffects").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(StopEffects)).ToLocalChecked());

  Nan::Set(target, Nan::New("setLightingFromBitmap").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetLightingFromBitmap)).ToLocalChecked());
  Nan::Set(target, Nan::New("excludeKeysFromBitmap").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(ExcludeKeysFromBitmap)).ToLocalChecked());

  Nan::Set(target, Nan::New("setLightingForKeyWithKeyName").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetLightingForKeyWithKeyName)).ToLocalChecked());
  Nan::Set(target, Nan::New("setLightingForKeyWithScanCode").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetLightingForKeyWithScanCode)).ToLocalChecked());
  Nan::Set(target, Nan::New("setLightingForKeyWithQuartzCode").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SetLightingForKeyWithQuartzCode)).ToLocalChecked());
  
  Nan::Set(target, Nan::New("saveLightingForKey").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(SaveLightingForKey)).ToLocalChecked());
  Nan::Set(target, Nan::New("flashSingleKey").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(FlashSingleKey)).ToLocalChecked());
  Nan::Set(target, Nan::New("pulseSingleKey").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(PulseSingleKey)).ToLocalChecked());
  Nan::Set(target, Nan::New("restoreLightingForKey").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(RestoreLightingForKey)).ToLocalChecked());

  Nan::Set(target, Nan::New("stopEffectsOnKey").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(StopEffectsOnKey)).ToLocalChecked());

  Nan::Set(target, Nan::New("shutdown").ToLocalChecked(),
    Nan::GetFunction(Nan::New<FunctionTemplate>(Shutdown)).ToLocalChecked());
  
}

NODE_MODULE(logiled, InitAll)
