var osc = require("osc");
var flock = require("flocking");

var serialPort = new osc.SerialPort({
    devicePath: process.argv[2] || "/dev/cu.usbmodem174561"
});

serialPort.on("message", function (oscMessage) {

    switch (oscMessage.address){
        case "/fader/0":
            granny.set("granny.source.freq", oscMessage.args[0] + 200);
            break;
        case "/fader/1":
            granny.set("granny.numGrains", oscMessage.args[0]/8 + 2);
            break;
        case "/fader/2":
            granny.set("granny.grainDur", oscMessage.args[0]/1024 + 0.01);
            break;

        default: 
            break;
    }
});

serialPort.open();

var granny = flock.synth({
    synthDef: {
        id: "granny",
        ugen: "flock.ugen.granulator",
        numGrains: 100,
        grainDur: 0.5,
        delayDur: 3,
        source: {
            ugen: "flock.ugen.filter.biquad.lp",
            freq: 500,
            q: 0.56,
            source: {
                ugen: "flock.ugen.whiteNoise"
            }
        }
    }
});

flock.init();
granny.play();
