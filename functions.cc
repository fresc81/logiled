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

        int          red     = Nan::To<int>(Nan::Get(obj, Nan::New("defaultRed").ToLocalChecked()).ToLocalChecked()).FromJust();
        int          green   = Nan::To<int>(Nan::Get(obj, Nan::New("defaultGreen").ToLocalChecked()).ToLocalChecked()).FromJust();
        int          blue    = Nan::To<int>(Nan::Get(obj, Nan::New("defaultBlue").ToLocalChecked()).ToLocalChecked()).FromJust();
        bool         result  = LogiLedGetConfigOptionColor(wstr.c_str(), &red, &green, &blue);

        Nan::Set(obj, Nan::New("red").ToLocalChecked(),   Nan::New(red));
        Nan::Set(obj, Nan::New("green").ToLocalChecked(), Nan::New(green));
        Nan::Set(obj, Nan::New("blue").ToLocalChecked(),  Nan::New(blue));
        delete [] lpsConfigPath;

        info.GetReturnValue().Set(Nan::New(result));
    }
    
}

NAN_METHOD(GetConfigOptionKeyInput) {
    // TODO: implement
}

NAN_METHOD(SetConfigOptionLabel) {
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

        v8::Local<v8::String> label = Nan::To<v8::String>(Nan::Get(obj, Nan::New("label").ToLocalChecked()).ToLocalChecked()).ToLocalChecked();
        ssize_t      szLabel        = DecodeBytes(label, Nan::Encoding::UTF8)+1;
        char        *lpsLabel       = new char[szLabel];
        ZeroMemory(lpsLabel, szLabel);
        DecodeWrite(lpsLabel, szLabel, label, Nan::Encoding::UTF8);

        std::string strLabel(lpsLabel);
        std::wstring wstrLabel = converter.from_bytes(strLabel);

        bool         result         = LogiLedSetConfigOptionLabel(wstr.c_str(), const_cast<wchar_t *>(wstrLabel.c_str()));

        delete [] lpsLabel;
        delete [] lpsConfigPath;

        info.GetReturnValue().Set(Nan::New(result));
    }
    
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

NAN_METHOD(SetLightingForTargetZone) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int deviceType            = Nan::To<int>(Nan::Get(obj, Nan::New("deviceType").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   zone                  = Nan::To<int>(Nan::Get(obj, Nan::New("zone").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSetLightingForTargetZone((LogiLed::DeviceType)deviceType, zone, redPercentage, greenPercentage, bluePercentage)));
    }
}

NAN_METHOD(SaveCurrentLighting) {
    info.GetReturnValue().Set(Nan::New(LogiLedSaveCurrentLighting()));
}

NAN_METHOD(SetLighting) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int redPercentage   = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage  = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSetLighting(redPercentage, greenPercentage, bluePercentage)));
    }
}

NAN_METHOD(RestoreLighting) {
    info.GetReturnValue().Set(Nan::New(LogiLedRestoreLighting()));
}

NAN_METHOD(FlashLighting) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   milliSecondsDuration  = Nan::To<int>(Nan::Get(obj, Nan::New("milliSecondsDuration").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   milliSecondsInterval  = Nan::To<int>(Nan::Get(obj, Nan::New("milliSecondsInterval").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedFlashLighting(redPercentage, greenPercentage, bluePercentage, milliSecondsDuration, milliSecondsInterval)));
    }
}

NAN_METHOD(PulseLighting) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   milliSecondsDuration  = Nan::To<int>(Nan::Get(obj, Nan::New("milliSecondsDuration").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   milliSecondsInterval  = Nan::To<int>(Nan::Get(obj, Nan::New("milliSecondsInterval").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedPulseLighting(redPercentage, greenPercentage, bluePercentage, milliSecondsDuration, milliSecondsInterval)));
    }
}

NAN_METHOD(StopEffects) {
    info.GetReturnValue().Set(Nan::New(LogiLedStopEffects()));
}

NAN_METHOD(SetLightingFromBitmap) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();

        v8::Local<v8::Value> bitmap = Nan::Get(obj, Nan::New("bitmap").ToLocalChecked()).ToLocalChecked();
        size_t szBitmapLength = Nan::TypedArrayContents<unsigned char>(bitmap).length();
        if (szBitmapLength >= LOGI_LED_BITMAP_SIZE) {
            unsigned char *lpucBitmap = new unsigned char [LOGI_LED_BITMAP_SIZE];
            ZeroMemory(lpucBitmap, LOGI_LED_BITMAP_SIZE);

            for (size_t i=0; i<LOGI_LED_BITMAP_SIZE; i++) {
                lpucBitmap[i] = (*Nan::TypedArrayContents<unsigned char>(bitmap))[i];
            }

            bool result = LogiLedSetLightingFromBitmap(lpucBitmap);
            delete [] lpucBitmap;

            info.GetReturnValue().Set(Nan::New(result));
        }

    }
}

NAN_METHOD(SetLightingForKeyWithScanCode) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyCode               = Nan::To<int>(Nan::Get(obj, Nan::New("keyCode").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSetLightingForKeyWithScanCode(keyCode, redPercentage, greenPercentage, bluePercentage)));
    }
}

