#include "functions.h"
#include <LogitechLEDLib.h>

#include <iostream>
#include <string>
#include <locale>
#include <codecvt>

using namespace Nan;

NAN_METHOD(Init) {
    bool result = LogiLedInit();
    info.GetReturnValue().Set(Nan::New(result));
}

NAN_METHOD(GetSdkVersion) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);
    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        int  majorNum = 0
          ,  minorNum = 0
          ,  buildNum = 0;
        bool result   = LogiLedGetSdkVersion(&majorNum, &minorNum, &buildNum);
        if (result) {
            v8::Local<v8::Object> obj = arg0.ToLocalChecked();
            Nan::Set(obj, Nan::New("majorNum").ToLocalChecked(), Nan::New((double)majorNum));
            Nan::Set(obj, Nan::New("minorNum").ToLocalChecked(), Nan::New((double)minorNum));
            Nan::Set(obj, Nan::New("buildNum").ToLocalChecked(), Nan::New((double)buildNum));
        }
        info.GetReturnValue().Set(Nan::New(result));
    }
}

NAN_METHOD(GetConfigOptionNumber) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();

        v8::Local<v8::String> configPath = Nan::To<v8::String>(Nan::Get(obj, Nan::New("configPath").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
        ssize_t      szConfigPath   = DecodeBytes(configPath, Nan::Encoding::UTF8)+1;
        char        *lpsConfigPath  = new char[szConfigPath];
        ZeroMemory(lpsConfigPath, szConfigPath);
        DecodeWrite(lpsConfigPath, szConfigPath, configPath, Nan::Encoding::UTF8);

        std::string str(lpsConfigPath);
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wstr = converter.from_bytes(str);

        double       value          = Nan::To<double>(Nan::Get(obj, Nan::New("defaultValue").ToLocalChecked()).ToLocalChecked()).FromJust();
        bool         result         = LogiLedGetConfigOptionNumber(wstr.c_str(), &value);

        Nan::Set(obj, Nan::New("value").ToLocalChecked(), Nan::New(value));
        delete [] lpsConfigPath;

        info.GetReturnValue().Set(Nan::New(result));
    }
    
}

NAN_METHOD(GetConfigOptionBool) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();

        v8::Local<v8::String> configPath = Nan::To<v8::String>(Nan::Get(obj, Nan::New("configPath").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
        ssize_t      szConfigPath   = DecodeBytes(configPath, Nan::Encoding::UTF8)+1;
        char        *lpsConfigPath  = new char[szConfigPath];
        ZeroMemory(lpsConfigPath, szConfigPath);
        DecodeWrite(lpsConfigPath, szConfigPath, configPath, Nan::Encoding::UTF8);

        std::string str(lpsConfigPath);
        std::wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
        std::wstring wstr = converter.from_bytes(str);

        bool         value          = Nan::To<bool>(Nan::Get(obj, Nan::New("defaultValue").ToLocalChecked()).ToLocalChecked()).FromJust();
        bool         result         = LogiLedGetConfigOptionBool(wstr.c_str(), &value);

        Nan::Set(obj, Nan::New("value").ToLocalChecked(), Nan::New(value));
        delete [] lpsConfigPath;

        info.GetReturnValue().Set(Nan::New(result));
    }
    
}

NAN_METHOD(GetConfigOptionColor) {
    
}

NAN_METHOD(GetConfigOptionKeyInput) {
    
}

NAN_METHOD(SetConfigOptionLabel) {
    
}

NAN_METHOD(SetTargetDevice) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int targetDevice = Nan::To<int>(Nan::Get(obj, Nan::New("targetDevice").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSetTargetDevice(targetDevice)));
    }
}

NAN_METHOD(SaveCurrentLighting) {
    info.GetReturnValue().Set(Nan::New(LogiLedSaveCurrentLighting()));
}

