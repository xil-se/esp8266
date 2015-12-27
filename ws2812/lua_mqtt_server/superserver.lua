sk=net.createConnection(net.TCP, 0)
sk:on("receive", function(sck, c) ledmate.push_msg(c) end )
sk:connect(3344,"149.210.234.62")
--sk:connect(3344,"192.168.1.100")
