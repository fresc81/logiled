import 'mocha';
import * as assert from 'assert';
import * as async from 'async';

import logiled from '.';
import { SdkVersion, ConfigColorSetting, ConfigNumberSetting, ConfigBooleanSetting } from '.';

const LOGI_LOGO = [
  logiled.KeyName.G_LOGO,
  logiled.KeyName.G_BADGE,
];

const LOGI_WSAD = [
  logiled.KeyName.W,
  logiled.KeyName.S,
  logiled.KeyName.A,
  logiled.KeyName.D
];

const LOGI_KEY_NUMLOCK_SCANCODE    = 0x45;
const LOGI_KEY_NUMLOCK_HIDCODE     = 0x45;
const LOGI_KEY_NUMLOCK_QUARTZCODE  = 0x47;

describe('logiled', function() {

  it('should run on windows', function () {

    var isWindowsPlatform = process.platform === 'win32';
    assert.equal(isWindowsPlatform, true);

  });

  it('should initialize sdk', function(done) {
    this.slow(500);
    this.timeout(2500);

    var result = logiled.init();
    assert.equal(typeof result, 'boolean');
    assert.equal(result, true);

    setTimeout(done, 250);
  });

  it('should get sdk version', function() {

    var version: SdkVersion = { };
    var result = logiled.getSdkVersion(version);

    assert.equal(typeof result, 'boolean');
    assert.equal(result, true);

    if (result) {
      assert.equal(typeof version.majorNum, 'number');
      assert.equal(typeof version.minorNum, 'number');
      assert.equal(typeof version.buildNum, 'number');
    }
  });

  it('should finalize sdk', function() {
    logiled.shutdown();
  });

  describe('per key RGB', function() {

    before('setup sdk', function(done) {
      logiled.init();
      setTimeout(done, 250);
    });

    after('finalize sdk', function() {
      logiled.shutdown();
    });

    it('should setup keyboard (per key RGB)', function() {

      var result = logiled.setTargetDevice({
        targetDevice: logiled.TargetDevice.PerKeyRGB
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

    });

    it('should get a numeric config option', function() {

      var configOption: ConfigNumberSetting = {
        configPath: 'player/numeric',
        defaultValue: 0
      };
      var result = logiled.getConfigOptionNumber(configOption);

      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      if (result) {
        assert.equal(typeof configOption.value, 'number');
        assert.equal(configOption.value, 0);
      }
    });

    it('should get a boolean config option', function() {

      var configOption: ConfigBooleanSetting = {
        configPath: 'player/boolean',
        defaultValue: false
      };
      var result = logiled.getConfigOptionBool(configOption);

      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      if (result) {
        assert.equal(typeof configOption.value, 'boolean');
        assert.equal(configOption.value, false);
      }
    });

    it('should get a color config option', function() {

      var configOption: ConfigColorSetting = {
        configPath:   'player/color',
        defaultRed:   0,
        defaultGreen: 0,
        defaultBlue:  0,
      };
      var result = logiled.getConfigOptionColor(configOption);

      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      if (result) {
        assert.equal(typeof configOption.red,   'number');
        assert.equal(configOption.red, 0);
        assert.equal(typeof configOption.green, 'number');
        assert.equal(configOption.green, 0);
        assert.equal(typeof configOption.blue,  'number');
        assert.equal(configOption.blue, 0);
      }
    });

    it('should set config option labels', function() {

      var configOptions = [{
        configPath:   'player',
        label:        'Player'
      },{
        configPath:   'player/numeric',
        label:        'Numeric Option'
      },{
        configPath:   'player/boolean',
        label:        'Boolean Option'
      },{
        configPath:   'player/color',
        label:        'Color Option'
      }];

      configOptions.forEach(function(configOption) {
        var result = logiled.setConfigOptionLabel(configOption);
        assert.equal(typeof result, 'boolean');
        assert.equal(result, true);
      });

    });

    it('should save current ligthing', function(done) {
      this.slow(500);
      this.timeout(1000);

      var result = logiled.saveCurrentLighting();
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 250);
    });

    it('should blink keyboard (red)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.flashLighting({
        redPercentage:   100,
        greenPercentage: 5,
        bluePercentage:  5,
        milliSecondsDuration: 4000,
        milliSecondsInterval: 250
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should fade keyboard (green)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.pulseLighting({
        redPercentage:   0,
        greenPercentage: 100,
        bluePercentage:  0,
        milliSecondsDuration: 4000,
        milliSecondsInterval: 250
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should set keyboard color (blue)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.setLighting({
        redPercentage:   0,
        greenPercentage: 0,
        bluePercentage:  100
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should stop effects', function() {

      var result = logiled.stopEffects();
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

    });

    it('should restore ligthing', function(done) {
      this.slow(500);
      this.timeout(1000);

      var result = logiled.restoreLighting();
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 250);
    });

    it('should save lighting for ESC key', function(done) {
      this.slow(500);
      this.timeout(1000);

      var result = logiled.saveLightingForKey({
        keyName: logiled.KeyName.ESC
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 250);
    });

    it('should blink ESC key (red)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.flashSingleKey({
        keyName: logiled.KeyName.ESC,
        redPercentage: 100,
        greenPercentage: 5,
        bluePercentage: 5,
        milliSecondsDuration: 3000,
        milliSecondsInterval: 250
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should fade ESC key (green)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.pulseSingleKey({
        keyName: logiled.KeyName.ESC,
        startRedPercentage: 5,
        startGreenPercentage: 5,
        startBluePercentage: 5,
        finishRedPercentage: 5,
        finishGreenPercentage: 100,
        finishBluePercentage: 5,
        milliSecondsDuration: 3000,
        isInfinite: false
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should set ESC key color (blue)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.setLightingForKeyWithKeyName({
        keyName: logiled.KeyName.ESC,
        redPercentage: 0,
        greenPercentage: 0,
        bluePercentage: 100
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should stop effects on ESC key', function() {

      var result = logiled.stopEffectsOnKey({
        keyName: logiled.KeyName.ESC
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

    });

    it('should restore lighting for ESC key', function(done) {
      this.slow(500);
      this.timeout(1000);

      var result = logiled.restoreLightingForKey({
        keyName: logiled.KeyName.ESC
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 250);
    });

    it('should exclude W,S,A and D keys from bitmap', function() {

      var result = logiled.excludeKeysFromBitmap({
        keyList: LOGI_WSAD
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);
    });

    it('should exclude existing Int32Array key lists from bitmap', function() {

      var result = logiled.excludeKeysFromBitmap({
        keyList: new Int32Array(LOGI_WSAD) as any
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);
    });

    it('should animate lighting from bitmap', function(done) {
      this.slow(20000);
      this.timeout(25000);

      var bitmap = new Uint8Array(logiled.LED_BITMAP_SIZE);
      var time   = 0;
      var timer  = null;

      function animate() {

        var offset = 0;
        var t = time * 0.001;

        async.times(logiled.LED_BITMAP_HEIGHT, function (y, doneY) {

          async.times(logiled.LED_BITMAP_WIDTH, function (x, doneX) {

            bitmap[offset++] = Math.floor(Math.sin(
              t + x / logiled.LED_BITMAP_WIDTH
            ) * 256); // blue

            bitmap[offset++] = Math.floor(Math.cos(
              t + y / logiled.LED_BITMAP_HEIGHT
            ) * 256); // green

            bitmap[offset++] = Math.floor(Math.atan2(
              Math.cos(t) + y / logiled.LED_BITMAP_HEIGHT,
              Math.sin(t) + x / logiled.LED_BITMAP_WIDTH
            ) * 256); // red

            bitmap[offset++] = 255; // alpha

            doneX(null, true);
          }, function (err) {
            var result = logiled.setLightingFromBitmap({
              bitmap: bitmap
            });
            assert.equal(typeof result, 'boolean');
            assert.equal(result, true);
            doneY(err, result);
          });

        }, function (err, results) {
          time += 50;
          if (time >= 19000) {
            clearInterval(timer);
            timer = null;
            done();
          }
        });

      }

      timer = setInterval(animate, 50);
    });

    it('should set NumLock key color (white, by scan code)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.setLightingForKeyWithScanCode({
        keyCode: LOGI_KEY_NUMLOCK_SCANCODE,
        redPercentage:   100,
        greenPercentage: 100,
        bluePercentage:  100
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should set NumLock key color (black, by hid code)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.setLightingForKeyWithScanCode({
        keyCode: LOGI_KEY_NUMLOCK_HIDCODE,
        redPercentage:   0,
        greenPercentage: 0,
        bluePercentage:  0
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should set NumLock key color (white, by quartz code)', function(done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.setLightingForKeyWithQuartzCode({
        keyCode: LOGI_KEY_NUMLOCK_QUARTZCODE,
        redPercentage:   100,
        greenPercentage: 100,
        bluePercentage:  100
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });
  });

  describe('RGB', function() {

    before('setup sdk', function(done) {
      logiled.init();
      setTimeout(done, 250);
    });

    after('finalize sdk', function () {
      logiled.shutdown();
    });

    it('should setup keyboard/mouse (RGB)', function () {

      var result = logiled.setTargetDevice({
        targetDevice: logiled.TargetDevice.RGB
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);
    });

    it('should set device color (blue)', function(done) {

      this.slow(6000);
      this.timeout(10000);

      var result = logiled.setLighting({
        redPercentage:   0,
        greenPercentage: 0,
        bluePercentage:  100
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    // it('should set mouse zone colors (orange and purple)', function (done) {
    //   this.slow(6000);
    //   this.timeout(10000);

    //   var result = logiled.setLightingForTargetZone({
    //     deviceType: logiled.DeviceType.Mouse,
    //     zone: 1,
    //     redPercentage:   0,
    //     greenPercentage: 0,
    //     bluePercentage:  100
    //   });
    //   assert.equal(typeof result, 'boolean');
    //   assert.equal(result, true);

    //   setTimeout(done, 5000);
    // });

    it('should blink device (red)', function (done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.flashLighting({
        redPercentage: 100,
        greenPercentage: 5,
        bluePercentage: 5,
        milliSecondsDuration: 4000,
        milliSecondsInterval: 250
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });

    it('should fade device (green)', function (done) {
      this.slow(6000);
      this.timeout(10000);

      var result = logiled.pulseLighting({
        redPercentage: 0,
        greenPercentage: 100,
        bluePercentage: 0,
        milliSecondsDuration: 4000,
        milliSecondsInterval: 500
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, true);

      setTimeout(done, 5000);
    });
  });
});
