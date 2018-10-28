
const LOGITECH_LED_SDK_URL = 'https://gaming.logitech.com/sdk/LED_8.87.zip';

var fs = require('fs');
var path = require('path');
var EOL = require('os').EOL;
var unzip = require('unzip');
var fstream = require('fstream');
var request = require('request');
var progress = require('request-progress');
var progressBar = require('progress-bar').create(process.stdout, (process.stdout.columns || 70) - 20);
progressBar.format = '$bar; $percentage;% finished.';

var writeStream = new fstream.Writer(__dirname);

// only download SDK if not already done
if (!fs.existsSync(path.join(__dirname, 'LED'))) {

    // download and unzip SDK into the LED folder...
    console.log('Download and unzip Logitech LED SDK...');

    // also show a fancy progress bar if stdout is a terminal
    progress(request(LOGITECH_LED_SDK_URL), {
        throttle: 250
    })
    .on('progress', function (state) {
        if (process.stdout.isTTY) {
            progressBar.update(state.percent);
        }
    })
    .on('error', function (err) {
        if (process.stdout.isTTY) {
            progressBar.clear();
        }
        console.log('error downloading Logitech LED SDK:', err.message, EOL);
        process.exit(1);
    })
    .on('end', function (state) {
        if (process.stdout.isTTY) {
            progressBar.clear();
        }
        console.log('finished successfully.' + EOL);
    })
    .pipe(unzip.Parse())
    .pipe(writeStream);
}
