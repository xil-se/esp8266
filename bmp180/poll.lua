function getTP(sda, sck)
    bmp085.init(sda, sck)
    local t = bmp085.temperature()
    local t = string.format("%s.%s", t / 10, t % 10)
    local p = bmp085.pressure()
    local p = string.format("%s.%s", p / 100, p % 100)
    return t, p
end

function update()
    local t, p = getTP(1, 2)
    local data = "sensor.temp.fridge " .. t .. "\nsensor.pressure.fridge " .. p .. "\n"
    local t, p = getTP(5, 6)
    local data = data .. "sensor.temp.kitchen " .. t .. "\nsensor.pressure.kitchen " .. p .. "\n"
    print(data)
    post(data)
    tmr.alarm(1, 5000, tmr.ALARM_SINGLE, update)
end

function post(d)
    local sk=net.createConnection(net.TCP, 0)


    sk:on("connection", function()
        sk:send(d)
        print("uploaded")
    end)

    sk:connect(1234, "192.168.5.55")
end

update()
