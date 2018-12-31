const PORT = 3000;
const CORES = require('os').cpus().length;

const process = require('process');
const path = require('path');
const child_process = require('child_process');
const spawn = child_process.spawn;
const hostname = require('os').hostname();
const express = require('express');
const app = express();

let stressors = [];

app.use((req, res, next) => {
    res.setHeader('Connection', 'close');
    next();
});

function stress(cores) {
    if (process.platform === "win32") {
        const stressorPath = path.join(__dirname, 'winStressor.bat');

        for (let i = 0; i < cores; i++)
            stressors.push(spawn(stressorPath, []));

        return stressors;
    } else {
        const stressorPath = path.join(__dirname, 'lnxStressor.sh');

        for (let i = 0; i < cores; i++)
            stressors.push(spawn(stressorPath, [], { detached: true }));

        return stressors;
    }
}

function release() {
    if (stressors.length == 0) return;
    if (process.platform === "win32") {
        while (true) {
            if (stressors.length == 0) break;
            stressors.pop().kill();
        }
    } else {
        while (true) {
            if (stressors.length == 0) break;
            proc = stressors.pop();
            process.kill(-proc.pid, 'SIGKILL');
        }
    }
}

app.get('/', (req, res) => res.send(hostname))
    .get('/work', (req, res) => {
        if (stressors.length) return res.end();
        stressors = stress(CORES);
        res.end();
    })
    .get('/rest', (req, res) => {
        release();
        res.end();
    });

app.listen(PORT, () => console.log(`app listening on port ${PORT}`));