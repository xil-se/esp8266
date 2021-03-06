var dgram = require("dgram");
var fs = require("fs");
var btoa = require("btoa");
var WebSocketServer = require('websocket').server;
var http = require('http');

var WEBSOCKET_PORT = 8088
var UDPSERVER_PORT = 8888

var server = http.createServer(function(request, response) {
    // process HTTP request. Since we're writing just WebSockets server
    // we don't have to implement anything.
});
server.listen(WEBSOCKET_PORT, function() { });

// create the server
wsServer = new WebSocketServer({
    httpServer: server
});

// WebSocket server
var global_connection;
wsServer.on('request', function(request) {
    var connection = request.accept(null, request.origin);
    global_connection = connection;
    console.log('request');
    console.log(request);

    // This is the most important callback for us, we'll handle
    // all messages from users here.
    connection.on('message', function(message) {
        console.log('message');
        console.log(message);
        if (message.type === 'utf8') {
            // process WebSocket message
        }
    });

    connection.on('close', function(connection) {
        // close user connection
    });
});



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

  if (global_connection) {
    global_connection.sendUTF(JSON.stringify(framebuffer));
  }
});

udpserver.on("listening", function () {
  var address = server.address();
  console.log("server listening " +
      address.address + ":" + address.port);
});

udpserver.bind(8888);
