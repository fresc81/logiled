
module.exports = require('bindings')({
  compiled: 'dist',
  try: [
    
    // first try binaries in ./build folder, prefer debug builds
    [ 'module_root', 'build', 'Debug',    'bindings' ],
    [ 'module_root', 'build', 'Release',  'bindings' ],

    // finally fallback to a dummy javascript implementation
    [ 'module_root', 'compiled', 'dummy.js' ],
  ]
});

// mixin LED SDK constants...
var constants = require(__dirname+'/dist/constants');
Object.getOwnPropertyNames(constants).forEach(function (key) {
  module.exports[key] = constants[key];
});

// mixin keynames...
var keynames = require(__dirname+'/dist/keyname');
Object.getOwnPropertyNames(keynames).forEach(function (key) {
  module.exports[key] = keynames[key];
});
