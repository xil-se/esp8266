 s=net.createServer(net.UDP) 
 packets={}
 s:on("receive",function(s,c)
    packet = c:byte(1)
    print("packet " .. packet)
    print(node.heap())
    packets[packet] = c:sub(2,#c)
    if packet == 3 then ws2812.writefast(3, table.concat(packets, ""), 1) end
    end)
 s:listen(8888)