NAN_METHOD(SetLightingForKeyWithHidCode) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyCode               = Nan::To<int>(Nan::Get(obj, Nan::New("keyCode").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSetLightingForKeyWithHidCode(keyCode, redPercentage, greenPercentage, bluePercentage)));
    }
}

NAN_METHOD(SetLightingForKeyWithQuartzCode) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyCode               = Nan::To<int>(Nan::Get(obj, Nan::New("keyCode").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSetLightingForKeyWithQuartzCode(keyCode, redPercentage, greenPercentage, bluePercentage)));
    }
}

NAN_METHOD(SetLightingForKeyWithKeyName) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyName               = Nan::To<int>(Nan::Get(obj, Nan::New("keyName").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSetLightingForKeyWithKeyName((LogiLed::KeyName)keyName, redPercentage, greenPercentage, bluePercentage)));
    }
}

NAN_METHOD(SaveLightingForKey) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyName               = Nan::To<int>(Nan::Get(obj, Nan::New("keyName").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedSaveLightingForKey((LogiLed::KeyName)keyName)));
    }
}

NAN_METHOD(RestoreLightingForKey) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyName               = Nan::To<int>(Nan::Get(obj, Nan::New("keyName").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedRestoreLightingForKey((LogiLed::KeyName)keyName)));
    }
}

NAN_METHOD(ExcludeKeysFromBitmap) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);
    
    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        v8::Local<v8::Value> keyList = Nan::Get(obj, Nan::New("keyList").ToLocalChecked()).ToLocalChecked();
        size_t szKeyListLength = Nan::TypedArrayContents<int>(keyList).length();

        LogiLed::KeyName *lpKeyList = new LogiLed::KeyName[szKeyListLength];
        ZeroMemory(lpKeyList, szKeyListLength * sizeof(LogiLed::KeyName));

        for (size_t i=0; i<szKeyListLength; i++) {
            lpKeyList[i] = (LogiLed::KeyName) (*Nan::TypedArrayContents<int>(keyList))[i];
        }

        bool result = LogiLedExcludeKeysFromBitmap(lpKeyList, (int) szKeyListLength);
        delete [] lpKeyList;

        info.GetReturnValue().Set(Nan::New(result));
    }
}

NAN_METHOD(FlashSingleKey) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyName               = Nan::To<int>(Nan::Get(obj, Nan::New("keyName").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   redPercentage         = Nan::To<int>(Nan::Get(obj, Nan::New("redPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   greenPercentage       = Nan::To<int>(Nan::Get(obj, Nan::New("greenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   bluePercentage        = Nan::To<int>(Nan::Get(obj, Nan::New("bluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   milliSecondsDuration  = Nan::To<int>(Nan::Get(obj, Nan::New("milliSecondsDuration").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   milliSecondsInterval  = Nan::To<int>(Nan::Get(obj, Nan::New("milliSecondsInterval").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedFlashSingleKey((LogiLed::KeyName)keyName, redPercentage, greenPercentage, bluePercentage, milliSecondsDuration, milliSecondsInterval)));
    }
}

NAN_METHOD(PulseSingleKey) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyName               = Nan::To<int>(Nan::Get(obj, Nan::New("keyName").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   startRedPercentage    = Nan::To<int>(Nan::Get(obj, Nan::New("startRedPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   startGreenPercentage  = Nan::To<int>(Nan::Get(obj, Nan::New("startGreenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   startBluePercentage   = Nan::To<int>(Nan::Get(obj, Nan::New("startBluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   finishRedPercentage   = Nan::To<int>(Nan::Get(obj, Nan::New("finishRedPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   finishGreenPercentage = Nan::To<int>(Nan::Get(obj, Nan::New("finishGreenPercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   finishBluePercentage  = Nan::To<int>(Nan::Get(obj, Nan::New("finishBluePercentage").ToLocalChecked()).ToLocalChecked()).FromJust()
        ,   milliSecondsDuration  = Nan::To<int>(Nan::Get(obj, Nan::New("milliSecondsDuration").ToLocalChecked()).ToLocalChecked()).FromJust();
        bool isInfinite           = Nan::To<bool>(Nan::Get(obj, Nan::New("isInfinite").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedPulseSingleKey((LogiLed::KeyName)keyName, startRedPercentage, startGreenPercentage, startBluePercentage, finishRedPercentage, finishGreenPercentage, finishBluePercentage, milliSecondsDuration, isInfinite)));
    }
}

NAN_METHOD(StopEffectsOnKey) {
    Nan::MaybeLocal<v8::Object> arg0 = Nan::To<v8::Object>(info[0]);

    if (arg0.IsEmpty()) {
        info.GetReturnValue().Set(Nan::New(false));
    } else {
        v8::Local<v8::Object> obj = arg0.ToLocalChecked();
        int keyName               = Nan::To<int>(Nan::Get(obj, Nan::New("keyName").ToLocalChecked()).ToLocalChecked()).FromJust();
        info.GetReturnValue().Set(Nan::New(LogiLedStopEffectsOnKey((LogiLed::KeyName)keyName)));
    }
}

NAN_METHOD(Shutdown) {
    LogiLedShutdown();
}
