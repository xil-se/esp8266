var dgram = require("dgram");

var UDPSERVER_PORT = 8888

var udpserver = dgram.createSocket("udp4");
var framebuffer = new Uint8Array(144*8*3);
udpserver.on("message", function (msg, rinfo) {
  if (msg[0] == 1) start = 0;
  if (msg[0] == 2) start = 1458;
  if (msg[0] == 3) start = 1458*2;

  for (x = 1; x < msg.length; x++) {
    framebuffer[start + x - 1] = msg[x];
  }

  if (msg[0] != 3) return;

  var output = [];
  output.push("\033[0;0H");
  for(var y = 0; y < 4; y++) {
    var upper = [];
    var lower = [];
    for(var x = 0; x < 144; x++) {
      var start1 = y*144*3*2 + x*3;
      var start2 = y*144*3*2 + 144*3 + (143-x)*3;
      var c = 32;
      upper.push({
        g: Math.min(255, c*framebuffer[start1]),
        r: Math.min(255, c*framebuffer[start1 + 1]),
        b: Math.min(255, c*framebuffer[start1 + 2]),
      });
      lower.push({
        g: Math.min(255, c*framebuffer[start2]),
        r: Math.min(255, c*framebuffer[start2 + 1]),
        b: Math.min(255, c*framebuffer[start2 + 2]),
      });
    }
    for(var x = 0; x < upper.length; x++) {
      output.push("\033[38;2;" + upper[x].r + ';' + upper[x].g + ';' + upper[x].b + ';48;2;' + lower[x].r + ';' + lower[x].g + ';' + lower[x].b + 'm▀');
    }
    output.push("\033[0m\n");
  }
  console.log(output.join(''));
});

udpserver.bind(8888);

