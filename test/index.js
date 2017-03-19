var logiled = require('../');
var assert = require('assert');
var async = require('async');

const LOGI_LOGO = [
  logiled.KeyName.G_LOGO,
  logiled.KeyName.G_BADGE,
];

var expectedResult = true;

function runDemo (done) {
  console.log('start');
  async.series([

    function (cb) {
      console.log('e1');

      var result = logiled.saveCurrentLighting();
      assert.equal(typeof result, 'boolean');
      assert.equal(result, expectedResult);

      setTimeout(cb, 250, null, result);
    },
    function (cb) {
      console.log('e2');

      var result = logiled.setLighting({
        redPercentage:   0,
        greenPercentage: 0,
        bluePercentage:  0
      });
      assert.equal(typeof result, 'boolean');
      assert.equal(result, expectedResult);

      cb(null, result);
    },
    function (cb) {

      console.log('e3 start');
      var i = 1;
      async.every(LOGI_LOGO, function (item, ready) {
        console.log('e3.'+(i++));

        var result = logiled.flashSingleKey({
          keyName: item,
          redPercentage: 100,
          greenPercentage: 100,
          bluePercentage: 100,
          milliSecondsDuration: 10000,
          milliSecondsInterval: 250
        });
        ready(null, result);

      }, function (err, result) {
        console.log('e3 end');
        assert.equal(typeof result, 'boolean');
        assert.equal(result, expectedResult);
        cb(err, result);
      });

    },

    function (cb) {

      console.log('e4');
      setTimeout(cb, 10000, null, true);

    },

    function (cb) {
      console.log('e5');

      var result = logiled.restoreLighting();
      assert.equal(typeof result, 'boolean');
      assert.equal(result, expectedResult);

      setTimeout(cb, 250, null, result);
    },

  ], function (err, results) {
    assert.equal(!!err, false);
    console.log('end');
    done();
  });
}

describe('logiled', function() {

  it('should run on windows', function () {
    var isWindowsPlatform = process.platform === 'win32';
    assert.equal(isWindowsPlatform, true);
    if (!isWindowsPlatform) {
      expectedResult = false;
    }
  });

  it('should initialize sdk', function(done) {
    this.slow(500);
    this.timeout(1000);
    
    var result = logiled.init();
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

    setTimeout(done, 250);
  });

  it('should get sdk version', function() {
    var version = { };
    var result = logiled.getSdkVersion(version);
    
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

    if (result) {
      assert.equal(typeof version.majorNum, 'number');
      assert.equal(typeof version.minorNum, 'number');
      assert.equal(typeof version.buildNum, 'number');
    }
  });

  it('should setup keyboard', function() {
    var result = logiled.setTargetDevice({
      targetDevice: logiled.DEVICETYPE_PERKEY_RGB
    });
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);
  });

  it('should get a numeric config option', function() {
    
    var configOption = {
      configPath: 'player/numeric',
      defaultValue: 0
    };
    var result = logiled.getConfigOptionNumber(configOption);

    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

    if (result) {
      assert.equal(typeof configOption.value, 'number');
      assert.equal(configOption.value, 0);
    }
  });

  it('should get a boolean config option', function() {
    
    var configOption = {
      configPath: 'player/boolean',
      defaultValue: false
    };
    var result = logiled.getConfigOptionBool(configOption);

    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);
    
    if (result) {
      assert.equal(typeof configOption.value, 'boolean');
      assert.equal(configOption.value, false);
    }
  });

  it('should save current ligthing', function(done) {
    this.slow(500);
    this.timeout(1000);

    var result = logiled.saveCurrentLighting();
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

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
    assert.equal(result, expectedResult);

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
    assert.equal(result, expectedResult);

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
    assert.equal(result, expectedResult);

    setTimeout(done, 5000);
  });

  it('should stop effects', function() {

    var result = logiled.stopEffects();
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

  });

  it('should restore ligthing', function(done) {
    this.slow(500);
    this.timeout(1000);

    var result = logiled.restoreLighting();
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

    setTimeout(done, 250);
  });

  it('should save lighting for ESC key', function(done) {
    this.slow(500);
    this.timeout(1000);

    var result = logiled.saveLightingForKey({
      keyName: logiled.KeyName.ESC
    });
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

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
    assert.equal(result, expectedResult);

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
    assert.equal(result, expectedResult);

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
    assert.equal(result, expectedResult);

    setTimeout(done, 5000);
  });

  it('should stop effects on ESC key', function() {

    var result = logiled.stopEffectsOnKey({
      keyName: logiled.KeyName.ESC
    });
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

  });

  it('should restore lighting for ESC key', function(done) {
    this.slow(500);
    this.timeout(1000);

    var result = logiled.restoreLightingForKey({
      keyName: logiled.KeyName.ESC
    });
    assert.equal(typeof result, 'boolean');
    assert.equal(result, expectedResult);

    setTimeout(done, 250);
  });

  it('should run a demo', function(done) {
    this.slow(20000);
    this.timeout(0);
    runDemo(done);
  });

  it('should finalize sdk', function() {

    logiled.shutdown();
    
  });

});
