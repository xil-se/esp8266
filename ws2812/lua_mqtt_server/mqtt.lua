-- init mqtt client with keepalive timer 120sec
m = mqtt.Client("foo", 120, "", "")

m:on("connect", function(con) print ("connected") end)
m:on("offline", function(con) print ("offline") end)

-- on publish message receive event
m:on("message", function(conn, topic, data)
    print(topic .. ":" .. data)
    ledmate.push_msg(data, data)
end)

m:connect("149.210.234.62", 3344, 0, function(conn)
    print("connected")
    m:subscribe("/ledmate", 0, function(conn)
        print("subscribe success")
    end)
end)
