
module.exports = require('bindings')({
  try: [
    
    // first try binaries in ./build folder, prefer debug builds
    [ 'module_root', 'build', 'Debug',    'bindings' ],
    [ 'module_root', 'build', 'Release',  'bindings' ],

    // then try binaries in ./dist folder, automatically resolving platform and arch
    [ 'module_root', 'dist',  'platform', 'arch', 'bindings' ],

    // finally fallback to a dummy javascript implementation
    [ 'module_root', 'dist',  'dummy.js' ],
  ]
});

// mixin LED SDK constants...
var constants = require(__dirname+'/dist/constants');
Object.getOwnPropertyNames(constants).forEach(function (key) {
  module.exports[key] = constants[key];
});
