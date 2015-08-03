function update()
    bmp085.init(1, 2)
    local t = bmp085.temperature()
    local t = string.format("%s.%s", t / 10, t % 10)
    local p = bmp085.pressure()
    local p = string.format("%s.%s", p / 100, p % 100)
    data = "1=" .. t .. "&2=" .. p 
    print(data)
    post(data)

    tmr.alarm(1, 5000, tmr.ALARM_SINGLE, update)
end

function post(d)
    local r = string.format([===[POST /update HTTP/1.1
Host: api.thingspeak.com
Connection: close
X-THINGSPEAKAPIKEY: --SECETKEYHERE--
Content-Type: application/x-www-form-urlencoded
Content-Length: %s

%s]===], #d, d)

    print("Request: " .. r)
    local sk=net.createConnection(net.TCP, 0)
    sk:on("receive", function(sck, c)  end )
    --sk:on("receive", function(sck, c) print(c) end )
    sk:connect(80, "184.106.153.149")
    sk:send(r)
end