NAN_METHOD(SetLighting) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);
    Nan::MaybeLocal<v8::Number> arg1 = Nan::To<v8::Number>(info[1]);
    Nan::MaybeLocal<v8::Number> arg2 = Nan::To<v8::Number>(info[2]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty() || arg1.IsEmpty() || arg2.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int redPercentage   = Nan::To<int>(arg0.ToLocalChecked()).FromJust()
        ,   greenPercentage = Nan::To<int>(arg1.ToLocalChecked()).FromJust()
        ,   bluePercentage  = Nan::To<int>(arg2.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedSetLighting(redPercentage, greenPercentage, bluePercentage)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(RestoreLighting) {
    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedRestoreLighting()));
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(FlashLighting) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);
    Nan::MaybeLocal<v8::Number> arg1 = Nan::To<v8::Number>(info[1]);
    Nan::MaybeLocal<v8::Number> arg2 = Nan::To<v8::Number>(info[2]);
    Nan::MaybeLocal<v8::Number> arg3 = Nan::To<v8::Number>(info[3]);
    Nan::MaybeLocal<v8::Number> arg4 = Nan::To<v8::Number>(info[4]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty() || arg1.IsEmpty() || arg2.IsEmpty() || arg3.IsEmpty() || arg4.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int redPercentage        = Nan::To<int>(arg0.ToLocalChecked()).FromJust()
        ,   greenPercentage      = Nan::To<int>(arg1.ToLocalChecked()).FromJust()
        ,   bluePercentage       = Nan::To<int>(arg2.ToLocalChecked()).FromJust()
        ,   milliSecondsDuration = Nan::To<int>(arg3.ToLocalChecked()).FromJust()
        ,   milliSecondsInterval = Nan::To<int>(arg4.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedFlashLighting(redPercentage, greenPercentage, bluePercentage, milliSecondsDuration, milliSecondsInterval)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(PulseLighting) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);
    Nan::MaybeLocal<v8::Number> arg1 = Nan::To<v8::Number>(info[1]);
    Nan::MaybeLocal<v8::Number> arg2 = Nan::To<v8::Number>(info[2]);
    Nan::MaybeLocal<v8::Number> arg3 = Nan::To<v8::Number>(info[3]);
    Nan::MaybeLocal<v8::Number> arg4 = Nan::To<v8::Number>(info[4]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty() || arg1.IsEmpty() || arg2.IsEmpty() || arg3.IsEmpty() || arg4.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int redPercentage        = Nan::To<int>(arg0.ToLocalChecked()).FromJust()
        ,   greenPercentage      = Nan::To<int>(arg1.ToLocalChecked()).FromJust()
        ,   bluePercentage       = Nan::To<int>(arg2.ToLocalChecked()).FromJust()
        ,   milliSecondsDuration = Nan::To<int>(arg3.ToLocalChecked()).FromJust()
        ,   milliSecondsInterval = Nan::To<int>(arg4.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedPulseLighting(redPercentage, greenPercentage, bluePercentage, milliSecondsDuration, milliSecondsInterval)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(StopEffects) {
    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedStopEffects()));
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(SetLightingFromBitmap) {
    
}

NAN_METHOD(SetLightingForKeyWithScanCode) {
    
}

NAN_METHOD(SetLightingForKeyWithHidCode) {
    
}

NAN_METHOD(SetLightingForKeyWithQuartzCode) {
    
}

NAN_METHOD(SetLightingForKeyWithKeyName) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);
    Nan::MaybeLocal<v8::Number> arg1 = Nan::To<v8::Number>(info[1]);
    Nan::MaybeLocal<v8::Number> arg2 = Nan::To<v8::Number>(info[2]);
    Nan::MaybeLocal<v8::Number> arg3 = Nan::To<v8::Number>(info[3]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty() || arg1.IsEmpty() || arg2.IsEmpty() || arg3.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int keyName              = Nan::To<int>(arg0.ToLocalChecked()).FromJust()
        ,   redPercentage        = Nan::To<int>(arg1.ToLocalChecked()).FromJust()
        ,   greenPercentage      = Nan::To<int>(arg2.ToLocalChecked()).FromJust()
        ,   bluePercentage       = Nan::To<int>(arg3.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedSetLightingForKeyWithKeyName((LogiLed::KeyName)keyName, redPercentage, greenPercentage, bluePercentage)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(SaveLightingForKey) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int keyName              = Nan::To<int>(arg0.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedSaveLightingForKey((LogiLed::KeyName)keyName)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(RestoreLightingForKey) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int keyName              = Nan::To<int>(arg0.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedRestoreLightingForKey((LogiLed::KeyName)keyName)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(ExcludeKeysFromBitmap) {
}

NAN_METHOD(FlashSingleKey) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);
    Nan::MaybeLocal<v8::Number> arg1 = Nan::To<v8::Number>(info[1]);
    Nan::MaybeLocal<v8::Number> arg2 = Nan::To<v8::Number>(info[2]);
    Nan::MaybeLocal<v8::Number> arg3 = Nan::To<v8::Number>(info[3]);
    Nan::MaybeLocal<v8::Number> arg4 = Nan::To<v8::Number>(info[4]);
    Nan::MaybeLocal<v8::Number> arg5 = Nan::To<v8::Number>(info[5]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty() || arg1.IsEmpty() || arg2.IsEmpty() || arg3.IsEmpty() || arg4.IsEmpty() || arg5.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int keyName              = Nan::To<int>(arg0.ToLocalChecked()).FromJust()
        ,   redPercentage        = Nan::To<int>(arg1.ToLocalChecked()).FromJust()
        ,   greenPercentage      = Nan::To<int>(arg2.ToLocalChecked()).FromJust()
        ,   bluePercentage       = Nan::To<int>(arg3.ToLocalChecked()).FromJust()
        ,   milliSecondsDuration = Nan::To<int>(arg4.ToLocalChecked()).FromJust()
        ,   milliSecondsInterval = Nan::To<int>(arg5.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedFlashSingleKey((LogiLed::KeyName)keyName, redPercentage, greenPercentage, bluePercentage, milliSecondsDuration, milliSecondsInterval)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(PulseSingleKey) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);
    Nan::MaybeLocal<v8::Number> arg1 = Nan::To<v8::Number>(info[1]);
    Nan::MaybeLocal<v8::Number> arg2 = Nan::To<v8::Number>(info[2]);
    Nan::MaybeLocal<v8::Number> arg3 = Nan::To<v8::Number>(info[3]);
    Nan::MaybeLocal<v8::Number> arg4 = Nan::To<v8::Number>(info[4]);
    Nan::MaybeLocal<v8::Number> arg5 = Nan::To<v8::Number>(info[5]);
    Nan::MaybeLocal<v8::Number> arg6 = Nan::To<v8::Number>(info[6]);
    Nan::MaybeLocal<v8::Number> arg7 = Nan::To<v8::Number>(info[7]);
    Nan::MaybeLocal<v8::Boolean> arg8 = Nan::To<v8::Boolean>(info[8]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty() || arg1.IsEmpty() || arg2.IsEmpty() || arg3.IsEmpty() || arg4.IsEmpty() || arg5.IsEmpty() || arg6.IsEmpty() || arg7.IsEmpty() || arg8.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int keyName               = Nan::To<int>(arg0.ToLocalChecked()).FromJust()
        ,   startRedPercentage    = Nan::To<int>(arg1.ToLocalChecked()).FromJust()
        ,   startGreenPercentage  = Nan::To<int>(arg2.ToLocalChecked()).FromJust()
        ,   startBluePercentage   = Nan::To<int>(arg3.ToLocalChecked()).FromJust()
        ,   finishRedPercentage   = Nan::To<int>(arg4.ToLocalChecked()).FromJust()
        ,   finishGreenPercentage = Nan::To<int>(arg5.ToLocalChecked()).FromJust()
        ,   finishBluePercentage  = Nan::To<int>(arg6.ToLocalChecked()).FromJust()
        ,   milliSecondsDuration  = Nan::To<int>(arg7.ToLocalChecked()).FromJust();
        bool isInfinite           = Nan::To<bool>(arg8.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedPulseSingleKey((LogiLed::KeyName)keyName, startRedPercentage, startGreenPercentage, startBluePercentage, finishRedPercentage, finishGreenPercentage, finishBluePercentage, milliSecondsDuration, isInfinite)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(StopEffectsOnKey) {
    Nan::MaybeLocal<v8::Number> arg0 = Nan::To<v8::Number>(info[0]);

    v8::Local<v8::Object> obj = Nan::New<v8::Object>();
    if (arg0.IsEmpty()) {
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(false));
    } else {
        int keyName              = Nan::To<int>(arg0.ToLocalChecked()).FromJust();
        Nan::Set(obj, Nan::New("result").ToLocalChecked(), Nan::New(LogiLedStopEffectsOnKey((LogiLed::KeyName)keyName)));
    }
    info.GetReturnValue().Set(obj);
}

NAN_METHOD(Shutdown) {
    LogiLedShutdown();
}
