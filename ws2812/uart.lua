--uart.setup(0, 115200, 8, 0, 1, 0)
uart.setup(0, 9600, 8, 0, 1, 0)

--packets = {}
--packet = 0

--uart.on("data", 144,
--    function(data)
--        packets[packet] = data
--        packet = packet + 1
--        if packet == 24 then
--            ws2812.writedual(3, 4, table.concat(packets, ""), 1)
--            packets = {}
--            packet = 0
--        end
--    end, 0 )

uart.on("ws2812", 100, function(data) end, 0)


