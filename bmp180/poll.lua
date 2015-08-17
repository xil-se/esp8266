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
    local data = "5=" .. t .. "&6=" .. p 
    local t, p = getTP(5, 6)
    local data = data .. "&3=" .. t .. "&4=" .. p
    print(data)
    --post(data)
    tmr.alarm(1, 5000, tmr.ALARM_SINGLE, update)
end

function post(d)
    local r = string.format([===[POST /update HTTP/1.1
Host: api.thingspeak.com
Connection: close
X-THINGSPEAKAPIKEY: %s
Content-Type: application/x-www-form-urlencoded
Content-Length: %s

%s]===], thingspeakapikey, #d, d)

    local sk=net.createConnection(net.TCP, 0)
    -- sk:on("receive", function(sck, c) print(c) end )
    sk:connect(80, "184.106.153.149")
    sk:send(r)
end

update()
