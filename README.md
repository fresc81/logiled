# logiled

NodeJS Bindings for the Logitech LED SDK.

## Installing

```
$ npm install logiled
```

The module comes with prebuilt binaries for Windows 32 and 64 Bit versions.

## Building

To compile the extension for the first time, enter the module folder and run 

```
$ npm i
$ npm run configure
$ npm run build
```

All subsequent builds only need `npm run build`

You can confirm everything built correctly by [running the test suite](#to-run-tests).

### To run tests:

```
$ npm t
```

or to run test continuously 

```
$ npm test -- watch
```

## Usage

The module slightly changes the way data is sent to and
received from the LED SDK functions.

The original functions all return a boolean value indicating
the success of the SDK function call. If data needs to be
received from the function, the calling code must be able to
pass function parameters as a reference so the function can alter
the parameter's value. However, this is not possible in the
javascript language.

Instead all functions that return a boolean value in the SDK
will - within this node module - return an object that contains at least
a boolean _result_ property which reflects the result of the SDK function.

### Example

```javascript

var logiled = require('logiled');

// always initialize the library first...
logiled.init();

// note: you should wait a few milliseconds after initializing

// store the current lighting for restoring it later...
logiled.saveCurrentLighting();



// restore the lighting to the state it was saved earlier...
logiled.restoreLighting();

// finally free the ressources again...
logiled.shutdown();

```

### Furter Information

Refer to the Logitech LED SDK documentation
in the _PDF_-File located at `LED/Doc/LogitechGamingLEDSDK.pdf`
after building the module for the first time.
