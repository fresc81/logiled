import bindings = require('bindings');

import { LogiLed, TargetDevice, LogiLedStatic, KeyListSetting } from './models';
import { Constants } from './constants';
import { KeyName } from './keyname';

const sdk: LogiLed = bindings({
    compiled: 'dist',
    try: [
      
        // first try binaries in ./build folder, prefer debug builds
        ['module_root', 'build', 'Debug', 'bindings'],
        ['module_root', 'build', 'Release', 'bindings'],
  
        // finally fallback to a dummy javascript implementation
        ['module_root', 'compiled', 'dummy.js'],
    ]
});

// Override excludeKeysFromBitmap to handle the conversion to Int32Array...
const origExcludeKeysFromBitmap = sdk.excludeKeysFromBitmap;
sdk.excludeKeysFromBitmap = function (options: KeyListSetting) {
    return origExcludeKeysFromBitmap.call(this, {
        keyList: new Int32Array(options.keyList)
    });
};

// Build out the default export object...
const logiled = sdk as LogiLedStatic;

// Add each constant to logiled...
for (let key of Object.keys(Constants)) logiled[key] = Constants[key];

// Add the enums to logiled...
logiled.KeyName = KeyName;
logiled.TargetDevice = TargetDevice;

export default logiled;

// Export the library and types individually...
export { sdk }
export * from './models';