# logiled

NodeJS Bindings for the Logitech LED SDK.
The Logitech LED SDK is used to control the RGB-LEDs of
various logitech hardware like keyboard or mouse.

To use the full potential of the module, you need
supported hardware like the G910 keyboard and the
Logitech Gaming Software must be running.

## Installing

```
$ npm install logiled
```

The module downloads prebuilt binaries from GitHUB
during the installation. Windows binaries are available for
the 32 and 64 bit versions of NodeJS, io.js and electron.

## Features

 * full support for all functions of the Logitech LED SDK
 * fallback compatibility layer for non-Windows operating systems -
   if not on Windows the module just behaves like the
   Logitech Gaming Software has been exited under Windows
 * works with node webkit

## Usage

The module slightly changes the way data is sent to and
received from the LED SDK functions. If you need to pass
parameters you will have to use an object.

### Example

```javascript

var logiled = require('logiled');

// always initialize the library first...
logiled.init();

// note: you should wait a few milliseconds after initializing

// store the current lighting for restoring it later...
logiled.saveCurrentLighting();

// set color of all keys to black (LEDs off)
logiled.setLighting({
    redPercentage:   0,
    greenPercentage: 0,
    bluePercentage:  0
});

// ... wait a moment to see the effect

// set color of ESC key to blue
logiled.setLightingForKeyWithKeyName({
    keyName: logiled.KeyName.ESC, 
    redPercentage: 0,
    greenPercentage: 0,
    bluePercentage: 100
});

// ... wait a moment to see the effect

// restore the lighting to the state it was saved earlier...
logiled.restoreLighting();

// finally free the ressources again...
logiled.shutdown();

```

## Building

This project features precompiled binaries for nodeJS, io.js and electron.

To compile the extension yourself you will need to get Microsoft Visual Studio
or the Microsoft Build Tools. To build logiled yourself, enter the module
folder and run:

```
$ npm i
$ npm run configure
$ npm run build
```

All subsequent builds only need `npm run build`

You can confirm everything built correctly by [running the test suite](#to-run-tests).

### Node-Webkit

There are no prebuilt binaries for node-webkit (nw.js) but you can compile logiled
with `nw-gyp`. Every logiled release will at least be tested against the most recent
version of node-webkit.

### To run tests:

Run checks against every API function a/k/a funny blinking demo.

```
$ npm test
```

### Furter Information

Refer to the Logitech LED SDK documentation
in the _PDF_-File located at `LED/Doc/LogitechGamingLEDSDK.pdf`
after building the module for the first time.

Visit the [LOGITECH G DEVELOPER LAB](http://gaming.logitech.com/en-us/developers).

## License

Copyright 2017 Paul Bottin <paul.bottin+git@gmail.com>

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED
OF THE POSSIBILITY OF SUCH DAMAGE.
