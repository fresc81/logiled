var logiled = require('../');
var assert = require('assert');
var async = require('async');

const LOGI_LOGO = [
  logiled.KeyName.G_LOGO,
  logiled.KeyName.G_BADGE,
];

function runDemo (done) {
  console.log('start');
  async.series([

    function (cb) {
      console.log('e1');
      var result = logiled.saveCurrentLighting();
      assert.equal(typeof result, 'object');
      assert.equal(result.result, true);
      setTimeout(cb, 250, null, result.result);
    },
    function (cb) {
      console.log('e2');
      var result = logiled.setLighting(0, 0, 0);
      assert.equal(typeof result, 'object');
      assert.equal(result.result, true);
      cb(null, result.result);
    },
    function (cb) {

      console.log('e3 start');
      var i = 1;
      async.every(LOGI_LOGO, function (item, ready) {
        console.log('e3.'+(i++));
        var result = logiled.flashSingleKey(item, 100, 100, 100, 10000, 250);
        ready(null, result.result);
      }, function (err, result) {
        console.log('e3 end');
        assert.equal(typeof result, 'boolean');
        assert.equal(result, true);
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
      assert.equal(typeof result, 'object');
      assert.equal(result.result, true);
      setTimeout(cb, 250, null, result.result);
    },

  ], function (err, results) {
    assert.equal(!!err, false);
    console.log('end');
    done();
  });
}

describe('logiled', function() {

  it('should initialize sdk', function(done) {
    this.slow(500);
    this.timeout(1000);
    
    var result = logiled.init();
    assert.equal(typeof result, 'boolean');
    assert.equal(result, true);

    setTimeout(done, 250);
  });

  it('should get sdk version', function() {
    var version = { };
    var result = logiled.getSdkVersion(version);
    
    assert.equal(typeof result, 'boolean');
    assert.equal(result, true);

    assert.equal(typeof version.majorNum, 'number');
    assert.equal(typeof version.minorNum, 'number');
    assert.equal(typeof version.buildNum, 'number');
  });

  it('should setup keyboard', function() {
    var result = logiled.setTargetDevice(logiled.DEVICETYPE_PERKEY_RGB);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
  });

  it('should get a numeric config option', function() {
    
    var configOption = {
      configPath: 'player/numeric',
      defaultValue: 0
    };
    var result = logiled.getConfigOptionNumber(configOption);

    assert.equal(typeof result, 'boolean');
    assert.equal(result, true);

    assert.equal(typeof configOption.value, 'number');
    assert.equal(configOption.value, 0);
  });

  it('should get a boolean config option', function() {
    
    var configOption = {
      configPath: 'player/boolean',
      defaultValue: false
    };
    var result = logiled.getConfigOptionBool(configOption);

    assert.equal(typeof result, 'boolean');
    assert.equal(result, true);

    assert.equal(typeof configOption.value, 'boolean');
    assert.equal(configOption.value, false);
  });

  it('should save current ligthing', function(done) {
    this.slow(500);
    this.timeout(1000);
    var result = logiled.saveCurrentLighting();
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 250);
  });

  it('should blink keyboard (red)', function(done) {
    this.slow(6000);
    this.timeout(10000);
    var result = logiled.flashLighting(100, 5, 5, 4000, 250);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 5000);
  });

  it('should fade keyboard (green)', function(done) {
    this.slow(6000);
    this.timeout(10000);
    var result = logiled.pulseLighting(0, 100, 0, 4000, 250);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 5000);
  });

  it('should set keyboard color (blue)', function(done) {
    this.slow(6000);
    this.timeout(10000);
    var result = logiled.setLighting(0, 0, 100);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 5000);
  });

  it('should stop effects', function() {
    var result = logiled.stopEffects();
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
  });

  it('should restore ligthing', function(done) {
    this.slow(500);
    this.timeout(1000);
    var result = logiled.restoreLighting();
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 250);
  });

  it('should save lighting for ESC key', function(done) {
    this.slow(500);
    this.timeout(1000);
    var result = logiled.saveLightingForKey(logiled.KeyName.ESC);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 250);
  });

  it('should blink ESC key (red)', function(done) {
    this.slow(6000);
    this.timeout(10000);
    var result = logiled.flashSingleKey(logiled.KeyName.ESC, 100, 5, 5, 3000, 250);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 5000);
  });

  it('should fade ESC key (green)', function(done) {
    this.slow(6000);
    this.timeout(10000);
    var result = logiled.pulseSingleKey(logiled.KeyName.ESC, 5, 5, 5, 5, 100, 5, 3000, false);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 5000);
  });

  it('should set ESC key color (blue)', function(done) {
    this.slow(6000);
    this.timeout(10000);
    var result = logiled.setLightingForKeyWithKeyName(logiled.KeyName.ESC, 0, 0, 100);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
    setTimeout(done, 5000);
  });

  it('should stop effects on ESC key', function() {
    var result = logiled.stopEffectsOnKey(logiled.KeyName.ESC);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
  });

  it('should restore lighting for ESC key', function(done) {
    this.slow(500);
    this.timeout(1000);
    var result = logiled.restoreLightingForKey(logiled.KeyName.ESC);
    assert.equal(typeof result, 'object');
    assert.equal(result.result, true);
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
