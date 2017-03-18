
module.exports = require('bindings')({
  try: [
      [ 'module_root', 'build', 'Release', 'bindings' ],
      [ 'module_root', 'build', 'Debug',   'bindings' ],
      [ 'module_root', 'dist',  'arch',    'bindings' ],
  ]
});

var constants = require('./dist/constants');
Object.getOwnPropertyNames(constants).forEach(function (key) {
  module.exports[key] = constants[key];
});
