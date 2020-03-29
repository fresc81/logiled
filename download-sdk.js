
//const LOGITECH_LED_SDK_URL = 'https://gaming.logitech.com/sdk/LED_8.87.zip';
const LOGITECH_LED_SDK_URL = 'https://www.logitechg.com/sdk/LED_SDK_9.00.zip';

const fs = require('fs-extra');
const path = require('path');
const EOL = require('os').EOL;
const unzip = require('unzip');
const fstream = require('fstream');
const request = require('request');
const progress = require('request-progress');
const progressBar = require('progress-bar').create(process.stdout, (process.stdout.columns || 70) - 20);
progressBar.format = '$bar; $percentage;% finished.';

const TMP = path.join(__dirname, 'TMP');
const TMP_LED = path.join(TMP, 'LED');
const LED = path.join(__dirname, 'LED');

// only download SDK if not already done
if (!fs.existsSync(LED)) {

    if (fs.existsSync(TMP)) {
        fs.removeSync(TMP);
    }

    fs.mkdirSync(TMP);
    const writeStream = new fstream.Writer(TMP);

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
        fs.moveSync(TMP_LED, LED);
        fs.rmdirSync(TMP);
        if (process.stdout.isTTY) {
            progressBar.clear();
        }
        console.log('finished successfully.' + EOL);
    })
    .pipe(unzip.Parse())
    .pipe(writeStream);
}
