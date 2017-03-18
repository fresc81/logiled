
var fs = require('fs');
var spawn = require('child_process').spawn;

// using precompiled dist folder if it exists...
if (!fs.existsSync(__dirname+'/dist/')) {
    // rebuild dist folder otherwise...
    spawn('node-gyp rebuild', {
        shell: true,
        stdio: [
            null,
            process.stdout,
            process.stderr
        ]
    });
}