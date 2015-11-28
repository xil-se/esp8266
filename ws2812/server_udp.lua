-- Listens on UDP port 8888 and pushes pixels to a LED screen.
-- A full frame buffer is larger than the size of a UDP packet so it has to
-- be sent in multiple packets. The first byte of each packet determines which
-- part it is. \x01 \x02 \x03 are valid values.
-- When packet #3 is received the pixels are pushed to the LEDs.

s=net.createServer(net.UDP) 
packets={}
s:on("receive",function(s,c)
  packet = c:byte(1)
  if packet > 0 and packet < 4 then
    packets[packet] = c:sub(2, #c)
    if packet == 3 then
      ws2812.writedual(3, 4, table.concat(packets, ""), 1)
    end
  end
end)
s:listen(8888)

