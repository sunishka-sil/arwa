// One terminal: start the server, then the simulator (keys go to the simulator).
const { spawn } = require('child_process');
const path = require('path');
const srv = spawn(process.execPath, [path.join(__dirname, '..', 'server', 'index.js')], { stdio: ['ignore', 'inherit', 'inherit'] });
process.on('exit', () => srv.kill());
setTimeout(() => require('../sim/sensor.js'), 800);
