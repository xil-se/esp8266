// The function gets called when the window is fully loaded
window.onload = function() {
  var canvas = document.getElementById("viewport");
  var context = canvas.getContext("2d");

  // Define the image dimensions
  var width = canvas.width;
  var height = canvas.height;
  var imagedata = context.createImageData(width, height);
  var framebuffer = new Uint8Array(144*8*3);

  var ws;
  ws = new WebSocket("ws://localhost:8088/");
  ws.onopen = function() {
  }
  ws.onmessage = function(e) {
//    console.log(e.data);

    var decoded = atob(e.data);
    var i, il = decoded.length;

    var x, X, y, r, g, b, pixelindex, start;
    if (decoded.charCodeAt(0) == 1) start = 0;
    if (decoded.charCodeAt(0) == 2) start = 1458;
    if (decoded.charCodeAt(0) == 3) start = 1458*2;

    for (x = 1; x < decoded.length; x++) {
      framebuffer[start + x - 1] = decoded.charCodeAt(x);
    }

    if (decoded.charCodeAt(0) != 3) return;

    console.log("full frame");
    console.log(framebuffer);

    for (var y = 0; y < height; y++) {
      for (var X = 0; X < width; X++) {
        pixelindex = (y * width + X) * 4;

        x = (y%2) ? (143 - X) : X;

        g = framebuffer[(y*width + x)*3];
        r = framebuffer[(y*width + x)*3 + 1];
        b = framebuffer[(y*width + x)*3 + 2];

        r = r > 0 ? Math.min(r*32, 255) : 0;
        g = g > 0 ? Math.min(g*32, 255) : 0;
        b = b > 0 ? Math.min(b*32, 255) : 0;

        imagedata.data[pixelindex]   = r;
        imagedata.data[pixelindex+1] = g;
        imagedata.data[pixelindex+2] = b;
        imagedata.data[pixelindex+3] = 255;
      }
    }

    // Draw the image data to the canvas
    context.putImageData(imagedata, 0, 0);

  }
};

/*

// Get the canvas and context
var canvas = document.getElementById("viewport");
var context = canvas.getContext("2d");

// Define the image dimensions
var width = canvas.width;
var height = canvas.height;

// Create an ImageData object
var imagedata = context.createImageData(width, height);

// Create the image
function createImage(offset) {
// Loop over all of the pixels
for (var x=0; x<width; x++) {
for (var y=0; y<height; y++) {
// Get the pixel index
var pixelindex = (y * width + x) * 4;

// Generate a xor pattern with some random noise
var red = ((x+offset) % 256) ^ ((y+offset) % 256);
var green = ((2*x+offset) % 256) ^ ((2*y+offset) % 256);
var blue = 50 + Math.floor(Math.random()*100);

// Rotate the colors
blue = (blue + offset) % 256;

// Set the pixel data
imagedata.data[pixelindex] = red;     // Red
imagedata.data[pixelindex+1] = green; // Green
imagedata.data[pixelindex+2] = blue;  // Blue
imagedata.data[pixelindex+3] = 255;   // Alpha
}
}
}

// Main loop
function main(tframe) {
// Request animation frames
window.requestAnimationFrame(main);

// Create the image
createImage(Math.floor(tframe / 10));

// Draw the image data to the canvas
context.putImageData(imagedata, 0, 0);
}

// Call the main loop
main(0);
};
*/
